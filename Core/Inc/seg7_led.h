/*
 * seg7.h
 *
 *  Created on: Nov 3, 2023
 *      Author: tuankiet
 */

#ifndef INC_SEG7_H_
#define INC_SEG7_H_

int GREEN_light_counter;
int YELLOW_light_counter;
int RED_light_counter;

int SEG7_buffer [3];

void update7SEG (void);

void traffic_light_fsm(void);

#endif /* INC_SEG7_H_ */
