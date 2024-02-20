using namespace std;
#include <iostream>

void celulas(float v, int &um, int &cinco, int &dez, int &vinte);
void celulas(float v, int &um, int &cinco, int &dez, int &vinte){

    cout << (int)v/vinte << endl;
    v = (int)v%vinte;
    cout << (int)v/dez << endl;
    v = (int)v%dez;
    cout << (int)v/cinco << endl;
    v = (int)v%cinco;
    cout << (int)v/um << endl;

}

int main(){

    float v;
    cout << "Informe um valor:" << endl;
    cin >> v;

    int cUm = 1, cCinco = 5, cDez = 10, cVinte = 20;
    celulas(v, cUm, cCinco, cDez, cVinte);

    return 0;
}
