
#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "LCD_init.h"
#include "delay_ms.h"
#include "uart0_portA_init.h"

SystemInit(void)
{

}
int main(void)
{
    volatile long ADC_Output=0;
     volatile long temp_c=0;
    ADC_Init();
        LCD_Init();


LCD_data('T');LCD_data('e');LCD_data('m');LCD_data('p');LCD_data('e');LCD_data('r');
LCD_data('');LCD_data('I');LCD_data('s');LCD_data('= ');LCD_command(0x0C);LCD_data(" ");LCD_data(" C");

while(1)
{
ADC0_PSSI_R |= 0x8; /* start a conversion sequence 3 */
while((ADC0_RIS_R & 0x8) == 0) ; /* wait for conversion complete */
ADC_Output = ADC0_SSFIFO3_R & 0xFFF;
temp_c = 147.5 - ((247.5*ADC_Output) / 4096 ) ;
LCD_command (0xC4);
// LCD_Convert_Long_to_char(temp_c);
ADC0_ISC_R = 0x8; /* clear completion flag */
sprintf(buffer, "\r\nTemp = %dF", temp_c);
UART0_puts(buffer);
delayMs(1000);
}

}









