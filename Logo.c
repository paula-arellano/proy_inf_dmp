#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//	AVISO: Este codigo esta preparado para funcionar con AltEnter, separarlos puede desembocar en resultados no deseados.

int GetFontSize(HANDLE windowHandle, COORD *size)
{
	CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };
	if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
		return 0;

	*size = font.dwFontSize;
	return 1;
}

int SetFontSize(HANDLE windowHandle, COORD size)
{
	CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };
	if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
		return 0;

	font.dwFontSize = size;

	if (!SetCurrentConsoleFontEx(windowHandle, 0, &font))
		return 0;

	return 1;
}


void AltEnter(){
	keybd_event(VK_MENU,		0x38,		0,		0);

	keybd_event(VK_RETURN,		0x1c,		0,		0);

	keybd_event(VK_RETURN,		0x1c,		KEYEVENTF_KEYUP,		0);

	keybd_event(VK_MENU,		0x38,		KEYEVENTF_KEYUP,		0);

	return 0;
}

void logo() {
	system("COLOR 70");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size;
	if (GetFontSize(hConsole, &size)) {
		size.X += (SHORT)(size.X * 14);
		size.Y += (SHORT)(size.Y * 14);
		SetFontSize(hConsole, size);
	}

	//TAMAÑO 14 5-ESPACIOS || TAMAÑO 15 4-ESPACIOS

	SetConsoleTextAttribute(hConsole, 240);		//LETRAS NEGRAS EN FONDO BLANCO
	printf("     HOSPITAL       \n");
	
	//SetConsoleTextAttribute(hConsole, 252);		BLANCO
	//SetConsoleTextAttribute(hConsole, 204);		ROJO

	SetConsoleTextAttribute(hConsole, 252); printf("       ");	/* ROJO */	 SetConsoleTextAttribute(hConsole, 204); printf("   ");		/*ROJO*/	SetConsoleTextAttribute(hConsole, 252); printf("        \n");
	SetConsoleTextAttribute(hConsole, 252); printf("     ");	/* ROJO */	 SetConsoleTextAttribute(hConsole, 204); printf("       ");	/*ROJO*/	SetConsoleTextAttribute(hConsole, 252); printf("        \n");
	SetConsoleTextAttribute(hConsole, 252); printf("       ");	/* ROJO */	 SetConsoleTextAttribute(hConsole, 204); printf("   ");		/*ROJO*/	SetConsoleTextAttribute(hConsole, 252); printf("        \n");

	SetConsoleTextAttribute(hConsole, 255);
	system("PAUSE");

	if (GetFontSize(hConsole, &size)) {
		size.X = (SHORT)(size.X * 0.085);
		size.Y = (SHORT)(size.Y * 0.085);
		SetFontSize(hConsole, size);
	}

	system("color 07");
	system("cls");
}

//																					VOID MAIN
void main() {

	AltEnter();

	logo();

	printf("TEST\n");
	system("PAUSE");
}
