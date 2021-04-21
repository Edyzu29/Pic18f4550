/* 
 * File:   Servo.h
 * Author: EDWIN
 *
 * Created on 7 de junio de 2019, 09:29 AM
 */

#ifndef SERVO_H
#define	SERVO_H


//Seteo de Servos

#define Servo_Uno_Tris               TRISBbits.RB0
#define Servo_Dos_Tris               TRISBbits.RB1
#define Servo_Tres_Tris              TRISBbits.RB2
#define Servo_Cuatro_Tris          TRISBbits.RB3
#define Servo_Cinco_Tris            TRISBbits.RB4
#define Servo_Seis_Tris               TRISBbits.RB5

//Control de Servos



#define Servo_Uno               LATBbits.LATB0
#define Servo_Dos               LATBbits.LATB1
#define Servo_Tres              LATBbits.LATB2
#define Servo_Cuatro          LATBbits.LATB3
#define Servo_Cinco            LATBbits.LATB4
#define Servo_Seis               LATBbits.LATB5

//Grados del Servo 

#define g0          0.500
#define g15        0.670
#define g30        0.830
#define g45        1.000
#define g60        1.170
#define g75        1.300
#define g90        1.500
#define g105      1.670
#define g120      1.830
#define g135      2.000
#define g150      2.170
#define g165      2.300
#define g180      2.500

//Funciones
void Confi_Servo (void);
void Servo_Posicion_Inicial (void);

void Servo_Uno_0      (void);
void Servo_Uno_15    (void);
void Servo_Uno_30    (void);
void Servo_Uno_45    (void);
void Servo_Uno_60    (void);
void Servo_Uno_75    (void);
void Servo_Uno_90    (void);
void Servo_Uno_105  (void);
void Servo_Uno_120  (void);
void Servo_Uno_135  (void);
void Servo_Uno_150  (void);
void Servo_Uno_165  (void);
void Servo_Uno_180  (void);

void Servo_Dos_0      (void);
void Servo_Dos_15    (void);
void Servo_Dos_30    (void);
void Servo_Dos_45    (void);
void Servo_Dos_60    (void);
void Servo_Dos_75    (void);
void Servo_Dos_90    (void);
void Servo_Dos_105  (void);
void Servo_Dos_120  (void);
void Servo_Dos_135  (void);
void Servo_Dos_150  (void);
void Servo_Dos_165  (void);
void Servo_Dos_180  (void);

void Servo_Tres_0      (void);
void Servo_Tres_15    (void);
void Servo_Tres_30    (void);
void Servo_Tres_45    (void);
void Servo_Tres_60    (void);
void Servo_Tres_75    (void);
void Servo_Tres_90    (void);
void Servo_Tres_105  (void);
void Servo_Tres_120  (void);
void Servo_Tres_135  (void);
void Servo_Tres_150  (void);
void Servo_Tres_165  (void);
void Servo_Tres_180  (void);

void Servo_Cuatro_0      (void);
void Servo_Cuatro_15    (void);
void Servo_Cuatro_30    (void);
void Servo_Cuatro_45    (void);
void Servo_Cuatro_60    (void);
void Servo_Cuatro_75    (void);
void Servo_Cuatro_90    (void);
void Servo_Cuatro_105  (void);
void Servo_Cuatro_120  (void);
void Servo_Cuatro_135  (void);
void Servo_Cuatro_150  (void);
void Servo_Cuatro_165  (void);
void Servo_Cuatro_180  (void);

void Servo_Cinco_0      (void);
void Servo_Cinco_15    (void);
void Servo_Cinco_30    (void);
void Servo_Cinco_45    (void);
void Servo_Cinco_60    (void);
void Servo_Cinco_75    (void);
void Servo_Cinco_90    (void);
void Servo_Cinco_105  (void);
void Servo_Cinco_120  (void);
void Servo_Cinco_135  (void);
void Servo_Cinco_150  (void);
void Servo_Cinco_165  (void);
void Servo_Cinco_180  (void);

void Servo_Seis_0      (void);
void Servo_Seis_15    (void);
void Servo_Seis_30    (void);
void Servo_Seis_45    (void);
void Servo_Seis_60    (void);
void Servo_Seis_75    (void);
void Servo_Seis_90    (void);
void Servo_Seis_105  (void);
void Servo_Seis_120  (void);
void Servo_Seis_135  (void);
void Servo_Seis_150  (void);
void Servo_Seis_165  (void);
void Servo_Seis_180  (void);

#endif	/* SERVO_H */

