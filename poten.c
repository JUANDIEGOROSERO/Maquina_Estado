#include    <xc.h>
#include    <pic16f887.h>
#include    "config.h"
#include    "canal.h"

int poten(int Vadc){
    
    
    int V_real = (Vadc*5)/1023;
    return V_real;
    
}
