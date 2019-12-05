using namespace std;
#include <iostream>

void quebra(int n, int&prim, int &ult, int &miolo);
void quebra(int n, int&prim, int &ult, int &miolo){

    int x = 1;
    ult = n%10;
    n = n/10;
    miolo = 0;

    while(n>0){
        if(n/10 == 0){
            prim = n%10;
            n = n/10;
        }
        miolo = miolo + ((n%10) * x);
        x = x*10;

        n = n/10;
    }

    cout << prim << endl;
    cout << miolo << endl;
    cout << ult << endl;
    cout << "------------" << endl;

    if(prim != ult){
        cout << "Nao e palindromo." << endl;
        miolo = 0;
    }


}

int main(){

    int n, prim, ult, miolo;
    cout << "Informe o valor de n:" << endl;
    cin >> n;

    quebra(n, prim, ult, miolo);

    while(miolo/10>0){
        quebra(miolo, prim, ult, miolo);
    }


    return 0;
}
