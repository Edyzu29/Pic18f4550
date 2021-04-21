#include "Confi.h"
#include <xc.h>
#include <stdint.h>
#include "MiADC.h"

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
    
    Adc_Flag=0;
    PIE1bits.ADIE=1;
    IPR1bits.ADIP=0;
    
    ADCON2bits.ACQT = 0b010;    // Adquisición auto: 4 TAD
    ADCON2bits.ADCS = 0b101;    // Fosc/16
    ADCON2bits.ADFM = 1;        // right
    ADCON1bits.PCFG = 0b1101;   // AN0, AN1
    ADCON1bits.VCFG = 0b00;     // VDD, VSS
    ADCON0bits.ADON = 1;                 // Inicia adquisición de dato
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
    return (ADRESH<<8) + (ADRESL);       // Devuelve los 10 bits obtenidos
 }
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/*
    PCFG3:PCFG0 AN12 AN11 AN10 AN9 AN8 AN7(2)  AN6(2) AN5(2) AN4 AN3 AN2 AN1 AN0
        0000  --> TODOS Anlogiocos         
        0001    --> TODOS Anlogiocos                      
        0010    --> TODOS Anlogiocos         
        0011      --> AN12 D         
        0100     --> AN12 D,  AN11 D         
        0101     --> AN12 D, AN11 D,  AN10 D         
        0110        --> AN12 D, AN11 D, AN10 D,  AN9 D         
        0111        --> AN12 D, AN11 D, AN10 D, AN9 D , AN8D      
        1000    -->  AN12 D, AN11 D, AN10 D, AN9 D , AN8D,  AN7D
        1001        --> AN12 D, AN11 D, AN10 D, AN9 D , AN8D ,  AN7D,  AN6D        
        1010        --> AN12 D, AN11 D, AN10 D, AN9 D , AN8D ,  AN7D,  AN6D, AN5D         
        1011        --> AN12 D, AN11 D, AN10 D, AN9 D , AN8D ,  AN7D,  AN6D, AN5D, AN4D         
        1100        --> AN12 D, AN11 D, AN10 D, AN9 D , AN8D ,  AN7D,  AN6D, AN5D, AN4D, AN3D         
        1101        -->  AN0 A, AN1 A         
        1110        --> AN0 A         
        1111        --> TODOS DIGITALES         
 */

