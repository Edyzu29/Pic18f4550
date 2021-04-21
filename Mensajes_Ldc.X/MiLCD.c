#include <xc.h>
#include <stdint.h>
#include "MiLCD.h"

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000UL
#endif

void LCD_Inicializa( void );
void LCD_CursorIncr ( void );
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
void LCD_2Lineas8Bits5x7( void );
void LCD_EnviaComando( uint8_t );
void LCD_EnviaCaracter( uint8_t );
void LCD_EnviaCadena( uint8_t * );
void LCD_Envia( uint8_t );
uint8_t LCD_CodigoCGROM( uint8_t );
void LCD_LineaEnBlanco( void );
void LCD_UnEspacioBlanco( void );
void LCD_DosEspaciosBlancos( void );
void LCD_TresEspaciosBlancos( void );
void LCD_EnviaBlancos( uint8_t );
void LCD_EnviaOtroBlanco( void );
void LCD_EnviaByte( uint8_t );
void LCD_EnviaByteCompleto( uint8_t );
void LCD_EnviaNibble( uint8_t );
void LCD_Port( uint8_t );
void LCD_CfgPort( uint8_t );
void LCD_ShiftRight( void );
void LCD_ShiftLeft( void );

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_Inicializa"
//
// Inicializaci�n del m�dulo LCD: Configura funciones del LCD, produce reset por software,
// borra memoria y enciende pantalla. El fabricante especifica que para garantizar la
// configuraci�n inicial hay que hacerla como sigue:
//------------------------------------------------------------------------------
void LCD_Inicializa( void )
{
    LCD_CfgPinRS = 0;
    LCD_CfgPinRW = 0;
    LCD_CfgPinEN = 0;
    LCD_CfgPinD7 = 0;
    LCD_CfgPinD6 = 0;
    LCD_CfgPinD5 = 0;
    LCD_CfgPinD4 = 0;
    LCD_CfgPinD3 = 0;
    LCD_CfgPinD2 = 0;
    LCD_CfgPinD1 = 0;
    LCD_CfgPinD0 = 0;
    
    LCD_PinRW = 0;          // En caso de que est� conectado le indica
                            // que se va a escribir en el LCD.
	LCD_PinEN = 0;          // Impide funcionamiento del LCD poniendo E=0.
    LCD_PinRS = 0;          // Activa el Modo Comando poniendo RS=0.
	__delay_ms( 200 );
	LCD_Envia(0B00111000);  // Escribe el dato en el LCD.
	__delay_ms( 5 );
    LCD_Envia(0B00110000);
	__delay_us( 200 );
    LCD_Envia(0B00110000);
	__delay_us( 200 );      // Este retardo es necesario para simular en PROTEUS.
    LCD_Envia(0B00110000);  // Interface de 8 bits.
	__delay_us( 20 );       // Este retardo es necesario para simular en PROTEUS.
    
                            // Ahora configura el resto de los par�metros: 
	LCD_2Lineas8Bits5x7();  // LCD de 2 l�neas y caracteres de 5x7 puntos, bus de 8.
	LCD_Borra();            // Pantalla encendida y limpia. Cursor al principio
	LCD_CursorOFF();        // de la l�nea 1. Cursor apagado.
	LCD_CursorIncr();       // Cursor en modo incrementar. 
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_CursorIncr"
//
// Cursor en modo incrementar.
//------------------------------------------------------------------------------
void LCD_CursorIncr( void )
{
	LCD_EnviaComando(0B00000110);
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_Linea1"
//
// Cursor al principio de la L�nea 1.
//------------------------------------------------------------------------------
void LCD_Linea1( void )
{
	LCD_EnviaComando(0x80 + 0x00);   // Direcci�n 00h de la DDRAM
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_Linea2"
//
// Cursor al principio de la L�nea 2.
//------------------------------------------------------------------------------
void LCD_Linea2( void )
{
	LCD_EnviaComando(0x80 + 0x40);   // Direcci�n 40h de la DDRAM
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_Linea3"
//
// Cursor al principio de la L�nea 3.
//------------------------------------------------------------------------------
void LCD_Linea3( void )
{
	LCD_EnviaComando(0x80 + LCD_NumCarPorLinea/2);   // Direcci�n LCD_NumCarPorLinea/2 de la DDRAM
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_Linea4"
//
// Cursor al principio de la L�nea 4.
//------------------------------------------------------------------------------
void LCD_Linea4( void )
{
	LCD_EnviaComando(0x80 + 0x40 + LCD_NumCarPorLinea/2);   // Direcci�n 40h + LCD_NumCarPorLinea/2 de la DDRAM
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_PosicionLinea1"
//
// Cursor a posici�n de la L�nea 1, a partir de la direcci�n 00h de la DDRAM m�s
// el valor de Pos
//------------------------------------------------------------------------------
void LCD_PosicionLinea1( uint8_t Pos )
{
    LCD_EnviaComando(0x80 + 0x00 + Pos);
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_PosicionLinea2"
//
// Cursor a posici�n de la L�nea 2, a partir de la direcci�n 40h de la DDRAM m�s
// el valor de Pos
//------------------------------------------------------------------------------
void LCD_PosicionLinea2( uint8_t Pos )
{
    LCD_EnviaComando(0x80 + 0x40 + Pos);
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_PosicionLinea3"
//
// Cursor a posici�n de la L�nea 3, a partir de la direcci�n 00h +
// LCD_NumCarPorLinea/2 de la DDRAM m�s el valor de Pos
//------------------------------------------------------------------------------
void LCD_PosicionLinea3( uint8_t Pos )
{
    LCD_EnviaComando(0x80 + 0x00 + LCD_NumCarPorLinea/2 + Pos);
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_PosicionLinea4"
//
// Cursor a posici�n de la L�nea 4, a partir de la direcci�n 40h +
// LCD_NumCarPorLinea/2 de la DDRAM m�s el valor de Pos
//------------------------------------------------------------------------------
void LCD_PosicionLinea4( uint8_t Pos )
{
    LCD_EnviaComando(0x80 + 0x40 + LCD_NumCarPorLinea/2 + Pos);
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_OFF"
//
// Pantalla apagada.
//------------------------------------------------------------------------------
void LCD_OFF( void )
{
    LCD_EnviaComando(0B00001000);
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_CursorON"
//
// Pantalla encendida y cursor encendido.
//------------------------------------------------------------------------------
void LCD_CursorON( void )
{
    LCD_EnviaComando(0B00001110);
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_CursorOFF"
//
// Pantalla encendida y cursor apagado.
//------------------------------------------------------------------------------
void LCD_CursorOFF( void )
{
    LCD_EnviaComando(0B00001100);
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_Borra"
//
// Borra toda la pantalla, memoria DDRAM y pone el cursor a principio de la
// l�nea 1.
//------------------------------------------------------------------------------
void LCD_Borra( void )
{
    LCD_EnviaComando(0B00000001);
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_2Lineas8Bits5x7"
//
// Define la pantalla de 2 l�neas, con caracteres de 5x7 puntos y conexi�n al
// PIC mediante bus de 8 bits.
//------------------------------------------------------------------------------
void LCD_2Lineas8Bits5x7( void )
{
    LCD_EnviaComando(0B00111000);
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_EnviaComando"
//
// Escribe un comando en el registro del m�dulo LCD. La palabra de comando ha
// sido entregada a trav�s de Comando.  Trabaja en Modo Comando.
//------------------------------------------------------------------------------
void LCD_EnviaComando( uint8_t Comando )
{
    LCD_PinRS = 0;          // Activa el Modo Comando, poniendo RS=0.
    LCD_Envia( Comando );
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_EnviaCaracter"
//
// Escribe en la memoria DDRAM del LCD el car�cter ASCII introducido a trav�s
// de Caracter. Trabaja en Modo Dato.
//------------------------------------------------------------------------------
void LCD_EnviaCaracter( uint8_t Caracter )
{
    LCD_PinRS = 1;                              // Activa el "Modo Dato", poniendo RS=1.
    Caracter = LCD_CodigoCGROM( Caracter );    // Obtiene el c�digo para correcta visualizaci�n.
    LCD_Envia( Caracter );
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_EnviaCadena"
//
// Escribe en la memoria DDRAM del LCD los car�cter ASCII introducido a trav�s
// de Cadena. Trabaja en Modo Dato.
//------------------------------------------------------------------------------
void LCD_EnviaCadena( uint8_t * Cadena )
{
    while( *Cadena )
        LCD_EnviaCaracter( *(Cadena++) );
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_Envia"
//
// Escribe en la memoria DDRAM del LCD el car�cter ASCII introducido a trav�s
// de Caracter. Trabaja en Modo Dato.
//------------------------------------------------------------------------------
void LCD_Envia( uint8_t Dato )
{
    uint8_t LCD_GuardaTRIS = (LCD_CfgPinD7 << 7) |
                             (LCD_CfgPinD6 << 6) |
                             (LCD_CfgPinD5 << 5) |
                             (LCD_CfgPinD4 << 4) |
                             (LCD_CfgPinD3 << 3) |
                             (LCD_CfgPinD2 << 2) |
                             (LCD_CfgPinD1 << 1) |
                             (LCD_CfgPinD0 << 0);   // Guarda la configuraci�n que ten�an los pines de Datos.
    
    LCD_CfgPinD7 = 0;       // Puerto como salida.
    LCD_CfgPinD6 = 0;
    LCD_CfgPinD5 = 0;
    LCD_CfgPinD4 = 0;
    LCD_CfgPinD3 = 0;
    LCD_CfgPinD2 = 0;
    LCD_CfgPinD1 = 0;
    LCD_CfgPinD0 = 0;
    
    LCD_Port( Dato );       // Env�a el dato al m�dulo LCD.
    LCD_PinEN = 1;          // Permite funcionamiento del LCD mediante un peque�o...
    __delay_us(1);
    LCD_PinEN = 0;          // ... pulso y termina impidiendo el funcionamiento del LCD.
    LCD_CfgPort( LCD_GuardaTRIS );  // Restaura el antiguo valor en la configuraci�n del Puerto.
    
    if( !LCD_PinRS ) __delay_ms( 20 );  // Debe garantizar una correcta escritura manteniendo
    __delay_us( 50 );                   // 2 ms en modo comando y 50 �s en modo c�racter.
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_CodigoCGROM"
//
// A partir del car�cter ASCII n�mero 127 los c�digos de los caracteres definidos en la
// tabla CGROM del LM016L no coinciden con los c�digos ASCII. As� por ejemplo, el c�digo
// ASCII de la "�" en la tabla CGRAM del LM016L es EEh.
//
// Esta subrutina convierte los c�digos ASCII de la "�", "�" y otros, a c�digos CGROM para que
// que puedan ser visualizado en el m�dulo LM016L.
// 
// Entrada:	el c�digo ASCII del car�cter que se desea visualizar.
// Salida:	el c�digo definido en la tabla CGROM.
//------------------------------------------------------------------------------
uint8_t LCD_CodigoCGROM( uint8_t Caracter )
{
    if( Caracter == '�' ) return 0B11101110;     // C�digo CGROM de la "�".
    if( Caracter == '�' ) return 0B11101110;     // C�digo CGROM de la "�" (No hay s�mbolo).
    if( Caracter == '�' ) return 0B11011111;     // C�digo CGROM de la "�".
    return Caracter;
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_LineaEnBlanco"
//
// Visualiza espacios en blanco.
//------------------------------------------------------------------------------
void LCD_LineaEnBlanco( void )
{
    LCD_EnviaBlancos( LCD_NumCarPorLinea );
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_UnEspacioBlanco"
//
// Visualiza un espacio en blanco.
//------------------------------------------------------------------------------
void LCD_UnEspacioBlanco( void )
{
    LCD_EnviaBlancos( 1 );
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_DosEspaciosBlancos"
//
// Visualiza dos espacios en blanco.
//------------------------------------------------------------------------------
void LCD_DosEspaciosBlancos( void )
{
    LCD_EnviaBlancos( 2 );
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_TresEspaciosBlancos"
//
// Visualiza tres espacios en blanco.
//------------------------------------------------------------------------------
void LCD_TresEspaciosBlancos( void )
{
    LCD_EnviaBlancos( 3 );
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_EnviaBlancos"
//
// Visualiza tanto espacios en blanco como se haya cargado en NumBlancos
//------------------------------------------------------------------------------
void LCD_EnviaBlancos( uint8_t NumBlancos )
{
    while( NumBlancos-- )
        LCD_EnviaCaracter( ' ' );		
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_Byte"
//
// Visualiza el byte pasado como par�metro, pero en caso de que el nibble alto
// sea cero visualiza en su lugar un espacio en blanco.
// Por ejemplo si 0B10101110 visualiza "AE"
// y si 0B00001110, visualiza " E" (un espacio blanco delante).
//------------------------------------------------------------------------------
void LCD_EnviaByte( uint8_t Byte )
{
    Byte & 0xF0 ? LCD_EnviaNibble( Byte >> 4 ) : LCD_EnviaCaracter( ' ' );
    LCD_EnviaNibble( Byte );
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_ByteCompleto"
//
// Visualiza el byte pasado como par�metro en el lugar actual de la pantalla.
// Por ejemplo, si 0B10101110 visualiza "AE".
//------------------------------------------------------------------------------
void LCD_EnviaByteCompleto( uint8_t Byte )
{
    LCD_EnviaNibble( Byte >> 4 );
    LCD_EnviaNibble( Byte );
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_Nibble"
//
// Visualiza en el lugar actual de la pantalla, el valor hexadecimal que almacena
// en el nibble bajo. El nibble alto no es tenido en cuenta. Ejemplos:
// - Si 0B01010110, se visualizar� "6". 
// - Si 0B10101110, se visualizar� "E". 
//------------------------------------------------------------------------------
void LCD_EnviaNibble( uint8_t Byte )
{
    Byte &= 0x0F;
    if( Byte < 10 ) LCD_EnviaCaracter( Byte + '0' );
    else            LCD_EnviaCaracter( Byte + 'A' - 10 );
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_Port"
//
// Coloca Dato en el puerto de Datos del LCD. 
//------------------------------------------------------------------------------
void LCD_Port( uint8_t Dato )
{
    LCD_PinD7 = (Dato & 0x80) ? 1 : 0;
    LCD_PinD6 = (Dato & 0x40) ? 1 : 0;
    LCD_PinD5 = (Dato & 0x20) ? 1 : 0;
    LCD_PinD4 = (Dato & 0x10) ? 1 : 0;
    LCD_PinD3 = (Dato & 0x08) ? 1 : 0;
    LCD_PinD2 = (Dato & 0x04) ? 1 : 0;
    LCD_PinD1 = (Dato & 0x02) ? 1 : 0;
    LCD_PinD0 = (Dato & 0x01) ? 1 : 0;
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_CfgPort"
//
// Emplea Cfg para configurar las l�neas usadas para controlar las l�neas de
// Datos del LCD. 
//------------------------------------------------------------------------------
void LCD_CfgPort( uint8_t Cfg )
{
    LCD_CfgPinD7 = (Cfg & 0x80) ? 1 : 0;
    LCD_CfgPinD6 = (Cfg & 0x40) ? 1 : 0;
    LCD_CfgPinD5 = (Cfg & 0x20) ? 1 : 0;
    LCD_CfgPinD4 = (Cfg & 0x10) ? 1 : 0;
    LCD_CfgPinD3 = (Cfg & 0x08) ? 1 : 0;
    LCD_CfgPinD2 = (Cfg & 0x04) ? 1 : 0;
    LCD_CfgPinD1 = (Cfg & 0x02) ? 1 : 0;
    LCD_CfgPinD0 = (Cfg & 0x01) ? 1 : 0;
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_ShiftRight"
//
// Efecto de corrimiento a la derecha del mensaje en pantalla. 
//------------------------------------------------------------------------------
void LCD_ShiftRight( void )
{
	LCD_EnviaComando( 0x01 );
	LCD_EnviaComando( 0x0C );
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Funci�n "LCD_ShiftLeft"
//
// Efecto de corrimiento a la izquierda del mensaje en pantalla. 
//------------------------------------------------------------------------------
void LCD_ShiftLeft( void )
{
	LCD_EnviaComando( 0x01 );
	LCD_EnviaComando( 0x08 );
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
