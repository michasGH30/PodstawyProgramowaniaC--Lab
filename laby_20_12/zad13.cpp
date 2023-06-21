#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct film
{
    string tytul;
    string gatunek;
    string wersja;
    int czas;
    float cena;
};

int main()
{
    setlocale(LC_ALL,"Polish");
    srand(time(NULL));
    film filmy[6];
    for(int i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
            filmy[i].tytul="Forest Gump";
            filmy[i].gatunek="Obyczajowy";
            filmy[i].wersja="oryginał";
            filmy[i].czas=90;
            break;
        case 1:
            filmy[i].tytul="Harry Potter i Kamień Filozoficzny";
            filmy[i].gatunek="Fantasy";
            filmy[i].wersja="kopia";
            filmy[i].czas=100;
        break;
        case 2:
            filmy[i].tytul="Harry Potter i Komnata Tajemnic";
            filmy[i].gatunek="Fantasy";
            filmy[i].wersja="oryginał";
            filmy[i].czas=105;
        break;
        case 3:
            filmy[i].tytul="Kevin sam w Domu";
            filmy[i].gatunek="Obyczajowy";
            filmy[i].wersja="kopia";
            filmy[i].czas=95;
        break;
        case 4:
            filmy[i].tytul="Kevin sam w Nowym Yorku";
            filmy[i].gatunek="Obyczajowy";
            filmy[i].wersja="oryginał";
            filmy[i].czas=110;
        break;
        case 5:
            filmy[i].tytul="Harry Potter i Zakon Feniksa";
            filmy[i].gatunek="Fantasy";
            filmy[i].wersja="kopia";
            filmy[i].czas=115;
        break;
        }
        filmy[i].cena=rand()/(float)RAND_MAX * 40.0 + 10.0;
    }

    for(int i = 0; i < 6; i++)
    {
        cout<<filmy[i].tytul<<' ';
        cout<<filmy[i].gatunek<<' ';
        cout<<filmy[i].wersja<<' ';
        cout<<filmy[i].czas<<' ';
        cout<<filmy[i].cena<<' ';
        cout<<'\n';
    }

    float sredniaOb = 0;
    int ileOb = 0;
    float sredniaFa = 0;
    int ileFa = 0;

    for(int i = 0; i < 6; i++)
    {
        if(filmy[i].gatunek == "Obyczajowy")
        {
            sredniaOb+=filmy[i].cena;
            ileOb++;
        }
        if(filmy[i].gatunek == "Fantasy")
        {
            sredniaFa+=filmy[i].cena;
            ileFa++;
        }
    }

    sredniaFa/=(float)ileFa;
    sredniaOb/=(float)ileOb;

    cout<<"\n\nFilmy z gatunku Obyczajowy z ceną poniżej średniej("<<sredniaOb<<"):\n";
    for(int i = 0; i < 6; i++)
    {
        if(filmy[i].gatunek=="Obyczajowy" && filmy[i].cena<sredniaOb)
        {
            cout<<filmy[i].tytul<<' ';
            cout<<filmy[i].gatunek<<' ';
            cout<<filmy[i].wersja<<' ';
            cout<<filmy[i].czas<<' ';
            cout<<filmy[i].cena<<' ';
            cout<<'\n';
        }
    }

    cout<<"\n\nFilmy z gatunku Fantasy z ceną poniżej średniej("<<sredniaFa<<"):\n";
    for(int i = 0; i < 6; i++)
    {
        if(filmy[i].gatunek=="Fantasy" && filmy[i].cena<sredniaFa)
        {
            cout<<filmy[i].tytul<<' ';
            cout<<filmy[i].gatunek<<' ';
            cout<<filmy[i].wersja<<' ';
            cout<<filmy[i].czas<<' ';
            cout<<filmy[i].cena<<' ';
            cout<<'\n';
        }
    }

    return 0;
}