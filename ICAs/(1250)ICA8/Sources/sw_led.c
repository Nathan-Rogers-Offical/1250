#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "sw_led.h"

void SWL_Init(void)
{
  PT1AD1 &= 0x1F;
  DDR1AD1 = 0xE0;
  ATD1DIEN1 |= 0x1F;
}

void SWL_ON(SWL_LEDColour Led)
{
  PT1AD1 |= Led;
}

void SWL_OFF(SWL_LEDColour Led)
{
  PT1AD1 &= ~Led;
}

int SWL_Pushed(SWL_SwitchPos pos)
{
  return (PT1AD1 & pos) > 0;
}

void SWL_TOG(SWL_LEDColour Led)
{
  PT1AD1 ^= Led;
}