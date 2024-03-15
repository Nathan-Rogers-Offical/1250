#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "clock.h"

void Clock_Set24MHZ(void)
{
    SYNR = 5;
    REFDV = 3;
    CLKSEL_PSTP = 1;
    PLLCTL = 0b01100000;
    while (!CRGFLG_LOCK)
        ;
    CLKSEL_PLLSEL = 1;
}

void Clock_Set20MHZ(void)
{
    SYNR = 4;
    REFDV = 3;
    CLKSEL_PSTP = 1;
    PLLCTL = 0b01100000;
    while (!CRGFLG_LOCK)
        ;
    CLKSEL_PLLSEL = 1;
}

void Clock_Set8MHZ(void)
{
    SYNR = 1;
    REFDV = 3;
    CLKSEL_PSTP = 1;
    PLLCTL = 0b01100000;
    while (!CRGFLG_LOCK)
        ;
    CLKSEL_PLLSEL = 1;
}

unsigned long Clock_GetBusSpeed()
{
}