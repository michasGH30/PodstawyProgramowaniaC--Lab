#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    int max_liczba_dla_fora = 3;
    int max_liczba = 0;
    int a = 0;
    for(int i = 0; i < max_liczba_dla_fora; i++)
    {
        cin>>a;
        int temp = a;
        int ile_cyfr = 0;
        while(temp > 0)
        {
            ile_cyfr++;
            temp/=10;
        }
        if(ile_cyfr%2!=0)
        {
            if(a > max_liczba)
                max_liczba = a;
        }
        
    }
    cout<<max_liczba;
    return 0;
}