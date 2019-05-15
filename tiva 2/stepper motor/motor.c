#include "motor.h"
#include "port.h"
#include "dio.h"

//p0,p1,p4,p5
//0x01,0x02,0x10,0x20
extern uint8_t cursor;

void _delay_ms(uint32_t y)
{
	 unsigned long volatile t;
	 t= 1000*y;
 	 while(t){t--;}
 }

 
 void stepper_setup()
 {
	 Port_Init(1);
	 Port_Init(5);
	 Port_SetPinDirection(1,0x33,PORT_PIN_OUT);
	 Port_SetPinDirection(5,0x11,PORT_PIN_IN);
	 DIO_WritePort (1,0x33,STD_LOW);
	 Port_SetPinPullUp(5,0x11,1);
 }

 void movestepperleft()
 {
	  DIO_WritePort(1,0x21,STD_HIGH);
	 _delay_ms(20);
	 DIO_WritePort(1,0x21,STD_LOW);
	  DIO_WritePort(1,0x30,STD_HIGH);
	 _delay_ms(20);
	 DIO_WritePort(1,0x30,STD_LOW);
	 DIO_WritePort(1,0x12,STD_HIGH);
	 _delay_ms(20);
	 DIO_WritePort(1,0x12,STD_LOW);
	  DIO_WritePort(1,0x03,STD_HIGH);
	 _delay_ms(20);
	 DIO_WritePort(1,0x03,STD_LOW);
 }
 
  void movestepperright()
 {
	 DIO_WritePort(1,0x03,STD_HIGH);
	 _delay_ms(20);
	  DIO_WritePort(1,0x03,STD_LOW);
	  DIO_WritePort(1,0x12,STD_HIGH);
	 _delay_ms(20);
	 DIO_WritePort(1,0x12,STD_LOW);
	  DIO_WritePort(1,0x30,STD_HIGH);
	 _delay_ms(20);
	 DIO_WritePort(1,0x30,STD_LOW);
	  DIO_WritePort(1,0x21,STD_HIGH);
	 _delay_ms(20);
	 DIO_WritePort(1,0x21,STD_LOW);
 } 
