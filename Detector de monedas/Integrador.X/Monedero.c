#include "Confi.h"
#include <xc.h>
#include <stdint.h>
#include "MiADC.h"
#include "Servo.h"
#include "Usart.h"
#include "TMRs.h"
#include "Valores_de_la_modeda.h"

//Auxiliar de Monedas
uint16_t Coin_Field = 0; //Distorcion
uint8_t Diametro = 0; //diametro
/*----------------------------------------------------------------------------*/
/*Constantes de lectura*/
uint16_t valor_adc;
uint16_t Curva[N_MUESTRAS];
/*----------------------------------------------------------------------------*/
/*Banderas*/
volatile uint8_t Bandera_de_Lectura = 0;
/*----------------------------------------------------------------------------*/
/*Acumuladores y Contadores*/
volatile uint16_t conta_100us = 0;
uint16_t i = 0;
/*----------------------------------------------------------------------------*/
/*Varibles Auxiliar*/
uint8_t caida;
uint8_t Espera_Campo = 1;
uint16_t Punto_minimo = 1023;
char Moneda;

//Funcion Principal

void main(void) {
    Inicializacion(); //Configuracion del pic
    TMR0_Start = 1;
    UART0_Tx_String("Conexion Establecida \r\n Buenas noches \r\n");
    while (1) {
        // Diametro=Interrupcion_Laser();

        Espera_Campo = 1;
        while (Espera_Campo) {
            if (Bandera_de_Lectura) {
                Bandera_de_Lectura = 0;
                caida = Detecta_Cambio(LecturaADC());
                if (caida) {
                    Espera_Campo = 0;
                    for (i = 0; i < N_MUESTRAS - 1; i++) {
                        while (Bandera_de_Lectura == 0);
                        Bandera_de_Lectura = 0;
                        Curva[i] = LecturaADC();
                    }
                    for (i = 0; i < N_MUESTRAS - 2; i++)
                        if (Curva[i] < Punto_minimo)Punto_minimo = Curva[i];
                    UART0_Tx_Integer(Punto_minimo);
                    //                    UART0_Tx_String("A=[");
                    //                    i=0;
                    //                    for(i=0;i<N_MUESTRAS-1;i++){
                    //                       UART0_Tx_Integer(Curva[i]); 
                    //                       if(i<N_MUESTRAS-2)Tx_char(',');
                    //                    } 
                    //                    UART0_Tx_String("]; \n\r");

                }
            }
        }

        if (Comprobar_Sol(Punto_minimo, Diametro) == 1) UART0_Tx_String("sol \r\n");
        else if (Comprobar_Dos(Punto_minimo, Diametro) == 1) UART0_Tx_String("dos \r\n");
        else if (Comprobar_Cinco(Punto_minimo, Diametro) == 1) UART0_Tx_String("Cinco \r\n");
        else if (Comprobar_Diez(Punto_minimo, Diametro) == 1) UART0_Tx_String("Diez \r\n");
        else if (Comprobar_Veinte(Punto_minimo, Diametro) == 1) UART0_Tx_String("Veinte \r\n");
        else if (Comprobar_Cincuenta(Punto_minimo, Diametro) == 1) UART0_Tx_String("Cincuenta \r\n");
        else {
            Moneda_Fake();
            UART0_Tx_String("Moneda Falsa \r\n");
        }
        Punto_minimo = 1023;
        __delay_ms(100);
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

//switch(Boton_Principal){
//            case 0: //Modo Guardado de datos
//                
//                
//                
//                
//                yisus=1;
//                while(yisus==1) Coin_Field=Coil();
//                GuardaBigDato(u,Coin_Field);
//                Save_8bits(Coin_Size,30+u);
//                Coin_Field=0;
//                Coin_Size=0;
//                u++;
//                Led_Pausa=0;
//            break;
//            case 1: //Modo activacion
//                for(u=0;u<Canti_Mon;u++)Mon[u]=SacaDatos(2*u);
//                for(u=0;u<Canti_Mon;u++)Diame[u]=Show_data(30+u);
//                u=0;
//                Coin_Field=0;
//                Coin_Size=0;
//                while(Boton_Principal==1){
//                    while(Laser_Pin==1);
//                    Led_Pausa=1;
//                    while(Laser_Pin==0){
//                        TMR1_Start=1;
//                        if(TMR1_Flag==1){
//                            TMR1_Flag=0;
//                            Coin_Size++;
//                            TMR1_Reset();
//                        }
//                    }                
//                    TMR1_Start=0;
//                    TMR1_Reset();
//                    yisus=1;
//                    while(yisus==1) Coin_Field=Coil();
//                    
//                    for(u=0;u<Canti_Mon;u++){
//                        if((Coin_Field==Mon[u])&&(Coin_Size==Diame[u])){
//                        
//                        }
//                    }
//                    Coin_Field=0;
//                    Coin_Size=0;
//                }
//            break;
//        }