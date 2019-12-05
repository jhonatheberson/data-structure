#include<iostream>
using namespace std;
#define MAX 100

int main()
{
    int tamlinA, tamlinB, tamcolA, tamcolB;
    int A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];
    cout << "indique as dimensoes de A." << endl;
    cout << "linha:";
    cin >> tamlinA;
    cout << "coluna:";
    cin >> tamcolA;
    cout << "indique as dimensoes de B." << endl;
    cout << "linha:";
    cin >> tamlinB;
    cout << "coluna:";
    cin >> tamcolB;
    cout << "defina o vetor A : " << endl;

    for(int i=0; i<tamlinA; i++)
    {
        for(int j=0; j<tamcolA; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << endl;
    cout << "defina a matriz B : " << endl;

    for(int i=0; i<tamlinB; i++)
    {
        for(int j=0; j<tamcolB; j++)
        {
            cin >> B[i][j];
        }
    }

    cout << endl;

    if(tamcolA != tamlinB)
    {

        cout << "nao e possivel realizar a multiplicacao" << endl;

    }

    else
    {

        for(int i=0; i<tamlinA; i++)
        {

            for(int j=0; j<tamcolB; j++)
            {
                R[i][j] = 0;
                for(int k=0; k<tamlinB; k++)
                {
                    R[i][j] = R[i][j] + A[i][k]*B[k][j];
                }
            }
        }
    }

    cout << "produto AB = " << endl;

    for(int i=0; i<tamlinA; i++)
    {
        for(int j=0; j<tamcolB; j++)
        {
            cout << R[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;




    return 0;
}


