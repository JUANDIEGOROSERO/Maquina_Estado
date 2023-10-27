#include    <xc.h>
#include    <pic16f887.h>
#include    <stdio.h>
#include    <string.h>

#include    "config.h"
#include    "canal.h"
#include    "poten.h"
#include    "temperatura.h"
#include    "LCD.h"

int Termometro;
int Fotocelda;
int Fuego;

int TempC;

char buffer [17];

void function_monitoreo_ambiente(void) {
    
    //OSCCON = 0b01110001;
    OSCCON = 0x71;
    TRISD = 0x00;// salida puerto D
    
    
    TRISA0 = 1; // si es 0 es salida si es 1 es entrada
    TRISA1 = 1;
    TRISA5 = 1;
    
    ANSEL = 0x01; //  Configura el Puerto como Entrada Analógica.
    
    adc_begin();
    LCD_Init();
    LCD_String_xy(0,0,"cond ambientales");
    
    __delay_ms(2000);
    //ADCON1 = 0X00; otra maneera de asignar lo anrterior
    



    //............................. CICLO INFINITO .............................
    
    while (1) {
   
        Termometro = adc_conversion(0); // Se visualiza la respuesta de adresh  en port d
        
        Fotocelda  = adc_conversion(1);
        
        Fuego      = adc_conversion(4);
        
        TempC = convertir_temperatura(Termometro);
        
        int n = sprintf(buffer, "Tm=%d,Ft=%d,Fg=%d", TempC, Fotocelda, Fuego);
        
        LCD_String_xy(1,0,buffer);
        
        __delay_ms(500);
        
    }
    return TempC;
    //..........................................................................
}

