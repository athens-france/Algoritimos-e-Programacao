#include <iostream>
#include <array>
using namespace std;

struct Produto{ 
    int codigo = -1; 
    string nome; 
    double preco = -1; 
    int estoque = 0; 
};

void cadastrarProdutos(array<Produto, 5>&);
void exibirProdutos(const array<Produto, 5>&);
int buscarPorCodigo(const array<Produto, 5>&, int);
int contarEstoqueBaixo(const array<Produto, 5>&, int);


int main(){

    array<Produto, 5> produtos{};
    int codigo = 0, limite = 0;

    cout << "CONTROLE DE ESTOQUE\n" << endl;
    cadastrarProdutos(produtos);
    exibirProdutos(produtos);
    cout << "\nInforme um código para buscar: ";
    cin >> codigo;
    if (buscarPorCodigo(produtos, codigo)==-1){
        cout << "\nProduto não encontrado!" << endl;
    }else{
        codigo = buscarPorCodigo(produtos, codigo);
        cout << "\nProduto encontrado:" << endl;
        cout << "Produto " << codigo+1 << endl;
        cout << "Código: " << produtos[codigo].codigo << endl;
        cout << "Nome: " << produtos[codigo].nome << endl;
        cout << "Preço: " << produtos[codigo].preco << endl;
        cout << "Quantidade em estoque: " << produtos[codigo].estoque << endl;
    }
    cout << "\nDigite um limite para buscar produtos que estão abaixo desse limite de estoque: " << endl;
    cin >> limite;
    cout << "Abaixo de " << limite << ": " << contarEstoqueBaixo(produtos, limite) << endl;
    
    return 0;
}

void cadastrarProdutos(array<Produto, 5>&prod){
    for (int i=0; i<prod.size(); i++){
        while (prod[i].codigo < 0 || prod[i].preco < 0 || prod[i].estoque <= 0){
            cout << "Produto " << i+1 << endl;
            cout << "Código: " << endl;
            cin >> prod[i].codigo;
            cout << "Nome: " << endl;
            cin >> prod[i].nome;
            cout << "Preço: " << endl;
            cin >> prod[i].preco;
            cout << "Quantidade em estoque: " << endl;
            cin >> prod[i].estoque;
        }
        cout << "Produto " << i+1 << " cadastrado com sucesso" << endl;
    }
}

void exibirProdutos(const array<Produto, 5>&prod){
    for (int i=0; i<prod.size(); i++){
        cout << "\nProduto " << i+1 << ":" << endl;
        cout << "Código: " << prod[i].codigo << endl;
        cout << "Nome: " << prod[i].nome << endl;
        cout << "Preço: " << prod[i].preco << endl;
        cout << "Quantidade em estoque: " << prod[i].estoque << endl;
    }
}

int buscarPorCodigo(const array<Produto, 5>&prod, int cod){
    for (int i=0; i<prod.size(); i++){
        if (prod[i].codigo == cod){
            return i;
        }
    }
    return -1;
}

int contarEstoqueBaixo(const array<Produto, 5>&prod, int lim){
    int abaixo = 0;
    for (int i=0; i<prod.size(); i++){
        if (prod[i].estoque < lim){
            abaixo++;
        }
    }
    return abaixo;
}