#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    char z;
    int counter = 0;
    int numbers = 0;
    do
    {
        z = getch();
        if(z == 0)
        {
            z = getch();
            if(z == 60)
                cout<<"Klawisz F2"<<endl;
            else if(z == 75)
                cout<<"<-"<<endl;
            else if(z == 77)
                cout<<"->"<<endl;
            else 
            {
                cout<<"Inny klawisz";
            }
        }
        else
            cout<<z<<endl;
        counter++;
        if(z >= 48 && z <= 57)
            numbers++;
    }while(z!= 27);

    counter--;

    cout<<"Znaków: "<<counter<<" cyfr: "<<numbers<<endl;
    return 0;
}