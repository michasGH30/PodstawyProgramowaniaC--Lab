#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    cout<<"Podaj n: ";
    int n = 0;
    int licznik = 0;
    cin>>n;
    int pop = 0;
    int nast = 0;
    cout<<"Podaj liczbę: ";
    cin>>pop;
    cout<<"Podaj liczbę: ";
    cin>>nast;
    if(pop > 0 && nast > 0)
        licznik++;
    for(int i = 2; i < n; i++)
    {
        pop = nast;
        cout<<"Podaj liczbę: ";
        cin>>nast;
        if(pop > 0 && nast > 0)
            licznik++;
    }
    cout<<"Par było: "<<licznik;
    return 0;
}