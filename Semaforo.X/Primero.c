
// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>
#include <stdint.h>
#include <pic18f4550.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG1L
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = INTOSCIO_EC// Oscillator Selection bits (Internal oscillator, port function on RA6, EC used by USB (INTIO))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = ON        // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOR = ON         // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = OFF      // MCLR Pin Enable bit (RE3 input pin enabled; MCLR pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)

#define _XTAL_FREQ 4000000UL
                                    

                                            /*Variables y Arreglos */  

    int     u,              //Variable de Unidades
            d,              //Variable de Decenas
            R[]={20,30,30},         //Luz Roja         (Sensor=0) ||  Luz Roja         (Sensor=1) || Luz Roja         (Interrucion)
            r0=20,       //Luz Roja         (Sensor=0)
            r1=30,       //Luz Roja         (Sensor=1)
            r2=30,       //Luz Roja         (Interrucion)
            A[]={3,8},                  //Luz Ambar      (Sensor=0) ||  Luz Roja         (Consideracion)
            y=3,          //Luz Ambar      (Sensor=0)
            j=8,           //Luz Roja         (Consideracion)
            V[]={30,66,66},          //Luz Verde       (Sensor=0) ||  Luz Verde       (Sensor=1) ||   Luz Verde       (Interrucion)
            v0=30,       //Luz Verde       (Sensor=0)
            v1=66,       //Luz Verde       (Sensor=1)
            v2=66,        //Luz Verde       (Interrucion)
            i
            ;
    int sensor1;

    
    void main ( void )
{                                                           /*Registros Especiales*/
    
     OSCCONbits.IRCF=0b110;
     TRISD=0x00;
     TRISC=0;
     TRISBbits.RB1=1;
     LATD=0x00;
     LATC=0x00;
     INTCON=0b10010000;
     INTCON2bits.INTEDG0=1;
     ADCON1bits.PCFG=0b1111;

                                                                    /*Programa*/    
    
    while (1){
        
        sensor1=(PORTBbits.RB1);
        
        if (sensor1==0){
                LATC=0;
                LATC0=1;                                // Verde
                LATC7=1;
                        for( i=V[0];i>0;i--){
                                    d= i / 10;
                                    u = i-(d*10);
                                    d=d<<4;
                                    LATD= d+u;
                                    __delay_ms(500);}
               
                LATC=0;
                LATC1=1;                               // Ambar
                LATC7=1;
                        for( i=A[0];i>0;i--){
                                    d= i / 10;
                                    u = i-(d*10);
                                    d=d<<4;
                                    LATD= d+u;
                                    __delay_ms(500);}
                
                LATC=0;
                LATC2=1;                               //Roja
                LATC6=1;
                        for( i=R[0];i>0;i--){
                                    d= i / 10;
                                    u = i-(d*10);
                                    d=d<<4;
                                    LATD= d+u;
                                    __delay_ms(500);}
        }
    
        else if (sensor1==1){
                    LATC=0;
                LATC0=1;                                // Verde
                LATC7=1;
                        for( i=V[1];i>0;i--){
                                    d= i / 10;
                                    u = i-(d*10);
                                    d=d<<4;
                                    LATD= d+u;
                                    __delay_ms(500);}
               
                LATC=0;
                LATC1=1;                               // Ambar
                LATC7=1;
                        for( i=A[0];i>0;i--){
                                    d= i / 10;
                                    u = i-(d*10);
                                    d=d<<4;
                                    LATD= d+u;
                                    __delay_ms(500);}
                
                LATC=0;
                LATC2=1;                               //Roja
                LATC6=1;
                        for( i=R[1];i>0;i--){
                                    d= i / 10;
                                    u = i-(d*10);
                                    d=d<<4;
                                    LATD= d+u;
                                    __delay_ms(500);}
        }
    }
 }

void __interrupt(high_priority) hbdsahbas (void){
	
   if ( INTCONbits.INT0IF==1){
       
                if ( PORTCbits.RC2==1){
                    
                   LATC=0;
                LATC2=1;                               //Roja
                LATC6=1;
                        for( i=A[1];i>0;i--){
                                    d= i / 10;
                                    u = i-(d*10);
                                    d=d<<4;
                                    LATD= d+u;
                                    __delay_ms(500);}

                   LATC=0;
                LATC0=1;                                // Verde
                LATC7=1;
                        for( i=V[2];i>0;i--){
                                    d= i / 10;
                                    u = i-(d*10);
                                    d=d<<4;
                                    LATD= d+u;
                                    __delay_ms(500);}
               
                LATC=0;
                LATC1=1;                               // Ambar
                LATC7=1;
                        for( i=A[1];i>0;i--){
                                    d= i / 10;
                                    u = i-(d*10);
                                    d=d<<4;
                                    LATD= d+u;
                                    __delay_ms(500);}
                
                LATC=0;
                LATC2=1;                               //Roja
                LATC6=1;
                        for( i=R[2];i>0;i--){
                                    d= i / 10;
                                    u = i-(d*10);
                                    d=d<<4;
                                    LATD= d+u;
                                    __delay_ms(500);}
                }

                
                else{               
                    
                       LATC=0;
                LATC0=1;                                // Verde
                LATC7=1;
                        for( i=V[2];i>0;i--){
                                    d= i / 10;
                                    u = i-(d*10);
                                    d=d<<4;
                                    LATD= d+u;
                                    __delay_ms(500);}
               
                LATC=0;
                LATC1=1;                               // Ambar
                LATC7=1;
                        for( i=A[1];i>0;i--){
                                    d= i / 10;
                                    u = i-(d*10);
                                    d=d<<4;
                                    LATD= d+u;
                                    __delay_ms(500);}
                
                LATC=0;
                LATC2=1;                               //Roja
                LATC6=1;
                        for( i=R[2];i>0;i--){
                                    d= i / 10;
                                    u = i-(d*10);
                                    d=d<<4;
                                    LATD= d+u;
                                    __delay_ms(500);}
                         }
                INTCONbits.INT0IF=0;  
        }
}

