#include "uart.h"

void UART7_init(void)
{
	SYSCTL_RCGCUART_R |= (1<<7); //Enable and provide a clock to UART module 7 in Run mode.
	while ((SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R4) == 0);


	SYSCTL_RCGCGPIO_R |=(1<<4); //Enable and provide a clock to GPIO Port E in Run mode.
	while ((SYSCTL_PRUART_R & SYSCTL_PRUART_R7) == 0);

 
	UART7_CTL_R &= ~UART_CTL_UARTEN; //Disable UART5
	
	UART7_IBRD_R=104;
	UART7_FBRD_R=11;
	
	UART7_LCRH_R |= (UART_LCRH_WLEN_8 );
		UART7_LCRH_R &= ~(UART_LCRH_FEN);
	
	UART7_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
	
	GPIO_PORTE_AFSEL_R |=((1<<0)|(1<<1)); //PE0,PE1 as RX , TX
	
	GPIO_PORTE_PCTL_R |= (GPIO_PORTE_PCTL_R&0xFFFFFF00) | (GPIO_PCTL_PE1_U7TX | GPIO_PCTL_PE0_U7RX); // putting values 1 in pmc 0 to activate uart7 in PE0,1 in pmc 1 to activate uart7 in PE1
	
	GPIO_PORTE_DEN_R |= ((1<<0)|(1<<1));
	
}

void UART_sendByte(const uint8_t data)
{
	while((UART5_FR_R&UART_FR_TXFF) != 0);
	UART5_DR_R = data;
	
	
}

void UART_sendString(const uint8_t *Str)
{
	uint8_t i = 0;
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
}

void UART_receiveString(uint8_t *Str)
{
	uint8_t i = 0;
	Str[i] = UART_receiveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_receiveByte();
	}
	Str[i] = '\0';

}

uint8_t UART_receiveByte(void)
{
	
	while(UART7_Available() != 1);
	return (uint8_t)(UART5_DR_R&0xFF);
	
}

uint8_t UART7_Available(void)
{
	return ((UART5_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
}