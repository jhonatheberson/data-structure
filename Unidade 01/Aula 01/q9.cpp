# include <iostream>

using namespace std;


int main(){

    int n;
    cout << "Informe o valor de n: " << endl;
    cin >> n;

    int v[n];
    int f[n];

    for(int i = 0;i<n;i++){
        cout << "informe o valor do vetor na posicao " << i << ":" << endl;
        cin >> v[i];
    }

    int cont = 0;
    int cont2 = 1;
    int fatorial = 1;
    while(cont<n){
        fatorial = 1;
        cont2 = 1;
         while(cont2<=v[cont]){
            fatorial = fatorial*cont2;
            cont2++;
         }
        f[cont] = fatorial;
        cont++;
    }

    for(int i = 0;i<n;i++){
        cout <<  v[i] << ": " << f[i] << endl;
    }

    return 0;
}
