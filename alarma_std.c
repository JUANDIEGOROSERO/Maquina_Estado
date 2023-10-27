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

void function_alarma(void){
    
    LCD_Clear();
    LCD_String_xy(0,0,"std_Alarma");
    color(1,0,0);
    __delay_ms(500);

}

