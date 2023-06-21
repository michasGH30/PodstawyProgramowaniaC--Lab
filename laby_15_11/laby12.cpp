#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    srand(time(NULL));
    int n = 0;
    float x0, y0, r;
    cout<<"Podaj ilość punktów: ";
    cin>> n;
    cout<<"Podaj x0: ";
    cin>>x0;
    cout<<"Podaj y0: ";
    cin>>y0;
    cout<<"Podaj promień: ";
    cin>>r;
    for(int i = 0; i < n; i++)
    {
        float x = rand()/(float)RAND_MAX * 10.0 - 5.0;
        float y = rand()/(float)RAND_MAX * 10.0 - 5.0;
        float d = sqrt(pow(x0 - x,2) + pow(y0 - y, 2));
        if(d <= r)
            cout<<"Punkt o współrzędnych x = "<<x<<", y = "<<y<<" należy do koła"<<'\n';
    }
    return 0;
}