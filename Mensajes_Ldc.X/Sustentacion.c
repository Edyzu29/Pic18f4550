#include "Confi.h"
#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "MiLCD.h"

//VARIABLES
uint8_t Contador=0;
uint16_t i, j;          // Acumuladores
char Msj1[]={"VAMOS WELS"};
char Msj2[]={"En Wels Theory"};
char Msj3[]={"La Tesis!!!"};
char Msj4[]={"Machuca Cuida"};
char Msj5[]={"Tu Mundo CTM"};
char Msj6[]={"Franzua 2x1sol?"};

//CONSTANTES
#define Deley 350
#define Delay 200

//FUNCIONES

void main (void){
    Inicializacion();
    INTCONbits.GIE=1;
    INTCONbits.INT0E=1;
    INTCONbits.INT0F=0;
    while(1){
        switch(Contador){            
            case 0:
                LCD_Borra();
                for(i=0;i<16;i++){
                    LCD_PosicionLinea1(0);
                    LCD_EnviaCadena("                      ");
                    LCD_PosicionLinea1(i);
                    LCD_EnviaCadena(Msj1);
                    __delay_ms(Deley);
                }
            break;
            
            case 1:
                LCD_Borra();
                for(i=0;i<16;i++){
                    LCD_PosicionLinea1(0);
                    LCD_EnviaCadena("                      ");
                    LCD_PosicionLinea1(i);
                    LCD_EnviaCadena(Msj2);
                    __delay_ms(Deley);
                    LCD_PosicionLinea2(0);
                    LCD_EnviaCadena("                      ");
                    LCD_PosicionLinea2(i);
                    LCD_EnviaCadena(Msj3);
                    __delay_ms(Deley);
                }
            break;
            
            case 2:
                LCD_Borra();
                for(i=0;i<16;i++){
                    LCD_PosicionLinea1(0);
                    LCD_EnviaCadena("                      ");
                    LCD_PosicionLinea1(i);
                    LCD_EnviaCadena(Msj4);
                    __delay_ms(Delay);
                    LCD_PosicionLinea2(0);
                    LCD_EnviaCadena("                      ");
                    LCD_PosicionLinea2(i);
                    LCD_EnviaCadena(Msj5);
                    __delay_ms(Delay);
                }
            break;
            
            case 3:
                LCD_Borra();
                for(i=0;i<16;i++){
                    LCD_PosicionLinea1(0);
                    LCD_EnviaCadena("                      ");
                    LCD_PosicionLinea1(i);
                    LCD_EnviaCadena(Msj6);
                    __delay_ms(Deley);
                }
            break;
        }
    }
}

void __interrupt(high_priority) Wels(void){
    if(INTCONbits.INT0F==1) {
        Contador++;
        INTCONbits.INT0F=0;
    }
    else if (Contador==4) Contador=0;
}