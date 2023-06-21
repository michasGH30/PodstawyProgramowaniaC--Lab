#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

namespace wektory
{
    void wprowadz(int tab[3])
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "Podaj " << i + 1 << " wartość wektora: ";
            cin >> tab[i];
        }
        cout << endl;
    }

    void wypisz(int w[3])
    {
        cout << " Wektor: [" << w[0] << ", " << w[1] << ", " << w[2] << "] ";
    }

    void suma(int w1[3], int w2[3], int w3[3])
    {
        cout << "Suma wektorów: ";
        wypisz(w1);
        wypisz(w2);
        wypisz(w3);
        cout << " jest równa: [" << w1[0] + w2[0] + w3[0] << ", " << w1[1] + w2[1] + w3[1] << ", " << w1[2] + w2[2] + w3[2] << "]" << endl;
    }

    float dlugosc(int w[3])
    {
        return sqrt(pow(w[0], 2) + pow(w[1], 2) + pow(w[2], 2));
    }

    void max(int w1[3], int w2[3], int w3[3])
    {
        int s1 = dlugosc(w1);
        int s2 = dlugosc(w2);
        int s3 = dlugosc(w3);
        if (s1 > s2 && s1 > s3)
        {
            wypisz(w1);
            cout << "jest największy" << endl;
        }
        else if (s2 > s1 && s2 > s3)
        {
            wypisz(w2);
            cout << "jest największy" << endl;
        }
        else if (s3 > s2 && s3 > s1)
        {
            wypisz(w3);
            cout << "jest największy" << endl;
        }
    }

    void min(int w1[3], int w2[3], int w3[3])
    {
        int s1 = dlugosc(w1);
        int s2 = dlugosc(w2);
        int s3 = dlugosc(w3);
        if (s1 < s2 && s1 < s3)
        {
            wypisz(w1);
            cout << "jest najmniejszy" << endl;
        }
        else if (s2 < s1 && s2 < s3)
        {
            wypisz(w2);
            cout << "jest najmniejszy" << endl;
        }
        else if (s3 < s2 && s3 < s1)
        {
            wypisz(w3);
            cout << "jest najmniejszy" << endl;
        }
    }
};
using namespace wektory;
int main()
{
    setlocale(LC_ALL, "Polish");
    int w1[3];
    int w2[3];
    int w3[3];
    wprowadz(w1);
    wprowadz(w2);
    wprowadz(w3);

    suma(w1, w2, w3);
    max(w1, w2, w3);
    min(w1, w2, w3);
    return 0;
}