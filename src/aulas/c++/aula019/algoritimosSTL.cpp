#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric> // accumulate
#include <functional> // outras funções
#include <string> // getline
using namespace std;

bool positivo(const double& a);
bool iguais(const double& a, const double& b);
bool alfa(const char& a, const char& b);
bool alfabeticaInvertida(const char& a, const char& b);
bool alfabeto(const char& a);

int main(){


    for(int j = 65; j<123; j++){ // 65 - 122
        cout << char(j) << " ";
    }

    array <double, 7> temperaturas = {22.5, 25.0, 19.5, 28.0, 25.0, 30.5, 21.0};

    auto it = max_element(temperaturas.begin(),temperaturas.end());

    cout << endl << *it; // iterador = objeto que conecta containers e algoritmos != ponteiro, mas é semelhante

    cout << endl << *temperaturas.end();

    cout << endl << *temperaturas.begin();

    auto p = find(temperaturas.begin(), temperaturas.end(), 0);

    cout << *p; //  p == temperaturas.end() nenhum dos dois existem então é true

    char a = a;

    cout << positivo(a);

    /*
    struct->atributo == (*struct).atributo
    it->valor == (*it).valor
    */

    cout << endl;

    //char a[100] = {'f','r','a','s','e'};

    array <char, 5> frase = {'f','r','a','s','e'};

    sort(frase.begin(), frase.end(), alfa); // recebe o iterador da função, então não chama ela com alfa()
    
    cout << frase.data() << " ";
    
    vector <char> conteudo;
    string texto, filtrado;

    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Digite uma frase para coloca-lá em ordem alfabética: ";
    getline(std::cin, texto);

    /*
    if (std::getline(std::cin, texto)) {
        for (char c : texto) {
            unsigned char uc = static_cast<unsigned char>(c); // evita problemas com char signed
            if (uc >= 65 && uc <= 122) {
                filtrado.push_back(c);
            }
        }
    }
    */
    
    for(char t : texto) conteudo.insert(conteudo.end(), t);

    sort(conteudo.begin(), conteudo.end(), alfa);

    auto valido = remove_if(conteudo.begin(), conteudo.end(), alfabeto);
    conteudo.erase(valido, conteudo.end());


    //cout.write(conteudo.data(), conteudo.size());
    //conteudo.push_back('\0');
    
    
    cout << conteudo.data() << " ";
    

    conteudo.erase(conteudo.begin(), conteudo.end()); // somente para vector

    /*
    Modelo Mental:CONTAINER → ITERADORES → ALGORITMO → RESULTADO
    Evolução: CONTAINER → ITERADORES → ALGORITMO + FUNÇÃO PERSONALIZADA → RESULTADO
    */

    return 0;
}


// Função predicado
bool positivo(const double& a){
    return a>0;
}

// Função comparadora
bool iguais(const double& a, const double& b){
    return a == b;
}

bool alfa(const char& a, const char& b){
    return a < b; // alfabética
}

bool alfabeticaInvertida(const char& a, const char& b){
    return a < b; // alfabética
}

bool alfabeto(const char& a){
    return a > 64 && a < 123;
}