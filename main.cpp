#include <stdio.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "ConioSub.cpp"
#include "Util.cpp"
#include "Cobra.cpp"
#include "Regras.cpp"
#include "Tela.cpp"
#include "Sobre.cpp"
#include "Menu.cpp"

int main()
{
    Menu menu;
    menu.gerarMenu();
    gotoxy(0,35);
    SetColor(7);
    return 0;
}
