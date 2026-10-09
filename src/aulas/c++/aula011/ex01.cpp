#include <iostream>
using namespace std;

double altura=0, peso=0, imc=0;

double lerPeso();
double lerAltura();
bool pesoValido(double peso);
bool alturaValida(double altura);
double calcularIMC(double altura, double peso);
string classificarIMC(double imc);
void exibirResultado();


int main(){
    exibirResultado();
    return 0;
}


double calcularIMC(double altura, double peso){
    if (pesoValido(peso)&&alturaValida(altura)){
        imc = peso/(altura*altura);
        cout << "Seu IMC é: " << imc;
        return imc;
    }else{
        return 0;
    }
}

double lerPeso(){
    cout << "Insira seu peso em quilos (ex. 75): ";
    cin >> peso;
    return peso;
}

double lerAltura(){
    cout << "Insira sua altura em metros (ex. 1.75): ";
    cin >> altura;
    return altura;
}

bool pesoValido(double peso){
    if (25<=peso&&peso<=635){
        return true;
    }else{
        cout << "Peso inválido";
        return false;
    }
}

bool alturaValida(double altura){
    if (2.51>=altura&&altura>=0.628){
        return true;
    }else{
        cout << "Altura inválida";
        return false;
    }
}

 string classificarIMC(double imc){
     if(imc<16){
         return "magreza grave";}
-    else if(imc<16&&imc<17){
+    else if(imc>=16&&imc<17){
         return "magreza moderada";}
     else if(imc>=17&&imc<18.5){
         return "magreza leve";}
    else if(imc>=18.5&&imc<25){
        return "saudável";}
    else if(imc>=25&&imc<30){
        return "sobrepeso";}
    else if(imc>=30&&imc<35){
        return "obesidade grau l";}
    else if(imc>=35&&imc<40){
        return "obesidade grau ll";}
    else{
        return "obesidade grau lll";}
}

void exibirResultado(){
    altura = lerAltura();
    peso = lerPeso();
    if (pesoValido(peso)&&alturaValida(altura)){
        imc = calcularIMC(altura,peso);
        cout << "\nVocê está com o estado: " <<classificarIMC(imc);
    }else{
        cout << "Altura ou peso inválido";
    }
}
