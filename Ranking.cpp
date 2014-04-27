class Ranking : protected Util{
public:
    void imprimir();
    void lerPontos(int pontos);
};

void Ranking::imprimir(){
    centralizarTexto(" ----------------------",2,40);
    centralizarTexto("| Posicao | Pontuacao  |",3,40);
    centralizarTexto(" ----------------------",4,40);
    f.imprimirRanking();
    SetColor(14);
    centralizarTexto("Voltar - <ENTER>",28,40);
    while(getch() != 13);
}

void Ranking::lerPontos(int pontos){
    f.lerPontos(pontos);
}
