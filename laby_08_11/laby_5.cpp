#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    int liczba = 0;
    cin>> liczba;
    int n = 5;
    int licznik = 0;
    int a = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        if(liczba%a==0)
            licznik++;
    }
    cout<<licznik;
    return 0;
}