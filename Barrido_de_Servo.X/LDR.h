/* 
 * File:   LDR.h
 * Author: EDWIN
 *
 * Created on 14 de julio de 2019, 11:14 AM
 */

#ifndef LDR_H
#define	LDR_H

#define ACQ_US_DELAY 5

#define VMAX 5
#define VMIN 0
#define RESOLUCION 10
#define LectorAdc TRISAbits.RA0

void ConfigADC(void);
uint16_t LecturaADC(uint8_t);

#define _XTAL_FREQ 8000000UL


#endif	/* LDR_H */

