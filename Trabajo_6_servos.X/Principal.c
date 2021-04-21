#include "Confi.h"
#include <xc.h>
#include <stdint.h>
#include "Servo.h"
#include "Usart.h"

//Variables
char Mensaje;
uint8_t aux;

void main (void){
    Inicializacion();
    Interrupciones_Usart(1);
    UART0_Tx_String("GOLA");
    while(1){
        if(Rx_flag==1) {
            Rx_flag=0;
            Mensaje=Rx();
            switch (Mensaje){
                case 'A':
                    Servos_150_30();
                    break;
                case 'B':
                    Servos_150_60();
                    break;
                case 'C':
                    Servos_150_90();
                    break;
                case 'D':
                    Servos_150_120();
                    break;
                case 'E':
                    Servos_150_150();
                    break;
                case '1':
                    Servos_60_30_Lento();
                    break;
                case '2':
                    Servos_60_60_Lento();
                    break;
                case '3':
                    Servos_60_30_Rapido();
                    break;
                case '4':
                    Servos_60_60_Rapido();
                    break;
                case 'Z':
                    Servos_90_30_Lento();
                    break;
                case 'Y':
                    Servos_90_60_Lento();
                    break;
                case 'X':
                    Servos_90_90_Lento();
                    break;
                case 'W':
                    Servos_90_30_Rapido();
                    break;
                case 'V':
                    Servos_90_90_Rapido();
                    break;
                case 'U':
                    Servos_90_90_Rapido();
                    break;
                default:
                    UART0_Tx_String("Error, Ángulo erroneo \r\n");
                    break;
            }
        }
    }
}
/*
 Servo_Uno_0();
        Servo_Uno_15();
        Servo_Uno_30();
        Servo_Uno_45();
        Servo_Uno_60();
        Servo_Uno_75();
        Servo_Uno_90();
        Servo_Uno_105();
        Servo_Uno_120();
        Servo_Uno_135();
        Servo_Uno_150();
        Servo_Uno_165();
        Servo_Uno_180();
        Servo_Uno_165();
        Servo_Uno_150();
        Servo_Uno_135();
        Servo_Uno_120();
        Servo_Uno_105();
        Servo_Uno_90();
        Servo_Uno_75();
        Servo_Uno_60();
        Servo_Uno_45();
        Servo_Uno_30();
        Servo_Uno_15();
        Servo_Uno_0();
 * 
 * case 'N':
                    while(aux){
                        if(Rx_flag==1) {                            
                            aux=0;
                            Rx_flag=0;
                            Mensaje=Rx();
                            if(Mensaje=='L')    Servos_90_Lento();
                            if(Mensaje=='R')    Servos_90_Rapido();
                        }
                    }
                    break;
                case 'S':
                    while(aux){
                        if(Rx_flag==1) {
                            aux=0;
                            Rx_flag=0;
                            Mensaje=Rx();
                            if(Mensaje=='L')    Servos_60_Lento();
                            if(Mensaje=='R')    Servos_60_Rapido();                            
                        }
                    }
                    break;
 
 */