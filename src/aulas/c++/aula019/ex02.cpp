#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct Aluno {
    string nome;
    double media;
};

bool cre(const double& a, const double& b);


int main(){

    vector <Aluno> Alunos = {
        {"Ana", 7.5},
        {"Beatriz", 8.0},
        {"Caio", 5.0},
        {"Davi", 6.3},
        {"João", 5.0}
    };

    /*
        • localizar o primeiro aluno aprovado
        • contar os alunos aprovados
        • ordenar os alunos pela média
        • localizar a maior média
        • localizar a menor média
        • verificar se todos foram aprovados
        • verificar se algum aluno foi reprovado
    */


    return 0;
}


bool cre(const double& a, const double& b){
    return a < b; // crescente
}