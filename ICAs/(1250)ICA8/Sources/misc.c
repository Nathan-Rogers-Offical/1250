#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "misc.h"
#include <stdlib.h>

int GetRandom(int iLow, int iHighEx)
{
    int value;
    value = iLow + (rand() % (iHighEx - iLow));
    return value;
}