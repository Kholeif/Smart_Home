

#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "lcd_init.c"



void intTochar(uint32_t y)
{
	int tenthousands;
	int thousands;
	int cents;
	int tens;
	int ones;
	
    if(y<=9){
        switch(y)
        {
            case 0:
                LCD_data('0');
                break;
            case 1:
                LCD_data('1');
                break;
            case 2:
                LCD_data('2');
                break;
            case 3:
                LCD_data('3');
                break;
            case 4:
                LCD_data('4');
                break;
            case 5:
                LCD_data('5');
                break;
            case 6:
                LCD_data('6');
                break;
            case 7:
                LCD_data('7');
                break;
            case 8:
                LCD_data('8');
                break;
            case 9:
                LCD_data('9');
                break;
        
        }
    }                                                       
    if(y<100 && y>=10)
    {
        tens=y/10;
        intTochar(tens);     // Recursive Function
        ones=y-(tens*10);
        intTochar(ones);
    }                                               
    if(y<1000 && y>=100)
    {
        cents=y/100;
            intTochar(cents);
        tens=(y-(cents*100))/10;
            intTochar(tens);
        ones=y-(cents*100)-(tens*10);
            intTochar(ones);
    }
    if(y<10000 && y>=1000)
    {
        thousands=y/1000;
            intTochar(thousands);
            cents=(y-(thousands*1000))/100;
            intTochar(cents);
        tens=(y-(thousands*1000)-(cents*100))/10;
            intTochar(tens);
        ones=y-(thousands*1000)-(cents*100)-(tens*10);
            intTochar(ones);
    }
    if(y<100000 && y>=10000)
    {
        tenthousands=y/10000;
            intTochar(tenthousands);
            thousands=(y-(tenthousands*10000))/1000;
            intTochar(thousands);
            cents=(y-(tenthousands*10000)-(thousands*1000))/100;
            intTochar(cents);
        tens=(y-(tenthousands*10000)-(thousands*1000)-(cents*100))/10;
            intTochar(tens);
        ones=y-(tenthousands*10000)-(thousands*1000)-(cents*100)-(tens*10);
            intTochar(ones);
    }
}