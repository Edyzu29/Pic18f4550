/* 
 * File:   Confi.h
 * Author: EDWIN
 *
 * Created on 12 de junio de 2019, 01:55 PM
 */

#ifndef  CONFI_H
#define CONFI_H

#include <stdint.h>

/* Constantes y macros */
#define Tris_Led       TRISDbits.RD0
#define Led                PORTDbits.RD0

#define _XTAL_FREQ 8000000
//Declarar Variables
    
//Declarar funciones
void Inicializacion (void);
uint32_t Division_entera_up(uint32_t dividendo, uint32_t divisor);
void Led_Twinkle (void);

#endif	/* CONFI_H */

