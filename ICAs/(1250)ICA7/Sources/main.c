/********************************************************************/
// HC12 Program:  ICA7
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Nathan Rogers
// Details:                    
// Date:          1/12/2024
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

//Other system includes or your includes go here
//#include <stdlib.h>
//#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/
long count;
/********************************************************************/
// Constants
/********************************************************************/

/********************************************************************/
// Main Entry
/********************************************************************/
void main(void)
{
  //Any main local variables must be declared here

  // main entry point
  _DISABLE_COP();
  //EnableInterrupts;
  
/********************************************************************/
  // one-time initializations
/********************************************************************/
SWL_Init ();
Clock_Set20MHZ();
/********************************************************************/
  // main program loop
/********************************************************************/
for (;;)
{
if (SWL_Pushed(SWL_RIGHT) > 0){
  SWL_OFF (SWL_RED);
  SWL_ON (SWL_GREEN);
}
else if(SWL_Pushed(SWL_LEFT) > 0){
  SWL_OFF (SWL_GREEN);
  SWL_ON (SWL_RED);
  RTI_Delay_ms(1);
  SWL_OFF (SWL_RED);
  RTI_Delay_ms(9);
}
else if((SWL_Pushed(SWL_DOWN) > 0) && (SWL_Pushed(SWL_UP) > 0)){
  SWL_OFF (SWL_GREEN);
  SWL_TOG (SWL_RED);
  RTI_Delay_ms(10);
}
else if(SWL_Pushed(SWL_UP) > 0){
  SWL_OFF (SWL_GREEN);
  SWL_TOG (SWL_RED);
  RTI_Delay_ms(8);
}
else if(SWL_Pushed(SWL_DOWN) > 0){
  SWL_OFF (SWL_GREEN);
  SWL_TOG (SWL_RED);
  RTI_Delay_ms(12);
}
else{
  SWL_OFF (SWL_GREEN);
  SWL_TOG (SWL_RED);
  RTI_Delay_ms(10);
}

}                  
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/