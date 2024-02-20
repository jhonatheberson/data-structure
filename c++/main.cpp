#include <iostream>
#include <cmath>

#define MAX 11

using namespace std;

// Primeiro, cria-se um tipo estruturado do tipo
// disco. Onde P1 é o pino que o disco está, P2
// é pra onde ele precisa ir e o P3 seria o auxiliar

struct disco{
    int n;
    int P1;
    int P2;
    int P3;
};

struct pilha{
    disco V[MAX];
    int topo;
};

void Empilhar(pilha &P, disco D){
    {
        if(P.topo == MAX - 1)
        {
            cout << "Bad luck! Pilha cheia :/ \n";
        }
        P.topo++;
        P.V[P.topo] = D;
    }
}

disco Desempilhar(pilha &P){
    {
        disco d;
        d.n = -1;
        if(P.topo == -1)
        {
            return d;
        }
        P.topo--;
        return P.V[P.topo+1]; // retorna o topo da pilha
    }
}

void Hanoi(pilha P,int n, int P1, int P2, int P3)
{
    disco d;
    int aux;

    d.n = n;
    d.P1 = P1;
    d.P2 = P2;
    d.P3 = P3;

    while(true)
    {
        while(d.n>0)
        {
            Empilhar(P,d);
            aux = d.P2;
            d.P2 = d.P3;
            d.P3 = aux;
            d.n--;
        }
        if(P.topo == -1)
        {
            break;
        }
        else d = Desempilhar(P);

        cout << "You just have moved the disco from " << d.P1 << " to " << d.P2 << endl;

        aux = d.P3;
        d.P3 = d.P1;
        d.P1 = aux;
        d.n--;
    }
}

int main(void)
{
    int n=3; // quantidade de discos;
    disco d;
    pilha P;
    int aux;
    P.topo = -1; // inicialmente a pilha começa vazia

    Hanoi(P,n,1,3,2); // inicialmente todos os discos começam no pino 1 e precisam ir pro 3

    return 0;
}
