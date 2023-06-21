#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    int n = 0;
    int m = 0;
    cout<<"Podaj ilość wierszy: ";
    cin>>n;
    cout<<"Podaj ilość kolumn: ";
    cin>>m;
    float **tab = new float*[n];
    for(int i = 0; i < n; i++)
    {
        tab[i] = new float [m];
    }

    float srednia = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            tab[i][j] = rand()/(float)RAND_MAX * 10.0 - 5.0;
            cout<<tab[i][j]<<" ";
            srednia+= tab[i][j];
        }
        cout<<'\n';
    }
    srednia/=(float)(n*m);
    cout<<"Średnia wynosi: "<<srednia<<'\n';

    int iW = 0, iK = 0;
    float roznica = 100;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(fabs(srednia - tab[i][j])<roznica)
            {
                roznica = fabs(srednia - tab[i][j]);
                iW = i;
                iK = j;
            }
        }
    }

    cout<<"Wartość najbliżej średniej to: "<<tab[iW][iK]<<"\nJest ona w wierszu: "<<iW<<" i kolumnie: "<<iK;

    for(int i = 0; i < n; i++)
    {
        delete [] tab[i];
    }
    delete [] tab;
    return 0;
}