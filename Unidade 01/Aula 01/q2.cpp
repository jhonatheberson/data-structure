using namespace std;
#include <iostream>

int main(){
    int n, ultimoDigito, primeiroDigito;
    cout << "Informe um valor inteiro" << endl;
    cin >> n;

    ultimoDigito = n%10;
    while(n>0){
        primeiroDigito = n%10;
        n = n/10;
    }

    if(ultimoDigito == primeiroDigito){
        cout << "iguais " << endl;
    }
    else {
        cout << "Distintos" << endl;
    }
    return 0;
}
