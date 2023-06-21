#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Wektor
{
    int x, y, z;

public:
    Wektor()
    {
        x = 5;
        y = 5;
        z = 5;
    }
    Wektor(int xK, int yK, int zK)
    {
        x = xK;
        y = yK;
        z = zK;
    }
    void dlugosc()
    {
        float d = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        cout << "Długość ";
        wypisz();
        cout << "ma długość: " << d << '\n';
    }
    void wypisz()
    {
        cout << "Wektor: [" << x << ", " << y << ", " << z << "]\n";
    }
    int retX()
    {
        return x;
    }
    int retY()
    {
        return y;
    }
    int retZ()
    {
        return z;
    }
    void iloczyn_s(Wektor w)
    {
        cout << "Iloczyn skalarny wektorów W1: ";
        wypisz();
        cout << "oraz W2: ";
        w.wypisz();
        cout << "wynosi: " << x * w.retX() + y * w.retY() + z * w.retZ() << '\n';
    }
    void iloczyn_w(Wektor w)
    {
        cout << "Iloczyn wektorowy wektorów W1: ";
        wypisz();
        cout << "oraz W2: ";
        w.wypisz();
        cout << "wynosi: [" << y * w.retZ() - z * w.retY() << ", " << z * w.retX() - x * w.retZ() << ", " << x * w.retY() - y * w.retX() << "]\n";
    }
};

int main()
{
    setlocale(LC_ALL, "Polish");
    Wektor W1;
    Wektor W2(1, 2, 3);
    W1.dlugosc();
    W1.iloczyn_s(W2);
    W1.iloczyn_w(W2);
    return 0;
}