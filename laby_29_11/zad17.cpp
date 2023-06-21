#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm> 
#include <cmath> 

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    string s = "";
    int n = 0;
    int wybor = 0;
    cout<<"Podaj co chcesz zrobić.\n1.Zamiana z dziesiątnego na szestnastkowy.\n2.Zamiana z szesnastkowego na dziesiętny.\n";
    cin>> wybor;
    if(wybor == 1)
    {
        cout<<"Podaj liczbę: ";
        cin>>n;
        while(n > 1)
        {
            int reszta = n % 16;
            if(reszta < 10)
                s = s + to_string(reszta);
            else 
            {
                switch (reszta)
                {
                case 10:
                    s = s + "A";
                    break;
                case 11:
                    s = s + "B";
                    break;
                case 12:
                    s = s + "C";
                    break;
                case 13:
                    s = s + "D";
                    break;
                case 14:
                    s = s + "E";
                    break;
                case 15:
                    s = s + "F";
                    break;
                }
            }

            n = n /16;

        }
        reverse(s.begin(), s.end());
        cout<<s;
    }
    else if(wybor == 2)
    {
        cout<<"Podaj liczbę: ";
        cin >> s;
        for(int i = 0; i < s.length(); i++)
        {
            if(!((int)s.at(i) >= 48 && (int)s.at(i)<=57 ||  (int)s.at(i)>= 65 && (int)s.at(i) <= 70))
            {
                cout<<"Błąd";
                return -1;
            }
        }
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if((int)s.at(i) >= 48 && (int)s.at(i)<=57)
            {
                n = n + ((int)s.at(i) - 48)*pow(16,s.length() - 1- i);
            }
            else 
            {
                n = n + ((int)s.at(i) - 55)*pow(16,s.length() - 1- i);
            }
            
        }
        cout<<n;
    }
    return 0;
}