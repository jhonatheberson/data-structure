#include <iostream>
#define MAX1 100
using namespace std;

int buscarListaSequenciaOrdenada(int v[MAX1], int n, int x)
{
    for(int i = 0;i<n;i++){
        if(v[i] >= x){
            return i;
        }
    }
    return n;
}

void inserirListaSequencialOrdenada(int v[MAX1], int &n, int x)
{
    int i;
    if(n < MAX1)
    {
        i = buscarListaSequenciaOrdenada(v,n,x);
        if(v[i]!=x)
        {
            int j = n;
            while(j>=i)
            {
                v[j+1] = v[j];
                j = j-1;
            }
            v[i] = x;
            n++;
        }
        else
        {
            cout << "O elemento já se encontra na lista" << endl;
        }
    }


}

void removerListaSequencialOrdenada(int v[MAX1], int &n, int x){

    int i;
    if(n != 0)
    {
        i = buscarListaSequenciaOrdenada(v,n,x);
        if(v[i]==x)
        {
            for(int j = i;j<n-1;j++){
                v[j] = v[j+1];
            }
            n = n-1;
        }
        else
        {
            cout << "O elemento nao se encontra na lista" << endl;
        }
    }
}

int main()
{
    int n = 0;
    int v[MAX1];

    inserirListaSequencialOrdenada(v, n, 20);
    for(int i = 0;i<n;i++){
        cout << v[i] << " ";
    }
    cout<< endl;
    inserirListaSequencialOrdenada(v, n, 10);
    for(int i = 0;i<n;i++){
        cout << v[i] << " ";
    }
    cout << endl;
    removerListaSequencialOrdenada(v,n,10);
    for(int i = 0;i<n;i++){
        cout << v[i] << " ";
    }
    return 0;
}
