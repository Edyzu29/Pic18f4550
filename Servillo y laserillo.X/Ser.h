/* 
 * File:   Servo.h
 * Author: EDWIN
 *
 * Created on 7 de junio de 2019, 09:29 AM
 */

#ifndef SER_H
#define	SER_H

//Seteo de Servos

#define Servo_Fake_Tris         TRISBbits.RB0

#define Servo_Diez_Tris         TRISBbits.RB1
#define Servo_Veinte_Tris       TRISBbits.RB2
#define Servo_Cincuenta_Tris    TRISBbits.RB3
#define Servo_Sol_Tris          TRISBbits.RB4
#define Servo_Dos_Tris          TRISBbits.RB5
#define Servo_Cinco_Tris        TRISBbits.RB6

//Control de Servos

#define Servo_Fake              LATBbits.LATB0

#define Servo_Diez              LATBbits.LATB1
#define Servo_Veinte            LATBbits.LATB2
#define Servo_Cincuenta         LATBbits.LATB3
#define Servo_Sol               LATBbits.LATB4
#define Servo_Dos               LATBbits.LATB5
#define Servo_Cinco             LATBbits.LATB6

//Grados del Servo 

#define g0    0.5
#define g45   1.0
#define g90   1.5
#define g135  2.0
#define g180  2.5

//Constante del Delay

#define _XTAL_FREQ  20000000

//Funciones

void Confi_Servo (void);
void Servo_Posicion_Inicial (void);
void Moneda_Fake (void);
void Dam_Dinero (uint8_t ,uint8_t);

void Servo_Diez_0   (void);
void Servo_Diez_45  (void);
void Servo_Diez_90  (void);
void Servo_Diez_135 (void);
void Servo_Diez_180 (void);

void Servo_Veinte_0   (void);
void Servo_Veinte_45  (void);
void Servo_Veinte_90  (void);
void Servo_Veinte_135 (void);
void Servo_Veinte_180 (void);

void Servo_Cincuenta_0   (void);
void Servo_Cincuenta_45  (void);
void Servo_Cincuenta_90  (void);
void Servo_Cincuenta_135 (void);
void Servo_Cincuenta_180 (void);

void Servo_Sol_0   (void);
void Servo_Sol_45  (void);
void Servo_Sol_90  (void);
void Servo_Sol_135 (void);
void Servo_Sol_180 (void);

void Servo_Dos_0   (void);
void Servo_Dos_45  (void);
void Servo_Dos_90  (void);
void Servo_Dos_135 (void);
void Servo_Dos_180 (void);

void Servo_Cinco_0   (void);
void Servo_Cinco_45  (void);
void Servo_Cinco_90  (void);
void Servo_Cinco_135 (void);
void Servo_Cinco_180 (void);

void Servo_Fake_0   (void);
void Servo_Fake_45  (void);
void Servo_Fake_90  (void);
void Servo_Fake_135 (void);
void Servo_Fake_180 (void);

#endif	/* SER_H */

