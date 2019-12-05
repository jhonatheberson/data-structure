#include <iostream>
using namespace std;

void insertion_sort(int v[100], int n) {

    for (int i = 0; i < n; i++) {
		int escolhido = v[i];
		int j = i - 1;

		while ((j >= 0) && (v[j] > escolhido)) {
			v[j + 1] = v[j];
			j--;
		}

		v[j + 1] = escolhido;
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

    insertion_sort(v, n);

    return 0;
}
