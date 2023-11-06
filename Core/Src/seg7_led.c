/*
 * seg7.c
 *
 *  Created on: Nov 3, 2023
 *      Author: tuankiet
 */


#include "main.h"
#include "seg7_led.h"

typedef enum {
    RED, GREEN, YELLOW
} TrafficLightState;

int SEG7_buffer [3] = {0 , 0 , 0};

int RED_light_counter = 5;
int GREEN_light_counter = 3;
int YELLOW_light_counter = 2;

void update7SEG (void)
{
    const unsigned int ON_ = 0, OFF_ = 1;

    switch (SEG7_buffer[0])
    {
        case 0:
            HAL_GPIO_WritePin(a0_GPIO_Port, a0_Pin, ON_);
            HAL_GPIO_WritePin(b0_GPIO_Port, b0_Pin, ON_);
            HAL_GPIO_WritePin(c0_GPIO_Port, c0_Pin, ON_);
            HAL_GPIO_WritePin(d0_GPIO_Port, d0_Pin, ON_);
            HAL_GPIO_WritePin(e0_GPIO_Port, e0_Pin, ON_);
            HAL_GPIO_WritePin(f0_GPIO_Port, f0_Pin, ON_);
            HAL_GPIO_WritePin(g0_GPIO_Port, g0_Pin, OFF_);
            break;

        case 1:
            HAL_GPIO_WritePin(a0_GPIO_Port, a0_Pin, OFF_);
            HAL_GPIO_WritePin(b0_GPIO_Port, b0_Pin, ON_);
            HAL_GPIO_WritePin(c0_GPIO_Port, c0_Pin, ON_);
            HAL_GPIO_WritePin(d0_GPIO_Port, d0_Pin, OFF_);
            HAL_GPIO_WritePin(e0_GPIO_Port, e0_Pin, OFF_);
            HAL_GPIO_WritePin(f0_GPIO_Port, f0_Pin, OFF_);
            HAL_GPIO_WritePin(g0_GPIO_Port, g0_Pin, OFF_);
            break;

        case 2:
            HAL_GPIO_WritePin(a0_GPIO_Port, a0_Pin, ON_);
            HAL_GPIO_WritePin(b0_GPIO_Port, b0_Pin, ON_);
            HAL_GPIO_WritePin(c0_GPIO_Port, c0_Pin, OFF_);
            HAL_GPIO_WritePin(d0_GPIO_Port, d0_Pin, ON_);
            HAL_GPIO_WritePin(e0_GPIO_Port, e0_Pin, ON_);
            HAL_GPIO_WritePin(f0_GPIO_Port, f0_Pin, OFF_);
            HAL_GPIO_WritePin(g0_GPIO_Port, g0_Pin, ON_);
            break;

        case 3:
            HAL_GPIO_WritePin(a0_GPIO_Port, a0_Pin, ON_);
            HAL_GPIO_WritePin(b0_GPIO_Port, b0_Pin, ON_);
            HAL_GPIO_WritePin(c0_GPIO_Port, c0_Pin, ON_);
            HAL_GPIO_WritePin(d0_GPIO_Port, d0_Pin, ON_);
            HAL_GPIO_WritePin(e0_GPIO_Port, e0_Pin, OFF_);
            HAL_GPIO_WritePin(f0_GPIO_Port, f0_Pin, OFF_);
            HAL_GPIO_WritePin(g0_GPIO_Port, g0_Pin, ON_);
            break;

        case 4:
            HAL_GPIO_WritePin(a0_GPIO_Port, a0_Pin, OFF_);
            HAL_GPIO_WritePin(b0_GPIO_Port, b0_Pin, ON_);
            HAL_GPIO_WritePin(c0_GPIO_Port, c0_Pin, ON_);
            HAL_GPIO_WritePin(d0_GPIO_Port, d0_Pin, OFF_);
            HAL_GPIO_WritePin(e0_GPIO_Port, e0_Pin, OFF_);
            HAL_GPIO_WritePin(f0_GPIO_Port, f0_Pin, ON_);
            HAL_GPIO_WritePin(g0_GPIO_Port, g0_Pin, ON_);
            break;

        case 5:
            HAL_GPIO_WritePin(a0_GPIO_Port, a0_Pin, ON_);
            HAL_GPIO_WritePin(b0_GPIO_Port, b0_Pin, OFF_);
            HAL_GPIO_WritePin(c0_GPIO_Port, c0_Pin, ON_);
            HAL_GPIO_WritePin(d0_GPIO_Port, d0_Pin, ON_);
            HAL_GPIO_WritePin(e0_GPIO_Port, e0_Pin, OFF_);
            HAL_GPIO_WritePin(f0_GPIO_Port, f0_Pin, ON_);
            HAL_GPIO_WritePin(g0_GPIO_Port, g0_Pin, ON_);
            break;

        case 6:
            HAL_GPIO_WritePin(a0_GPIO_Port, a0_Pin, ON_);
            HAL_GPIO_WritePin(b0_GPIO_Port, b0_Pin, OFF_);
            HAL_GPIO_WritePin(c0_GPIO_Port, c0_Pin, ON_);
            HAL_GPIO_WritePin(d0_GPIO_Port, d0_Pin, ON_);
            HAL_GPIO_WritePin(e0_GPIO_Port, e0_Pin, ON_);
            HAL_GPIO_WritePin(f0_GPIO_Port, f0_Pin, ON_);
            HAL_GPIO_WritePin(g0_GPIO_Port, g0_Pin, ON_);
            break;

        case 7:
            HAL_GPIO_WritePin(a0_GPIO_Port, a0_Pin, ON_);
            HAL_GPIO_WritePin(b0_GPIO_Port, b0_Pin, ON_);
            HAL_GPIO_WritePin(c0_GPIO_Port, c0_Pin, ON_);
            HAL_GPIO_WritePin(d0_GPIO_Port, d0_Pin, OFF_);
            HAL_GPIO_WritePin(e0_GPIO_Port, e0_Pin, OFF_);
            HAL_GPIO_WritePin(f0_GPIO_Port, f0_Pin, OFF_);
            HAL_GPIO_WritePin(g0_GPIO_Port, g0_Pin, OFF_);
            break;

        case 8:
            HAL_GPIO_WritePin(a0_GPIO_Port, a0_Pin, ON_);
            HAL_GPIO_WritePin(b0_GPIO_Port, b0_Pin, ON_);
            HAL_GPIO_WritePin(c0_GPIO_Port, c0_Pin, ON_);
            HAL_GPIO_WritePin(d0_GPIO_Port, d0_Pin, ON_);
            HAL_GPIO_WritePin(e0_GPIO_Port, e0_Pin, ON_);
            HAL_GPIO_WritePin(f0_GPIO_Port, f0_Pin, ON_);
            HAL_GPIO_WritePin(g0_GPIO_Port, g0_Pin, ON_);
            break;

        case 9:
            HAL_GPIO_WritePin(a0_GPIO_Port, a0_Pin, ON_);
            HAL_GPIO_WritePin(b0_GPIO_Port, b0_Pin, ON_);
            HAL_GPIO_WritePin(c0_GPIO_Port, c0_Pin, ON_);
            HAL_GPIO_WritePin(d0_GPIO_Port, d0_Pin, ON_);
            HAL_GPIO_WritePin(e0_GPIO_Port, e0_Pin, OFF_);
            HAL_GPIO_WritePin(f0_GPIO_Port, f0_Pin, ON_);
            HAL_GPIO_WritePin(g0_GPIO_Port, g0_Pin, ON_);
            break;

        default:
            HAL_GPIO_WritePin(a0_GPIO_Port, a0_Pin, OFF_);
            HAL_GPIO_WritePin(b0_GPIO_Port, b0_Pin, OFF_);
            HAL_GPIO_WritePin(c0_GPIO_Port, c0_Pin, OFF_);
            HAL_GPIO_WritePin(d0_GPIO_Port, d0_Pin, OFF_);
            HAL_GPIO_WritePin(e0_GPIO_Port, e0_Pin, OFF_);
            HAL_GPIO_WritePin(f0_GPIO_Port, f0_Pin, OFF_);
            HAL_GPIO_WritePin(g0_GPIO_Port, g0_Pin, OFF_);
            break;
    }

    switch (SEG7_buffer[1])
    {
        case 0:
            HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, ON_);
            HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, ON_);
            HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, ON_);
            HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, ON_);
            HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, ON_);
            HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, ON_);
            HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, OFF_);
            break;

        case 1:
            HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, OFF_);
            HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, ON_);
            HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, ON_);
            HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, OFF_);
            HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, OFF_);
            HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, OFF_);
            HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, OFF_);
            break;

        case 2:
            HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, ON_);
            HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, ON_);
            HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, OFF_);
            HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, ON_);
            HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, ON_);
            HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, OFF_);
            HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, ON_);
            break;

        case 3:
            HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, ON_);
            HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, ON_);
            HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, ON_);
            HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, ON_);
            HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, OFF_);
            HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, OFF_);
            HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, ON_);
            break;

        case 4:
            HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, OFF_);
            HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, ON_);
            HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, ON_);
            HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, OFF_);
            HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, OFF_);
            HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, ON_);
            HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, ON_);
            break;

        case 5:
            HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, ON_);
            HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, OFF_);
            HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, ON_);
            HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, ON_);
            HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, OFF_);
            HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, ON_);
            HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, ON_);
            break;

        case 6:
            HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, ON_);
            HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, OFF_);
            HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, ON_);
            HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, ON_);
            HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, ON_);
            HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, ON_);
            HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, ON_);
            break;

        case 7:
            HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, ON_);
            HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, ON_);
            HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, ON_);
            HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, OFF_);
            HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, OFF_);
            HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, OFF_);
            HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, OFF_);
            break;

        case 8:
            HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, ON_);
            HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, ON_);
            HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, ON_);
            HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, ON_);
            HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, ON_);
            HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, ON_);
            HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, ON_);
            break;

        case 9:
            HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, ON_);
            HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, ON_);
            HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, ON_);
            HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, ON_);
            HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, OFF_);
            HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, ON_);
            HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, ON_);
            break;

        default:
            HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, OFF_);
            HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, OFF_);
            HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, OFF_);
            HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, OFF_);
            HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, OFF_);
            HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, OFF_);
            HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, OFF_);
            break;
    }

    switch (SEG7_buffer[2])
    {
        case 0:
            HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, ON_);
            HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, ON_);
            HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, ON_);
            HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, ON_);
            HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, ON_);
            HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, ON_);
            HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, OFF_);
            break;

        case 1:
            HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, OFF_);
            HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, ON_);
            HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, ON_);
            HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, OFF_);
            HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, OFF_);
            HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, OFF_);
            HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, OFF_);
            break;

        case 2:
            HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, ON_);
            HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, ON_);
            HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, OFF_);
            HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, ON_);
            HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, ON_);
            HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, OFF_);
            HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, ON_);
            break;

        case 3:
            HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, ON_);
            HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, ON_);
            HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, ON_);
            HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, ON_);
            HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, OFF_);
            HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, OFF_);
            HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, ON_);
            break;

        case 4:
            HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, OFF_);
            HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, ON_);
            HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, ON_);
            HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, OFF_);
            HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, OFF_);
            HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, ON_);
            HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, ON_);
            break;

        case 5:
            HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, ON_);
            HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, OFF_);
            HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, ON_);
            HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, ON_);
            HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, OFF_);
            HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, ON_);
            HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, ON_);
            break;

        case 6:
            HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, ON_);
            HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, OFF_);
            HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, ON_);
            HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, ON_);
            HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, ON_);
            HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, ON_);
            HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, ON_);
            break;

        case 7:
            HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, ON_);
            HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, ON_);
            HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, ON_);
            HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, OFF_);
            HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, OFF_);
            HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, OFF_);
            HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, OFF_);
            break;

        case 8:
            HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, ON_);
            HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, ON_);
            HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, ON_);
            HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, ON_);
            HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, ON_);
            HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, ON_);
            HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, ON_);
            break;

        case 9:
            HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, ON_);
            HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, ON_);
            HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, ON_);
            HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, ON_);
            HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, OFF_);
            HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, ON_);
            HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, ON_);
            break;

        default:
            HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, OFF_);
            HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, OFF_);
            HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, OFF_);
            HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, OFF_);
            HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, OFF_);
            HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, OFF_);
            HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, OFF_);
            break;
    }
}




void traffic_light_fsm(void)
{
    static TrafficLightState state0     = RED;
    static int               counter0   = 5;

    static TrafficLightState state1     = GREEN;
    static int               counter1   = 3;

    switch (state0)
    {
        case GREEN:
            HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, 0);
            HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, 0);
            HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, 1);

            SEG7_buffer[0] = --counter0;
            if (counter0 <= 0)
            {
                state0 = YELLOW;
                counter0 = YELLOW_light_counter;
            }
            break;
        
        case YELLOW:
            HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, 0);
            HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, 1);
            HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, 0);

            SEG7_buffer[0] = --counter0;
            if (counter0 <= 0)
            {
                state0 = RED;
                counter0 = RED_light_counter;
            }
            break;
        
        case RED:
            HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, 1);
            HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, 0);
            HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, 0);

            SEG7_buffer[0] = --counter0;
            if (counter0 <= 0)
            {
                state0 = GREEN;
                counter0 = GREEN_light_counter;
            }
            break;
        
        default:
            break;
    }


    switch (state1)
    {
        case GREEN:
            HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 0);
            HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 0);
            HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 1);

            SEG7_buffer[1] = SEG7_buffer[2] = --counter1;
            if (counter1 <= 0)
            {
                state1 = YELLOW;
                counter1 = YELLOW_light_counter;
            }
            break;
        
        case YELLOW:
            HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 0);
            HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 1);
            HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 0);

            SEG7_buffer[1] = SEG7_buffer[2] = --counter1;
            if (counter1 <= 0)
            {
                state1 = RED;
                counter1 = RED_light_counter;
            }
            break;
        
        case RED:
            HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
            HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 0);
            HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 0);

            SEG7_buffer[1] = SEG7_buffer[2] = --counter1;
            if (counter1 <= 0)
            {
                state1 = GREEN;
                counter1 = GREEN_light_counter;
            }
            break;
        
        default:
            break;
    }

    update7SEG();
}
