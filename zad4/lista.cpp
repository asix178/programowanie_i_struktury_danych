#include"lista.h"
#include"iban.h"
#include<string>
#include<iostream>

using namespace std;

Lista::Node::Node(IBAN i, Node* N)
{
    dane=i;
    nast=N;
}

 Lista::Lista()
 {
     pocz=nullptr;
     IleJest=0;
 }
Lista::~Lista()
{
    Node* killer;
    while(pocz!=nullptr)
    {
        killer=pocz;
        pocz=(*killer).nast;
        delete killer;
        IleJest--;
    }
}
void Lista::wstaw(IBAN n)
{

    Node* nowy;
    nowy = new Node(n);

    if(pocz==nullptr)
    {
        pocz=nowy;
    }
    else
    {
        Node* szuk = pocz;
        while(szuk->nast != nullptr)
        {
            szuk = szuk->nast;
        }
        szuk->nast = nowy;
    }

    IleJest++;
}
IBAN Lista::zdejmij()
{
    Node* killer=pocz;
    IBAN i=(*pocz).dane;
    pocz=(*killer).nast;
    delete killer;
    IleJest--;
    return i;
}
void Lista::wypisz()
{
    if(pocz==nullptr)
    {
        cout<<"Lista pusta"<<endl;
        return;
    }
    else
    {
        Node* biegacz=pocz;
        while(biegacz!=nullptr)
        {
            cout<<(*biegacz).dane<<endl;
            biegacz=(*biegacz).nast;
        }
    }
}
int Lista::dajIleJest() const
{
    return IleJest;
}
