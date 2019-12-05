#include <iostream>
using namespace std;

struct Funcionario {
    string nome;
    double salario;
};

void insertiorSortOrdemCrescenteSalario(Funcionario f1[5], int n) {

    for (int i = 0; i < n; i++) {
		int escolhido = f1[i].salario;
		string nome = f1[i].nome;
		int j = i - 1;

		while ((j >= 0) && (f1[j].salario > escolhido)) {
			f1[j + 1].salario = f1[j].salario; //troca as posições
			f1[j + 1].nome = f1[j].nome;
			j--;
		}

		f1[j + 1].salario = escolhido;
		f1[j + 1].nome = nome;
	}

	for(int i = 0;i<n;i++){
        cout << f1[i].nome << " " << f1[i].salario << endl;;
    }

}



int main(){

    int n = 5;
    Funcionario f1[n];

    for(int i = 0;i<n;i++){
        cout << "Informe o nome do funcionario " << i+1 << ":" << endl;
        cin >> f1[i].nome;
        cout << "Informe o salario do funcionario " << i+1 << ":" << endl;
        cin >> f1[i].salario;
    }

    /*for(int i = 0;i<n;i++){
        cout << "nome do funcionario " << i+1 << ": " << f1[i].nome << endl;
        cout << "salario do funcionario " << i+1 << ": " << f1[i].salario << endl;
    }*/

    insertiorSortOrdemCrescenteSalario(f1, n);
    return 0;
}
