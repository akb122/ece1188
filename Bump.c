/*
 * Bump.c
 *
 *  Created on: Apr 10, 2023
 *      Author: Ashton
 */

#include <stdint.h>
#include "msp.h"

// Initialize negative logic bump sensors
// P4.7 Bump5, left side of robot
// P4.6 Bump4
// P4.5 Bump3
// P4.3 Bump2
// P4.2 Bump1
// P4.0 Bump0, right side of robot

void Bump_Init(void)
{
    //GPIO
    P4->SEL0 &= ~0xED;
    P4->SEL1 &= ~0xED;
    //INPUT
    P4->DIR &= ~0xED;
    //PUPD RESISTOR - PULL UP
    P4->REN |= 0xED;
    P4->OUT |= 0xED;
}

// Read current state of 6 switches
// Returns a 6-bit positive logic result (0 to 63)
// bit 5 Bump5
// bit 4 Bump4
// bit 3 Bump3
// bit 2 Bump2
// bit 1 Bump1
// bit 0 Bump0
uint8_t Bump_Read(void)
{
    return (P4->IN&0xED);   // Read 6 most LSB of port 4
}
