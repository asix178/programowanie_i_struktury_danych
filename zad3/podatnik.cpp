#include<iostream>
#include<string>
#include"podatnik.h"
#include<string>
using namespace std;
Podatnik::Podatnik(string N, string A)
{
    nazwa=A;
    NIP=N;
}
ostream& operator<<(ostream&os, const Podatnik& p)
{
os<<p.NIP<<" "<<p.nazwa<<endl;
}
bool Podatnik::czy_NIP(string N)
{
    if(N.length()!=10)
    {
        return false;
    }
    else
    {
        for(int i=0;i<10;i++)
        {
            if(N[i]<'0'||N[i]>'9')
            {
                return false;
            }
        }
        return true;
    }
}
int Podatnik::urzad()
{
    if(NIP[0]=='7' && NIP[1]=='7' && NIP[2]=='1')
        {
            return 0;
        }
        else if (NIP[0]=='7' && NIP[1]=='7' && NIP[2]=='2')
        {
            return 1;
        }
        else if (NIP[0]=='7' && NIP[1]=='7' && NIP[2]=='3')
        {
            return 2;
        }
        else
        {
            throw runtime_error("Inny urzad");
        }
}
