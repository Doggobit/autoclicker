#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "headers/ENABLES.h" //header file for the struct with the bools of right click & left click
#include <string.h>
#include "headers/calculate_ms.h"

#pragma comment(lib, "User32.lib") // link User32.lib
#pragma comment(lib, "calculate_ms.lib") // link calculate_ms.lib

int main(int argc, char** argv)
{
	int click = cps_to_ms(3);
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
		if((strcmp(argv[1], "0") == 0) || (strcmp(argv[1], "1") == 0) || ((strcmp(argv[2], "1")) == 0) || ((strcmp(argv[2], "0")) == 0)) //check if argv[1] or argv[2] is 0 or 1
		{
		enables -> LENABLE = atoi(argv[1]);
		enables -> RENABLE = atoi(argv[2]);
		}
		else //if something isn't right gets the error
		{
			system("powershell (Write-Host \"`nTHE ARG NEEDS TO BE 0(false) or 1(true)`n\" -ForegroundColor DarkRed)");
			return 1;
		}
	}
	else
	{
		enables -> LENABLE = 1;
		enables -> RENABLE = 1;
	}
	
	int random; //random variable
	int sleep_time;	//delay between clicks
	int cps_max; //max number of cps
	int cps_min; //minimum number of cps
	int delay_jitter; //jitter delay
	POINT p; //pointer to a structure with the x & y of the cursor
	
	system("powershell (Write-Host \"enter minimum cps -> \" -ForegroundColor DarkYellow -NoNewline)"); // Ask the user the minimum cps he wants to do
	scanf_s("%d", &cps_min); //gets an input with cps_min
	
	system("powershell (Write-Host \"`nenter maxium cps -> \" -ForegroundColor DarkYellow -NoNewline)");
	scanf_s("%d", &cps_max);
	
	system("powershell (Write-Host \"`nPRESS F7 TO START/STOP`n\" -ForegroundColor Cyan)");
	system("powershell (Write-Host \"`nPRESS CTRL + END TO BREAK`n\" -ForegroundColor Cyan)");
	
	if(!(cps_max >= cps_min))
	{
		system("powershell (Write-Host \"`n maxium cps needs to be higher than minimum cps!\" -ForegroundColor DarkRed )");
		return 1;
	}
	
	delay_jitter = cps_max;
	delay_jitter -= cps_min;
	cps_to_ms(delay_jitter);
	delay_jitter++;
	
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
			
				random = rand() % delay_jitter; //set the random value to randomize cps
				sleep_time = cps_min + random; //set the random delay time
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