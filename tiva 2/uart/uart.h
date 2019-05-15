 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_


#include "stdint.h"
#include "tm4c123gh6pm.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void UART7_init(void);

void UART_sendByte(const uint8_t data);

uint8_t UART_receiveByte(void);

void UART_sendString(const uint8_t *Str);
	
void UART_receiveString(uint8_t *Str);

uint8_t UART7_Available(void);
#endif /* UART_H_ */
