/* 
 * File:   Laser.h
 * Author: EDWIN
 *
 * Created on 14 de junio de 2019, 11:43 AM
 */

#ifndef TMRS_H
#define	TMRS_H

//Declarando Constantes

#define TMR0_Switch    INTCONbits.T0IE
#define TMR0_Flag      INTCONbits.TMR0IF
#define TMR0_Start     T0CONbits.TMR0ON
#define Offset_TMR0        65036

#define TMR1_Switch    PIE1bits.TMR1IE
#define TMR1_Flag      PIR1bits.TMR1IF
#define TMR1_Start     T1CONbits.TMR1ON
#define Offset_TMR1        64911

//Declarando funciones
    void Confi_TMR0(void);
    void TMR0_Reset(void);
    
    void Confi_TMR1(void);
    void TMR1_Reset(void);

#endif	/* LASER_H */