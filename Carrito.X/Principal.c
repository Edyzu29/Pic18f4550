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
#pragma config MCLRE = ON      // MCLR Pin Enable bit (RE3 input pin enabled; MCLR pin disabled)

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
#include <stdio.h>
#include "MiLCD.h"
/*---------------------------------Constantes-------------------------------------------*/
#define _XTAL_FREQ 8000000UL
/*------------------------------Pines Importantes---------------------------------------*/
#define Int1_izquierda  PORTDbits.RD3
#define Int2_izquierda  PORTDbits.RD2
#define Int3_derecha    PORTDbits.RD1
#define Int4_derecha    PORTDbits.RD0
/*---------------------------------Variables-------------------------------------------*/
int datos[25]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
int direccion[25]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
char Msj;
int winnie[4];
/*---------------------------------Funciones------------------------------------------*/
void Inicializacion (void){
        LCD_Inicializa();
}       //Inicializa todo
void Movimiento (uint8_t way){
    switch(way){
        case 0:
            Int4_derecha=0;
            Int3_derecha=1;
            Int2_izquierda=0;   
            Int1_izquierda=1;
        break;  
                   
        case 1:
            Int4_derecha=0;
            Int3_derecha=1;
            Int2_izquierda=1;   
            Int1_izquierda=0;
        break;
                
        case 2:
            Int4_derecha=1;
            Int3_derecha=0;
            Int2_izquierda=0;   
            Int1_izquierda=1;
        break;
        
        case 3:
            Int4_derecha=1;
            Int3_derecha=0;
            Int2_izquierda=1;   
            Int1_izquierda=0;
        break;
        
        case 4:
            Int4_derecha=1;
            Int3_derecha=1;
            Int2_izquierda=1;   
            Int1_izquierda=1;  
    }
}   //Esta función activa las ruedas
void Tx(char data){
    TXREG = data;                               
}               //Esta función envia datos
char Rx(void){
    return RCREG; 
}                    //Esta función recibe datos
void Save_data1 (int mario){
    int b=0x00;
    int yolo=0x00;
    switch(mario){
        case 1:
            yolo=0x00;
            break;
        case 2:
            yolo=0x32;
            break;
        case 3:
            yolo=0x64;
            break;
        case 4:
            yolo=0x96;
            break;
    }
    for(b;b<=0x18;b++){
        EEADR=b+yolo;                          //Elije la direccion a guardar
        EEDATA=datos[b];                       //Señalas el dato a guardar
        EECON1 = 0x04;                         //Activas la escritura
        EECON2 = 0x55;                         //Siempre va
        EECON2 = 0xAA;                         //Siempre va
        EECON1bits.WR = 1;                     // Orden de escritura
        while(EECON1bits.WR == 1);
    }
}     //Grarda datos en la EEPRROM
void Save_data2 (int mario){
    int b=0x00;
    int yele=0x00;
    switch(mario){
        case 1:
            yele=0x19;
            break;
        case 2:
            yele=0x4B;
            break;
        case 3:
            yele=0x7D;
            break;
        case 4:
            yele=0xAF;
            break;
    }
    
    for(b;b<=0x18;b++){
        EEADR=b+yele;                          //Elije la direccion a guardar
        EEDATA=direccion[b];                   //Señalas el dato a guardar
        EECON1 = 0x04;                         //Activas la escritura
        EECON2 = 0x55;                         //Siempre va
        EECON2 = 0xAA;                         //Siempre va
        EECON1bits.WR = 1;                     // Orden de escritura
        while(EECON1bits.WR == 1);
    }
}     //Guarda las direcciones de los datos en la EEPROM
void Save_data3 (void){
    for(int b=0;b<=3;b++){
        EEADR = b+0xC9;                          //Elije la direccion a guardar
        EEDATA=winnie[b];                   //Señalas el dato a guardar
        EECON1 = 0x04;                         //Activas la escritura
        EECON2 = 0x55;                         //Siempre va
        EECON2 = 0xAA;                         //Siempre va
        EECON1bits.WR = 1;                     // Orden de escritura
        while(EECON1bits.WR == 1);
    };
}
int  Show_data  (int mario){
    EEADR=mario;
    EECON1=0x01;     // RD = 1, Orden de lectura
    return EEDATA;
}      //Leen datos de la memoria EEPRROM
/*--------------------------Configuración de registros--------------------------------*/
void Pines(void){
    TRISAbits.RA6=1;                           //El pin RA6 configurado como entrada
    TRISAbits.RA5=1;                           //El pin RA5 configurado como entrada
    TRISAbits.RA0=1;                           //El pin RA0 configurado como entrada
    TRISCbits.RC1=0;                           //El pin RC1 configurado como salida
    TRISCbits.RC2=0;                           //El pin RC2 configurado como salida
    TRISCbits.RC6=0;                           //El pin RC6 = Tx -> Salida
    TRISCbits.RC7=1;                           //El pin RC7 = Rx -> Entrad 
    TRISD =0;                                  //El puerto D configurado como salida
}                //Configuracion principal
void Modulos (void){
    //Oscilador
    OSCCONbits.IRCF=0b111;                     //8MHz
    //Interrucciones
    INTCONbits.GIE=1;                          //Activar interrucciones
    PIR1bits.RCIF=0;
    //EUSAR
    SPBRG=12;                                  //Baudios
    TXSTAbits.BRGH = 0;                        //Low Speed
    BAUDCONbits.BRG16=0;                       //8 bits de Baudiage
    TXSTAbits.SYNC = 0;                        //Asincrono
    RCSTAbits.SPEN = 1;                        //Habilitar Tx y Rx
        //Transmisión
        TXSTAbits.TX9 = 0;                     //8 bits
        TXSTAbits.TXEN = 1;                    //Activamos transmisión
        //Recepción
        RCSTAbits.RC9 = 0;                     //8 bits
        RCSTAbits.CREN = 1;                    //Activamos recepción
}             //Configuracion de interrucciones
/*---------------------------------Comentarios----------------------------------------*/
/* El sensor menor a 0.35v, el color sensado es negro, mayor a ese valor el color el blanco.
 * En la funcion movimiento, los valores ingresados deben ser 0(front), 3(back), 1(right), 2(left) y 4(stop);
 * La velociadad de transmision es de 9600 Baud/s
 * El bluetooth debe mandar 0(verde), 1(amarrillo), 2(rojo) y 3(azul)
 * Respecto a lo guardado en la EEPRROM de las direcciones son las siguientes:
 *                                          ROJO        0-24    y   25-49
 *                                          AZUL        50-74   y   75-99 
 *                                          VERDE       100-124 y   125-149
 *                                          AMARILLO    150-174 y   175-199
/*-----------------------------Funcion principal--------------------------------------*/
void main ( void ){
    Pines();
    Modulos();
    Inicializacion();
    int i=0; int repito=1;
    int j[]={0,0,0,0};
    int auto1=1; int auto2=1; int auto3=1;
    int b; int c1; int c2; int c3;
    while(1){
        switch(PORTAbits.RA6){
            case 1:
                    while(auto1){
                    Msj=Rx();
                    switch (Msj){
                        case '0':
                            if(j[0]==0){
                                Movimiento(0); 
                                direccion[i]=0;
                                datos[i]=datos[i]+1;
                                __delay_ms(250);
                                i++; j[0]=1; j[1]=0; j[2]=0; j[3]=0;
                            }
                            else {
                                Movimiento(0);                                              
                                datos[i-1]=datos[i-1]+1;
                                __delay_ms(250);
                            }
                        break;

                        case '1':
                            if(j[1]==0){
                                Movimiento(1); 
                                direccion[i]=1;
                                datos[i]=datos[i]+1;
                                __delay_ms(10);
                                i++; j[0]=0; j[1]=1; j[2]=0; j[3]=0;
                            }
                            else {
                                Movimiento(1); 
                                datos[i-1]=datos[i-1]+1;
                                __delay_ms(10);
                            }
                        break;

                        case '2':
                            if(j[2]==0){
                                Movimiento(2); 
                                direccion[i]=2;
                                datos[i]=datos[i]+1;
                                __delay_ms(10);
                                i++; j[0]=0; j[1]=0; j[2]=1; j[3]=0;
                            }
                            else {
                                Movimiento(2); 
                                datos[i-1]=datos[i-1]+1;
                                __delay_ms(10);
                            }
                        break;

                        case '3':
                            if(j[3]==0){
                                Movimiento(3); 
                                direccion[i]=3;
                                datos[i]=datos[i]+1;
                                __delay_ms(250);
                                i++; j[0]=0; j[1]=0; j[2]=0; j[3]=1;
                            }
                            else {
                                Movimiento(3); 
                                datos[i-1]=datos[i-1]+1;
                                __delay_ms(250);
                            }
                        break;

                        case '4':
                                Movimiento(4); 
                                direccion[i]=4;
                                datos[i]=1;
                                Save_data1(repito);
                                Save_data2(repito);
                                while (auto2){
                                    Msj=Rx();
                                    if (Msj=='5'){i=0; auto2=0; Msj='pepe';}
                                    else if (Msj=='6'){i=0; auto2=0; auto1=0; Msj='pepe';LCD_Borra();}
                                }
                        break;
                    }
                }
            break;

            case 0: 
                    LCD_PosicionLinea1(0);
                    LCD_EnviaCadena("MODO AUTOMATICO");
                    while(auto3==1){
                    Msj=Rx();
                    switch (Msj){
                        case '2':       //Rojo
                            for(b=0x00; b<=0x18 ;b++){
                                c1 = Show_data(b);
                                c2 = Show_data(b+0x19);                              
                                for(c3=0; c3<=c1; c3++){
                                    Movimiento(c2);
                                    if ((c2==1)|(c2==2))__delay_ms(10);
                                    else if ((c2==3)|(c2==0))__delay_ms(250);
                                }
                            }
                            Movimiento(1);
                            __delay_ms(390);
                            Movimiento(4);
                            for(int b=0x18;b>=0x00;b--){
                                c1 = Show_data(b);
                                c2 = Show_data(b+0x19);                                
                                for(c3=0; c3<=c1; c3++){
                                    Movimiento(c2);
                                    if ((c2==1)|(c2==2))__delay_ms(10);
                                    else if ((c2==3)|(c2==0))__delay_ms(250);
                                }
                            }
                            Movimiento(4);
                        break;
                        
                        case '3':       //Azul
                            LCD_PosicionLinea2(0);
                            LCD_EnviaCadena("Camino Azul");
                            for(b=0x00; b<=winnie[1] ;b++){
                                c1 = Show_data(b+0x32);
                                c2 = Show_data(b+0x4B);                               
                                for(c3=0; c3<=c1; c3++){
                                    Movimiento(c2);
                                    if ((c2==1)|(c2==2))__delay_ms(10);
                                    else if ((c2==3)|(c2==0))__delay_ms(250);
                                }
                            }
                            Movimiento(1);
                            __delay_ms(390);
                            Movimiento(4);
                            for(int b=0x18;b>=0x00;b--){
                                c1 = Show_data(b+0x32);
                                c2 = Show_data(b+0x4B);
                                for(c3=0; c3<=c1; c3++){
                                    Movimiento(c2);
                                    if ((c2==1)|(c2==2))__delay_ms(10);
                                    else if ((c2==3)|(c2==0))__delay_ms(250);
                                }
                           
                            }
                            Movimiento(4);
                        break;
                        
                        case '0':       //verde
                            LCD_PosicionLinea2(0);
                            LCD_EnviaCadena("Camino Verde");
                            for(b=0x00; b<=0x18;b++){
                                c1 = Show_data(b+0x64);
                                c2 = Show_data(b+0x7D);
                                for(c3=0; c3<=c1; c3++){
                                    Movimiento(c2);
                                    if ((c2==1)|(c2==2))__delay_ms(10);
                                    else if ((c2==3)|(c2==0))__delay_ms(250);
                                }
                            }
                            Movimiento(1);
                            __delay_ms(390);
                            Movimiento(4);
                            for(int b=0x18;b>=0x00; b--){
                                c1 = Show_data(b+0x64);
                                c2 = Show_data(b+0x7D);                                
                                for(c3=0; c3<=c1; c3++){
                                    Movimiento(c2);
                                    if ((c2==1)|(c2==2))__delay_ms(10);
                                    else if ((c2==3)|(c2==0))__delay_ms(250);
                                }
                            }
                            Movimiento(4);
                        break;
                        
                        case '1':       //Amarillo
                            LCD_PosicionLinea2(0);
                            LCD_EnviaCadena("Camino Amarillo");
                            for(b=0x00; b<=0x18 ;b++){
                                c1 = Show_data(b+0x96);
                                c2 = Show_data(b+0xAF);
                                for(c3=0; c3<=c1; c3++){
                                    Movimiento(c2);
                                    if ((c2==1)|(c2==2))__delay_ms(10);
                                    else if ((c2==3)|(c2==0))__delay_ms(250);
                                }
                            }
                            Movimiento(1);
                            __delay_ms(390);
                            Movimiento(4);
                            for(int b=0x18;b>=0x00;b--){
                                c1 = Show_data(b+0x96);
                                c2 = Show_data(b+0xAF);                                
                                for(c3=0; c3<=c1; c3++){
                                    Movimiento(c2);
                                    if ((c2==1)|(c2==2))__delay_ms(10);
                                    else if ((c2==3)|(c2==0))__delay_ms(250);
                                }                  
                            }
                            Movimiento(4);
                        break;
                        
                        case 9:
                            Movimiento(4);
                        break;
                    }
                }
            break;
        }   
       }
}