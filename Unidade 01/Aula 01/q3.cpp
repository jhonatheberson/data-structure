using namespace std;
#include <iostream>

int main(){

    int n, i, j;
    cout << "Informe o valor de n:" << endl;
    cin >> n;
    cout << "Informe o valor de i:" << endl;
    cin >> i;
    cout << "Informe o valor de j:" << endl;
    cin >> j;

    int cont = 0;
    int cont2 = 0;
    while(cont<n){

        if(cont2%i == 0 || cont2%j==0){
            cout << cont2 << " ";
            cont++;
        }
        cont2++;
    }

    return 0;
}
