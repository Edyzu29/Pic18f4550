#include "Confi.h"
#include <xc.h>
#include <stdint.h>
#include "MiADC.h"
#include "Usart.h"
#include "TMRs.h"
#include "Valores_de_la_modeda.h"
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*-----------------------------------Laser-------------------------------------------*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Interrupcion_Laser (void){
//    Laser_Tris=1;
//    Laser_Pin=0;
//    INTCONbits.INT0IE=1;
//    INTCON2bits.T0IP=1;
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*-------------------------------Campo Magnético-------------------------------------*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
uint8_t Detecta_Cambio(uint16_t varible){
 
    if(varible<Umbral)  Caida=1; 
    else    Caida=0;
   
    return Caida;
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
uint8_t Comprobar_Sol  (uint16_t Coin_Field,uint16_t Coin_Size){
   if(((Coin_Field>= Valor_bobina_sol - Bobina_Error)&&(Coin_Field<= Valor_bobina_sol + Bobina_Error ))/*&&((Coin_Size >= Valor_laser_sol - Laser_Error)&&(Coin_Size <= Valor_laser_sol + Laser_Error))*/){
            Que_Moneda=1;      
    }
    else {
            Que_Moneda=0;
    };
    return Que_Moneda;
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
uint8_t Comprobar_Dos  (uint16_t Coin_Field,uint16_t Coin_Size){
    if(((Coin_Field>= Valor_bobina_dos - Bobina_Error)&&(Coin_Field<= Valor_bobina_dos + Bobina_Error ))/*&&((Coin_Size >= Valor_laser_dos - Laser_Error)&&(Coin_Size <= Valor_laser_dos + Laser_Error)))*/){
            Que_Moneda=1;      
    }
    else {
            Que_Moneda=0;
    };
    return Que_Moneda;
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
uint8_t Comprobar_Cinco  (uint16_t Coin_Field,uint16_t Coin_Size){
    if(((Coin_Field>= Valor_bobina_cinco - Bobina_Error)&&(Coin_Field<= Valor_bobina_cinco + Bobina_Error ))/*&&((Coin_Size >= Valor_laser_cinco - Laser_Error)&&(Coin_Size <= Valor_laser_cinco + Laser_Error))*/){
           Que_Moneda=1;      
    }
    else {
            Que_Moneda=0;
    };
    return Que_Moneda;
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
uint8_t Comprobar_Diez  (uint16_t Coin_Field,uint16_t Coin_Size){
    if(((Coin_Field>= Valor_bobina_diez - Bobina_Error)&&(Coin_Field<= Valor_bobina_diez + Bobina_Error ))/*&&((Coin_Size >= Valor_laser_diez - Laser_Error)&&(Coin_Size <= Valor_laser_diez + Laser_Error))*/){
            Que_Moneda=1;      
    }
    else {
            Que_Moneda=0;
    };
    return Que_Moneda;
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
uint8_t Comprobar_Veinte  (uint16_t Coin_Field,uint16_t Coin_Size){
    if(((Coin_Field>= Valor_bobina_veinte - Bobina_Error)&&(Coin_Field<= Valor_bobina_veinte + Bobina_Error ))/*&&((Coin_Size >= Valor_laser_veinte - Laser_Error)&&(Coin_Size <= Valor_laser_veinte + Laser_Error))*/){
            Que_Moneda=1;      
    }
    else {
            Que_Moneda=0;
    };
    return Que_Moneda;
   
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
uint8_t Comprobar_Cincuenta  (uint16_t Coin_Field,uint16_t Coin_Size){
    if(((Coin_Field>= Valor_bobina_cincuenta - Bobina_Error)&&(Coin_Field<= Valor_bobina_cincuenta + Bobina_Error ))/*&&((Coin_Size >= Valor_laser_cincuenta - Laser_Error)&&(Coin_Size <= Valor_laser_cincuenta + Laser_Error))*/){
            Que_Moneda=1;      
    }
    else {
            Que_Moneda=0;
    };
    return Que_Moneda;
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/