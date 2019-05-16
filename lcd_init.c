//PA5 -> RS
// PA6 -> RW
// PA7 -> EN

// Port B for Data

#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "LCD_init.h"
#include "delay_ms.h"
#include "delay_us.h"

#define RS 0x20 //portA Bit5 mask
#define RW 0x40 //portA Bit6 mask
#define EN 0x80 //portA Bit7 mask
void LCD_command(unsigned char command)
{
GPIO_PORTA_DATA_R = 0; /* RS = 0, R/W = 0 */
GPIO_PORTB_DATA_R = command;
GPIO_PORTA_DATA_R = EN; /* pulse E */
delayUs(1);
GPIO_PORTA_DATA_R  = 0;
if (command < 4)
delayMs(2); /* command 1 and 2 needs up to 1.64ms */
else
delayUs(40); /* all others 40 us */
}

void LCD_data(unsigned char data)
{
GPIO_PORTA_DATA_R = RS; /* RS = 1, R/W = 0 */
GPIO_PORTB_DATA_R = data;
GPIO_PORTA_DATA_R = EN | RS; /* pulse E */
delayUs(0);
GPIO_PORTA_DATA_R = 0;
delayUs(40);
}

void LCD_Init(void)
{
SYSCTL_RCGCGPIO_R |= 0x02; /* enable clock to GPIOB */
SYSCTL_RCGCGPIO_R |= 0x01; /* enable clock to GPIOA */
GPIO_PORTA_DIR_R = 0xE0; /* set all PORTA pins as output */
GPIO_PORTA_DEN_R = 0xE0; /* set all PORTA pins as digital pins */
GPIO_PORTB_DIR_R = 0xFF; /* set all PORTB pins as output */
GPIO_PORTB_DEN_R = 0xFF; /* set all PORTB pins as digital pins */

delayMs(20); /* initialization sequence */
LCD_command(0x30);
delayMs(5);
LCD_command(0x30);
delayUs(100);
LCD_command(0x30);


LCD_command(0x38); /* set 4-bit data, 2-line, 5x7 font */
LCD_command(0x06); /* move cursor right */
LCD_command(0x01); /* clear screen, move cursor to home */
LCD_command(0x0F); /* turn on display, cursor blinking */
}








