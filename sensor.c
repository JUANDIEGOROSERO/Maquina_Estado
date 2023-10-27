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

unsigned char monitoring_sensor(void){
    unsigned char alarm_activ = 0;

    if(SENSOR_IR==1){
        alarm_activ=1;
    }
    if(SENSOR_HALL==1){
        alarm_activ=1;
    }
    if(SENSOR_METAL==1){
        alarm_activ=1;
    }   
    return alarm_activ;
}

