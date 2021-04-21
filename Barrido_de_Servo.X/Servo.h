/* 
 * File:   Servo.h
 * Author: EDWIN
 *
 * Created on 14 de julio de 2019, 11:16 AM
 */

#ifndef SERVO_H
#define	SERVO_H

//Seteo de Pines
#define Servo_Luz_Tris         TRISDbits.RD7

//Control de Servos
#define Servo_Luz              LATDbits.LATD7

//Grados del Servo    
#define g0    0.7
#define g15   1.0
#define g30   1.1
#define g45   1.2
#define g60   1.3
#define g75   1.4
#define g90   1.5
#define g105  1.7
#define g120  1.9
#define g135  2.0
#define g150  2.1
#define g165  2.3
#define g180  2.5

#define _XTAL_FREQ 8000000UL

//Funciones
void Confi_Servo (void);
void Grados_0 (void);
void Grados_15 (void);
void Grados_30 (void);
void Grados_45 (void);
void Grados_60 (void);
void Grados_75 (void);
void Grados_90 (void);
void Grados_105 (void);
void Grados_120 (void);
void Grados_135 (void);
void Grados_150 (void);
void Grados_165 (void);
void Grados_180 (void);

#endif	/* SERVO_H */

