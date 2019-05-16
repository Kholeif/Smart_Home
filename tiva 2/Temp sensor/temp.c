#include"temp.h"


float Temp_init(void)
{
   volatile int ADC_Output = 0;
   volatile float temp_c = 0;

    ADC0_PSSI_R |= 0x8; // start conversion sequence 3
    while ((ADC0_RIS_R & 0x8) == 0); // wait for conversion to complete
    ADC_Output = ADC0_SSFIFO3_R & 0xFFF; // read conversion result
    temp_c = 147.5 - ((247.5*ADC_Output)/4096.0); 
    ADC0_ISC_R = 0x8; // clear completion flag
    delayMs(1000);
		return temp_c;
}

