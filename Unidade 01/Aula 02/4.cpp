#define MAX 100
#include <iostream>
using namespace std;

void intersec(int A[MAX+1], int B[MAX+1], int C[MAX+1]);
void intersec(int A[MAX+1], int B[MAX+1], int C[MAX+1]){
    int n;
    cout << "Informe o tamanho do vetor:" << endl;
    cin >> n;

    for(int i = 1;i<=n;i++){
        cout << "A na posicao " << i << endl;
        cin >> A[i];

    }
    for(int i = 1;i<=n;i++){
        cout << "B na posicao " << i << endl;
        cin >> B[i];
    }

    int contIntersec = 0, cont = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(A[i] == B[j]){
                C[cont] = A[i];
                contIntersec++;
                cont++;
            }
        }
    }

    C[0] = contIntersec;

    for(int i = 0;i<=contIntersec
    ;i++){
        cout << C[i] << " ";
    }
}
int main(){
    int A[MAX+1];
    int B[MAX+1];
    int C[MAX+1];

    intersec(A,B,C);
    return 0;
}

