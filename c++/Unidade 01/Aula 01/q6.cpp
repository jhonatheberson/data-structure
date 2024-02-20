using namespace std;
#include <iostream>

int main(){
    int a,b;
    cout << "Informe o valor de a: " << endl;
    cin >> a;
    cout << "Informe o valor de b:" << endl;
    cin >> b;

    int cont = 1;
    while(cont<=a && cont<=b){
        if(a%cont==0 && b%cont==0){
            a = a/cont;
            b = b/cont;
            cont = 1;
        }
        cont++;
    }

    cout << "Fracao irredutivel: " << a << "/" << b;
    return 0;
}
