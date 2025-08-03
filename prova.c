#include <stdio.h>
#include "headers/calculate_ms.h"

#pragma comment(lib, "calculate_ms.lib")

int main()
{
	int b = cps_to_ms(3);
	printf("%d\n", b);
	return 0;
}