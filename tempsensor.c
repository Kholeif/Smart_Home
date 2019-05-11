
#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "lCD_init.c"
#include "Delay_ms.c"
#include "uart0_portA_init.c"
#include "intochar.c"

SystemInit(void)
{

}



int main(void)
{
    volatile long ADC_Output=0;
     volatile long temp_c=0;
     uart_init();
        LCD_Init();


LCD_data('T');LCD_data('e');LCD_data('m');LCD_data('p');LCD_data('e');LCD_data('r');
LCD_data('');LCD_data('I');LCD_data('s');LCD_data('= ');LCD_command(0x0C);LCD_data(" ");LCD_data(" C");


    

    while((UART6_FR_R & 0x10) != 0); /* wait until the buffer is not empty */
    GPIO_PORTB_DATA_R = UART6_DR_R; /* read the received data */






ADC_Output = GPIO_PORTB_DATA_R ;
temp_c = 147.5 - ((247.5*ADC_Output) / 4096 ) ;
LCD_command (0xC4);
// LCD_Convert_Long_to_char(temp_c);
intTochar(temp_c);


}









