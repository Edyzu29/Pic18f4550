// PIC18F4550 Configuration Bit Settings
// 'C' source line config statements
#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "Confi.h"
#include "MiLCD.h"



void Inicializacion(void){
    //Modulos
    OSCCONbits.IRCF = 0b111;
    
    //Puertos
    Tris_Principal=1; 
    
    //LIBRERIAS
    LCD_Inicializa();

    //PRESENTACION
}


