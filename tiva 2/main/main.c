#include "port.h"
#include "dio.h"
#include "pwm.h"
#include "adc_init.h"
#include "uart.h"
#include "temp.h"
#include "motor.h"
int x=0;
int y=0;

void SystemInit(){}
int __main()
{
	UART5_init();
	ADC_Init();
		
	char send[]={'2','4','.','1','#'};
	stepper_setup();
	uint8_t receive[4];
	UART5_init();
	while(1)
	{   //display temperature on the LCD
		float temp=Temp_init();
		int intPart = temp ; 
		float floatPart = temp - intPart ;
		int units = intPart % 10 ;
		intPart = intPart / 10 ;
		int tens = intPart % 10 ;
		int decimal = floatPart * 10 ;

		char Units = units + '0' ;
		char Tens = tens + '0' ;
		char Decimal = decimal + '0' ;
		send[0]=Tens;
		send[1]=Units;
		send[3]=Decimal;
		UART_sendString(send);
		delayMs(500);
		
		
		

		UART_receiveString(receive);
		if(receive[0]=='A')              //move the steeper motor 30 degrees to the right
		{
			for(x=0;x<85;x++)
			{
				movestepperright();
			}
		}
		else if(receive[0]=='B')         //move the steeper motor 30 degrees to the left
		{
			for(y=0;y<85;y++)
			{
				movestepperleft();
			}
		}
		else  //control brightness of the the led
		{
			PWM_init();
			int receive1 = receive [0] - '0' ;
			int receive2 = receive [1] - '0' ;
			int receive3 = receive [2] - '0' ;
			int receive4 = receive [3] - '0' ;
			int receiveTotal = receive4 * 1000 + receive3 * 100 + receive2 * 10 + receive1 ;
			PWM_setDuty(receiveTotal);
		}
	}
	return 0;
}
	