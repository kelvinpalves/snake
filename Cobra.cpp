class Cobra{
private:
    int linha, coluna;
public:
    Cobra();
    Cobra(int l, int c);
    void setLinha(int l) {this->linha = l;};
    void setColuna (int c) {this->coluna = c;};
    int getLinha(){return this->linha;};
    int getColuna(){return this->coluna;};
};
Cobra::Cobra(){}

Cobra::Cobra(int l, int c){
    this->linha = l;
    this->coluna = c;
}
