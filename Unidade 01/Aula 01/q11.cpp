#include <iostream>
#include <cmath>
using namespace std;


int main(){

    int h;
    cout << "Informe o valor de h:" << endl;
    cin >> h;

    int cont1 = 1, i, j;
    while(cont1<=h){
        for(i = 1;i<=h;i++){
            for(j = 1;j<=h;j++){
                if(sqrt(((i*i)+(j*j))) == cont1 && i<=j){
                    cout << cont1 << " (" << i << "." << j << ")" <<endl;
                }
            }
        }

        cont1++;
    }

    return 0;
}
