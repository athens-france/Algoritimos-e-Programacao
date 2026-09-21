#include <iostream>
#include <array>
using namespace std;

void preencherNotas(array<double, 8>&);
void exibirNotas(const array<double, 8>&);
double calcularMedia(const array<double, 8>&);
double maiorNota(const array<double, 8>&);
double menorNota(const array<double, 8>&);
int contarAprovados(const array<double, 8>&);


int main(){

    array<double, 8> notas{};

    cout << "PAINEL DE NOTAS DA TURMA" << endl;
    preencherNotas(notas);
    exibirNotas(notas);
    cout << "Média: " << calcularMedia(notas) << endl;
    cout << "Maior nota: " << maiorNota(notas) << endl;
    cout << "Menor nota: " << menorNota(notas) << endl;
    cout << "Aprovados: " << contarAprovados(notas) << "/8 (média 6)" << endl;

    return 0;
}


void preencherNotas(array<double, 8>&notas){
    for (int i=0; i<8; i++){
        double nota = -1.0;
        while (nota<0||nota>10){
            cout << "Digite a nota do aluno "<< i+1 <<" (entre 0 e 10): " << endl;
            cin >> nota;
        }
        notas[i] = nota;
    }
    cout << "Notas preenchidas com sucesso" << endl;    
}

void exibirNotas(const array<double, 8>&notas){
    for(int i = 0; i<notas.size(); i++){
        cout << "Nota do aluno " << i+1 << ": " << notas[i] << endl;
    }
}

double calcularMedia(const array<double, 8>&notas){
    double media = 0;
    for(int i = 0; i<notas.size(); i++){
        media+=notas[i];
    }
    return media/notas.size();
}

double maiorNota(const array<double, 8>&notas){
    double maior = notas[0];
    for(int i = 0; i<notas.size(); i++){
        if (notas[i]>maior){
            maior = notas[i];
        }
    }
    return maior;
}

double menorNota(const array<double, 8>&notas){
    double menor = notas[0];
    for(int i = 0; i<notas.size(); i++){
        if (notas[i]<menor){
            menor = notas[i];
        }
    }
    return menor;
}

int contarAprovados(const array<double, 8>&notas){
    double aprovados = 0;
    for(int i = 0; i<notas.size(); i++){
        if (notas[i]>=6){
            aprovados++;
        }
    }
    return aprovados;
}