/* 
 * File:   Servito.h
 * Author: EDWIN
 *
 * Created on 13 de julio de 2019, 12:43 PM
 */

#ifndef SERVITO_H
#define	SERVITO_H

//Seteo de Pines
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
#define g90   1.5
#define g180  2.5

//Funciones
void Giro_Servo (char,int);
void Confi_Servo (void);
void Servo_Posicion_Inicial (void);
void Dam_Dinero (uint8_t ,uint8_t);

#endif	/* SERVITO_H */

