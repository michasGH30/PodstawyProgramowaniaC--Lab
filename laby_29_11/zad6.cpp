#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    cout<<"Podaj n: ";
    int n;
    cin>>n;
    cout<<"Podaj wariant.\n1.Tabliczka mnożenia.\n2.Tabliczka dzielenia.\n3.Tabliczka reszty z dzielenia.\n";
    int w  = 0;
    cin>>w;
    if(w < 1 || w > 3)
        return -1;
    switch (w)
    {
    case 1:
        cout<<"Tabliczka mnożenia.\n";
        break;
    case 2:
        cout<<"Tabliczka dzielenia:\n";
        break;
    case 3:
            cout<<"Tabliczka reszty z dzielenia:\n";
        break;
    default:
        break;
    }
    cout<<"  ";
    for(int i = 1; i <= n; i++)
        cout<<i<<" ";
    cout<<'\n';
    for(int i = 1; i <= n; i++)
    {
        cout<<i<<" ";
        for(int j = 1; j <=n; j++)
        {
            switch (w)
            {
            case 1:
                cout<<i*j<<" ";
                break;
            case 2:
                cout<<j/i<<" ";
                break;
            case 3:
                cout<<j%i<<" ";
                break;
            default:
                break;
            }
        }
        cout<<'\n';
    }
    return 0;
}