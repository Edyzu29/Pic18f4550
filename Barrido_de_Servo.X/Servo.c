#include <xc.h>
#include <stdint.h>
#include "Servo.h"

//Declarion de variables
  int i;

//Funciones
void Confi_Servo(void){    
    Servo_Luz_Tris=0;
};
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
 void Grados_0 (void){
             for(int i=0;i<16;i++){
            Servo_Luz=0;
            Servo_Luz=1;
            __delay_ms(g0);
            Servo_Luz=0;
            __delay_ms(20-g0);}
    }
 
 void Grados_15 (void){
             for(int i=0;i<16;i++){
            Servo_Luz=0;
            Servo_Luz=1;
            __delay_ms(g15);
            Servo_Luz=0;
            __delay_ms(20-g15);}
    }
 
 void Grados_30 (void){
             for(int i=0;i<16;i++){
            Servo_Luz=0;
            Servo_Luz=1;
            __delay_ms(g30);
            Servo_Luz=0;
            __delay_ms(20-g30);}
    }
 
 void Grados_45 (void){
             for(int i=0;i<16;i++){
            Servo_Luz=0;
            Servo_Luz=1;
            __delay_ms(g45);
            Servo_Luz=0;
            __delay_ms(20-g45);}
    }

void Grados_60 (void){
             for(int i=0;i<16;i++){
            Servo_Luz=0;
            Servo_Luz=1;
            __delay_ms(g60);
            Servo_Luz=0;
            __delay_ms(20-g60);}
    }

void Grados_75 (void){
    for(int i=0;i<16;i++){
            Servo_Luz=0;
            Servo_Luz=1;
            __delay_ms(g75);
            Servo_Luz=0;
            __delay_ms(20-g75);} 
    
}

void Grados_90 (void){
             for(int i=0;i<16;i++){
            Servo_Luz=0;
            Servo_Luz=1;
            __delay_ms(g90);
            Servo_Luz=0;
            __delay_ms(20-g90);}
    }

void Grados_105 (void){
             for(int i=0;i<16;i++){
            Servo_Luz=0;
            Servo_Luz=1;
            __delay_ms(g105);
            Servo_Luz=0;
            __delay_ms(20-g105);}
    }
 
 void Grados_120 (void){
             for(int i=0;i<16;i++){
            Servo_Luz=0;
            Servo_Luz=1;
            __delay_ms(g120);
            Servo_Luz=0;
            __delay_ms(20-g120);}
    }

void Grados_135 (void){
             for(int i=0;i<16;i++){
            Servo_Luz=0;
            Servo_Luz=1;
            __delay_ms(g135);
            Servo_Luz=0;
            __delay_ms(20-g135);}
    }

void Grados_150 (void){
    for(int i=0;i<16;i++){
            Servo_Luz=0;
            Servo_Luz=1;
            __delay_ms(g150);
            Servo_Luz=0;
            __delay_ms(20-g150);} 
    
}

void Grados_165 (void){
    for(int i=0;i<16;i++){
            Servo_Luz=0;
            Servo_Luz=1;
            __delay_ms(g165);
            Servo_Luz=0;
            __delay_ms(20-g165);} 
    
}

void Grados_180 (void){
    for(int i=0;i<16;i++){
            Servo_Luz=0;
            Servo_Luz=1;
            __delay_ms(g180);
            Servo_Luz=0;
            __delay_ms(20-g180);} 
    
}