#include    <xc.h>
#include    <pic16f887.h>
#include    "config.h"

void adc_begin(void){
    
    ADCON1bits.ADFM  = 0;       //  Justificación Izquierda (modo-8bits).
    ADCON1bits.VCFG0 = 0;       //  Selecciona Voltajes de Referencia (5v-0v).
    ADCON1bits.VCFG1 = 0;       //  Selecciona Voltajes de Referencia (5v-0v). 
    ADCON0bits.ADCS  = 0b01;    //  Tiempo de conversion Fosc/8.
}

int adc_conversion(int channel){
        
        ADCON0bits.CHS = (0x0f & channel);
        ADCON0bits.ADON = 1; //  Habilita el Módulo AD.
        __delay_us(30);
        ADCON0bits.GO = 1; //  Inicia la COnversió AD.
        while (ADCON0bits.GO); //  Espera a que termine la conversión AD.
        ADCON0bits.ADON = 0; //  Habilita el Módulo AD.
        
        return ADRESH;
}