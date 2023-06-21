#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    srand(time(NULL));

    int n = 20;
    float tab[20];
    int dl[20];
    int indeks[20];
    int globalI = 0;
    for(int i = 0; i < n; i++)
    {
        tab[i]=rand()/(float)RAND_MAX * 10.0 - 5.0;
        cout<<tab[i]<<" ";
    }
    cout<<'\n';
    int temp = 0;
    for(int i = 0; i < n; i++)
    {
        if(tab[i]>0)
            temp++;
        else
        {
            dl[globalI] = temp;
            temp = 0;
            indeks[globalI] = i;
            globalI++;
        }
    }

    // for(int i = 0; i < globalI; i++)
    // {
    //     cout<<dl[i]<<" "<<indeks[i]<<'\n';
    // }

    for(int i = 0; i < globalI; i++)
    {
        for(int j = 0; j < globalI - 1; j++)
        {
            if(dl[j]<dl[j+1])
            {
                int temp = dl[j];
                dl[j]=dl[j+1];
                dl[j+1]=temp;

                temp = indeks[j];
                indeks[j]=indeks[j+1];
                indeks[j+1]=temp;
            }
        }
    }

    // cout<<'\n';
    // for(int i = 0; i < globalI; i++)
    // {
    //     cout<<dl[i]<<" "<<indeks[i]<<'\n';
    // }

    for(int i = indeks[0]-dl[0]; i < indeks[0]; i++)
    {
        cout<<tab[i]<<" ";
    }

    cout<<'\n';

    for(int i = 1; i < globalI;i++)
    {
        if(dl[i]==dl[0])
        {
            for(int j = indeks[i]-dl[i]; j < indeks[i]; j++)
            {
                cout<<tab[j]<<" ";
            }
            cout<<'\n';
        }
    }

    return 0;
}