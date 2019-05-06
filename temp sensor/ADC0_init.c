#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "LCD_init.h"
void ADC_Init(void)
{
		volatile unsigned long delay;
	SYSCTL_RCGC0_R |= 0x00010000; //Activate ADC0 bit 16 of RCGC reg
	delay = SYSCTL_RCGC2_R; //allow time for clock
	SYSCTL_RCGC0_R &= ~0x00000300;
ADC0_SSPRI_R &= ~0xF000; /*set priority of sequencer 3 the highest one ZEROS at bits 15:12*/
ADC0_ACTSS &= ~0x8; /* disable SS3 during configuration */
ADC0_EMUX &= ~0xF000; /* software trigger conversion */
ADC0_SSMUX3 = 0x0; /* get input from channel 0 */
ADC0_SSCTL3 |= 0x0E; /* take one sample at a time, set flag at 1st sample */
ADC0_ACTSS |= 0x8; /* enable ADC0 sequencer 3 */
}