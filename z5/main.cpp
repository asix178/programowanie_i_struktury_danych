#include<iostream>
#include<string>
#include"dane.h"
#include"kontener.h"
#include<fstream>
#include<sstream>
#include<stdexcept>
#include<cmath>

using namespace std;

int main()
{
    ListaSort<Podatnik> LS;

    string L;

    ifstream pod;
    ifstream rozl;

    pod.open("podatnicy.txt");
    rozl.open("rozliczenia.txt");

    if(!pod || !rozl)
    {
        throw runtime_error("Bledny plik");
    }

    while (true)
    {
        string im, nz, ni, pusta;
        double rz, rz2;
        getline(pod,ni);

        getline(pod,L);
        istringstream in(L);
        in>>nz>>im;
        getline(pod, pusta);

        getline(rozl,L);
        istringstream inn(L);
        inn>>rz;
        rz2=round(rz);
        try
        {
            if(czyNip(ni)==false)
            {
                throw logic_error("Niepoprawny nip");
            }
            Podatnik p(im,nz,ni,rz2);
            LS.wstaw(p);
        }
        catch(exception&e)
        {
            cout<<e.what()<<" "<<ni;
        }
        cout<<"Lista: "<<endl;
        LS.wypisz();
        cout<<endl;

        if(rozl.peek()==EOF || pod.peek()==EOF) break;
    }
    rozl.close();
    pod.close();

    ofstream pz;
    pz.open("wyniki.txt");
    while(LS.dajIleJest())
    {
        Podatnik p;
        p=LS.zdejmij();
        pz<<p;
    }
    pz.close();

    return 0;
}
