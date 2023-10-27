#include    <xc.h>
#include    <pic16f887.h>
#include    <math.h>

#include    "config.h"

#define beta 4090

int convertir_temperatura(int temperatura){
    long a =1023 -temperatura;
    float tempC = (float) (beta/(log((1025.0*10/a-10)/10) + beta/298.0)- 273.0);
    
    float tempF = (float) (tempC + 273.15);
    
    return (int)tempC;
}
