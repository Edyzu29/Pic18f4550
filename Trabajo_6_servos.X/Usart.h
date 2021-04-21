/* 
 * File:   Usart.h
 * Author: EDWIN
 *
 * Created on 7 de julio de 2019, 01:31 AM
 */

#ifndef USART_H
#define	USART_H
#include <stdint.h>

//Seteo de Pines
#define Tris_Rx     TRISCbits.RC7
#define Tris_Tx     TRISCbits.RC6

//Interrupciones
#define Tx_flag       PIR1bits.TXIF
#define Tx_switch    PIE1bits.TXIE
#define Tx_priority IPR1bits.TXIP

#define Rx_flag       PIR1bits.RCIF
#define Rx_switch    PIE1bits.RCIE
#define Rx_priority IPR1bits.RCIP

//Funciones
void Tx_str(char);
void Tx_num(uint8_t);
char Rx(void);
void Confi_Blue (void);
void UART0_Tx_String(char *str);
void UART0_Tx_Integer(int32_t num);
void Interrupciones_Usart(uint8_t priority); // 1 --> high  0 --> low (solo Recepción)
   

#endif	/* USART_H */

