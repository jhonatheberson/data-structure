using namespace std;
#include <iostream>

int main(){
    int n, n1, n2;
    cout << "Informe um numero inteiro" << endl;
    cin >> n;

    while(n>10){
        n1 = n%10;
        n = n/10;
        n2 = n%10;
        if(n1 == n2){
            cout << "Existem dois numeros iguais consecutivos." << endl;
            return 0;
        }
    }
    return 0;
}
