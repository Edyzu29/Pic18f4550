
 #include <xc.h>
#include <stdint.h>
#include "TMRs.h"

//Funciones

void Confi_TMR0(void){
    INTCONbits.GIE=1;     //Acticar las Interrupciones
    RCONbits.IPEN=1;
    INTCONbits.PEIE=1;
    
    TMR0_Start= 0;
    TMR0_Flag = 0;
    TMR0_Switch=1;
    INTCON2bits.T0IP=1;
    INTCON2bits.INTEDG0=0;
    
    
    TMR0H=((Offset_TMR0)>>8)&0xff;           //Setear al TMR0 para que 
    TMR0L=(Offset_TMR0)&0xff;
    
    T0CONbits.T08BIT=0; 
    /* 1 -->  8bits  
     * 0 --> 16bits
    */
    T0CONbits.PSA=1;      //Activar el Pre-escalador
    /* 1 --> Desactivar Pre-Escaler
     * 0 --> Activar Pre-Escaler 
    */
    T0CONbits.T0CS=0;     //Elejir el Oscilador(Interno)
    /* 1 --> Transcion externa  
     * 0 --> Transcion interna
    */
    T0CONbits.T0SE=0;     //flaco de subida
    /* 1 --> Flanco de bajada 
     * 0 --> Flanco de subida
    */
    T0CONbits.T0PS=0b001; //Pre-escalador de 16
    /* 111 = 1:256 Prescale value
     * 110 = 1:128 Prescale value
     * 101 = 1:64 Prescale value
     * 100 = 1:32 Prescale value
     * 011 = 1:16 Prescale value
     * 010 = 1:8 Prescale value
     * 001 = 1:4 Prescale value
     * 000 = 1:2 Prescale value
     */
}
void TMR0_Reset(void){
    TMR0H=((Offset_TMR0)>>8)&0xff;           //Setear al TMR0 para que 
    TMR0L=(Offset_TMR0)&0xff;
    TMR0_Flag = 0;
}
void Confi_TMR1(void){
    INTCONbits.GIE=1;     //Acticar las Interrupciones
    
    TMR1_Start=0;
    TMR1_Flag = 0;
    TMR1_Switch=1;

    TMR1H=((Offset_TMR1)>>8)&0xff;           //Setear al TMR0 para que 
    TMR1L=(Offset_TMR1)&0xff;
    
    T1CONbits.RD16=1; 
    /* 1 -->  8bits  
     * 0 --> 16bits
    */
    T1CONbits.TMR1CS=0;     //Elejir el Oscilador(Externo)
    /* 1 --> Transcion externa  
     * 0 --> Transcion interna
    */
    T1CONbits.T1CKPS=0b001; //Pre-escalador de 16
    /* 11 = 1:8 Prescale value
     * 10 = 1:4 Prescale value
     * 01 = 1:2 Prescale value
     * 00 = 1:1 Prescale value
     */
}
void TMR1_Reset(void){
    TMR1H=((Offset_TMR1)>>8)&0xff;           //Setear al TMR0 para que 
    TMR1L=(Offset_TMR1)&0xff;
    TMR1_Flag=0;
}