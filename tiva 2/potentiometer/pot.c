#include "pot.h"

void ADC_init (void)
{
	//enable clocks 
	SYSCTL_RCGCGPIO_R |= 0x10 ; // enable clock .. AIN0 on PE3
	SYSCTL_RCGCADC_R |= 0x1; // enable ADC0
	// initialize E3 for AIN0 input 
	GPIO_PORTE_AFSEL_R |= 0x8;
	GPIO_PORTE_DEN_R &= ~0x8;
	GPIO_PORTE_AMSEL_R |= 0x8;
	// initialize ADC0
	ADC0_ACTSS_R &= ~0x8; // disable ss3 
	ADC0_EMUX_R   &= ~0xF000; //software trigger
	ADC0_SSMUX3_R |= 0x0 ; //get input from channel 0
	ADC0_SSCTL3_R |= 0x6 ; // one input at a time
	ADC0_ACTSS_R |= 0x8; //enable ADC0 sequencer 3
	
}

int adcResult (void)
{
	volatile int result ;
  ADC0_PSSI_R |= 0x8; // start conversion sequence 3
	while ( (ADC0_RIS_R & 0x8) == 0 ); // wait for conversion
	result = ADC0_SSFIFO3_R ; // read result 
	ADC0_ISC_R = 0x8 ; // clear completion flag
	return result;
}
