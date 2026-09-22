#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void mudarVetor(const vector<int>& numeros);

int main(){

    cout << "Vector" << endl;

    vector<int> numeros {5,6,7,8}; // começa vazio e pode crescer
    vector<int> numeros1 {1,2,3,4};

    reverse(numeros.begin(), numeros.end());
    reverse(numeros1.begin(), numeros1.end());

    for (int i=0; i<numeros1.size(); i++){
        numeros.push_back(numeros1[i]);
    }
    
    reverse(numeros.begin(), numeros.end());

    for (int i=0; i<numeros.size(); i++){
        cout << numeros.at(i) << " ";
    }


    cout << endl;
    mudarVetor(numeros); // tudo 1
    cout << endl;

    vector<int> numeros2 {5,6,7,8}; // começa vazio e pode crescer
    vector<int> numeros3 {1,2,3,4};

    for (int i=0; i<numeros3.size(); i++){
        numeros2.push_back(numeros3[i]);
    }

    sort(numeros2.begin(), numeros2.end());

    for (int i=0; i<numeros2.size(); i++){
        cout << numeros2.at(i) << " ";
    }

    return 0;
}

void mudarVetor(const vector<int>& numeros){
    for (int valores:numeros){
        valores %= 2;
        cout << valores << " ";
    }
}