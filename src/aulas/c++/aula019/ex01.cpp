#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


bool cre(const double& a, const double& b);


int main(){

    vector <double> temperaturas = {22.5, 25.0, 19.5, 28.0, 25.0, 30.5, 21.0};

    auto valor = find(temperaturas.begin(), temperaturas.end(), 25.0);

    cout << *valor << endl;

    int qtd = count(temperaturas.begin(), temperaturas.end(), 25.0);

    cout << qtd << endl;

    sort(temperaturas.begin(), temperaturas.end(), cre);

    cout << "Vector em ordem crescente: ";
    for(auto x : temperaturas) cout << x << " ";
    cout << endl;

    auto minimo = min_element(temperaturas.begin(), temperaturas.end());
    auto maximo = max_element(temperaturas.begin(), temperaturas.end());

    cout << "Mínimo: " << *minimo << endl;

    cout << "Máximo: " << *maximo << endl;

    double total = accumulate(temperaturas.begin(), temperaturas.end(), 0.0);

    cout << "Somatório total: " << total << endl;

    cout << "Média: " << total/temperaturas.size() << endl;


    return 0;
}


bool cre(const double& a, const double& b){
    return a < b; // crescente
}