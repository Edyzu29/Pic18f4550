#include <xc.h>
#include <stdint.h>
#include "Ser.h"

//Declarion de variables
  int i;

//Funciones
void Confi_Servo(void){
    Servo_Diez_Tris=0;
    Servo_Veinte_Tris=0;
    Servo_Cincuenta_Tris=0;
    Servo_Sol_Tris=0;
    Servo_Dos_Tris=0;
    Servo_Cinco_Tris=0;
    
    Servo_Fake_Tris=0;
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
 void Servo_Fake_0 (void){
             for(int i=0;i<16;i++){
            Servo_Fake=0;
            Servo_Fake=1;
            __delay_ms(g0);
            Servo_Fake=0;
            __delay_ms(20-g0);}
    }
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
  void Servo_Fake_45 (void){
             for(int i=0;i<16;i++){
            Servo_Fake=0;
            Servo_Fake=1;
            __delay_ms(g45);
            Servo_Fake=0;
            __delay_ms(20-g45);}
    }
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/ 
void Servo_Fake_90 ( void){
             for(int i=0;i<16;i++){
            Servo_Fake=0;
            Servo_Fake=1;
            __delay_ms(g90);
            Servo_Fake=0;
            __delay_ms(20-g90);}
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Servo_Fake_135 (void){
             for(int i=0;i<16;i++){
            Servo_Fake=0;
            Servo_Fake=1;
            __delay_ms(g135);
            Servo_Fake=0;
            __delay_ms(20-g135);}
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Servo_Fake_180 (void){
    for(int i=0;i<16;i++){
            Servo_Fake=0;
            Servo_Fake=1;
            __delay_ms(g180);
            Servo_Fake=0;
            __delay_ms(20-g180);}    
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
 void Servo_Sol_0 (void){
             for(int i=0;i<16;i++){
            Servo_Sol=0;
            Servo_Sol=1;
            __delay_ms(g0);
            Servo_Sol=0;
            __delay_ms(20-g0);}
    }
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
  void Servo_Sol_45 (void){
             for(int i=0;i<16;i++){
            Servo_Sol=0;
            Servo_Sol=1;
            __delay_ms(g45);
            Servo_Sol=0;
            __delay_ms(20-g45);}
    }
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/ 
void Servo_Sol_90 ( void){
             for(int i=0;i<16;i++){
            Servo_Sol=0;
            Servo_Sol=1;
            __delay_ms(g90);
            Servo_Sol=0;
            __delay_ms(20-g90);}
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Servo_Sol_135 (void){
             for(int i=0;i<16;i++){
            Servo_Sol=0;
            Servo_Sol=1;
            __delay_ms(g135);
            Servo_Sol=0;
            __delay_ms(20-g135);}
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Servo_Sol_180 (void){
    for(int i=0;i<16;i++){
            Servo_Sol=0;
            Servo_Sol=1;
            __delay_ms(g180);
            Servo_Sol=0;
            __delay_ms(20-g180);}    
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
 void Servo_Dos_0 (void){
             for(int i=0;i<16;i++){
            Servo_Dos=0;
            Servo_Dos=1;
            __delay_ms(g0);
            Servo_Dos=0;
            __delay_ms(20-g0);}
    }
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
  void Servo_Dos_45 (void){
             for(int i=0;i<16;i++){
            Servo_Dos=0;
            Servo_Dos=1;
            __delay_ms(g45);
            Servo_Dos=0;
            __delay_ms(20-g45);}
    }
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/ 
void Servo_Dos_90 ( void){
             for(int i=0;i<16;i++){
            Servo_Dos=0;
            Servo_Dos=1;
            __delay_ms(g90);
            Servo_Dos=0;
            __delay_ms(20-g90);}
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Servo_Dos_135 (void){
             for(int i=0;i<16;i++){
            Servo_Dos=0;
            Servo_Dos=1;
            __delay_ms(g135);
            Servo_Dos=0;
            __delay_ms(20-g135);}
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Servo_Dos_180 (void){
    for(int i=0;i<16;i++){
            Servo_Dos=0;
            Servo_Dos=1;
            __delay_ms(g180);
            Servo_Dos=0;
            __delay_ms(20-g180);}    
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
 void Servo_Cinco_0 (void){
             for(int i=0;i<16;i++){
            Servo_Cinco=0;
            Servo_Cinco=1;
            __delay_ms(g0);
            Servo_Cinco=0;
            __delay_ms(20-g0);}
    }
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
  void Servo_Cinco_45 (void){
             for(int i=0;i<16;i++){
            Servo_Cinco=0;
            Servo_Cinco=1;
            __delay_ms(g45);
            Servo_Cinco=0;
            __delay_ms(20-g45);}
    }
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/ 
void Servo_Cinco_90 ( void){
             for(int i=0;i<16;i++){
            Servo_Cinco=0;
            Servo_Cinco=1;
            __delay_ms(g90);
            Servo_Cinco=0;
            __delay_ms(20-g90);}
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Servo_Cinco_135 (void){
             for(int i=0;i<16;i++){
            Servo_Cinco=0;
            Servo_Cinco=1;
            __delay_ms(g135);
            Servo_Cinco=0;
            __delay_ms(20-g135);}
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Servo_Cinco_180 (void){
    for(int i=0;i<16;i++){
            Servo_Cinco=0;
            Servo_Cinco=1;
            __delay_ms(g180);
            Servo_Cinco=0;
            __delay_ms(20-g180);}    
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
 void Servo_Cincuenta_0 (void){
             for(int i=0;i<16;i++){
            Servo_Cincuenta=0;
            Servo_Cincuenta=1;
            __delay_ms(g0);
            Servo_Cincuenta=0;
            __delay_ms(20-g0);}
    }
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
  void Servo_Cincuenta_45 (void){
             for(int i=0;i<16;i++){
            Servo_Cincuenta=0;
            Servo_Cincuenta=1;
            __delay_ms(g45);
            Servo_Cincuenta=0;
            __delay_ms(20-g45);}
    }
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/ 
void Servo_Cincuenta_90 ( void){
             for(int i=0;i<16;i++){
            Servo_Cincuenta=0;
            Servo_Cincuenta=1;
            __delay_ms(g90);
            Servo_Cincuenta=0;
            __delay_ms(20-g90);}
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Servo_Cincuenta_135 (void){
             for(int i=0;i<16;i++){
            Servo_Cincuenta=0;
            Servo_Cincuenta=1;
            __delay_ms(g135);
            Servo_Cincuenta=0;
            __delay_ms(20-g135);}
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Servo_Cincuenta_180 (void){
    for(int i=0;i<16;i++){
            Servo_Cincuenta=0;
            Servo_Cincuenta=1;
            __delay_ms(g180);
            Servo_Cincuenta=0;
            __delay_ms(20-g180);}    
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
 void Servo_Veinte_0 (void){
             for(int i=0;i<16;i++){
            Servo_Veinte=0;
            Servo_Veinte=1;
            __delay_ms(g0);
            Servo_Veinte=0;
            __delay_ms(20-g0);}
    }
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
  void Servo_Veinte_45 (void){
             for(int i=0;i<16;i++){
            Servo_Veinte=0;
            Servo_Veinte=1;
            __delay_ms(g45);
            Servo_Veinte=0;
            __delay_ms(20-g45);}
    }
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/ 
void Servo_Veinte_90 ( void){
             for(int i=0;i<16;i++){
            Servo_Veinte=0;
            Servo_Veinte=1;
            __delay_ms(g90);
            Servo_Veinte=0;
            __delay_ms(20-g90);}
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Servo_Veinte_135 (void){
             for(int i=0;i<16;i++){
            Servo_Veinte=0;
            Servo_Veinte=1;
            __delay_ms(g135);
            Servo_Veinte=0;
            __delay_ms(20-g135);}
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Servo_Veinte_180 (void){
    for(int i=0;i<16;i++){
            Servo_Veinte=0;
            Servo_Veinte=1;
            __delay_ms(g180);
            Servo_Veinte=0;
            __delay_ms(20-g180);}    
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
 void Servo_Diez_0 (void){
             for(int i=0;i<16;i++){
            Servo_Diez=0;
            Servo_Diez=1;
            __delay_ms(g0);
            Servo_Diez=0;
            __delay_ms(20-g0);}
    }
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
  void Servo_Diez_45 (void){
             for(int i=0;i<16;i++){
            Servo_Diez=0;
            Servo_Diez=1;
            __delay_ms(g45);
            Servo_Diez=0;
            __delay_ms(20-g45);}
    }
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/ 
void Servo_Diez_90 ( void){
             for(int i=0;i<16;i++){
            Servo_Diez=0;
            Servo_Diez=1;
            __delay_ms(g90);
            Servo_Diez=0;
            __delay_ms(20-g90);}
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Servo_Diez_135 (void){
             for(int i=0;i<16;i++){
            Servo_Diez=0;
            Servo_Diez=1;
            __delay_ms(g135);
            Servo_Diez=0;
            __delay_ms(20-g135);}
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Servo_Diez_180 (void){
    for(int i=0;i<16;i++){
            Servo_Diez=0;
            Servo_Diez=1;
            __delay_ms(g180);
            Servo_Diez=0;
            __delay_ms(20-g180);}    
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Servo_Posicion_Inicial (void){
    Servo_Fake_0();
    Servo_Diez_0();
    Servo_Veinte_0();
    Servo_Cincuenta_0();
    Servo_Sol_0();
    Servo_Dos_0();
    Servo_Cinco_0();
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Dam_Dinero (uint8_t Numero_de_monedas,uint8_t money){
    switch(money){
        
        case 1:     // 0.10 centimos
            for(int i=0; i<Numero_de_monedas;i++){
                Servo_Diez_0();
                Servo_Diez_90();
            }
        break;      
        
        case 2:     //0.20 centimos
            for(int i=0; i<Numero_de_monedas;i++){
                Servo_Veinte_0();
                Servo_Veinte_90();
            }
        break;
        
        case 3:     //0.50 centimos
            for(int i=0; i<Numero_de_monedas;i++){
                Servo_Cincuenta_0();
                Servo_Cincuenta_90();
            }
        break;
        
        case 4:     //1.00 soles
            for(int i=0; i<Numero_de_monedas;i++){
                Servo_Sol_0();
                Servo_Sol_90();
            }
        break;
        
        case 5:     //2.00 soles
            for(int i=0; i<Numero_de_monedas;i++){
                Servo_Dos_0();
                Servo_Dos_90();
            }
        break;
        
        case 6:     //5.00 soles
            for(int i=0; i<Numero_de_monedas;i++){
                Servo_Cinco_0();
                Servo_Cinco_90();
            }
        break;
    }
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void Moneda_Fake (void){
        Servo_Fake_0();
        Servo_Fake_90();
}