
// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = HS // Oscillator Selection bits (Internal oscillator, CLKO function on RA6, EC used by USB (INTCKO))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

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


#include <xc.h>
#include <stdint.h>
#include "Adc.h"
#include "Laser1.h"
#include "BLUE.h"
#include "Servito.h"


#define Umbral   10  

#define N_MUESTRAS 50
#define Tiempo_de_muestreo 80


volatile uint8_t bandera_detectar_cambio = 1;
volatile uint8_t bandera_leer_adc = 0;
volatile uint8_t bandera_leer_moneda = 0;
volatile uint8_t bandera_imprimir_muestras = 0;


volatile uint16_t willi[N_MUESTRAS];
volatile uint16_t points[3];
volatile uint16_t valor_adc;

uint8_t Detecta_Cambio(void);
void Leer_Moneda(void);

void main (void){

    TRISDbits.RD0=0;
    TRISDbits.RD1=0;
    TRISAbits.RA1=1;
    
    Confi_TMR0();
    ConfigADC();
    Confi_Blue();
        
    int i;
    static int a;
    
    TMR0_Start=1;
    LATDbits.LATD0=1;
    
    UART0_Tx_String("Hola yisus \r\n");
    UART0_Tx_String("A=[");
    
    while(1){      
        if(bandera_leer_adc == 1){
            
            valor_adc = LecturaADC();
            
            if(bandera_detectar_cambio == 1){
                bandera_leer_moneda = Detecta_Cambio();
                bandera_detectar_cambio = !bandera_leer_moneda;
                willi[0] = points[0];
                willi[1] = points[1];
                willi[2] = points[2];
            }
             
            if(bandera_leer_moneda == 1){
                
                Leer_Moneda();
                a=Detecta_Cambio();             
            }
            
        }        
        
        if(bandera_imprimir_muestras == 1){
            //UART0_Tx_String("A=[");
            for(i=0;i<N_MUESTRAS;i++){ 
                UART0_Tx_Integer(willi[i]);
                if(i<N_MUESTRAS/*-1*/)UART0_Tx_String(",");
            }
            //UART0_Tx_String("]; \n\r");
            
            bandera_imprimir_muestras = 0;
            bandera_detectar_cambio = 1;
        }
        
//        if(bandera_leer_adc == 1){
//            valor_adc = LecturaADC(0);
//             UART0_Tx_Integer(valor_adc);
//             UART0_Tx_String(",");
//        }
    }
}


uint8_t Detecta_Cambio(void){
        
    int16_t diferencia1;
    int16_t diferencia2;
    
    uint8_t salida;
            
    points[0]=points[1];
    points[1]=points[2];
    points[2]=valor_adc;
    
    
    diferencia1 = (int16_t)points[1] - (int16_t)points[2];
    diferencia2 = (int16_t)points[0] - (int16_t)points[1];
    
    if (((diferencia1>Umbral)||(diferencia1<-Umbral))&&((diferencia2>Umbral)||(diferencia2<-Umbral))){
        salida = 1;
    }else{
        salida = 0;
    }
   
    return salida;
}

void Leer_Moneda(void){
    
    static uint8_t i = 3;
    
    //valor_adc = LecturaADC();
    willi[i]= valor_adc;
   
   i++;
   
   if(i >= N_MUESTRAS){
       i = 3;
       
       bandera_leer_moneda = 0;
       bandera_imprimir_muestras = 1;

   }
         
   
}


/* Cada 100 ms*/
void __interrupt(high_priority) Timer0_ISR(void){
    
    static uint16_t conta_1ms = 0;
   
    if(TMR0_Flag==1){
        LATDbits.LATD0=1;
        TMR0_Reset();        
        conta_1ms++;
        if(conta_1ms == Tiempo_de_muestreo){
            conta_1ms=0;
            ADCON0bits.GO = 1;
            
        }
        LATDbits.LATD0=0;
    }
    
    
}


void __interrupt(low_priority) ADC_ISR(void){
    if(PIR1bits.ADIF==1){
        LATDbits.LATD1=1;
        bandera_leer_adc = 1;
        PIR1bits.ADIF=0;
        LATDbits.LATD1=0;
    }  
}


