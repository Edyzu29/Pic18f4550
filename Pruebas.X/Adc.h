/* 
 * File:   Adc.h
 * Author: EDWIN
 *
 * Created on 26 de junio de 2019, 06:54 PM
 */

#ifndef ADC_H
#define	ADC_H

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 20000000UL
#endif

#define ACQ_US_DELAY 5

#define VMAX 5
#define VMIN 0
#define RESOLUCION 10
#define LectorAdc TRISAbits.RA0


extern volatile uint8_t bandera_leer_adc;


void ConfigADC(void);
uint16_t LecturaADC(void);

#endif	/* ADC_H */
