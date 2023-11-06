/*
 * button_processing.c
 *
 *  Created on: Nov 2, 2023
 *      Author: tuankiet
 */

#include "button_processing.h"
#include "seg7_led.h"
#include "timer.h"
#include "global.h"
#include "stdbool.h"
#include "main.h"

//chống rung 3 lần
static int BUTTON_MODE_Reg[2]		= {RELEASED_STATE, RELEASED_STATE},
 	 	   current_BUTTON_MODE 		= RELEASED_STATE,
		   pre_stable_BUTTON_MODE 	= RELEASED_STATE,
		   BUTTON_MODE_flag = 0;

static int BUTTON_MODIFY_Reg[2]		= {RELEASED_STATE, RELEASED_STATE},
 	 	   current_BUTTON_MODIFY 		= RELEASED_STATE,
		   pre_stable_BUTTON_MODIFY 	= RELEASED_STATE,
		   BUTTON_MODIFY_flag = 0;

static int BUTTON_SAVE_Reg[2]		= {RELEASED_STATE, RELEASED_STATE},
 	 	   current_BUTTON_SAVE 		= RELEASED_STATE,
		   pre_stable_BUTTON_SAVE 	= RELEASED_STATE,
		   BUTTON_SAVE_flag = 0;		   

static bool is_BUTTON_MODE_pressed(void)
{
	if (BUTTON_MODE_flag == 1)
	{
		BUTTON_MODE_flag = 0;
		return true;
	}
	else return false;
}

static bool is_BUTTON_MODIFY_pressed(void)
{
	if (BUTTON_MODIFY_flag == 1)
	{
		BUTTON_MODIFY_flag = 0;
		return true;
	}
	else return false;
}

static bool is_BUTTON_SAVE_pressed(void)
{
	if (BUTTON_SAVE_flag == 1)
	{
		BUTTON_SAVE_flag = 0;
		return true;
	}
	else return false;
}

extern void get_BUTTONs(void) //được gọi mỗi 10ms
{
	BUTTON_MODE_Reg[0] = BUTTON_MODE_Reg[1];
	BUTTON_MODE_Reg[1] = current_BUTTON_MODE;
	current_BUTTON_MODE = HAL_GPIO_ReadPin(BUTTON_MODE_GPIO_Port, BUTTON_MODE_Pin);

	if ((BUTTON_MODE_Reg[0] == BUTTON_MODE_Reg[1]) && (BUTTON_MODE_Reg[1] == current_BUTTON_MODE)) //khi phím nhấn ổn định
	{
		if (pre_stable_BUTTON_MODE != current_BUTTON_MODE) //trường hợp nhấn THẢ, hoặc là lần nhấn đầu tiên
		{
			pre_stable_BUTTON_MODE = current_BUTTON_MODE;
			if (current_BUTTON_MODE == PRESSED_STATE)
			{
				//TO DO: set the flag
				BUTTON_MODE_flag = 1;
			}
		}

		/* nhấn đè, chưa xử lý
		else //trường hợp nhấn đè
		{
			keyPress_counter--;
			if (keyPress_counter == 0)
			{
				keyPress_counter = 100;
				if (current_BUTTON_MODE == PRESSED_STATE)
				{
					subKeyProcess();
				}
			}
		}
		*/
	}

	BUTTON_MODIFY_Reg[0] = BUTTON_MODIFY_Reg[1];
	BUTTON_MODIFY_Reg[1] = current_BUTTON_MODIFY;
	current_BUTTON_MODIFY = HAL_GPIO_ReadPin(BUTTON_MODIFY_GPIO_Port, BUTTON_MODIFY_Pin);

	if ((BUTTON_MODIFY_Reg[0] == BUTTON_MODIFY_Reg[1]) && (BUTTON_MODIFY_Reg[1] == current_BUTTON_MODIFY)) //khi phím nhấn ổn định
	{
		if (pre_stable_BUTTON_MODIFY != current_BUTTON_MODIFY) //trường hợp nhấn THẢ, hoặc là lần nhấn đầu tiên
		{
			pre_stable_BUTTON_MODIFY = current_BUTTON_MODIFY;
			if (current_BUTTON_MODIFY == PRESSED_STATE)
			{
				//TO DO: set the flag
				BUTTON_MODIFY_flag = 1;
			}
		}
	}

	BUTTON_SAVE_Reg[0] = BUTTON_SAVE_Reg[1];
	BUTTON_SAVE_Reg[1] = current_BUTTON_SAVE;
	current_BUTTON_SAVE = HAL_GPIO_ReadPin(BUTTON_SAVE_GPIO_Port, BUTTON_SAVE_Pin);

	if ((BUTTON_SAVE_Reg[0] == BUTTON_SAVE_Reg[1]) && (BUTTON_SAVE_Reg[1] == current_BUTTON_SAVE)) //khi phím nhấn ổn định
	{
		if (pre_stable_BUTTON_SAVE != current_BUTTON_SAVE) //trường hợp nhấn THẢ, hoặc là lần nhấn đầu tiên
		{
			pre_stable_BUTTON_SAVE = current_BUTTON_SAVE;
			if (current_BUTTON_SAVE == PRESSED_STATE)
			{
				//TO DO: set the flag
				BUTTON_SAVE_flag = 1;
			}
		}
	}
}

static int counter_buffer;

extern void fsm_input_processing(void)
{
	switch (current_MODE_status)
	{ 
		case NORMAL_MODE:
			if (timer0_flag == 1)
			{
				setTimer0(1000);
				traffic_light_fsm();
			}
			
			if (is_BUTTON_MODE_pressed())
			{
				current_MODE_status = MODIFY_RED_MODE;
				setTimer0(250);
				counter_buffer = RED_light_counter;
				HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, 1);
				HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
			}
			break;
		
		case MODIFY_RED_MODE:
            HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, 0);
            HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, 0);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 0);
            HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 0);
			SEG7_buffer[0] = 2;
			SEG7_buffer[1] = counter_buffer;

			if (timer0_flag == 1)
			{
				setTimer0(250);
				HAL_GPIO_TogglePin(RED0_GPIO_Port, RED0_Pin);
				HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
			}
			if (is_BUTTON_MODIFY_pressed())
			{
				counter_buffer++;
				if (counter_buffer >= 100) counter_buffer = 1;
			}
			if (is_BUTTON_SAVE_pressed()) 
				RED_light_counter = counter_buffer;
			if (is_BUTTON_MODE_pressed())
			{
				current_MODE_status = MODIFY_YELLOW_MODE;
				setTimer0(250);
				counter_buffer = YELLOW_light_counter;
				HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, 1);
				HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 1);
			}
			break;
		
		case MODIFY_YELLOW_MODE:
            HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, 0);
            HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, 0);
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 0);
            HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 0);
			SEG7_buffer[0] = 3;
			SEG7_buffer[1] = counter_buffer;

			if (timer0_flag == 1)
			{
				setTimer0(250);
				HAL_GPIO_TogglePin(YELLOW0_GPIO_Port, YELLOW0_Pin);
				HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
			}
			if (is_BUTTON_MODIFY_pressed())
			{
				counter_buffer++;
				if (counter_buffer >= 100) counter_buffer = 1;
			}
			if (is_BUTTON_SAVE_pressed()) 
				YELLOW_light_counter = counter_buffer;
			if (is_BUTTON_MODE_pressed())
			{
				current_MODE_status = MODIFY_GREEN_MODE;
				setTimer0(250);
				counter_buffer = YELLOW_light_counter;
				HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, 1);
				HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 1);
			}
			break;

		case MODIFY_GREEN_MODE:
            HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, 0);
            HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, 0);
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 0);
            HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 0);
			SEG7_buffer[0] = 4;
			SEG7_buffer[1] = counter_buffer;

			if (timer0_flag == 1)
			{
				setTimer0(250);
				HAL_GPIO_TogglePin(GREEN0_GPIO_Port, GREEN0_Pin);
				HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
			}
			if (is_BUTTON_MODIFY_pressed())
			{
				counter_buffer++;
				if (counter_buffer >= 100) counter_buffer = 1;
			}
			if (is_BUTTON_SAVE_pressed()) 
				GREEN_light_counter = counter_buffer;
			if (is_BUTTON_MODE_pressed())
			{
				current_MODE_status = NORMAL_MODE;
				timer0_flag = 1;
			}
			break;
		
		default:
			break;
	}
}
