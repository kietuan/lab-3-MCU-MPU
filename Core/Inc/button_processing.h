/*
 * button_processing.h
 *
 *  Created on: Nov 2, 2023
 *      Author: tuankiet
 */

#ifndef INC_BUTTON_PROCESSING_H_
#define INC_BUTTON_PROCESSING_H_

#include "main.h"

#define BUTTON_ON 0
#define BUTTON_OFF 1

#define RELEASED_STATE 1
#define PRESSED_STATE 0

typedef enum
{
	NORMAL_MODE,
    MODIFY_RED_MODE,
    MODIFY_YELLOW_MODE,
    MODIFY_GREEN_MODE
} MODE_status;

MODE_status current_MODE_status;

void get_BUTTONs(void);

void fsm_input_processing(void);
//static void subKeyProcess(void);

#endif /* INC_BUTTON_PROCESSING_H_ */
