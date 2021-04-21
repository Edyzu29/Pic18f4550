/* 
 * File:   EEPROM.h
 * Author: EDWIN
 *
 * Created on 7 de junio de 2019, 11:07 AM
 */

#ifndef EEPROM_H
#define	EEPROM_H

//Declaracion de Funciones
void Save_float (float ,int);
void Save_8bits (int,int);
void GuardaBigDato (int,int);
int  Show_data (int);
void Guardafloat(int,float);
float SacaDatos(uint8_t );

//Declaracion de Variables
int j;

#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_H */

