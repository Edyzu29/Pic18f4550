/* 
 * File:   MiLCD.h
 * Author: EDUARDO
 *
 * Created on 12 de mayo de 2018, 08:11 PM
 */

#ifndef MIADC_H
#define	MIADC_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 4000000UL
#endif

#define ACQ_US_DELAY 5

#define VMAX 5
#define VMIN 0
#define RESOLUCION 10

void ConfigADC(void);
uint16_t LecturaADC(uint8_t);

#ifdef	__cplusplus
}
#endif

#endif	/* MIADC_H */

