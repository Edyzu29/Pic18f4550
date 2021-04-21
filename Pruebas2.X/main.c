#include "system.h"
#include <xc.h>
#include <stdint.h>
#include "Adc.h"
#include "BLUE.h"
#include "Laser1.h"

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
#define Valor_bobina_cinco      165
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
/*Constantes de lectura*/
uint16_t valor_adc;
uint16_t Curva[N_MUESTRAS];
/*----------------------------------------------------------------------------*/
/*Banderas*/
volatile uint8_t Bandera_de_Lectura=0;
/*----------------------------------------------------------------------------*/
/*Acumuladores y Contadores*/
volatile uint16_t conta_100us=0;
uint16_t i = 0;
/*----------------------------------------------------------------------------*/
/*Varibles Auxiliar*/
uint8_t caida;
uint16_t min=1023;

uint8_t Detecta_Cambio(uint16_t);

void main(void){
    
    Confi_Blue();
    Confi_TMR0();
    ConfigADC();
    
    UART0_Tx_String("Conexcion Establecida \r\n Buenos tardes \r\n");
   
    TMR0_Start=1;
    
    while(1){  
        
        if(Bandera_de_Lectura){
            Bandera_de_Lectura=0;
            valor_adc = LecturaADC();
            caida=Detecta_Cambio(valor_adc);
            if(caida){
                for(i=0;i<N_MUESTRAS;i++){
                    while(Bandera_de_Lectura==0);
                    Bandera_de_Lectura=0;
                    Curva[i]=LecturaADC();
                }
                 for(i=0;i<N_MUESTRAS;i++){
                    if(Curva[i]<min)min=Curva[i];
                }
                
                if (i>=N_MUESTRAS){
                   UART0_Tx_String("A=[");
                    for(i=0;i<N_MUESTRAS;i++){
                       UART0_Tx_Integer(Curva[i]); 
                       if(i<N_MUESTRAS-1)Tx_str(',');
                    } 
                    UART0_Tx_String("]; \n\r");
                    i=0;
                }
            }    
       }           
    }
        
}

uint8_t Detecta_Cambio(uint16_t jordiii){
    
    uint8_t salida=0;

    if(jordiii<Umbral)salida=1; 
    else    salida=0;
   
    return salida;
}

void __interrupt() Timer(void){
    if(TMR0_Flag==1){
        TMR0_Reset();
        conta_100us++; 
    }
    if(conta_100us==Tiempo_entre_Muestras){
           // labandeira=1;
            conta_100us=0;
            ADCON0bits.GO = 1;
    }
}

void __interrupt(low_priority) Adc(void){
    if(PIR1bits.ADIF==1){
        PIR1bits.ADIF=0;
        Bandera_de_Lectura=1;
    }
}