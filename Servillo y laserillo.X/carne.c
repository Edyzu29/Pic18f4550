
// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = HS        // Oscillator Selection bits (Internal oscillator, CLKO function on RA6, EC used by USB (INTCKO))
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
#pragma config STVREN = OFF     // Stack Full/Underflow Reset Enable bit (Stack full/underflow will not cause Reset)
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

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h> 
#include <stdint.h>
#include "Ser.h"
#include "usa.h"

#define Led_Tris        TRISDbits.RD0
#define Led_Pausa       LATDbits.LATD0

#define Laser_Tris      TRISDbits.RD1
#define Laser_Pin       PORTDbits.RD1

#define TMR1_Switch    PIE1bits.TMR1IE
#define TMR1_Flag      PIR1bits.TMR1IF
#define TMR1_Start     T1CONbits.TMR1ON
#define Offset_TMR1        64911

#define _XTAL_FREQ 20000000

#define Soles_5     69
#define Error_Laser 6

/*Calibracion para la lectura de la curva*/
#define Umbral  420
#define N_MUESTRAS 80
#define Tiempo_entre_Muestras  5
/*----------------------------------------------------------------------------*/
/*Valores de la interaccion del campo magnetico con las monedas*/
#define Valor_bobina_sol        123
#define Valor_bobina_veinte     144
#define Valor_bobina_cincuenta  158
#define Valor_bobina_diez       174
#define Valor_bobina_dos        187
#define Valor_bobina_cinco      200
/*----------------------------------------------------------------------------*/
/*Valores de la interaccion del campo magnetico con las monedas*/
#define Valor_laser_sol        
#define Valor_laser_veinte     
#define Valor_laser_cincuenta  
#define Valor_laser_diez       
#define Valor_laser_dos        
#define Valor_laser_cinco      
/*----------------------------------------------------------------------------*/
/*Errores*/
#define Laser_Error             6
#define Bobina_Error            8
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*Funciones del laser*/
uint8_t Interrupcion_Laser (void);
/*----------------------------------------------------------------------------*/
/*Variables*/
/*----------------------------------------------------------------------------*/

uint8_t Espera_Campo=1;
uint16_t Punto_minimo=1023;
char    Moneda;
uint16_t Coin_Field=0;     //Distorcion
uint8_t Diametro=0;      //diametro
/*Acumuladores y Contadores*/
volatile uint16_t conta_100us=0;
uint16_t i = 0;
volatile uint8_t Bandera_de_Lectura=0;

volatile uint8_t bandera_de_mensaje=0;

uint8_t Moneda;
uint8_t Num_Moneda;


void Confi_TMR1(void){
    INTCONbits.GIE=1;     //Acticar las Interrupciones

    TMR1H=((Offset_TMR1)>>8)&0xff;           //Setear al TMR0 para que 
    TMR1L=(Offset_TMR1)&0xff;
    
    T1CONbits.RD16=0; 
    /* 1 -->  8bits  
     * 0 --> 16bits
    */
    T1CONbits.TMR1CS=0;     //Elejir el Oscilador(Externo)
    /* 1 --> Transcion externa  
     * 0 --> Transcion interna
    */
    T1CONbits.T1CKPS=0b011; //Pre-escalador de 16
    /* 11 = 1:8 Prescale value
     * 10 = 1:4 Prescale value
     * 01 = 1:2 Prescale value
     * 00 = 1:1 Prescale value
     */
    
    TMR1_Start=0;
    TMR1_Flag = 0;
    TMR1_Switch=1;
}

void TMR1_Reset(void){
    TMR1H=((Offset_TMR1)>>8)&0xff;           //Setear al TMR0 para que 
    TMR1L=(Offset_TMR1)&0xff;
    TMR1_Flag=0;
    
}

uint8_t Detecta_Cambio(uint16_t varible){
 uint8_t Caida;
    if(varible<Umbral)  Caida=1; 
    else    Caida=0;
   
    return Caida;
}

void main (void){
    uint32_t Coin_Size=0;
    Confi_Blue();
    Confi_Servo();
    Confi_TMR1();
    
    ADCON1bits.PCFG=0xff;
    
    Laser_Tris=1;
    Led_Tris=0;
    
   TRISDbits.RD7 = 0;
    OSCCONbits.IRCF=0b111;
  
    while(1){
        Diametro=Interrupcion_Laser();
        Espera_Campo=1;
        while(Espera_Campo){
            if(Bandera_de_Lectura){
                Bandera_de_Lectura=0;
                caida=Detecta_Cambio(LecturaADC());
                if(caida){
                    Espera_Campo=0;
                    for(i=0;i<N_MUESTRAS;i++){
                        while(Bandera_de_Lectura==0);
                        Bandera_de_Lectura=0;
                        Curva[i]=LecturaADC();
                    }
                    for(i=0;i<N_MUESTRAS;i++)
                        if(Curva[i]<Punto_minimo)Punto_minimo=Curva[i];   
                }
            }    
        }
        if(Comprobar_Sol(Punto_minimo,Diametro)==1) Moneda="Sol";
    }
}



void __interrupt() Timer(void){
    if(TMR0_Flag==1){
        TMR0_Reset();
        conta_100us++; 
    }
    if(conta_100us==Tiempo_entre_Muestras){
        conta_100us=0;
        Inicio_Adc = 1;
    }
}

void __interrupt(low_priority) Adc(void){
    if(Adc_Flag==1){
        PIR1bits.ADIF=0;
        Bandera_de_Lectura=1;
    }
}

//        if(bandera_de_mensaje==1){
//            Dam_Dinero(Num_Moneda,Moneda);
//        }

//        Servo_Fake_0();
//        Servo_Fake_90();
//        for(int i=0;i<16;i++){
//            Servo_Fake=0;
//            Servo_Fake=1;
//            __delay_ms(g0);
//            Servo_Fake=0;
//            __delay_ms(20-g0);}
//        while(Laser_Pin==0)Coin_Size=0;
//        Led_Pausa=1;
//        while(Laser_Pin==1){
//            TMR1_Start=1;
//            TMR1_Switch=1;
//            if((TMR1_Flag==1)&(TMR1_Switch==1)){
//                Coin_Size++;
//                TMR1_Reset();
//            }
//        }
//        TMR1_Switch=0;
//        Led_Pausa=0;
//        TMR1_Start=0;
//        TMR1_Reset();
//        UART0_Tx_Integer(Coin_Size);
//        UART0_Tx_String("\r\n");
//        
//        Coin_Size=0;
    