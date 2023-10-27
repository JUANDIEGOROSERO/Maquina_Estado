#include <xc.h>
#include <PIC16F887.h>
#include <stdio.h>  
#include <string.h>

#include "CONFIG.h"
#include "KEYPAD.h"
#include "LCD.h"
#include "color_rgb.h"

unsigned char intento = 3;
const char password[4] ={'1','9','0','9'};
char pass_user[4];

unsigned char funcion_seguridad (void){
        char key = '0';
        unsigned char idx  = 0;
        /*para que sean solo 3 intentos en la conntraseña creamos una bandera*/ 
        unsigned char n = 0;
        
        LCD_Clear();
        LCD_String_xy(0,0,"Ingresar clave");
        LCD_Command(0xC0); 
        
        do{
            key = keypad_getkey();
            if(key != 0){
                LCD_Char('*');/* display pressed key on LCD16x2 */
                //LCD_Char(key);/* display pressed key on LCD16x2 */
                pass_user[idx++] = key;
            }
            __delay_ms(100);
        }while(idx < 4);
        
        if(strncmp(pass_user,password,4)==0){
            LCD_Clear();
            LCD_String_xy(0,0,"Clave Correcta");
            color(0,1,0);
            n=1;
        }
        else{
            if(intento > 1){
                LCD_Clear();
                LCD_String_xy(0,0,"Clave Incorrecta");
                color(0,0,1);
                __delay_ms(2000);
                LCD_Clear();
                LCD_String_xy(0,0,"intente otravez");
                intento--; 
                n=0;
            }
            else{
                LCD_Clear();
                n=2;
            }
        }
        __delay_ms(2000);
        return n;

}
