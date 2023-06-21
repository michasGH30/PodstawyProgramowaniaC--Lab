#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

struct student
{
    char nazwisko[25];
    char imie[15];
    int wiek;
    bool zalicznenie;
};
int main()
{
    setlocale(LC_ALL,"Polish");
    srand(time(NULL));
    student studenci[10];
    for(int i = 0; i < 10; i++)
    {
        cin>>studenci[i].nazwisko>>studenci[i].imie>>studenci[i].zalicznenie;
        studenci[i].wiek = rand()%121;
    }
    cout<<"\n\n";
    for(int i = 0; i < 10; i++)
    {
        cout<<studenci[i].nazwisko<<" "<<studenci[i].imie<<" "<<studenci[i].zalicznenie<<" "<<studenci[i].wiek<<'\n';
    }
    cout<<"\n\n";
    int wybor = -1;
    do 
    {
        cout<<"\n1. Najmłodszy student.\n2. Imiona i nazwiska o tej samej literze.\n3. Studenci o nazwiskach na literę.\n4. Koniec:\n";
        cin>>wybor;
        if(wybor == 1)
        {
            int naj = studenci[0].wiek;
            int index = 0;
            for(int i = 1; i < 10; i++)
            {
                if(studenci[i].wiek<naj)
                {
                    naj = studenci[i].wiek;
                    index = i;
                }
            }
            cout<<studenci[index].nazwisko<<' '<<studenci[index].imie<<" wiek: "<<studenci[index].wiek<<" zaliczył: "<<boolalpha<<studenci[index].zalicznenie;
        }
        else if(wybor == 2)
        {
            for(int i = 0; i < 10; i++)
            {
                if(studenci[i].nazwisko[0] == studenci[i].imie[0])
                {
                    cout<<studenci[i].nazwisko<<' '<<studenci[i].imie<<" wiek: "<<studenci[i].wiek<<" zaliczył: "<<boolalpha<<studenci[i].zalicznenie<<'\n';
                }
            }
        }
        else if(wybor == 3)
        {
            cout<<"Podaj literę: ";
            char litera;
            cin>>litera;
            for(int i = 0; i < 10; i++)
            {
                if(studenci[i].nazwisko[0] == litera)
                {
                    cout<<studenci[i].nazwisko<<' '<<studenci[i].imie<<" wiek: "<<studenci[i].wiek<<" zaliczył: "<<boolalpha<<studenci[i].zalicznenie<<'\n';
                }
            }
        }
    }while(wybor!=4);
    return 0;
}