#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    srand(time(NULL));
    int n = 3, m=4;
    int tab[3][4];
    int tabIl[3];
    int tabSu[4];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            tab[i][j]=rand()%10-5;
            cout<<tab[i][j]<<" ";
        }
        cout<<'\n';
    }

    int iloczyn = 1;
    int indeksIl = 0;

    for(int i = 0; i < n; i++)
        iloczyn *=tab[i][0];


    for(int j = 1; j < m; j++)
    {
        int tempIl = 1;
        for(int i = 0; i < n; i++)
        {   
            tempIl*= tab[i][j];
        }
        if(tempIl > iloczyn)
        {
            iloczyn = tempIl;
            indeksIl = j;
        }
    }

    cout<<'\n';

    for(int i = 0; i < n; i++)
    {
        tabIl[i]=tab[i][indeksIl];
        cout<<tabIl[i]<<' ';
    }

    int suma = 0;
    int indeksSu = 0;
    for(int j = 0; j < m; j++)
        suma+=tab[0][j];

    for(int i = 1; i< n; i++)
    {
        int tempSu = 0;
        for(int j = 0; j < m; j++)
        {
            tempSu+=tab[i][j];
        }
        if(tempSu<suma)
        {
            suma = tempSu;
            indeksSu = i;
        }
    }

    cout<<'\n';

    for(int j = 0; j < m; j++)
    {
        tabSu[j] = tab[indeksSu][j];
        cout<<tabSu[j]<<" ";
    }

    return 0;
}