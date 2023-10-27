#include <xc.h>
#include <PIC16F887.h>
#include <stdio.h>  
#include <string.h>

#include "CONFIG.h"
#include "KEYPAD.h"
#include "LCD.h"
#include "color_rgb.h"
#include "sensor.h"
#include "Seguridad.h"
#include "Bloqueo.h"
#include "Monitoreo.h"
#include "Alarma.h"

void function_bloqueado(void){

    LCD_Clear();
    LCD_String_xy(0,0,"SISTEMA BLOQUEADO");
    color(1,0,0);
    __delay_ms(2000);

    char buffer [17];
    unsigned char n=5;

    for (n=5; n>0; n--)
    {
    sprintf (buffer,"INTENTO EN: %ds", n);
    __delay_ms(1000);
    }

    LCD_Clear();
    LCD_String_xy(0,0,"SIGUIENTE");
    LCD_String_xy(1,0,buffer);

}

