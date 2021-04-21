/* 
 * File:   MiLCD.h
 * Author: EDUARDO
 *
 * Created on 12 de mayo de 2018, 08:11 PM
 */

#ifndef MIADC_H
#define	MIADC_H

//Constantes
//#define _XTAL_FREQ 20000000UL

//Banderas y pines
#define Inicio_Adc  ADCON0bits.GO
#define Adc_Flag    PIR1bits.ADIF
#define LectorAdc TRISAbits.RA0

//Funciones
void ConfigADC(void);
uint16_t LecturaADC(void);

#endif	/* MIADC_H */

