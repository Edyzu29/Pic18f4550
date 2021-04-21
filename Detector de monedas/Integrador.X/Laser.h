/* 
 * File:   Laser.h
 * Author: EDWIN
 *
 * Created on 14 de junio de 2019, 11:43 AM
 */

#ifndef LASER_H
#define	LASER_H

//Declarando Constantes
#define Tris_Laser     TRISDbits.RD2
#define Start_Laser    T0CONbits.TMR0ON
#define Laser_Flag     INTCONbits.TMR0IF
#define Laser_Switch   INTCONbits.TMR0IE

#define Laser_Pin      PORTDbits.RD2

#define Offset        7 

//Declarando Variables
    int diametro=0;

//Declarando funciones
    void Confi_laser(void);
    int Laser_TMR(void);

#endif	/* LASER_H */