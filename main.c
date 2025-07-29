#include <stdio.h>
#include <windows.h>

#pragma comment(lib, "User32.lib")

int main()
{
	POINT p;
	while (!(GetKeyState(0x51)))
	{
		Sleep(50);
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
	}
	return 0;
}