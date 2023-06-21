#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    srand(time(NULL));

    int n = rand()%99+1;
    int x = 0;

   cout<<"Wylosowano liczbę od 1 do 100.\nPodaj swoją liczbę: ";
   do
   {
    cin>>x;
    if(x < n)
        cout<<"Twoja liczba jest za mała.\n";
    else if(x > n)
        cout<<"Twoja liczba jest za duża.\n";
    else
        cout<<"Udało ci się zgadnąć.\n";
   }while(x!=n);

    return 0;
}