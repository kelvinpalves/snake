#define coluna 40

class Sobre : protected Util{
public:
    void imprimir();
private:
    int linha = 3;
};

void Sobre::imprimir(){
    SetColor(7);
    centralizarTexto("SNAKE C++",linha,coluna);
    linha += 3;
    centralizarTexto("O jogo foi desenvolvido apenas por diversao.",linha++,coluna);
    centralizarTexto("Provavelmente possui falhas e melhorias que podem ser aplicadas.",linha++,coluna);
    centralizarTexto("Entre em contato e mande sua sugestao, ou reporte um bug.",linha++,coluna);
    SetColor(5);
    centralizarTexto("kelvinpalves@gmail.com",linha++,coluna);
    SetColor(7);
    centralizarTexto("Durante o jogo eh possivel ajustar a velocidade.",linha++,coluna);
    centralizarTexto("Basta pressionar +/-, com velocidades de 10 a 90.",linha++,coluna);
    centralizarTexto("Conforme aumenta a velocidade, o alimento gera mais pontos.",linha++,coluna);
    centralizarTexto("Abaixo tabela de pontuacao:",linha++,coluna);
    centralizarTexto("--------------------------------------------------------",linha++,coluna);
    centralizarTexto("Velocidade entre 70 e 90, acrescentam 6 pontos.",linha++,coluna);
    centralizarTexto("Velocidade entre 40 e 60, acrescentam 4 pontos.",linha++,coluna);
    centralizarTexto("Velocidade entre 10 e 30, acrencentam 2 pontos.",linha++,coluna);
    centralizarTexto("--------------------------------------------------------",linha++,coluna);
    centralizarTexto("Possui um ranking com as 10 melhores pontuacoes.",linha++,coluna);
    SetColor(14);
    centralizarTexto("Voltar - <ENTER>",28,coluna);
    while(getch() != 13);
}
