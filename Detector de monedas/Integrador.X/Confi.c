#include "Confi.h"
#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "MiADC.h"
#include "Servo.h"
#include "Usart.h"
#include "Valores_de_la_modeda.h"
#include "TMRs.h"

void Inicializacion(void){
    //LIBRERIAS
    Led_Tris=0;
    Led_Pausa=0;
    ConfigADC();
    Confi_Servo();
    Confi_Blue();
    Confi_TMR0();
    Confi_TMR1();
    Servo_Posicion_Inicial();             
}