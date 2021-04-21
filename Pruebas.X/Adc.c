#include <xc.h>
#include <stdint.h>
#include "Adc.h"

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
    PIR1bits.ADIF=0;
    PIE1bits.ADIE=1;
    IPR1bits.ADIP=0;
    ADCON2bits.ACQT = 0b010;    // Adquisici�n auto: 4 TAD
    ADCON2bits.ADCS = 0b101;    // Fosc/16
    ADCON2bits.ADFM = 1;        // right
    ADCON1bits.PCFG = 0b1101;   // AN0, AN1
    ADCON1bits.VCFG = 0b00;     // VDD, VSS
    ADCON0bits.CHS = 0;              // Selecciona canal
    ADCON0bits.ADON = 1;                 // Inicia adquisici�n de dato
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
uint16_t LecturaADC(void)
{
    return (ADRESH<<8) + (ADRESL);       // Devuelve los 10 bits obtenidos
    bandera_leer_adc = 0;
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
