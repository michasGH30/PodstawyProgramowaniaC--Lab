#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    int n = 0;
    int a = 0, b = 0;
    cout<<"Podaj długość ramienia: ";
    cin>>n;
    cout<<"Podaj liczbę do wypełnienia: ";
    cin>>a;
    cout<<"Podaj liczbę brzegową: ";
    cin>>b;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(i == 0 || i == n-1)
                cout<<b;
            else 
            {
                if(j == 0 || j == i)
                    cout<<b;
                else 
                    cout<<a;
            }
        }
        cout<<'\n';
    }
    return 0;
}