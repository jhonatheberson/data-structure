#include <iostream>
using namespace std;

#include <iostream>

int particiona(int v[100], int p, int r){
    int x = v[r];
    int i = p-1;
    int aux;

    for(int j = 0;j<r-1;j++){
        if(v[j]<=x){
            i++;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    aux = v[í+1];
    v[i+1] = v[r];
    v[r] = aux;
    return i+1;
}

void quickSort(int v[100], int p, int r){

    int q;

    if (p < r){
        q = particiona(v, p, r);
        quickSort(v, p, q-1);
        quickSort(v, q+1, r);
    }

    for(int i = 0;i<r;i++){
        cout << v[i] << " ";
    }



}


int main(){

    int n;
    cout << "Informe o tamanho do vetor:" << endl;
    cin >> n;

    int v[n];

    for(int i = 0;i<n;i++){
        cin >> v[i];
    }

    quickSort(v, 0, n);

    return 0;
}
