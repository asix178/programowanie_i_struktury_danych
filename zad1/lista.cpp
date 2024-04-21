#include "student.h"
#include"lista.h"
#include <string>
#include<iostream>
#include<stdexcept>
using namespace std;
ListaSort::ListaSort()
{
    pocz=nullptr;
    IleJest=0;
}
ListaSort::Node::Node(Student L, Node*N)
{
    dane=L;
    nast=N;
}

ListaSort::~ListaSort()
{
    if(IleJest==0)
    {
        return;
    }
    Node *killer;

    while(pocz!=nullptr)
    {
        killer=pocz;
        pocz=(*killer).nast;
        delete killer;
        IleJest--;
    }
}
int ListaSort::getIleJest() const
{
    return IleJest;
}

void ListaSort::wypisz()
{
    if(IleJest==0)
    {
    cout<<"Pusta lista";
        return;
    }
    cout<<"pocz -> ";
    Node*biegacz=pocz;
    while(biegacz!=nullptr)
    {
        cout<<(*biegacz).dane<<endl;
        biegacz = (*biegacz).nast;
    }
    cout<<"koniec";
}

void ListaSort::wstaw(Student A)
{
    Node*nowy;
    nowy=new Node(A);
    if(pocz==nullptr)
    {
        pocz=nowy;
    }
    else if (pocz!=nullptr && A<(*pocz).dane)
    {
        (*nowy).nast=pocz;
        pocz=nowy;
    }
    else
    {
        Node*szuk=pocz;
        Node*zaszuk=nullptr;
        while(szuk!=nullptr && (*szuk).dane<A)
        {
            zaszuk=szuk;
            szuk=(*szuk).nast;
        }
        (*zaszuk).nast=nowy;
        (*nowy).nast=szuk;
    }
    IleJest++;
}

Student ListaSort::zdejmij()
{
    if(pocz==nullptr)
    {
        throw runtime_error("lista pusta");
    }
    Student s=(*pocz).dane;
    Node*killer=pocz;
    pocz=(*pocz).nast;
    delete killer;
    IleJest--;
    return s;
}
