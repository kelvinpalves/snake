class File : protected Util{
private:
    FILE *arquivo;
    void escrever(int pos);
public:
    void imprimirRanking();
    void lerPontos(int pontos);
};

void File::imprimirRanking(){
    char info[25];
    int l = 5;
    if((arquivo = fopen("/ranking.txt","r")) != NULL){
        while( (fgets(info, sizeof(info), arquivo))!=NULL ){
            centralizarTexto(info,l++,40);
            centralizarTexto(" ----------------------",l,40);
        }
        fclose(arquivo);
    }else{
        centralizarTexto(" Não foi possivel abrir o arquivo.",5,40);
    }
}

void File::lerPontos(int pontos){
    char pontosChar[4] = {'\0','\0','\0','\0'};
    char info[25];
    int pontosArray[10] = {0,0,0,0,0,0,0,0,0,0};
    char *result;
    int posicao = 0;
    int aux = 0;
    system("cls");
    if((arquivo = fopen("/ranking.txt","r")) != NULL){
        while(!feof(arquivo)){
            result = fgets(info,25,arquivo);
            int contPontos = 0;
            if(result){
                for(int i = 15; i < 19; i++){
                    pontosChar[contPontos] = ((char)info[i]);
                    contPontos++;
                }
                if(aux % 2 == 0){
                    pontosArray[posicao] = atoi(pontosChar);
                    posicao++;
                }
            }
            aux++;
        }
        fclose(arquivo);
    }
    pontos = 90;
    for(int i  = 0; i < 10; i++){
        if(pontos > pontosArray[i]){
            escrever(i);
            break;
        }
    }
}

void File::escrever(int pos){
    int auxRescrever = 9;
    char info[25];
    char *result;
    arquivo = fopen("/ranking.txt","r+");
    if(arquivo){
        for(int i = auxRescrever; i >= pos; i--){
            fseek(arquivo,(i*25),SEEK_SET);
            fgets(info,25,arquivo);
            printf("%s\n",info);
        }
    }else{
        printf("erro");
    }
}
