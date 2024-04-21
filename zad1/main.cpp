#include<iostream>
#include"student.h"
#include"lista.h"
#include<string>
#include<fstream>
#include<sstream>
#include<stdexcept>
using namespace std;

int main()
{
    ListaSort LS;
    string nazwyplikow[2]={"GRA.txt","SID.txt"};
    string nazwa, msg, L;
    ifstream pl;
    for(int n=0; n<2;n++)
    {
        nazwa=nazwyplikow[n];
        pl.open(nazwa);
        msg="brak pliku wejsciowego "+nazwa;
        if(!pl)
        {
            throw runtime_error(msg);
        }
        while(true)
        {
            getline(pl,L);
            cout<<"przeczytana linia: "<<L<<endl;
            string im, naz;
            int ind;
            double oc;

            istringstream in(L);
            in>>naz>>im>>ind>>oc;
            Student stud(im,naz,ind,oc);
            LS.wstaw(stud);

            cout<<"obecna lista: ";
            LS.wypisz();
            cout<<endl;

            if(pl.peek()==EOF)
            {
                break;
            }
        }
        pl.close();

    }
ofstream pw;
pw.open("INF.txt");
while(LS.getIleJest())
{
    pw<<LS.zdejmij(); //w pliku pw zapisujemy zjeta linie
}
pw.close();
}

