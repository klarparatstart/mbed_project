/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <cstdio>
//#include "platform/mbed_thread.h"


// Blinking rate in milliseconds
#define BLINKING_RATE1     500000
#define BLINKING_RATE2     300000
#define BLINKING_RATE3     100000

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);

Thread thread1;
Thread thread2;
Thread thread3;
Thread thread4;

void led1_thread()
{
    while (true)
    {
        led1 = !led1;
        wait_us(BLINKING_RATE1);
    }
}

void led2_thread()
{
    while (true)
    {
        led2 = !led2;
        wait_us(BLINKING_RATE2);
    }
}

void led3_thread()
{
    while (true)
    {
        led3 = !led3;
        wait_us(BLINKING_RATE3);
    }
}

void print_thread()
{
    while (true)
    {
        printf("Ra da da da da da da da Circus\n");
        wait_us(200000);
        printf("Da da da da da da da da Afro\n");
        wait_us(200000);
        printf("Circus, Afro Circus, Afro\n");
        wait_us(200000);
        printf("Polka dot, polka dot, polka dot, Afro!\n");
        wait_us(500000);
    }
}


int main()
{
    // Initialise the digital pin LED1 as an output
    
    thread1.start(led1_thread);
    thread2.start(led2_thread);
    thread3.start(led3_thread);
    thread4.start(print_thread);

}
