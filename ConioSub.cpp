#include <conio.h>
#include <windows.h> 		//header file for gotoxy
#include <stdio.h>     	//header file for standard input output
#define TRUE 1
#define FALSE 0


COORD coord={0,0}; 			//this is global variable center of axis is set to the top left cornor of the screen

/*Esta função posiciona o cursor nas coordenadas x=linha y=coluna
Adaptada da biblioteca conio.h para o codeblocks */

void gotoxy(int x,int y){
	coord.X=x;
 	coord.Y=y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/*

Esta função é igual a textcolor da bilbioteca conio.h

*/

void SetColor(int pValue){
  WORD lColor;
  //We will need this handle to get the current background attribute
  HANDLE lStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO lConsole;

  //We use csbi for the wAttributes word.
  if(GetConsoleScreenBufferInfo(lStdOut, &lConsole)){
    //Mask out all but the background attribute, and add in the forgournd color
    lColor = (lConsole.wAttributes & 0xF0) + (pValue & 0x0F);
    SetConsoleTextAttribute(lStdOut, lColor);
  }
}

/*

Esta função define as cores de fundo do console
Tem a mesma função do textbackground da biblioteca conio.h

*/

void ClearConsoleToColors(int pValue, int pBackgroudColor){
  WORD lColor = ((pBackgroudColor & 0x0F) << 4) + (pValue & 0x0F);
  //Get the handle to the current output buffer...
  HANDLE lStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  //This is used to reset the carat/cursor to the top left.
  COORD lCoord = {0, 0};
  //A return value... indicating how many chars were written
  //   not used but we need to capture this since it will be
  //   written anyway (passing NULL causes an access violation).
  DWORD lCount;
  //This is a structure containing all of the console info
  // it is used here to find the size of the console.
  CONSOLE_SCREEN_BUFFER_INFO lConsole;
  //Here we will set the current color
  SetConsoleTextAttribute(lStdOut, lColor);
  if(GetConsoleScreenBufferInfo(lStdOut, &lConsole)){
    //This fills the buffer with a given character (in this case 32=space).
    FillConsoleOutputCharacter(lStdOut, (TCHAR) 32, lConsole.dwSize.X * lConsole.dwSize.Y, lCoord, &lCount);
    FillConsoleOutputAttribute(lStdOut, lConsole.wAttributes, lConsole.dwSize.X * lConsole.dwSize.Y, lCoord, &lCount);
    //This will set our cursor position for the next print statement.
    SetConsoleCursorPosition(lStdOut, lCoord);
  }
}

/*

Esta função realiza a definição do cursor
Sem cursor
Cursor normal
Insert Cursor


*/

typedef enum {NOCURSOR, SOLIDCURSOR, NORMALCURSOR}CURSOR_TYPE;

void setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO Curinfo; // console sursor
	switch(c)
	{
	case NOCURSOR:
		Curinfo.dwSize = 1; //cursor size
		Curinfo.bVisible = FALSE; // cursor
		break;
	case SOLIDCURSOR:
		Curinfo.dwSize = 100;
		Curinfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		Curinfo.dwSize = 20;
		Curinfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Curinfo);
}
