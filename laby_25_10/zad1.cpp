#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    int n = 0;
    cout<<"Podaj n: ";
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cout<<"Michał Żuk\n";
    }
    return 0;
}