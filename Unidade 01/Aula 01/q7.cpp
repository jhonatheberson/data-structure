using namespace std;
#include <iostream>

int main(){

    int qtdDias, i;
    cout << "Informe a quantidade de dias do mes:" << endl;
    cin >> qtdDias;
    cout << "Informe o dia em que comeca o mes:" << endl; //1 domingo, 2 segunda...
    cin >> i;

    int cont = 1, cont2 = 1, cont3 = 1, j = i, cont4=1;

    while(cont4<i){
        cout << "  ";
        cont4++;
    }

    while(cont<=qtdDias){
        while(cont<=7*cont2 && cont<=qtdDias && j<=7){

            cout << cont << "  ";
            cont++;
            j++;
        }
        cout << endl;
        j = 1;
        cont2++;

    }

    return 0;
}
