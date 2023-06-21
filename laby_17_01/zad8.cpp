#include <iostream>
#include <cstdlib>

using namespace std;

void wprowadz(float *w, int n)
{
    cout << "Podaj wartości dla " << n << " wektora:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Podaj " << i + 1 << " wartość: ";
        cin >> w[i];
    }
}

void oblicz(float *w1, float *w2)
{
    float x = w1[1] * w2[2] - w1[2] * w2[1];
    float y = w1[2] * w2[0] - w1[0] * w2[2];
    float z = w1[0] * w2[1] - w1[1] * w2[0];
    cout << "Z mnożenia wektorowego wektorów A: [" << w1[0] << ", " << w1[1] << ", " << w1[2] << "] i B: [" << w2[0] << ", " << w2[1] << ", " << w2[2] << "] wynosi: [" << x << ", " << y << ", " << z << "]\n";
}

int main()
{
    setlocale(LC_ALL, "Polish");
    float *w1 = new float[3];
    float *w2 = new float[3];

    wprowadz(w1, 1);
    wprowadz(w2, 2);
    oblicz(w1, w2);
    delete[] w1;
    delete[] w2;
    return 0;
}