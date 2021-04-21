/* 
 * File:   PWM.h
 * Author: maxed
 *
 * Created on 16 de octubre de 2019, 08:25 PM
 */

#ifndef PWM_H
#define	PWM_H

/* Constantes y macros */
#define TMR2_Start       T2CONbits.TMR2ON

//Estos son para el CCP1
#define PWM_RC2_Tris     TRISCbits.RC2
#define PWM_RC2          LATCbits.LATC2

//Estos son para el CCP2
#define PWM_RC1_Tris     TRISCbits.RC1
#define PWM_RC1          LATCbits.LATC1

#define Periodo_PWM         249
#define Duty_cycle          20

/*Funciones*/
void Confi_PWM(void);
void Periodo_change(uint8_t);
void Duty_Cycle_Change(uint16_t);

#endif	/* PWM_H */

