#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    int wartosc = 0;
    int n = 0;
    cout<<"Podaj stopień wielomianu: ";
    cin>>n;
    int x = 0;
    cout<<"Podaj x: ";
    cin>>x;
    int a = 0;
    cout<<"Podaj kolejne a: ";
    cin>>a;
    wartosc += a * x;
    for(int i = 1; i<n; i++)
    {
        cout<<"Podaj kolejne a: ";
        cin>>a;
        wartosc = (wartosc + a) * x;
    }
    cout<<"Podaj kolejne a: ";
    cin>>a;
    wartosc += a;
    cout<<"Wartość: "<<wartosc;
    return 0;
}