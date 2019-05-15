#include "stdint.h"
#include "tm4c123gh6pm.h"

void ADC_Init(void)
{
	 volatile unsigned long delay;
   SYSCTL_RCGC0_R |=  0x00010000; // activate ADC0
   delay=SYSCTL_RCGC2_R; // wait for clock to become stable
   SYSCTL_RCGC0_R &= ~0x00000300; // default sampling value of 125k
   ADC0_SSPRI_R   &= ~0xF000; // priority of seqiencer 3 is highest
	 ADC0_ACTSS_R   &= ~0x8; // disable ss3
   ADC0_EMUX_R    &= ~0xF000; //software trigger
   ADC0_SSMUX3_R   =  0x0; // input from channel 0
   ADC0_SSCTL3_R  |=  0x0E; // enable Temperature sensor
   ADC0_ACTSS_R   |=  0x8; // enable ADC0 sequencer3

}

/*
enable clocks
choose sequencer
choose software trigger 
set ADC CTL  "ADCSSCCTL3" and enable temp sensor
enable sequencer
start conversion
wait and take value
*/