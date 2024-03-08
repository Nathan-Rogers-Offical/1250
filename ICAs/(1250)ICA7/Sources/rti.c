#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "rti.h"

void RTI_Init(){
    RTICTL = 0b10010111;
    CRGINT |= 0b10000000;
}

void RTI_Delay_ms(unsigned long ms){
    RTI_Init(); 
    for(ms; ms > 0; ms--){
    while (!CRGFLG_RTIF) // RTI period over?
    {} 
    CRGFLG = CRGFLG_RTIF_MASK; //clear flag, VERY IMPORTANT 
    } 
    RTI_Init(); 
}