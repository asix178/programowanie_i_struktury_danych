#ifndef ZNAM_STUDENT
#define ZNAM_STUDENT
#include<string>
using namespace std;
struct Student
{
private:
    string nazwisko, imie;
    int indeks;
    double ocena;
public:
    Student(string nazw="", string im="", int ind=1, double oc=2);
    bool operator < (const Student &s) const;

    friend ostream& operator<<(ostream &os, const Student &s);

};
ostream& operator<<(ostream &os, const Student &s);


#endif // ZNAM_STUDENT
