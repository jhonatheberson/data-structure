#include <iostream>
#define MAX 100
using namespace std;

void preencher(int v[MAX], int m[MAX][MAX], int n);
void preencher(int v[MAX], int m[MAX][MAX], int n){

    for(int i = 0;i<n;i++){
        cout << "Informe o valor do vetor na posicao " << i << ":" << endl;
        cin >> v[i];
    }

    cout << "-----------------" << endl;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << "Informe o valor da matriz na posicao " << i << "." << j << ":" << endl;
            cin >> m[i][j];
        }
    }

    cout << "-----------------" << endl;
    cout << "vetor:" << endl;
    for(int i = 0;i<n;i++){
        cout << v[i] << " " << endl;
    }

    cout << "matriz:" << endl;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

}

int main(){

    int n;

    cout << "Informe o valor de n:" << endl;
    cin >> n;

    int v[n];
    int m[n][n];

        for(int i = 0;i<n;i++){
        cout << "Informe o valor do vetor na posicao " << i << ":" << endl;
        cin >> v[i];
    }

    cout << "-----------------" << endl;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << "Informe o valor da matriz na posicao " << i << "." << j << ":" << endl;
            cin >> m[i][j];
        }
    }

    cout << "-----------------" << endl;
    cout << "vetor:" << endl;
    for(int i = 0;i<n;i++){
        cout << v[i] << " " << endl;
    }

    cout << "matriz:" << endl;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    int cont = 0, cont2=0;
    int soma[n];
    while(cont < n){
        for(int i = 0;i<n;i++){
            cout << v[i] <<  "*" << m[i][cont] << " = " <<  v[i]*m[i][cont] << endl;
            cont2 = cont2 + (v[i]*m[i][cont]);
        }
        cout << "cont2: " << cont2 << endl;
        soma[cont] = cont2;
        cont2=0;
        cont++;
    }

    cout << "Vetor soma [ ";
    for(int i = 0;i<n;i++){
        cout << soma[i] << " ";
    }
    cout << "]";

    return 0;
}
