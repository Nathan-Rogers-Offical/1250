/********************************************************************/
// HC12 Program:  ICA8
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Nathan Rogers
// Details:
// Date:          3/13/2024
// Revision History :
//  N/A

/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "clock.h"
#include "sw_led.h"
#include "rti.h"
#include "sci.h"
#include "misc.h"

// Other system includes or your includes go here
// #include <stdlib.h>
// #include <stdio.h>

/********************************************************************/
// Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/
unsigned char data;
unsigned char data2;
int info;
/********************************************************************/
// Constants
/********************************************************************/

/********************************************************************/
// Main Entry
/********************************************************************/
void main(void)
{
  // Any main local variables must be declared here

  // main entry point
  _DISABLE_COP();
  // EnableInterrupts;

  /********************************************************************/
  // one-time initializations
  /********************************************************************/
  SWL_Init();
  RTI_Init();
  Clock_Set20MHZ();
  sci0_Init(130);
  /********************************************************************/
  // main program loop
  /********************************************************************/
  for (;;)
  {
    SWL_TOG(SWL_RED);
    RTI_Delay_ms(50);

    data = (unsigned char)GetRandom(65, 90);

    sci0_txByte(data);
    if (sci0_read(&data2) == 1)
    {
      if (data2 == 'A' || data2 == 'E' || data2 == 'I' || data2 == 'O' || data2 == 'U' || data2 == 'a' || data2 == 'e' || data2 == 'i' || data2 == 'o' || data2 == 'u')
      {
        SWL_ON(SWL_GREEN);
        SWL_OFF(SWL_YELLOW);
      }
      else
      {
        SWL_OFF(SWL_GREEN);
        SWL_ON(SWL_YELLOW);
      }
    }
  }
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
