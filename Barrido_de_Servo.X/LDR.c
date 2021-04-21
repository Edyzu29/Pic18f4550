#include <xc.h>
#include <stdint.h>
#include "LDR.h"

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/*
 * Funci�n: ConfigADC
 *
 * Descripci�n: Configura ADC - AN0, AN1, se usar� VDD y VSS, Adquisici�n
 *              manual, Fosc/4 (por trabajar a 4MHz)
 * Entradas Ninguna
 * Salidas  Ninguna
 */
//------------------------------------------------------------------------------
void ConfigADC(void)
{   
    LectorAdc=1;
    ADCON2bits.ACQT = 0b000;    // Adquisici�n manual: 0 TAD
    ADCON2bits.ADCS = 0b100;    // Fosc/4
    ADCON2bits.ADFM = 1;        // right
    ADCON1bits.PCFG = 0b1110;   // AN0, AN1
    ADCON1bits.VCFG = 0b00;     // VDD, VSS
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/*
 * Funci�n: LecturaADC
 *
 * Descripci�n: Inicia ciclo de adquisi�n y conversi�n de dato para un canal
 *              indicado. El valor obtenido es devuelto por la funci�n 
 * Entradas Canal
 * Salidas  Valor Digital
 */
//------------------------------------------------------------------------------
uint16_t LecturaADC(uint8_t canal)
{
    ADCON0bits.CHS = canal;              // Selecciona canal
    ADCON0bits.ADON = 1;                 // Inicia adquisici�n de dato
    __delay_us(ACQ_US_DELAY);            // TAD = 2.45us seg�n datasheet 
    ADCON0bits.GO_nDONE = 1;             // Inicia conversi�n (aprox 10*TAD)
    while( ADCON0bits.GO_nDONE == 1 ) ;  // Espera hasta que conversi�n termine
    return (ADRESH<<8) + (ADRESL);       // Devuelve los 10 bits obtenidos
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
