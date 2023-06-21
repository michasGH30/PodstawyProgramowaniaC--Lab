#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    int n = 0;
    cout<<"Podaj ilość znaków, które chcesz wprowadzić: ";
    cin>>n;
    char *tab = new char[n];
    for(int i = 0; i < n; i++)
    {
        cin>>tab[i];
    }

    cout<<endl;

    for(int i = 0; i < n; i++)
    {
        switch(tab[i])
        {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
            case 'y':
            case 'Y':
            cout<<tab[i]<<" ";
            break;
        }
    }

    delete [] tab;
    return 0;
}