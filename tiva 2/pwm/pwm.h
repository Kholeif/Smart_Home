#ifndef PWM_H
#define PWM_H

#include "stdint.h"
#include "tm4c123gh6pm.h"

#define GPIO_PF2_M	0x04

void PWM_setDuty(uint32_t duty);
void PWM_init(void);

#endif