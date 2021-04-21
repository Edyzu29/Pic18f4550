#include "Confi.h"
#include <xc.h>
#include <stdint.h>
#include "PWM.h"

void Confi_PWM(void){
    PWM_RC2_Tris=0;
    TMR2_Start=0;
    
//XXXXXXXXXXXXXXXXX Elejir que modo Usar XXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    CCP1CONbits.CCP1M=0b1100;
    /*
    0000 = Capture/Compare/PWM disabled (resets CCPx module)
    0001 = Reserved
    0010 = Compare mode: toggle output on match (CCPxIF bit is set)
    0011 = Reserved
     
    0100 = Capture mode: every falling edge
    0101 = Capture mode: every rising edge
    0110 = Capture mode: every 4th rising edge
    0111 = Capture mode: every 16th rising edge
     
    1000 = Compare mode: initialize CCPx pin low; on compare match, force CCPx pin high (CCPxIF bit is set)
    1001 = Compare mode: initialize CCPx pin high; on compare match, force CCPx pin low (CCPxIF bitis set)
    1010 = Compare mode: generate software interrupt on compare match (CCPxIF bit is set, CCPx pin reflects I/O state)
    1011 = Compare mode: trigger special event, reset timer, start A/D conversion on CCPx match  (CCPxIF bit is set)
    
    11xx = PWM mode
    */
    
//XXXXXXXXXXXXXXXX Configurar TMR2 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    
    T2CONbits.TOUTPS=0b0000; 
    /*
    0000 = 1:1 Postscale
    0001 = 1:2 Postscale
    1111 = 1:16 Postscale
     */
    T2CONbits.T2CKPS=0b00; 
    /*
    00 = Prescaler is 1
    01 = Prescaler is 4
    1x = Prescaler is 16
     */
    
//XXXXXXXXXXXXX Inicializacion de los valores XXXXXXXXXXXXXXXXXXXXXXXXX
    
    PR2=Periodo_PWM;
    CCPR1L= 0xff & (Duty_cycle);
    CCPR1H= 0xff & (8>>Duty_cycle);
    TMR2_Start=1;
}

void Duty_Cycle_Change(uint16_t Change_Duty){
    CCPR1L= 0xff & (Change_Duty);
    CCPR1H= 0xff & (8>>Change_Duty);
}

void Periodo_change(uint8_t Change_Periodo){
    PR2=Change_Periodo;
}