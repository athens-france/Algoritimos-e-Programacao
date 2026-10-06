#include <iostream>

using namespace std;

void avancar(int** p);

int main()
{

    /*
    valor++       // move o ponteiro
    (*valor)++    // altera o valor apontado
    &valor        // endereço da variável ponteiro
    *valor        // valor apontado
    int        → valor inteiro
    int*       → endereço de um inteiro
    int**      → endereço de um ponteiro para inteiro
    */

    cout << "Implementação dos Ponteiros" << endl;
    int matriz[] = {1,2,3};
    int* valor = matriz;
    int* inicio = valor; // similar ao begin()

    // Print

    cout << valor << endl; // Endereço de memória
    cout << *valor << endl; // Valor de matriz[0]
    *valor++;
    cout << (*valor)++ << endl; // Valor de matriz[1] e depois incrementa +1
    cout << *(valor++) << endl; // Valor de matriz[2]

    // Chamando funções

    cout << endl; // Pulando linha para facilitar a visualização
    valor = inicio;
    avancar(&valor);
    for(int i=0; i<3; i++){
        cout << *(valor + i) << endl; // *(valor+2) dá out-of-bounds (undefined behavior)
    }
    // Resultado final do vetor {1,3,3}


    return 0;
}

void avancar(int** p){ // ponteiro de um endereço de uma variável (int &* valor)
    (*p)++; // Precedência dos operadores (p aponta para valor == matriz[0] após o inicio)
}