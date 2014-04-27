#ifndef CONIOSUB_H_INCLUDED
#define CONIOSUB_H_INCLUDED

typedef enum {NOCURSOR, SOLIDCURSOR, NORMALCURSOR}CURSOR_TYPE;

void gotoxy(int x,int y);// vá para linha coluna

void SetColor(int pValue);//seta a cor do foreground

void ClearConsoleToColors(int pValue, int pBackgroudColor); //seta a cor do background

void setcursortype(CURSOR_TYPE);

#endif // CONIOSUB_H_INCLUDED
