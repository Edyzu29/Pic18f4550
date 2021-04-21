/* 
 * File:   Valores_de_la_modeda.h
 * Author: EDWIN
 *
 * Created on 10 de julio de 2019, 05:52 PM
 */

#ifndef VALORES_DE_LA_MODEDA_H
#define	VALORES_DE_LA_MODEDA_H

/*Calibracion para la lectura de la curva*/
#define Umbral  420
#define N_MUESTRAS 100
#define Tiempo_entre_Muestras  5
/*----------------------------------------------------------------------------*/
/*Valores de la interaccion del campo magnetico con las monedas*/
#define Valor_bobina_sol        104
#define Valor_bobina_veinte     126
#define Valor_bobina_cincuenta  134
#define Valor_bobina_diez       152
#define Valor_bobina_dos        165
#define Valor_bobina_cinco      147
/*----------------------------------------------------------------------------*/
/*Valores de la interaccion del campo magnetico con las monedas*/
#define Valor_laser_sol        
#define Valor_laser_veinte     
#define Valor_laser_cincuenta  
#define Valor_laser_diez       
#define Valor_laser_dos        
#define Valor_laser_cinco      
/*----------------------------------------------------------------------------*/
/*Errores*/
#define Laser_Error             6
#define Bobina_Error            6
/*----------------------------------------------------------------------------*/
/*Funciones de la bobina*/
uint8_t Detecta_Cambio       (uint16_t);
uint8_t Comprobar_Sol        (uint16_t,uint16_t);
uint8_t Comprobar_Dos        (uint16_t,uint16_t);
uint8_t Comprobar_Cinco      (uint16_t,uint16_t);
uint8_t Comprobar_Diez       (uint16_t,uint16_t);
uint8_t Comprobar_Veinte     (uint16_t,uint16_t);
uint8_t Comprobar_Cincuenta  (uint16_t,uint16_t);
/*----------------------------------------------------------------------------*/
/*Funciones del laser*/
void Interrupcion_Laser (void);
/*----------------------------------------------------------------------------*/
/*Variables*/
uint8_t Caida;
uint8_t Que_Moneda;
/*----------------------------------------------------------------------------*/
/*Banderas de Laser*/
#define Laser_Pin   INTCONbits.INT0F
#define Laser_Tris  TRISBbits.RB0
/*----------------------------------------------------------------------------*/
#endif	/* VALORES_DE_LA_MODEDA_H */

