#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int suma_wspak(int n, int p)
{
    if (n < 1)
        return 0;
    return n % 10 * pow(10, p) + suma_wspak(n / 10, p - 1);
}

int podaj_liczbe()
{
    cout << "Podaj liczbę: ";
    int n = 0;
    cin >> n;
    return n;
}

int ile_cyfr(int n)
{
    int i = 0;
    while (n > 0)
    {
        n /= 10;
        i++;
    }
    return i;
}

int main()
{
    setlocale(LC_ALL, "Polish");
    int n = podaj_liczbe();
    int p = ile_cyfr(n);
    cout << suma_wspak(n, p - 1);
    return 0;
}