#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Aluno {
    string nome;
    double media;
};

bool aprovado(const Aluno & pessoa);
bool cre(const Aluno& a, const Aluno& b);
bool minima(const Aluno& a, const Aluno& b);


int main(){

    vector <Aluno> alunos = {
        {"Ana", 7.5},
        {"Beatriz", 8.0},
        {"Caio", 6.0},
        {"Davi", 9.3},
        {"João", 6.0}
    };

    auto passou = find_if(alunos.begin(), alunos.end(), aprovado);

    if (passou != alunos.end()) {
        cout << passou->nome << " (primeiro aprovado): ";
        cout << passou->media << endl;
    } else {
        cout << "Ninguém foi aprovado" << endl;
    }

    int passados = count_if(alunos.begin(), alunos.end(), aprovado);
    cout << "Aprovados: " << passados << endl;

    sort(alunos.begin(), alunos.end(), cre);

    cout << "Lista em ordem crescente:" << endl;

    for(auto a : alunos){cout << a.nome << ": " << a.media << endl;};

    auto maior = max_element(alunos.begin(), alunos.end(), cre);

    cout << "Maior média: " << maior->media << endl;

    auto menor = max_element(alunos.begin(), alunos.end(), minima);

    cout << "Menor média: " << menor->media << endl;

    auto todos = all_of(alunos.begin(), alunos.end(), aprovado);

    if (todos) {
        cout << "Todos foram aprovados!" << endl;
    } else {
        cout << "Nem todos foram aprovados..." << endl;
    }

    auto repetente = any_of(alunos.begin(), alunos.end(), aprovado);

    if (!repetente) {
        cout << "Alguém reprovou..." << endl;
    } else {
        cout << "Ninguém reprovou!" << endl;
    }


    return 0;
}


bool cre(const Aluno& a, const Aluno& b){
    return a.media < b.media; // crescente
}

bool aprovado(const Aluno & pessoa){
    return pessoa.media >= 6.0;
}

bool minima(const Aluno& a, const Aluno& b){
    return a.media > b.media; // decrescente
}