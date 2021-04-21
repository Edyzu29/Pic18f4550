/* 
 * File:   bluetooth.h
 * Author: EDWIN
 *
 * Created on 16 de junio de 2019, 02:06 PM
 */

#ifndef BLUE_H
#define	BLUE_H


#define _XTAL_FREQ 20000000UL
#define Baudios 38

//Seteo de Pines
#define Tris_Rx     TRISCbits.RC7
#define Tris_Tx     TRISCbits.RC6

//Funciones
void Tx_str(char);
void Tx_num(uint8_t);
char Rx(void);
void Confi_Blue (void);
void UART0_Tx_String(char *str);
void UART0_Tx_Integer(int32_t num);

#endif	/* BLUETOOTH_H */