# include <iostream>

using namespace std;


int main(){

    int n;

    cout << "Informe o tamanho do vetor: " << endl;
    cin >> n;

    int x, cont = 1, primos = 0, cont2 = 0;

    for(int i = 0;i<n;i++){
        cont2 = 0;
        cont = 1;
        cout << "Informe o valor do vetor na posicao " << i <<":" << endl;
        cin >> x;
        while(cont<=x){
            if(x%cont == 0){
                cont2++;
            }
            cont++;
        }
        if(cont2 == 2){
                cout << x << " e primo" << endl;
                primos = primos + x;
        }

    }
    cout << "soma dos primos: " << primos << endl;

    /*int primos = 0;
    int cont1 = 0, cont2 = 1;
    while(cont1<=n){

    }/*/
    return 0;
}
