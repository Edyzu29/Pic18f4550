#include "Confi.h"
#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "Servo.h"
#include "Usart.h"

void Inicializacion(void){
    //Registros Especiales
    OSCCONbits.IRCF=0b111;
    ADCON1bits.PCFG=0xF;
    RCONbits.IPEN = 1;    
    //LIBRERIAS
    Confi_Servo();
    Servo_Posicion_Inicial();       
    Confi_Blue();
}
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
void Servos_150_30(void){
       Servo_Tres_75();        Servo_Cuatro_75();
        Servo_Tres_90();        Servo_Cuatro_90();
        Servo_Tres_105();      Servo_Cuatro_105();
        Servo_Tres_90();        Servo_Cuatro_90();
        Servo_Tres_75();        Servo_Cuatro_75();
        Servo_Tres_60();        Servo_Cuatro_60();
        Servo_Tres_45();        Servo_Cuatro_45();
        Servo_Tres_60();        Servo_Cuatro_60();
        Servo_Tres_75();        Servo_Cuatro_75();
}
/*----------------------------------------------------------------------------------------------------------*/
void Servos_150_60(void){
        Servo_Tres_75();        Servo_Cuatro_75();
        Servo_Tres_90();        Servo_Cuatro_90();
        Servo_Tres_105();      Servo_Cuatro_105();
        Servo_Tres_120();      Servo_Cuatro_120();
        Servo_Tres_105();      Servo_Cuatro_105();
        Servo_Tres_90();        Servo_Cuatro_90();
        Servo_Tres_75();        Servo_Cuatro_75();
        Servo_Tres_60();        Servo_Cuatro_60();
        Servo_Tres_45();        Servo_Cuatro_45();
        Servo_Tres_30();        Servo_Cuatro_30();
        Servo_Tres_45();        Servo_Cuatro_45();
        Servo_Tres_60();        Servo_Cuatro_60();
        Servo_Tres_75();        Servo_Cuatro_75();
}
/*----------------------------------------------------------------------------------------------------------*/
void Servos_150_90(void){
        Servo_Tres_75();        Servo_Cuatro_75();
        Servo_Tres_90();        Servo_Cuatro_90();
        Servo_Tres_105();      Servo_Cuatro_105();
        Servo_Tres_120();      Servo_Cuatro_120();
        Servo_Tres_105();      Servo_Cuatro_105();
        Servo_Tres_90();        Servo_Cuatro_90();
        Servo_Tres_75();        Servo_Cuatro_75();
        Servo_Tres_60();        Servo_Cuatro_60();
        Servo_Tres_45();        Servo_Cuatro_45();
        Servo_Tres_30();        Servo_Cuatro_30();
        Servo_Tres_45();        Servo_Cuatro_45();
        Servo_Tres_60();        Servo_Cuatro_60();
        Servo_Tres_75();        Servo_Cuatro_75();
}
/*----------------------------------------------------------------------------------------------------------*/
void Servos_150_120(void){
        Servo_Tres_75();        Servo_Cuatro_75();
        Servo_Tres_90();        Servo_Cuatro_90();
        Servo_Tres_105();      Servo_Cuatro_105();
        Servo_Tres_120();      Servo_Cuatro_120();
        Servo_Tres_135();      Servo_Cuatro_135();
        Servo_Tres_120();      Servo_Cuatro_120();
        Servo_Tres_105();      Servo_Cuatro_105();
        Servo_Tres_90();        Servo_Cuatro_90();
        Servo_Tres_75();        Servo_Cuatro_75();
        Servo_Tres_60();        Servo_Cuatro_60();
        Servo_Tres_45();        Servo_Cuatro_45();
        Servo_Tres_30();        Servo_Cuatro_30();
        Servo_Tres_15();        Servo_Cuatro_15();
        Servo_Tres_30();        Servo_Cuatro_30();
        Servo_Tres_45();        Servo_Cuatro_45();
        Servo_Tres_60();        Servo_Cuatro_60();
        Servo_Tres_75();        Servo_Cuatro_75();
}
/*----------------------------------------------------------------------------------------------------------*/
void Servos_150_150(void){
        Servo_Tres_75();        Servo_Cuatro_75();
        Servo_Tres_90();        Servo_Cuatro_90();
        Servo_Tres_105();      Servo_Cuatro_105();
        Servo_Tres_120();      Servo_Cuatro_120();
        Servo_Tres_135();      Servo_Cuatro_135();
        Servo_Tres_150();      Servo_Cuatro_150();
        Servo_Tres_135();      Servo_Cuatro_135();
        Servo_Tres_120();      Servo_Cuatro_120();
        Servo_Tres_105();      Servo_Cuatro_105();
        Servo_Tres_90();        Servo_Cuatro_90();
        Servo_Tres_75();        Servo_Cuatro_75();
        Servo_Tres_60();        Servo_Cuatro_60();
        Servo_Tres_45();        Servo_Cuatro_45();
        Servo_Tres_30();        Servo_Cuatro_30();
        Servo_Tres_15();        Servo_Cuatro_15();
        Servo_Tres_0();          Servo_Cuatro_0();
        Servo_Tres_15();        Servo_Cuatro_15();
        Servo_Tres_30();        Servo_Cuatro_30();
        Servo_Tres_45();        Servo_Cuatro_45();
        Servo_Tres_60();        Servo_Cuatro_60();
        Servo_Tres_75();        Servo_Cuatro_75();
}
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
void Servos_60_30_Rapido(void){
        Servo_Cinco_0();        Servo_Seis_0();
        Servo_Cinco_30();      Servo_Seis_30();
        Servo_Cinco_0();        Servo_Seis_0();
}
/*----------------------------------------------------------------------------------------------------------*/
void Servos_60_60_Rapido(void){
        Servo_Cinco_0();        Servo_Seis_0();
        Servo_Cinco_30();      Servo_Seis_30();
        Servo_Cinco_60();      Servo_Seis_60();
        Servo_Cinco_30();      Servo_Seis_30();
        Servo_Cinco_0();        Servo_Seis_0();
}
/*----------------------------------------------------------------------------------------------------------*/
void Servos_60_30_Lento(void){
        Servo_Cinco_0();        Servo_Seis_0();
        Servo_Cinco_15();      Servo_Seis_15();
        Servo_Cinco_30();      Servo_Seis_30();
        Servo_Cinco_30();      Servo_Seis_30();
        Servo_Cinco_15();      Servo_Seis_15();
        Servo_Cinco_0();        Servo_Seis_0();
}
/*----------------------------------------------------------------------------------------------------------*/
void Servos_60_60_Lento(void){
        Servo_Cinco_0();        Servo_Seis_0();
        Servo_Cinco_15();      Servo_Seis_15();
        Servo_Cinco_30();      Servo_Seis_30();
        Servo_Cinco_45();      Servo_Seis_45();
        Servo_Cinco_60();      Servo_Seis_60();
        Servo_Cinco_45();      Servo_Seis_45();
        Servo_Cinco_30();      Servo_Seis_30();
        Servo_Cinco_15();      Servo_Seis_15();
        Servo_Cinco_0();        Servo_Seis_0();
}
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
void Servos_90_30_Rapido(void){
        Servo_Uno_0();        Servo_Dos_0();
        Servo_Uno_30();      Servo_Dos_30();
        Servo_Uno_0();        Servo_Dos_0();
}
/*----------------------------------------------------------------------------------------------------------*/
void Servos_90_60_Rapido(void){
        Servo_Uno_0();        Servo_Dos_0();
        Servo_Uno_30();      Servo_Dos_30();
        Servo_Uno_60();      Servo_Dos_60();
        Servo_Uno_30();      Servo_Dos_30();
        Servo_Uno_0();        Servo_Dos_0();
}
/*----------------------------------------------------------------------------------------------------------*/
void Servos_90_90_Rapido(void){
        Servo_Uno_0();        Servo_Dos_0();
        Servo_Uno_30();      Servo_Dos_30();
        Servo_Uno_60();      Servo_Dos_60();
        Servo_Uno_90();      Servo_Dos_90();
        Servo_Uno_60();      Servo_Dos_60();
        Servo_Uno_30();      Servo_Dos_30();
        Servo_Uno_0();        Servo_Dos_0();
}
/*----------------------------------------------------------------------------------------------------------*/
void Servos_90_30_Lento(void){
        Servo_Uno_0();        Servo_Dos_0();
        Servo_Uno_15();      Servo_Dos_15();
        Servo_Uno_30();      Servo_Dos_30();
        Servo_Uno_15();      Servo_Dos_15();
        Servo_Uno_0();        Servo_Dos_0();
}
/*----------------------------------------------------------------------------------------------------------*/
void Servos_90_60_Lento(void){
        Servo_Uno_0();        Servo_Dos_0();
        Servo_Uno_15();      Servo_Dos_15();
        Servo_Uno_30();      Servo_Dos_30();
        Servo_Uno_45();      Servo_Dos_45();
        Servo_Uno_60();      Servo_Dos_60();
        Servo_Uno_45();      Servo_Dos_45();
        Servo_Uno_30();      Servo_Dos_30();
        Servo_Uno_15();      Servo_Dos_15();
        Servo_Uno_0();        Servo_Dos_0();
}
/*----------------------------------------------------------------------------------------------------------*/
void Servos_90_90_Lento(void){
        Servo_Uno_0();        Servo_Dos_0();
        Servo_Uno_15();      Servo_Dos_15();
        Servo_Uno_30();      Servo_Dos_30();
        Servo_Uno_45();      Servo_Dos_45();
        Servo_Uno_60();      Servo_Dos_60();
        Servo_Uno_75();      Servo_Dos_75();
        Servo_Uno_90();      Servo_Dos_90();
        Servo_Uno_75();      Servo_Dos_75();
        Servo_Uno_60();      Servo_Dos_60();
        Servo_Uno_45();      Servo_Dos_45();
        Servo_Uno_30();      Servo_Dos_30();
        Servo_Uno_15();      Servo_Dos_15();
        Servo_Uno_0();        Servo_Dos_0();
}
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/