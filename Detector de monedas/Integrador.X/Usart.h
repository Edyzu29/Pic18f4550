/* 
 * File:   Usart.h
 * Author: EDWIN
 *
 * Created on 7 de julio de 2019, 01:31 AM
 */

#ifndef USART_H
#define	USART_H

#define Baudios 520

//Seteo de Pines
#define Tris_Rx     TRISCbits.RC7
#define Tris_Tx     TRISCbits.RC6

//Funciones
void Tx_char(char);
void Tx_num(uint8_t);
char Rx(void);
void Confi_Blue (void);
void UART0_Tx_String(char *str);
void UART0_Tx_Integer(int32_t num);

#endif	/* USART_H */

