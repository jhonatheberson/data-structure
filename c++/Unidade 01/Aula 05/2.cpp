#include <iostream>
using namespace std;

int maior(int v[100], int n, int &repeticaoMaior){

    int maior = 0;

    for(int i = 0;i<n;i++){
        if(maior < v[i]){
            maior = v[i];
        }
    }

    for(int i = 0;i<n;i++){
        if(v[i] == maior){
            repeticaoMaior++;
        }
    }

    return maior;
}

int menor(int v[100], int n, int &repeticaoMenor){

    int menor = INT_MAX;

    for(int i = 0;i<n;i++){
        if(menor > v[i]){
            menor = v[i];
        }
    }

    for(int i = 0;i<n;i++){
        if(v[i] == menor){
            repeticaoMenor++;
        }
    }

    return menor;
}

int main(){

    int n;
    cout << "Informe um valor para n:" << endl;
    cin >> n;

    int v[n], maiorElemento, menorElemento;
    int repeticaoMaior = 0, repeticaoMenor = 0;

    for(int i = 0;i<n;i++){
        cin >> v[i];
    }

    maiorElemento = maior(v, n, repeticaoMaior);
    menorElemento = menor(v, n, repeticaoMenor);
    cout << "Maior elemento: " << maiorElemento << ". Repete-se " << repeticaoMaior << " vezes." << endl;
    cout << "Menor elemento: " << menorElemento << ". Repete-se " << repeticaoMenor << " vezes." << endl;



    return 0;
}
