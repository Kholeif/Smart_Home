#include "MCAL.h"

void Port_Init(uint8_t port_index){
		uint32_t delay;
	switch(port_index)
		{
			case 0:
				SYSCTL_RCGCGPIO_R|=(1<<0);
				delay=1;
				GPIO_PORTA_LOCK_R=0x4C4F434B;
				GPIO_PORTA_CR_R=0xFF;
				GPIO_PORTA_AFSEL_R=0x00;
					GPIO_PORTA_PCTL_R=0;
				GPIO_PORTA_AMSEL_R=0;
				GPIO_PORTA_DEN_R=0xFF;
				break;
				
			case 1:
				SYSCTL_RCGCGPIO_R|=(1<<1);
				delay=1;
				GPIO_PORTB_LOCK_R=0x4C4F434B;
				GPIO_PORTB_CR_R=0xFF;
				GPIO_PORTB_AFSEL_R=0x00;
				GPIO_PORTB_PCTL_R=0;
				GPIO_PORTB_AMSEL_R=0;
				GPIO_PORTB_DEN_R=0xFF;			
				break;
			
			case 3:
				
				SYSCTL_RCGCGPIO_R|=(1<<3);
				delay=1;
				GPIO_PORTD_LOCK_R=0x4C4F434B;
				GPIO_PORTD_CR_R=0xFF;
				GPIO_PORTD_AFSEL_R=0x00;
				GPIO_PORTD_PCTL_R=0;
				GPIO_PORTD_AMSEL_R=0;
				GPIO_PORTD_DEN_R=0xFF;			
				break;
			
			case 4:
				SYSCTL_RCGCGPIO_R|=(1<<4);
				delay=1;
				GPIO_PORTE_LOCK_R=0x4C4F434B;
				GPIO_PORTE_CR_R=0xFF;
				GPIO_PORTE_AFSEL_R=0x00;
				GPIO_PORTE_PCTL_R=0;
				GPIO_PORTE_AMSEL_R=0;
				GPIO_PORTE_DEN_R=0xFF;		
				break;
			
			case 5:
				SYSCTL_RCGCGPIO_R|=(1<<5);
				delay=1;
				GPIO_PORTF_LOCK_R=0x4C4F434B;
				GPIO_PORTF_CR_R=0xFF; 
				GPIO_PORTF_AFSEL_R=0x00;
				GPIO_PORTF_PCTL_R=0;
				GPIO_PORTF_AMSEL_R=0;
				GPIO_PORTF_DEN_R=0xFF;
				break;
			}
}

void Port_SetPinDirection(uint8_t port_index,uint8_t pins_mask,Port_PinDirectionType pins_direction)
	{
		switch(port_index)
		{
			case 0:
				if(pins_direction)
					GPIO_PORTA_DIR_R |= pins_mask;
				else
					GPIO_PORTA_DIR_R &= ~pins_mask;
				break;
		
			case 1:
				if(pins_direction)
					GPIO_PORTB_DIR_R |= pins_mask;
				else
					GPIO_PORTB_DIR_R &= ~pins_mask;
				break;
				
			case 2:
				if(pins_direction)
					GPIO_PORTC_DIR_R |= pins_mask;
				else
					GPIO_PORTC_DIR_R &= ~pins_mask;
				break;
				
			case 3:
				if(pins_direction)
					GPIO_PORTD_DIR_R |= pins_mask;
				else
					GPIO_PORTD_DIR_R &= ~pins_mask;
				break;
				
			case 4:
				if(pins_direction)
					GPIO_PORTE_DIR_R |= pins_mask;
				else
					GPIO_PORTE_DIR_R &= ~pins_mask;
				break;
				
			case 5:
				if(pins_direction)
					GPIO_PORTF_DIR_R |= pins_mask;
				else
					GPIO_PORTF_DIR_R &= ~pins_mask;
				break;
	}
}

void Port_SetPinPullUp(uint8_t port_index, uint8_t pins_mask, uint8_t enable)
{
	if (enable == 1)
	{
		switch (port_index)
		{
		case 0:
			GPIO_PORTA_PUR_R |= pins_mask;
			break;
		case 1:
			GPIO_PORTB_PUR_R |= pins_mask;
			break;

		case 2:
			GPIO_PORTC_PUR_R |= pins_mask;
			break;
		case 3:
			GPIO_PORTD_PUR_R |= pins_mask;
			break;
		case 4:
			GPIO_PORTE_PUR_R |= pins_mask;
			break;
		case 5:
			GPIO_PORTF_PUR_R |= pins_mask;
			break;


		}
	}
	if (enable == 0)
	{
		switch (port_index)
		{
		case 0:
			GPIO_PORTA_PUR_R &= ~pins_mask;
			break;
		case 1:
			GPIO_PORTB_PUR_R &= ~pins_mask;
			break;

		case 2:
			GPIO_PORTC_PUR_R &= ~pins_mask;
			break;
		case 3:
			GPIO_PORTD_PUR_R &= ~pins_mask;
			break;
		case 4:
			GPIO_PORTE_PUR_R &= ~pins_mask;
			break;
		case 5:
			GPIO_PORTF_PUR_R &= ~pins_mask;
			break;
		}
	}
}


void Port_SetPinPullDown(uint8_t port_index, uint8_t pins_mask, uint8_t enable)
{
	if (enable == 1)
	{
		switch (port_index)
		{
		case 0:
			GPIO_PORTA_PDR_R |= pins_mask;
			break;
		case 1:
			GPIO_PORTB_PDR_R |= pins_mask;
			break;

		case 2:
			GPIO_PORTC_PDR_R |= pins_mask;
			break;
		case 3:
			GPIO_PORTD_PDR_R |= pins_mask;
			break;
		case 4:
			GPIO_PORTE_PDR_R |= pins_mask;
			break;
		case 5:
			GPIO_PORTF_PDR_R |= pins_mask;
			break;


		}
	}
	if (enable == 0)
	{
		switch (port_index)
		{
		case 0:
			GPIO_PORTA_PDR_R &= ~pins_mask;
			break;
		case 1:
			GPIO_PORTB_PDR_R &= ~pins_mask;
			break;

		case 2:
			GPIO_PORTC_PDR_R &= ~pins_mask;
			break;
		case 3:
			GPIO_PORTD_PDR_R &= ~pins_mask;
			break;
		case 4:
			GPIO_PORTE_PDR_R &= ~pins_mask;
			break;
		case 5:
			GPIO_PORTF_PUR_R &= ~pins_mask;
			break;
		}
	}
}



