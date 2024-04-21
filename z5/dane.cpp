#include"dane.h"
#include<string>
#include<iostream>
#include<stdexcept>
using namespace std;
Podatnik::Podatnik(string im,string naz,string n,double r)
{
    //if(czyNip(n)==false)
    //{
      //  throw runtime_error ("Bledny nip");
    //}
    imie=im;
    nazwisko=naz;
    nip=n;
    rozliczenie=r;
}
ostream& operator<<(ostream&os, const Podatnik&p)
{
    os<<p.nazwisko<<endl<<p.imie<<endl<<p.nip<<endl<<p.rozliczenie<<endl<<endl;
    return os;
}

bool Podatnik::operator >=(const Podatnik&os)
{
    if(nazwisko>=os.nazwisko)
    {
        /*if(nazwisko==os.nazwisko)
        {
            if(imie>=os.imie)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }*/
        return true;
    }
    else
    {
        return false;
    }
}
bool Podatnik::operator >(const Podatnik&os)
{
    if(nazwisko>os.nazwisko)
    {
        return true;
    }
    /*else if(nazwisko==os.nazwisko)
    {
        if(imie>os.imie)
        {
            return true;
        }
        else
        {
            return false;
        }
    }*/
    else
    {
        return false;
    }
}
bool czyNip(string n)
{
    if(n.length()!=10)
    {
        return false;
    }
    else
    {
        return true;
    }
}
