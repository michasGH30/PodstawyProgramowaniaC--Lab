#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    int tab[10];
    for(int i = 0; i < 10; i++)
    {
        tab[i]=i;
    }
    for(int i = 0; i < 10; i++)
    {
        if(i%2!=0)
            cout<<tab[i]<<" ";
    }
    return 0;
}