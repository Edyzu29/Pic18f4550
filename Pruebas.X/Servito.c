#include <xc.h>
#include <stdint.h>
#include "Servito.h"

#define _XTAL_FREQ 8000000UL
//Declarion de variables
  int i;

//Funciones
void Confi_Servo(void){
    Servo_Diez_Tris=0;
    Servo_Veinte_Tris=0;
    Servo_Cincuenta_Tris=0;
    Servo_Sol_Tris=0;
    Servo_Dos_Tris=0;
    Servo_Cinco_Tris=0;
    
    Servo_Fake_Tris=0;
};
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Giro_Servo(char selec,int SelecDeServo){
    switch(selec){
        case '0':
            for(int i=0;i<16;i++){
            SelecDeServo=0;
            SelecDeServo=1;
            __delay_ms(g0);
            SelecDeServo=0;
            __delay_ms(20-g0);}
            break;
        case '90':
            for(int i=0;i<16;i++){
            SelecDeServo=0;
            SelecDeServo=1;
            __delay_ms(g90);
            SelecDeServo=0;
            __delay_ms(20-g90);}
            break;
        case '180':
            for(int i=0;i<16;i++){
            SelecDeServo=0;
            SelecDeServo=1;
            __delay_ms(g180);
            SelecDeServo=0;
            __delay_ms(20-g180);}
            break;            
    }
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Servo_Posicion_Inicial (void){
    Giro_Servo('0',Servo_Fake);
    Giro_Servo('0',Servo_Diez);
    Giro_Servo('0',Servo_Veinte);
    Giro_Servo('0',Servo_Cincuenta);
    Giro_Servo('0',Servo_Sol);
    Giro_Servo('0',Servo_Dos);
    Giro_Servo('0',Servo_Cinco);
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Dam_Dinero (uint8_t Numero_de_monedas,uint8_t Que_Servo){
    uint8_t i;
    for(i=0;i<Numero_de_monedas;i++){
        Giro_Servo('90',Que_Servo);
        Giro_Servo('0',Que_Servo);        
    }
}



