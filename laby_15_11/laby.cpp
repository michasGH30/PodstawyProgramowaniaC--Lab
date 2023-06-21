#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    float c;
    cout<<"Podaj długość przeciwprostokątnej: ";
    cin>>c;
    float a = c/2.0;
    float b = sqrt(pow(c,2)-pow(a,2));
    float R = c/2.0;
    float p = 0.5*(a+b+c);
    float s = 0.5*a*b;
    float r = s/p;
    float poleO = 3.14 * pow(R,2);
    float poleW = 3.14 * pow(r,2);
    cout<<"Stosunek pola koła opisanego na trójkącie do pola koła wpisanego w trójkąt: "<<poleO/poleW;
    return 0;
}