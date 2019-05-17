#include <MCAL.h>

Port_Init(PORTF);
Port_SetPinDirection(PORTF,0x11,PORT_PIN_IN);
Port_SetPinPullUp(PORTF,0x11,1);

if ((GPIO_PORTF_DATA_R |= 0x11) == 0x01)
{
	UART_sendByte(A);
}
ele if ((GPIO_PORTF_DATA_R |= 0x11) == 0x10)
{
	UART_sendByte(B);
}
