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

//nơi lưu trữ giá trị sẽ hiển thị trên LED, nhưng việc hiển thị LED và quét LED sẽ do một hàm khác thực hiện
int SEG7_buffer [2] = {0 , 0}; 

int RED_light_counter = 5;
int GREEN_light_counter = 3;
int YELLOW_light_counter = 2;

static void display7SEG_0 (int number)
{   
    const int ON_ = 0, OFF_ = 1;
    switch(number)
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
}

static void display7SEG_1 (int number)
{
    const int ON_ = 0, OFF_ = 1;
    switch(number)
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
}

extern void scan_7SEGs(void)
{   
    const int ON = 1, OFF = 0;
    static int flag = 0;

    switch(flag)
    {
        case 0:
            HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, ON);
            HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, ON);
            HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, OFF);
            HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, OFF);
            display7SEG_0(SEG7_buffer[0] / 10);
            display7SEG_1(SEG7_buffer[1] / 10);
            flag = 1;
            break;

        case 1:
            HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, OFF);
            HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, OFF);
            HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, ON);
            HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, ON);
            display7SEG_0(SEG7_buffer[0] % 10);
            display7SEG_1(SEG7_buffer[1] % 10);
            flag = 0;
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

            SEG7_buffer[1] = --counter1;
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

            SEG7_buffer[1] = --counter1;
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

            SEG7_buffer[1] = --counter1;
            if (counter1 <= 0)
            {
                state1 = GREEN;
                counter1 = GREEN_light_counter;
            }
            break;
        
        default:
            break;
    }
}
