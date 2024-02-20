#include <iostream>
using namespace std;
void bubbleSort(int v[100], int n);
void bubbleSort(int v[100], int n){

    int aux;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<=n-1;j++){
            if(v[j] > v[j+1]){
                    aux = v[j+1];
                    v[j+1] = v[j];
                    v[j] = aux;
            }
        }
    }

    for(int i = 0;i<n;i++){
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

    bubbleSort(v, n);

    return 0;
}
