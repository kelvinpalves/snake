class Tela : protected Util{
public:
    void iniciar();
    void msgFinal();
    void jogar();
    Regras r;
private:
    void apresIni();
    void animeIni();
};

void Tela::jogar(){
    iniciar();
    r.iniciar();
}

void Tela::iniciar(){
    system("cls");
    SetColor(7);
    gerarLinhaHor(78,1,1,219);
    gerarLinhaHor(78,1,28,219);
    gerarLinhaVer(28,1,1,219);
    gerarLinhaVer(28,1,78,219);
}

void Tela::msgFinal(){
    Sleep(400);
    iniciar();
    centralizarTexto("-----------------------------",5,39);
    centralizarTexto("Pontuacao final:",6,39);
    centralizarTexto("-----------------------------",7,39);
    centralizarTexto("Total pontos....:",9,39,r.getPontos());
    centralizarTexto("Total comidas...:",10,39,r.getTotalCom());
    centralizarTexto("-----------------------------",12,39);
    centralizarTexto("Pressione ESC para sair.",13,39);
    centralizarTexto("-----------------------------",14,39);
    while(getch() != 27);
}
