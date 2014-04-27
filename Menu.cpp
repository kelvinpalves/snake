class Menu : protected Util{
private:
    Tela tela;
    Sobre sobre;
    int posCursor = 0,jogar = 0;
    void gerarGradeExt();
    void gerarGradeCon();
    void execMenu();
    void moverCursor(int boolean);
    void acao();
    void iniciarJogo();
    void sobreOp();
    void setPosMover(int c, int l, int op);
    void rankOp();
public:
    void gerarMenu();
};

void Menu::gerarMenu(){
    setcursortype(NOCURSOR);
    system("cls");
    SetColor(7);
    gerarGradeExt();
    gerarGradeCon();
    SetColor(2);
    centralizarTexto("SNAKE C++",5,39);
    centralizarTexto("----------------------------------",6,39);
    SetColor(7);
    gotoxy(37,12);
    printf("Iniciar");
    gotoxy(37,14);
    printf("Sobre");
    gotoxy(37,16);
    printf("Sair");
    SetColor(2);
    centralizarTexto("Desenvolvido por KELVIN ALVES",28,39);
    centralizarTexto("----------------------------------",29,39);
    SetColor(7);
    execMenu();
    if(jogar == 1){
        Sleep(1500);
        jogar = 0;
        system("cls");
        SetColor(7);
        gerarGradeExt();
        centralizarTexto("Seus pontos: ",4,37,tela.r.getPontos());
        centralizarTexto("-----------------------",5,40);
        SetColor(14);
        centralizarTexto("Menu - <ENTER>",28,40);
        while(getch() != 13);
        Menu menu;
        menu.gerarMenu();
    }
}

void Menu::gerarGradeExt(){
    gerarLinhaHor(80,0,0,219);
    gerarLinhaHor(80,0,30,219);
    gerarLinhaVer(30,0,0,219);
    gerarLinhaVer(30,0,79,219);
}

void Menu::gerarGradeCon(){
    gerarLinhaVer(12,11,30,186);
    gerarLinhaVer(12,11,49,186);
    gerarLinhaHor(18,31,10,205);
    gerarLinhaHor(18,31,23,205);
    gerarLinhaHor(1,30,10,201);
    gerarLinhaHor(1,30,23,200);
    gerarLinhaHor(1,49,10,187);
    gerarLinhaHor(1,49,23,188);
}

void Menu::execMenu(){
    int tc = 0;
    SetColor(7);
    gotoxy(32,12);
    printf(">");
    while(tc != 13){
        tc = getch();
        if(tc == 224){
            tc = getch();
            switch(tc){
                case 72: moverCursor(0); break;
                case 80: moverCursor(1); break;
            }
        }
    }
    acao();
}

void Menu::setPosMover(int c, int l, int op){
    gotoxy(c,l);
    printf(">");
    if(op == 0){
        l += 2;
    }else{
        l -= 2;
    }
    gotoxy(c,l);
    printf(" ");
}

void Menu::moverCursor(int boolean){
    switch(boolean){
        case 0:{
            if(this->posCursor == 1){
                setPosMover(32,12,boolean);
                this->posCursor = 0;
            }else if(this->posCursor == 2){
                setPosMover(32,14,boolean);
                this->posCursor = 1;
            }
        }break;
        case 1:{
            if(this->posCursor == 0){
                setPosMover(32,14,boolean);
                this->posCursor = 1;
            }else if(this->posCursor == 1){
                setPosMover(32,16,boolean);
                this->posCursor = 2;
            }
        }break;
    }
}

void Menu::sobreOp(){
    system("cls");
    gerarGradeExt();
    sobre.imprimir();
    this->posCursor = 0;
    gerarMenu();
}

void Menu::rankOp(){
    system("cls");
    gerarGradeExt();
    this->posCursor = 0;
    gerarMenu();
}

void Menu::acao(){
    switch(this->posCursor){
        case 0: jogar = 1;iniciarJogo(); break;
        case 1: sobreOp();break;
        case 2: system(0); break;
    }
}

void Menu::iniciarJogo(){
    tela.jogar();
}
