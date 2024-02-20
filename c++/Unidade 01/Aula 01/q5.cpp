using namespace std;
#include <iostream>

int main(){
    int i, j;
    cout << "informe o valor de i:" << endl;
    cin >> i;
    cout << "Informe o valor de j:" << endl;
    cin >> j;

    int mdc = 1, cont = 1;
    while(cont<=i && cont<=j){
        if(i%cont == 0 && j%cont==0){
            mdc = mdc*cont;
        }
        cont++;
    }
    cout << mdc;

    return 0;
}
