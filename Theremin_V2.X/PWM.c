#include <xc.h>
#include <stdio.h>
#include <stdint.h>


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
                    //CONSTANTE DE DELAY//
    #define _XTAL_FREQ 4000000UL
                    //DESIGNACION DE PINES//
    #define Triger1      PORTAbits.RA0
    #define Eco1         PORTBbits.RB0
    #define Triger2      PORTAbits.RA1
    #define Eco2         PORTBbits.RB1
                    //VARIABLES AUXILIARES//
    float Lon;                                      //Distancia
    int a;                                          //Auxiliar
                    //VARIABLES DE FRECUENCIAS//
//    uint16_t frec1[]={10,10,10,10};                 
//    uint16_t frec2[]={30,30,30,30};                 
//    uint16_t frec3[]={50,50,50,50};                 
//    uint16_t frec4[]={70,70,70,70};                 
//    uint16_t frec5[]={90,90,90,90};
    uint16_t frec1[]={10,10,10,10};                 
    uint16_t frec2[]={11,11,11,11};                 
    uint16_t frec3[]={12,12,12,12};                 
    uint16_t frec4[]={13,13,13,13};                 
    uint16_t frec5[]={14,14,14,14};   
                    //CONSTANTES DE VOLUMEN//
    #define vol1 42
    #define vol2 52
    #define vol3 62                                 
    #define vol4 72                                 
    #define vol5 82                                 

void CoPuer (void){
    TRISBbits.RB0 = 1;                              // Configurar el Eco1 como entrada
    TRISAbits.RA0 = 0;                              // Configurar el Triger1 como salida
    TRISBbits.RB1 = 1;                              // Configurar el Eco2 como entrada
    TRISAbits.RA1 = 0;                              // Configurar el Triger2 como salida
    TRISCbits.RC2 = 0;                              // Configurar la salida del PWM
    TRISD=0x00;
}                    // Configuracion de los Puertos

void CoRe (void){
    OSCCONbits.IRCF=0b110;                          //oscilador 4MHz
    ADCON1bits.PCFG=0b1111;                         // Poner todos en Digital
}                      // Configuracion de los Registros

void PWM (void) {                                   // configurar el PWM en la primera pata 
    T2CONbits.T2CKPS=0b11;                          // Preescaler de 16
    INTCON2bits.RBPU=0;
    CCP1CONbits.CCP1M=0b1100;                       // Modo PWM
}                      // Configuracion para el PWM

void CallofDuty (uint16_t duty){  
    uint8_t j;
    j= duty & (0b11);              
    CCP1CONbits.DC1B=j;
    j=(duty>>2);
    CCPR1L=j;
}       // Configuracion Duty Cicle

void Tono (uint16_t a[],uint8_t num){
        for (int i=0;i<=num;i++){
            CallofDuty(a[i]);
            __delay_ms(25);
           }
}  // Tocar sonidos

void CoTMRs (void){
    TMR2=0;                                         // Dato inicializador para el PWM
    T1CON=0b10000000;                               // Configuracion para el TMR1
}                    // Confiracion de TMR1 y TMR2

void main (void){
            CoPuer();                               // Configurar Puertos
            CoTMRs();                               // Configurar Timers
            CoRe();                                 // Configurar Registros Especiales
            PWM();                                  // Configurar PWM
            T2CONbits.TMR2ON=1;                     // Iniciar el PWM
  
     while (1){           
 //XXXXXXXXXXXXXXXXXXXXXXXXXX      VOLUMEN           XXXXXXXXXXXXXXXXXXXXXXXXX//                         
            
            Triger2 = 0; __delay_us(10);            // Inicio del puslo de disparo
            Triger2 = 1; __delay_us(10);
            Triger2 = 0;                            // Final del puslo de disparo
            
            while(Eco2 == 0); TMR1 = 0;             // inicializar TMR1
            T1CONbits.TMR1ON=1;                    // Iniciar el conteo de Distancia
            
            while(Eco2 == 1 ); a = TMR1;            // Finalizar TMR1
            T1CONbits.TMR1ON = 0;                   // Finalizar el conteo de Distancia
            
            Lon=1.0*(a)/(58);                       // Distancia del leída
             
            if ((Lon<35)&&(Lon>=28))PR2=vol1;
            if ((Lon<28)&&(Lon>=21))PR2=vol2;
            if ((Lon<21)&&(Lon>=14))PR2=vol3;
            if ((Lon<14)&&(Lon>=07))PR2=vol4;
            if ((Lon<07)&&(Lon>=00))PR2=vol5;               
//XXXXXXXXXXXXXXXXXXXXXXXXXX      FRECUENCIA           XXXXXXXXXXXXXXXXXXXXXXXXX//                         
           
            Triger1 = 0; __delay_us(10);            // Inicio del puslo de disparo
            Triger1 = 1; __delay_us(10);
            Triger1 = 0;                            // Final del puslo de disparo
            
            while(Eco1 == 0); TMR1 = 0;             // inicializar TMR1
            T1CONbits.TMR1ON=1;                    // Iniciar el conteo de Distancia
            
            while(Eco1 == 1 ); a = TMR1;            // Finalizar TMR1
            T1CONbits.TMR1ON = 0;                   // Finalizar el conteo de Distancia
            
            Lon=1.0*(a)/(58);                       // Distancia del leída
             
            if ((Lon<35)&&(Lon>=28)){RD4=1; Tono(frec1,4);}
            if ((Lon<28)&&(Lon>=21)){RD3=1; Tono(frec2,4);}
            if ((Lon<21)&&(Lon>=14)){RD2=1; Tono(frec3,4);}
            if ((Lon<14)&&(Lon>=07)){RD1=1; Tono(frec4,4);}
            if ((Lon<07)&&(Lon>=00)){RD0=1; Tono(frec5,4);}
            LATD=0x00;
       }
}