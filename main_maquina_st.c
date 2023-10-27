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

//Asignacion de cada uno de los estados en la variable State
enum State {
    Seguridad,      // Se asigna 0
    Monitoreo,      // Se asigna 1
    Bloqueado,      // Se asigna 2
    Alarma,          // Se asigna 3
    Sensor
};

enum State Estado;
//:::::::::::::::: ASIGNACION DE PROCESOS EN MAQUINA DE ESTADOS ::::::::::::::::

void main(){

OSCCON = 0x71; //Configura oscilador interno (FOSC = 8Mhz)
ANSEL = 0;

LCD_Init();
keypad_init();

TRISC = 0x07;

Estado = Seguridad;
while(1){
//.............................. ESTADO SEGURIDAD ..............................
    if (Estado==Seguridad){
        unsigned char n = funcion_seguridad();
        if (n==1){
            Estado = Monitoreo;
        }
        else if(n==2){
            Estado = Bloqueado;
        }
        else{
            Estado = Seguridad;
        }
    }
    
//.............................. ESTADO BLOQUEADO ..............................

    else if(Estado == Bloqueado){
        function_bloqueado();
        Estado = Seguridad;
        }
    
//.............................. ESTADO MONITOREO ..............................
    else if(Estado == Monitoreo){
        unsigned char m = function_monitoreo();
        if (m ==1){
            Estado = Alarma; //m es una bandera que dice si los sensores estan activos 
        }
        else{
            Estado = Monitoreo;
        }
        //delay par el cambio de estado
        //Estado = Sensores;
    }

//........................ ESTADO ALARMA SEGURIDAD .............................
    
        else if(Estado == Alarma){
            function_alarma();
            
            Estado=Monitoreo;
    }
//............................... ESTADO SENSORES ..............................
    
        else if(Estado == Sensor){
            int temp = function_monitoreo_ambiente();
            //delay para devuelta
            Estado=Monitoreo;
    }

//..............................................................................
    
        else{
        
        }
//..............................................................................
    }
}


