#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "sci.h"

unsigned long sci0_Init(unsigned long ulBusClock)
{
    SCI0BD = ulBusClock;
    SCI0CR2 = 0b00001100;
}

int sci0_read(unsigned char *pData)
{
    // Non-blocking receiving
    if (SCI0SR1 & SCI0SR1_RDRF_MASK) // Check if a character has been received
    {
        *pData = SCI0DRL;
        return 1;
    }

    return 0;
}

void sci0_txByte(unsigned char data)
{
    // Blocking 1 byte transmission
    while (!(SCI0SR1 & SCI0SR1_TDRE_MASK))
        ; // Wait till transmit data register is empty
    SCI0DRL = data;
}