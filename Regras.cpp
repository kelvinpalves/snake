class Regras : public Util{
public:
    Cobra cobras[300];
    void iniciar();
    int getPontos() {return this->pontos;};
    int getTotalCom() {return this->totalCom;};
private:
    int direcao = 0, tamanho = 5;
    int colunaCom, linhaCom;
    int velocidade = 50;
    int pontos = 0, totalCom = 0;
    void mover();
    void testes();//Apagar após desenvolvimento
    void apagarUltimo();
    int verificarColisao(int l, int c);
    void setDirecaoAtual(int tc);
    void setPrimeiro(int direcao);
    void atualizarNodos();
    void imprimir();
    void imprimirCom();
    void verificarComeu();
    void imprimirPontos();
    void alterarVelocidade(int vl);
    void imprimirVelocidade();
    void calcPontos();
    void pause();
    void imprimirPause(int cor);
};

void Regras::iniciar(){
    int val = 20;
    for(int i = 0; i < tamanho; i++){
        Cobra c(20,val--);
        cobras[i] = c;
    }
    srand(time(NULL));
    imprimirVelocidade();
    imprimirPontos();
    imprimirPause(14);
    imprimirCom();
    mover();
}

void Regras::mover(){
    int tc;
    while(tc != 27){
        if(kbhit()){
            tc = getch();
            if(tc == 224){
                tc = getch();
                setDirecaoAtual(tc);
            }else if(tc == 43 || tc == 45){
                alterarVelocidade(tc);
            }else if(tc == 80 || tc == 112){
                imprimirPause(3);
                pause();
            }
        }
        apagarUltimo();
        atualizarNodos();
        setPrimeiro(direcao);
        imprimir();
        verificarComeu();
        tc = verificarColisao(cobras[0].getLinha(),cobras[0].getColuna());
        Sleep(velocidade);
    }
}

void Regras::alterarVelocidade(int vl){
    velocidade = (vl == 43) ? ((velocidade > 20) ? velocidade - 10 : velocidade) : ((velocidade < 100) ? velocidade + 10 : velocidade);
    imprimirVelocidade();
}

void Regras::testes(){
    gotoxy(0,0);
    printf("C1: %i, L1: %i\n",cobras[0].getColuna(),cobras[0].getLinha());
    printf("C2: %i, L2: %i\n",cobras[1].getColuna(),cobras[1].getLinha());
    printf("C3: %i, L3: %i\n",cobras[2].getColuna(),cobras[2].getLinha());
    printf("C4: %i, L4: %i\n",cobras[3].getColuna(),cobras[3].getLinha());
    printf("C5: %i, L5: %i\n",cobras[4].getColuna(),cobras[4].getLinha());
}

void Regras::imprimir(){
    SetColor(2);
    for(int i = 0; i < tamanho; i++){
        gotoxy(cobras[i].getColuna(),cobras[i].getLinha());
        printf("#");
    }
}

void Regras::atualizarNodos(){
    for(int i = (tamanho-1); i > 0;i--){
        cobras[i].setColuna(cobras[i-1].getColuna());
        cobras[i].setLinha(cobras[i-1].getLinha());
    }
}

void Regras::apagarUltimo(){
    gotoxy(cobras[tamanho-1].getColuna(),cobras[tamanho-1].getLinha());
    printf(" ");
}

int Regras::verificarColisao(int l, int c){
    if(l == 2  || l == 27 || c == 2 || c == 77){
        return 27;
    }else{
        for(int i = 1; i < tamanho; i++){
            if(cobras[0].getColuna() == cobras[i].getColuna() && cobras[0].getLinha() == cobras[i].getLinha()){
                return 27;
            }
        }
    }
}

void Regras::setDirecaoAtual(int tc){
    switch(tc){
        case 72:{
            if(direcao == 0 || direcao == 1){
                direcao = 2;
            }
        }break;
        case 80:{
            if(direcao == 0 || direcao == 1){
                direcao = 3;
            }
        }break;
        case 75:{
            if(direcao == 2 || direcao == 3){
                direcao = 1;
            }
        }break;
        case 77:{
            if(direcao == 2 || direcao == 3){
                direcao = 0;
            }
        }break;
    }
}

void Regras::setPrimeiro(int direcao){
    switch(direcao){
        case 0: {
            cobras[0].setColuna(cobras[0].getColuna() + 1);
        }break;
        case 1:{
            cobras[0].setColuna(cobras[0].getColuna() - 1);
        }break;
        case 2:{
            cobras[0].setLinha(cobras[0].getLinha() - 1);
        }break;
        case 3:{
            cobras[0].setLinha(cobras[0].getLinha() + 1);
        }break;
    }
}

void Regras::imprimirCom(){
    int auxCol, auxLin,colisao = 0;
    gotoxy(0,0);
    auxCol = (rand() % 74) + 3;
    auxLin =(rand() % 24) + 3;
    if(auxCol == colunaCom || auxLin == linhaCom){
        colisao = 1;
    }else{
        for(int i = 0; i < tamanho; i++){
            if(cobras[i].getColuna() == auxCol || cobras[i].getLinha() == auxLin){
                colisao = 1;
            }
        }
    }
    if(colisao == 0){
        colunaCom = auxCol;
        linhaCom = auxLin;
    }else{
        imprimirCom();
    }

    gotoxy(colunaCom,linhaCom);
    SetColor(12);
    printf("o");
}

void Regras::verificarComeu(){
    if(cobras[0].getColuna() == colunaCom && cobras[0].getLinha() == linhaCom){
        cobras[tamanho].setLinha(cobras[tamanho-1].getLinha());
        cobras[tamanho].setColuna(cobras[tamanho-1].getColuna());
        tamanho++;
        calcPontos();
        totalCom++;
        imprimirPontos();
        imprimirCom();
    }
}

void Regras::calcPontos(){
    int aux;

    if(this->velocidade >= 20 && this->velocidade <= 40){
        aux = 6;
    }else if(this->velocidade >= 50 && this->velocidade <= 70){
        aux = 4;
    }else{
        aux = 2;
    }

    this->pontos += aux;
}

void Regras::imprimirPontos(){
    SetColor(14);
    gotoxy(3,29);
    printf("Pontos: ");
    SetColor(3);
    printf("%.3i",this->pontos);
}

void Regras::imprimirVelocidade(){
    SetColor(13);
    gotoxy(14,29);
    printf(" || ");
    SetColor(14);
    printf("Velocidade(+/-): ");
    SetColor(3);
    printf("%.3i",(110 - this->velocidade));
}

void Regras::pause(){
    int tc = 0;
    while(tc != 80 && tc != 112){
        tc = getch();
    }
    imprimirPause(14);
}

void Regras::imprimirPause(int cor){
    gotoxy(38,29);
    SetColor(13);
    printf(" || ");
    SetColor(cor);
    printf("[P]ause");
}
