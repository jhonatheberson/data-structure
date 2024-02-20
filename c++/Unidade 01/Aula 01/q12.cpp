#include <iostream>
using namespace std;

int main()
{

    int m,n;
    cout << "Insira a posicao m:" << endl;
    cin >> m;
    cout << "Insira a posicao n:" << endl;
    cin >> n;

    int maior = 0, i, j;

    for(int x = 1; x<=m; x++)
    {
        for(int y = 1; y<=n; y++)
        {
            cout << x << "." << y << " =" << (x*y-((x*x)) + y) << endl;
           if(         maior < (x*y-((x*x)) + y)         ){
                maior = (x*y-((x*x)) + y);
                i = x;
                j = y;
        }
    }
}
    cout << maior << " e o maior numero e esta na posicao " << i << "." << j;
return 0;
}
