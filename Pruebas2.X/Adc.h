/* 
 * File:   Adc.h
 * Author: EDWIN
 *
 * Created on 26 de junio de 2019, 06:54 PM
 */

#ifndef ADC_H
#define	ADC_H

#define LectorAdc TRISAbits.RA0

//Constantes
#define _XTAL_FREQ 20000000UL

//Banderas y pines
#define Adc_Flag    PIR1bits.ADIF

//Funciones
void ConfigADC(void);
uint16_t LecturaADC(void);

#endif	/* ADC_H */
