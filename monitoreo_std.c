#include <xc.h>
#include <stdio.h>
#include <string.h>

#include "CONFIG.h"
#include "sensor.h"
#include "LCD.h"

unsigned char var_sensor_ir= 0;
unsigned char var_sensor_hall = 0;
unsigned char var_sensor_metal = 0;
char buffer [17];
unsigned char var_Sensor=0;

unsigned char function_monitoreo(void){

    var_sensor_ir =SENSOR_IR;
    var_sensor_hall =SENSOR_HALL;
    var_sensor_metal =SENSOR_METAL;
    if(monitoring_sensor()==1){
        sprintf(buffer,"ir=%d,hl=%d,mt=%d",var_sensor_ir,var_sensor_hall,var_sensor_metal);
        LCD_String_xy(0,0,buffer);
        __delay_ms(5000);
        LCD_Clear();
        LCD_String_xy(0,0,"Alarma Activada");
        var_Sensor=1;
    //__delay_ms(2000);
    }
return var_Sensor;
}