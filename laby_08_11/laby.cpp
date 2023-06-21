#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    int n = 5;
    int liczba = 0;
    int najmniejsza_r = 0;
    int poprzednia = 0;
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            cin>>liczba;
        else if(i == 1)
        {
            poprzednia = liczba;
            cin>>liczba;
            najmniejsza_r = liczba - poprzednia;
            if(najmniejsza_r < 0)
                najmniejsza_r *=-1;
            
        }
        else 
        {
            poprzednia = liczba;
            cin>>liczba;
            int r = liczba - poprzednia;
            if(r < 0)
                r*= -1;
            if(r < najmniejsza_r)
                najmniejsza_r = r;
        }
    }
    cout<<najmniejsza_r;
    return 0;
}