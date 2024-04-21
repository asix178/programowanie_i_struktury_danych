#include<iostream>
#include"lista.h"
#include<string>
#include<fstream>
#include<sstream>
#include<stdexcept>

using namespace std;

int main()
{
    Lista LS;
    string nazwa_pliku;
    cout<<"Podaj plik z numerami IBAN"<<endl;
    getline(cin,nazwa_pliku);
    ifstream pl;
    pl.open(nazwa_pliku);
    if(!pl)
    {
        throw runtime_error("Zly plik");
    }
    while(true)
    {
        string linia;
        getline(pl,linia);
        string num,kr1,kr2,kr;
        cout<<linia<<endl<<endl;
        kr1=linia[0];
        kr2=linia[1];
        kr=kr1+kr2;
        cout<<kr;
        for (int i=2; i<linia.length();i++)
        {
            num=num+linia[i];
        }
        try
        {
            IBAN n;
            if(n.czyIBAN(num)==false || n.czyPL(kr)==false)
            {
                throw logic_error("Niepoprawny numer IBAN");
            }
            cout<<num.length();
            IBAN a(kr,num);
            LS.wstaw(a);
        }
        catch(exception &e)
        {
            cout<<e.what()<<" "<<kr<<" "<<num<<endl;
        }
        cout<<"Lista: "<<endl;
        LS.wypisz();

        if(pl.peek()==EOF)break;
    }
    pl.close();

    string nazwy[3]={"1020.txt","1140.txt","2490.txt"};
    ofstream plik;
    for(int i =0; i<3;i++)
    {
        plik.open(nazwy[i]);
        plik.close();
    }

    while (LS.dajIleJest())
    {
        IBAN x;
        x=LS.zdejmij();

        string kraj = x.dajKraj();
        string numer = x.dajNumer();

        if(numer[2]=='1'&& numer[3]=='0' && numer[4]=='2' && numer[5]=='0')
        {
            ofstream plik;
            plik.open(nazwy[0],ios::app);
            plik<<x;
            plik.close();
        }
        else if(numer[2]=='1' && numer[3]=='1' && numer[4]=='4' && numer[5]=='0')
        {
            ofstream plik;
            plik.open(nazwy[1],ios::app);
            plik<<x;
            plik.close();
        }
        else if(numer[2]=='2' && numer[3]=='4' && numer[4]=='9' && numer[5]=='0')
        {
            ofstream plik;
            plik.open(nazwy[2],ios::app);
            plik<<x;
            plik.close();
        }
        else
        {
            cout<<"nieznany bank "<<endl;
        }
    }

    return 0;
}
