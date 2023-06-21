#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
// . , ! ;
int main()
{
    setlocale(LC_ALL,"Polish");
    string text;
    cout<<"Podaj długi ciąg, program sprawdzi czy sa jakieś znaki interpunkcyjne:\n";
    getline(cin, text);
    bool is = false;
    for(int i = 0; i < text.length(); i++)
    {
        if((int)text[i] == 46 || (int)text[i] == 44 || (int)text[i] == 33 || (int)text[i] == 59)
            is = true;
    }
    if(is)
        cout<<"Są znaki interpunkcyjne (. , ! ;) w napisie.";
    else
        cout<<"Nie ma znaków interpunkcyjnych (. , ! ;) w napisie.";
    return 0;
}