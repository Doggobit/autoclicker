#include <stdio.h>
#include "headers/calculate_ms.h"
#include "headers/mouse_input.h"

#pragma comment(lib, "calculate_ms.lib")
#pragma comment(lib, "mouse_input.lib")

int main()
{
	LBUTTON_INPUT();
	LBUTTON_INPUT();
	LBUTTON_INPUT();
	int b = cps_to_ms(3);
	printf("%d\n", b);
	return 0;
}