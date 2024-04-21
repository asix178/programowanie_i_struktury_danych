#include<iostream>
#include<fstream>
#include<sstream>
#include<stdexcept>
#include"listaST.h"
#include<string>

using namespace std;

int main()
{
    Lista LS;
    string N;
    ifstream pl;
    pl.open("nipy.txt");
    if(!pl)
    {
        throw runtime_error("Nie ma pliku wejsciowego!");
    }


    while(true)
    {
        getline(pl,N);
        cout<<"przeczytana linia: "<<N<<endl;

        string nip, naz;

        istringstream in(N);
        in>>nip;
        in.ignore();
        getline(in,naz);
        Podatnik pod(nip,naz);
        try{
            if(pod.czy_NIP(nip)==false)
            {
                throw runtime_error("Nieprawidlowy nip");
            }
            LS.wstaw(pod);
            cout<<"Lista: ";
            LS.wypisz();
            cout<<endl;
        }
        catch(exception &e)
        {
            cout<<e.what()<<" "<<nip<<endl;
        }
        if(pl.peek()==EOF)
        {
            break;
        }
    }
    pl.close();
    string nazwy[3]={"piotrkow.txt", "radomsko.txt", "tomaszow.txt"};

    ofstream pz;
    for(int i=0; i<3;i++)
    {
        pz.open(nazwy[i]);
        pz.close();
    }
    while(LS.dajIleJest())
    {
        Podatnik s;
        s=LS.zdejmij();
        int numer;
        try
        {
        numer=s.urzad();
        pz.open(nazwy[numer],ofstream::app);
        pz<<s;
        pz.close();
        }
        catch (exception &e)
        {
            cout<<e.what()<<" "<<s<<endl;
        }

    }

    return 0;
}
