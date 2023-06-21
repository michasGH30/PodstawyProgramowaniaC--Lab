#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct pracownik
{
    string nazwisko;
    string stanowisko;
};

int main()
{
    setlocale(LC_ALL,"Polish");
    cout<<"Podaj ilość pracowników: ";
    int n = 0;
    cin>>n;
    pracownik *p = new pracownik [n];
    for(int i = 0; i < n; i++)
    {
        cout<<"Nazwisko: ";
        cin>>p[i].nazwisko;
        cout<<"Stanowisko: ";
        cin>>p[i].stanowisko;
    }

    for(int i = 0; i < n; i++)
    {
        string temp = p[i].stanowisko;
        for(int j = 0; j < n; j++)
        {
            if(i!=j && temp == p[j].stanowisko)
            {
                p[j].stanowisko = "brak";
            }
        }
    }
    int licznik = 0;
    for(int i = 0; i < n; i++)
    {
        if(p[i].stanowisko != "brak")
        {
            licznik++;
        }
    }

    string *s = new string [licznik + 1];

    int k = 0;

    for(int i = 0; i < n; i++)
    {
        if(p[i].stanowisko != "brak")
        {
            s[k] = p[i].stanowisko;
            k++;
        }
    }

    for(int i = 0; i < k; i++)
    {
        cout<<s[i]<<" ";
    }

    delete [] s;
    delete [] p;
    return 0;
}