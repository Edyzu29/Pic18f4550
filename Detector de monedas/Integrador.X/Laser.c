#include <xc.h>
#include <stdint.h>
#include "Laser.h"

//Funciones
void Confi_laser(void){
    INTCONbits.GIE=1;     //Acticar las Interrupciones
    Laser_Switch=1;       //Activar la interuccion del TM0
    Laser_Flag=0;         //Configurar labandeira del TM0

    TMR0=256-Offset;           //Setear al TMR0 para que 
    T0CONbits.T08BIT=1;   //Timer de 8bits
    T0CONbits.PSA=0;      //Activar el Pre-escalador
    T0CONbits.T0CS=1;     //Elejir el Oscilador(Externo)
    T0CONbits.T0SE=0;     //flaco de subida
    T0CONbits.T0PS=0b010; //Pre-escalador de 16
    Start_Laser=0;        //Detener el TMR0
    
    Tris_Laser=1;
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
int Laser_TMR (void){
    diametro=0;
    while(Laser_Pin==0){
        if(Laser_Flag==1){TMR0+=256-7; Laser_Flag=0; diametro++;}}
    Start_Laser=0;
    return diametro;
}