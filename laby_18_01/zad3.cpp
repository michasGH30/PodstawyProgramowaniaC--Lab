#include "zad3_f.cpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Polish");
    int n = ile_s();
    Samochod *samochody = generuj(n);
    wprowadz_dane(samochody, n);
    wypisz_typ(samochody, n, "Suv");
    wypisz_cena(samochody, n, "Toyota");
    delete[] samochody;
    return 0;
}