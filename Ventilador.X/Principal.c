// PIC12F675 Configuration Bit Settings
// 'C' source line config statements
// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
/*-----------------------------Librerias--------------------------------------*/
#include <xc.h>
#include <stdint.h>
#include "MiADC.h"
/*-----------------------------Variables y Constantes-------------------------*/

/*-----------------------------Funciones secundarias--------------------------*/
void Pines(void){
    ConfigADC();
    //Configuracion si in/out pines, pin AN3 siempre es entrada
    TRISIObits.TRISIO0=1;
    TRISIObits.TRISIO1=0;
    TRISIObits.TRISIO2=0;
    TRISIObits.TRISIO4=0;
    TRISIObits.TRISIO5=0;
    //Configuracion del oscilador como frecuencia normal
    OSCCALbits.CAL=0b100000;
    }
/*-----------------------------Funcion principal------------------------------*/
