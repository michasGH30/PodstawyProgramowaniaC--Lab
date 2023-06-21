#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Polish");
    string text;
    string encrypted = "";
    cout<<"Podaj ciąg do zaszyfrowania: ";
    getline(cin,text);
    for(int i = 0; i < text.length(); i = i + 2)
        encrypted+=text[i];
    
    for(int  i = 1; i < text.length(); i = i + 2)
        encrypted+= text[i];

    cout<<"Po zaszuwfrowaniu: "<<encrypted;
    return 0;
}