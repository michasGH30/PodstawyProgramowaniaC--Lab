#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    int ilosc = 0;
    int n = 0;
    cout<<"Podaj liczbę całkowitą: ";
    cin>>n;
    while(n != 0)
    {
        if(n > 10)
            ilosc++;
        cout<<"Podaj liczbę całkowitą: ";
        cin>>n;
    }
    cout<<"Ilość liczb większych od 10: "<<ilosc;
    return 0;
}