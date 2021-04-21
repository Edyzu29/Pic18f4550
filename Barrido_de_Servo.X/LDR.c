#include <xc.h>
#include <stdint.h>
#include "LDR.h"

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/*
 * Función: ConfigADC
 *
 * Descripción: Configura ADC - AN0, AN1, se usará VDD y VSS, Adquisición
 *              manual, Fosc/4 (por trabajar a 4MHz)
 * Entradas Ninguna
 * Salidas  Ninguna
 */
//------------------------------------------------------------------------------
void ConfigADC(void)
{   
    LectorAdc=1;
    ADCON2bits.ACQT = 0b000;    // Adquisición manual: 0 TAD
    ADCON2bits.ADCS = 0b100;    // Fosc/4
    ADCON2bits.ADFM = 1;        // right
    ADCON1bits.PCFG = 0b1110;   // AN0, AN1
    ADCON1bits.VCFG = 0b00;     // VDD, VSS
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/*
 * Función: LecturaADC
 *
 * Descripción: Inicia ciclo de adquisión y conversión de dato para un canal
 *              indicado. El valor obtenido es devuelto por la función 
 * Entradas Canal
 * Salidas  Valor Digital
 */
//------------------------------------------------------------------------------
uint16_t LecturaADC(uint8_t canal)
{
    ADCON0bits.CHS = canal;              // Selecciona canal
    ADCON0bits.ADON = 1;                 // Inicia adquisición de dato
    __delay_us(ACQ_US_DELAY);            // TAD = 2.45us según datasheet 
    ADCON0bits.GO_nDONE = 1;             // Inicia conversión (aprox 10*TAD)
    while( ADCON0bits.GO_nDONE == 1 ) ;  // Espera hasta que conversión termine
    return (ADRESH<<8) + (ADRESL);       // Devuelve los 10 bits obtenidos
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
