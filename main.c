#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "headers/ENABLES.h" //header file for the struct with the bools of right click & left click

#pragma comment(lib, "User32.lib") // link User32.lib

int main(int argc, char** argv)
{
	system("powershell -ExecutionPolicy Bypass -File \"intro.ps1\""); // program intro
	
	ENABLES* enables = malloc(sizeof(ENABLES)); // initialize a pointer to the structure
	
	if(enables == NULL) //check initialization
	{
		system("powershell (Write-Host \"`nMEMORY ALLOCATION DIDN'T SUCCEED!`n\" -ForegroundColor DarkRed)");
		return 1;
	}
	
	//set enables
	
	if(argc == 3)
	{
		enables -> LENABLE = atoi(argv[1]);
		enables -> RENABLE = atoi(argv[2]);
	}
	else
	{
		enables -> LENABLE = 1;
		enables -> RENABLE = 1;
	}
	
	int random; //random variable
	int sleep_time;	//delay between clicks
	POINT p; //pointer to a structure with the x & y of the cursor
	
	//start main while cycle
	
	while (1)
	{
		
		Sleep(100); // stop the program to avoid problem with the F7 key
		
		if (GetAsyncKeyState(0x76)  != 0) //detect when F7 is pressed
		{
			system("powershell (Write-Host \"`nAUTOCLICKER STARTED`n\" -ForegroundColor DarkGreen)"); //say the autoclicker is started
			Sleep(100); //stop the proprang for a second to avoid problems with F7 key
			
			//autoclicker loop
			
			while (1)
			{
			
				random = rand() % 21; //initialize the random value to randomize cps
				sleep_time = 20 + random; //set the random delay time
				Sleep(sleep_time);//delay beween clicks
			
				if (enables -> LENABLE && (GetAsyncKeyState(0x01) & 0x8000) != 0) //check if the left_click is enabled and if left button is held
				{
					if (GetCursorPos(&p)) //check the cursor
					{
						mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); //
						mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//autoclick
						continue;
					}
				}
				
				if (enables -> RENABLE && (GetAsyncKeyState(0x02) & 0x8000) != 0) //check if the right_click is enabled and if right button is held
				{
					if (GetCursorPos(&p)) // check the cursor
					{
						mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);//
						mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);//autoclick
						continue;
					}
				}
				if (GetAsyncKeyState(0x76) != 0) //detect when F7 is pressed
				{
					system("powershell (Write-Host \"`nAUTOCLICKER STOPPED`n\" -ForegroundColor Yellow)");//say that the autoclicker is topped
					break;
				}
				continue;
			}
		}
		if(GetAsyncKeyState(0x11) && GetAsyncKeyState(0x23))//detect when cntrl + end is pressed
		{
			system("powershell (Write-Host \"`nEXIT AUTOCLICKER`n\" -ForegroundColor Red)"); //say that you exit autoclicker
			break;
		}
		continue;
	}
	free(enables); //free the pointer to the ENABLES
	return 0;
}