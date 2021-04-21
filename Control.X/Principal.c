#include "Confi.h"
#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "MiADC.h"
#include "PWM.h"
#include "Usart.h"
#include "TMRs.h"
//Constantes
#define Numero      250
#define Tiempo_entre_Muestras  1

//Varibles
uint16_t Brillo; // en porcentaje
uint16_t Lectura_del_brillo;
uint32_t aux;
uint16_t valores[Numero];

//Acumuladores
uint8_t Iniciar_acumulacion_de_datos = 1;
uint8_t Indice = 0;
uint8_t i;
uint8_t a;

//Variables de interrupciones
volatile uint16_t conta_100us = 0;
volatile uint8_t Bandera_de_Lectura = 0;

void main(void) {
    Inicializacion();
    // Interrupciones_Usart(1);
    Led_Twinkle();
    TRISD1 = 0;
    RCONbits.IPEN = 1;
    TMR0_Start = 1;
    while (1) {
        for (a = 0; a < 6; a++) {
            RD1 = 0;
            __delay_ms(250);
            while (Iniciar_acumulacion_de_datos) {
                if (Bandera_de_Lectura == 1) {
                    Bandera_de_Lectura = 0;
                    valores[Indice] = LecturaADC(0);
                    if (Indice == 20) RD1 = 1;
                    Indice++;
                    if (Indice == Numero) {
                        Indice = 0;
                        Iniciar_acumulacion_de_datos = 0;

                        switch (a) {
                            case 0:
                                UART0_Tx_String("A=[");
                                break;
                            case 1:
                                UART0_Tx_String("B=[");
                                break;
                            case 2:
                                UART0_Tx_String("C=[");
                                break;
                            case 3:
                                UART0_Tx_String("D=[");
                                break;
                            case 4:
                                UART0_Tx_String("E=[");
                                break;
                            case 5:
                                UART0_Tx_String("F=[");
                                break;
                        }
                        for (i = 0; i < Numero; i++) {
                            UART0_Tx_Integer(valores[i]);
                            if (i < Numero - 1)UART0_Tx_String(",");
                        }
                        UART0_Tx_String("];");
                        UART0_Tx_String("\n\r");
                    }
                }
            }
            Iniciar_acumulacion_de_datos=1;
        }
        while (a == 6);
    }
}

void __interrupt(high_priority) Timer(void) {
    if (TMR0_Flag == 1) {
        TMR0_Reset();
        conta_100us++;
        if (conta_100us == Tiempo_entre_Muestras) {
            conta_100us = 0;
            Inicio_Adc = 1;
        }
    }
}

void __interrupt(low_priority) Adc(void) {
    if (Adc_Flag == 1) {
        PIR1bits.ADIF = 0;
        Bandera_de_Lectura = 1;
    }
}

//Programacion 
/*
         Lectura_del_brillo=LecturaADC(0);                 
         UART0_Tx_Integer(Lectura_del_brillo);
         UART0_Tx_String("\r\n");  
 ----------------------------------------------------------------------------------------------------------------------------------
            aux=LecturaADC(1);
            Brillo=Division_entera_up(aux*100,1023);        
            Duty_Cycle_Change(Brillo);
----------------------------------------------------------------------------------------------------------------------------------
         if(Rx_flag==1) {
            abc0=Rx();
            switch (abc0){
                case '1':
                        Tx_num(1);
                    break;
                case '0':
                        Tx_num(3);
                    break;
            }
            Rx_flag=0;
        }
 
 */