/*
 * timer.h
 *
 *  Created on: Nov 2, 2023
 *      Author: tuankiet
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#include "main.h"
int timer0_flag;
int timer1_flag;
int timer2_flag;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

void setTimer0 (int);
void setTimer1 (int);
void setTimer2 (int);

#endif /* INC_TIMER_H_ */
