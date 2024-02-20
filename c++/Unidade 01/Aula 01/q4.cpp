using namespace std;
#include <iostream>

int main(){
    int n;
    cout << "Informe o valor de n:" << endl;
    cin >> n;

   int cont = 1;

    while( (cont+2) < n){
        if( (cont*(cont+1)*(cont+2)) == n ){
            cout << n << " e um numero triangular." << endl;
            cout << cont << "*" << (cont+1) << "*" << (cont+2) << "=" << n << endl;
            return 0;
        }
        cont++;
    }

    cout << n << " nao e um numero triangular." << endl;
    return 0;
}
