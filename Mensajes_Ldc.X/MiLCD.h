/* 
 * File:   MiLCD.h
 * Author: EDUARDO
 *
 * Created on 12 de mayo de 2018, 08:11 PM
 */

#ifndef MILCD_H
#define	MILCD_H
    
#define LCD_NumCarPorLinea  40

#define LCD_PinD7   PORTBbits.RB7
#define LCD_PinD6   PORTBbits.RB6
#define LCD_PinD5   PORTBbits.RB5
#define LCD_PinD4   PORTBbits.RB4
#define LCD_PinD3   PORTBbits.RB3
#define LCD_PinD2   PORTBbits.RB2
#define LCD_PinD1   PORTBbits.RB1
#define LCD_PinD0   PORTDbits.RD7
#define LCD_PinRS   PORTCbits.RC2
#define LCD_PinRW   PORTCbits.RC1    
#define LCD_PinEN   PORTCbits.RC0
    
#define LCD_CfgPinD7   TRISBbits.TRISB7
#define LCD_CfgPinD6   TRISBbits.TRISB6
#define LCD_CfgPinD5   TRISBbits.TRISB5
#define LCD_CfgPinD4   TRISBbits.TRISB4
#define LCD_CfgPinD3   TRISBbits.TRISB3
#define LCD_CfgPinD2   TRISBbits.TRISB2
#define LCD_CfgPinD1   TRISBbits.TRISB1
#define LCD_CfgPinD0   TRISDbits.TRISD7
#define LCD_CfgPinRS   TRISCbits.TRISC2
#define LCD_CfgPinRW   TRISCbits.TRISC1
#define LCD_CfgPinEN   TRISCbits.TRISC0
    
void LCD_Inicializa( void );
void LCD_Linea1( void );
void LCD_Linea2( void );
void LCD_Linea3( void );
void LCD_Linea4( void );
void LCD_PosicionLinea1( uint8_t );
void LCD_PosicionLinea2( uint8_t );
void LCD_PosicionLinea3( uint8_t );
void LCD_PosicionLinea4( uint8_t );
void LCD_OFF( void );
void LCD_CursorON( void );
void LCD_CursorOFF( void );
void LCD_Borra( void );
void LCD_EnviaComando( uint8_t );
void LCD_EnviaCaracter( uint8_t );
void LCD_EnviaCadena( uint8_t * );
void LCD_Envia( uint8_t );
void LCD_LineaEnBlanco( void );
void LCD_UnEspacioBlanco( void );
void LCD_DosEspaciosBlancos( void );
void LCD_TresEspaciosBlancos( void );
void LCD_EnviaBlancos( uint8_t );
void LCD_EnviaOtroBlanco( void );
void LCD_EnviaByte( uint8_t );
void LCD_EnviaByteCompleto( uint8_t );
void LCD_EnviaNibble( uint8_t );
void LCD_ShiftRight( void );
void LCD_ShiftLeft( void );

#endif	/* MILCD_H */

