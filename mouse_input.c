#include "headers/mouse_input.h"
#include <windows.h>

#pragma comment(lib, "User32.lib")

int INVERTED_LBUTTON_INPUT(void)
{
	INPUT ip[2] = {};
	
	ip[0].type = INPUT_MOUSE;
	ip[0].mi.dwFlags = MOUSEEVENTF_LEFTUP;
	
	ip[1].type = INPUT_MOUSE;
	ip[1].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	
	SendInput(2, ip, sizeof(INPUT));
	
	return 0;
}

int INVERTED_RBUTTON_INPUT(void)
{
	INPUT ip[2] = {};
	
	ip[0].type = INPUT_MOUSE;
	ip[0].mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	
	ip[1].type = INPUT_MOUSE;
	ip[1].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	
	SendInput(2, ip, sizeof(INPUT));
	
	return 0;
}

int LBUTTON_INPUT(void)
{
	INPUT ip[2] = {};
	
	ip[0].type = INPUT_MOUSE;
	ip[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	
	ip[1].type = INPUT_MOUSE;
	ip[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
	
	SendInput(2, ip, sizeof(INPUT));
	
	return 0;
}

int RBUTTON_INPUT(void)
{
	INPUT ip[2] = {};
	
	ip[0].type = INPUT_MOUSE;
	ip[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	
	ip[1].type = INPUT_MOUSE;
	ip[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	
	SendInput(2, ip, sizeof(INPUT));
	
	return 0;
}