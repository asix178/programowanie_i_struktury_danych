#include<string>
#include<stdexcept>
#include<iostream>
#include"student.h"
using namespace std;
Student::Student(string nazw, string im, int ind, double oc)
{
if(ind<1 ||ind>999999 || oc<2 || oc>5)
{
    throw runtime_error("Zle dane studenta");
}
nazwisko=nazw;
imie=im;
indeks=ind;
ocena=oc;
}

bool Student::operator < (const Student &s) const
{
    if(indeks<s.indeks)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream& operator<<(ostream &os, const Student &s)
{
    os<<s.indeks<<";"<<s.ocena<<";"<<s.nazwisko<<" "<<s.imie[0]<<"."<<endl;
}
