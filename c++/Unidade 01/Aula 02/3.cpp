using namespace std;
#include <iostream>

bool divisao(int &m, int &n, int d);
bool divisao(int &m, int &n, int d){

    if(m%d == 0 || n%d == 0){
            if(m%d == 0){
                m = m/d;
            }
            if(n%d == 0){
                n = n/d;
            }
        return true;
    }

    else{
        return false;
    }

}



int main(){

    int m,n,d;
    cout << "Informe o valor de m:" << endl;
    cin >> m;
    cout << "Informe o valor de n:" << endl;
    cin >> n;
    cout << "Informe o valor de d:" << endl;
    cin >> d;

    cout << m/d << " " << n/d << endl;
    int cont = 1, mmc = 1;

    while(m>1 || n >1){
        if(divisao(m,n,cont) == true){
            mmc = mmc*cont;
        }
        cont++;
    }

    cout << "o mmc e: " << mmc << endl;
    return 0;
}
