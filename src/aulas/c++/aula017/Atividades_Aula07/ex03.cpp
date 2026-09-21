#include <iostream>
#include <array>
using namespace std;

void preencherMatriz(array<array<int, 3>, 3>&);
void exibirMatriz(const array<array<int, 3>, 3>&);
int somarElementos(const array<array<int, 3>, 3>&);
int maiorElemento(const array<array<int, 3>, 3>&);
int somarLinha(const array<array<int, 3>, 3>&, int);


int main(){

    cout << "MATRIZ COM STD::ARRAY" << endl;

    array<array<int, 3>, 3> matriz{};
    int linha = -1;

    preencherMatriz(matriz);
    exibirMatriz(matriz);
    cout << "Soma de todos os 9 elementos: " << somarElementos(matriz) << endl;
    cout << "Maior elemento da matriz: " << maiorElemento(matriz) << endl;
    while (linha<1||linha>3){
        cout << "Insira uma linha para somar seus 3 elementos (1-3): ";
        cin >> linha;
    }
    cout << "Soma dos elementos da linha " << linha << ": " << somarLinha(matriz, linha-1) << endl;

    return 0;
}


void preencherMatriz(array<array<int, 3>, 3>&matriz){
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[0].size(); j++) {
            cout << "Valor [" << i+1 << "][" << j+1 << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void exibirMatriz(const array<array<int, 3>, 3>&matriz){
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[0].size(); j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int somarElementos(const array<array<int, 3>, 3>&matriz){
    int soma = 0;
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[0].size(); j++) {
            soma+=matriz[i][j];
        }
    }
    return soma;
}

int maiorElemento(const array<array<int, 3>, 3>&matriz){
    int maior = matriz[0][0];
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[0].size(); j++) {
            if (matriz[i][j]>maior){
                maior = matriz[i][j];
            }
        }
    }
    return maior;
}

int somarLinha(const array<array<int, 3>, 3>&matriz, int linha){
    int soma = 0;
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[0].size(); j++) {
            if (i == linha){
                soma += matriz[i][j];
            }else{
                break;
            }
        }
    }
    return soma;
}