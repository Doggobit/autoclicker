#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#pragma comment(lib, "User32.lib")

int main()
{
	int random;
	int sleep_time;
	POINT p;
	printf("autoclicker\n");
	while (!(GetKeyState(0x51)))
	{
		random = rand() % 11;
		sleep_time = 20 + random;
		Sleep(sleep_time);
		if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0 && !(GetAsyncKeyState(0x76) & 0x8000))
		{
			if (GetCursorPos(&p))
			{
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			}
    }
		if ((GetAsyncKeyState(VK_RBUTTON) & 0x8000) != 0 && !(GetAsyncKeyState(0x76) & 0x8000))
		{
			if (GetCursorPos(&p))
			{
				mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			}
		}
		continue;
	}
	return 0;
}