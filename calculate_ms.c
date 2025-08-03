#include <stdio.h>
#include "headers/calculate_ms.h"

int cps_to_ms(int cps)
{
	if (cps <= 0) {
        return 0; // Handle invalid input
    }
    
    // interval = 1000 milliseconds / cps
    return (1000) / cps;
}