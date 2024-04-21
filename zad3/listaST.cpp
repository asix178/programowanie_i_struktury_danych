#include<iostream>
#include<stdexcept>
#include"listaST.h"
#include"podatnik.h"
using namespace std;
#include<string>
Lista::Node::Node(Podatnik P, Node* N)
{
    dane=P;
    nast=N;
}
Lista::Lista()
{
    pocz=nullptr;
    IleJest=0;
}
Lista::~Lista()
{
    Node *killer;
    while(pocz!=nullptr)
    {
        killer=pocz;
        pocz=(*killer).nast;
        delete killer;
        IleJest--;
    }
}
int Lista::dajIleJest()const
{
    return IleJest;
}
void Lista::wypisz()
{
    if(IleJest==0)
    {
        cout<<"Pusta lista";
        return;
    }
    Node* biegacz=pocz;
    while(biegacz!=nullptr)
    {
        cout<<(*biegacz).dane;
        biegacz=(*biegacz).nast;
    }
}
void Lista::wstaw(Podatnik P)
{
    Node* nowy;
    nowy= new Node(P);
    if(pocz==nullptr)
    {
        pocz=nowy;
    }
    else
    {
        Node* szuk=pocz;
        while((*szuk).nast!=nullptr)
        {
            szuk=(*szuk).nast;
        }
        (*szuk).nast=nowy;
    }
    IleJest++;
}
Podatnik Lista::zdejmij()
{
    if(IleJest==0)
    {
        throw runtime_error("Lista pusta");
    }
    Podatnik s =(*pocz).dane;
    Node* killer;
    killer=pocz;
    pocz=(*killer).nast;
    delete killer;
    IleJest--;
    return s;
}
