class Util{
protected:
    void centralizarTexto(char *op, int row, int length);
    void centralizarTexto(char *op, int row, int length, int t);
    void gerarLinhaHor(int total, int ini, int row, int caract);
    void gerarLinhaVer(int total,int ini, int col, int caract);
};

void Util::centralizarTexto(char *op, int row, int length){
    char option[strlen(op)];
    strcpy(option,op);

    int tamPal = strlen(option);
    int met = ceil(((double)tamPal/2));
    int posIni = length - met;
    for(int i = 0; i < tamPal; i++){
        gotoxy(++posIni,row);
        printf("%c",option[i]);
    }
}

void Util::centralizarTexto(char *op, int row, int length, int t){
    char option[strlen(op)];
    strcpy(option,op);

    int tamPal = strlen(option);
    int met = ceil(((double)tamPal/2));
    int posIni = length - met;
    for(int i = 0; i < tamPal; i++){
        gotoxy(++posIni,row);
        printf("%c %.4i",option[i],t);
    }
}

void Util::gerarLinhaHor(int total, int ini, int row, int caract){
    for(int i = 0; i < total; i++){
        gotoxy(ini++,row);
        printf("%c",caract);
    }
}

void Util::gerarLinhaVer(int total,int ini, int col, int caract){
    for(int i = 0; i < total; i++){
        gotoxy(col,ini++);
        printf("%c",caract);
    }
}
