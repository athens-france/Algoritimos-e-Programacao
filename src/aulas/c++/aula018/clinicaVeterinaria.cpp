#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Animal {
    int codigo = -1;
    string nome;
    string especie;
    string raca;
    double peso;
};

int buscarAnimal(const vector<Animal>& animais, int codigo);
void cadastrarAnimal(vector<Animal>& animais);
void exibirAnimal(const Animal& animal);
void exibirAnimais(const vector<Animal>& animais);
void consultarAnimal(const vector<Animal>& animais, int codigo);
void modificarAnimal(vector<Animal>& animais, int codigo);
void removerAnimal(vector<Animal>& animais, int codigo);


int main(){
    vector<Animal> animais; 
    int cod, opcao;

    cout << "EXERCÍCIO 1 - CADASTRO DE ANIMAIS DE UMA CLÍNICA VETERINÁRIA" << endl;
    
    while (opcao!=0){
        cout << "\n1 - Cadastrar animal" << endl;
        cout << "2 - Exibir todos os animais" << endl;
        cout << "3 - Consultar animal pelo código" << endl;
        cout << "4 - Modificar animal" << endl;
        cout << "5 - Remover animal" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cadastrarAnimal(animais);
            break;
        case 2:
            exibirAnimais(animais);
            break;
        case 3:
            cout << "Insira um código para buscar um animal: ";
            cin >> cod;
            consultarAnimal(animais, cod);
            break;
        case 4:
            cout << "Insira um código para modificar um animal: ";
            cin >> cod;
            modificarAnimal(animais, cod);
            break;
        case 5:
            cout << "Insira um código para remover um animal: ";
            cin >> cod;
            removerAnimal(animais, cod);
            break;
        case 0:
            cout << "Tchau...." << endl;
            break;
        
        default:
            cout << "Opção inválida!" << endl;
        }

    }


    return 0;
}

int buscarAnimal(const vector<Animal>& animais, int codigo) {
    for (int i = 0; i < animais.size(); i++) {
        if(animais[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void cadastrarAnimal(vector<Animal>& animais){
    int codigo = -1;
    double peso = 0;
    Animal animal;
    while (codigo<=0){
        cout << "\nInsira um código para o animal: ";
        cin >> codigo;
        if (buscarAnimal(animais, codigo) != -1){
            cout << "\nCódigo já existente!" << endl;
            codigo = -1;
        }
    }
    animal.codigo = codigo;
    cout << "Insira o nome do animal: ";
    cin >> animal.nome;
    cout << "Insira a espécie do animal: ";
    cin >> animal.especie;
    cout << "Insira a raça do animal: ";
    cin >> animal.raca;
    while (peso<=0){
        cout << "Insira um peso para o animal: ";
        cin >> peso;
        if (peso <= 0){
            cout << "\nPeso inválido!" << endl;
            peso = 0;
        }
    }
    animal.peso = peso;
    animais.push_back(animal);
}

void exibirAnimal(const Animal& animal){
    cout << "\nCódigo: " << animal.codigo << endl;
    cout << "Nome: " << animal.nome << endl;
    cout << "Espécie: " << animal.especie << endl;
    cout << "Raça: " << animal.raca << endl;
    printf("%.2f KG", animal.peso);
}

void exibirAnimais(const vector<Animal>& animais){
    if(animais.empty()){
        cout << "Não há animais cadastrados" << endl;
    }else{
        for (Animal bixo : animais){
            exibirAnimal(bixo);
            cout << endl;
        }
        cout << "\nAnimais cadastrados: " << animais.size() << endl;
    }
}

void consultarAnimal(const vector<Animal>& animais, int codigo){
    int indice = buscarAnimal(animais, codigo);
    if (indice != -1){
        exibirAnimal(animais[indice]);
    }else{
        cout << "O animal não foi encontrado :(" << endl;
    }
}

void modificarAnimal(vector<Animal>& animais, int codigo){
    int indice = buscarAnimal(animais, codigo);
    if (indice != -1) {
        double peso = 0;
        cout << "Novo nome do animal: ";
        cin >> animais[indice].nome;
        cout << "Confirme a espécie do animal: ";
        cin >> animais[indice].especie;
        cout << "Confirme a raça do animal: ";
        cin >> animais[indice].raca;
        while (peso<=0){
            cout << "Confime o peso do animal: ";
            cin >> peso;
            if (peso <= 0){
                cout << "Peso inválido!" << endl;
                cout << "Confirme de novo o peso do animal: ";
                peso = 0;
            }
        }
        animais[indice].peso = peso;
    } else if (indice == -1) {
        cout << "Animal não existe! :(" << endl;
    }
}

void removerAnimal(vector<Animal>& animais, int codigo){
    int indice = buscarAnimal(animais, codigo);
    if (indice != -1) {
        string escolha;
        cout << "Deseja mesmo apagar o animal? (s/n)" << endl;
        cin >> escolha;
        if (escolha == "S" || escolha == "s"){
            animais.erase(animais.begin() + indice);
            cout << "Animal apagado" << endl;
        }else{
            cout << "Ok, o cadastro do animal continua" << endl;
        }
    } else if (indice == -1) {
        cout << "Animal não existe! :(" << endl;
    }
}