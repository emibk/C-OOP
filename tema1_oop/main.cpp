#include <iostream>
#include<math.h>
#include <string.h>
#include<string>
#include <stdlib.h>
using namespace std;

class actor{
private:
    string nume_actor;
    int varsta;
public:
  actor(string nume_actor="anonim", int varsta=0)
    {

        this->nume_actor=nume_actor;
        this->varsta=varsta;
    }
    actor(actor&);
    ~actor();

    void set_nume_actor(string);
    void set_varsta(int);
    string get_nume_actor(){ return nume_actor;};
    int get_varsta(){return varsta;};

    void citire(istream &in);
    void afisare(ostream &out);

    actor& operator=(actor &z);

    friend istream& operator>>(istream &in, actor& z);
    friend ostream& operator<<(ostream &out, actor& z);

};

actor::actor(actor &z)
{
    this->nume_actor=z.nume_actor;
    this->varsta=z.varsta;
}
actor::~actor()
{
    this->nume_actor.clear();
    this->varsta=0;
}
void actor::set_nume_actor(string nume_actor)
{

    this->nume_actor=nume_actor;
}
void actor::set_varsta(int varsta)
{
    this->varsta=varsta;
}
void actor::citire(istream &in){
    cout<<"\nCititi numele actorului: ";
    in.ignore();
    getline(in,nume_actor);
    cout<<"\nVarsta actorului=";
    in>>varsta;
}

istream& operator>>(istream& in,actor& z){
    z.citire(in);
    return in;
}

void actor::afisare(ostream &out){
    out<<"\nNumele actorului este:"<<nume_actor;
    out<<"\nVarsta actorului este:"<<varsta;
}
ostream& operator<<(ostream& out, actor& z){
    z.afisare(out);
    return out;
}
actor& actor::operator=(actor &z){
    nume_actor=z.nume_actor;
    varsta=z.varsta;

}
class teatru{
private:
    string denumire_piesa;
    int nr_actori;
    actor *actori;
    int rating;
public:

 //   teatru();
    teatru(string,int,int);
    teatru(teatru&);
    ~teatru();

    void set_denumire_piesa(string);
    void set_nr_actori(int);
    void set_actori(actor*);
    void set_rating(int);
    string get_denumire_piesa(){ return denumire_piesa;};
    int get_nr_actori(){return nr_actori;};
    int get_rating(){return rating;};
    actor* get_actori(){return actori;};

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream &in, teatru& z);
    friend ostream& operator<<(ostream &out, teatru&z);


    teatru& operator=(teatru &z);


    friend bool operator>(const teatru& z1, const teatru& z2){return (z1.rating>z2.rating);}
    friend bool operator<(const teatru& z1, const teatru& z2){return (z1.rating<z2.rating);};


};

teatru::teatru(string denumire_piesa="anonim", int nr_actori=0,int rating=0)
    {
        this->denumire_piesa=denumire_piesa;
        this->nr_actori=nr_actori;
        this->rating=rating;
    }
teatru::teatru(teatru &z)
{
    this->denumire_piesa=z.denumire_piesa;
    this->nr_actori=z.nr_actori;
    this->rating=rating;
}
teatru::~teatru()
{
    this->denumire_piesa.clear();
    this->nr_actori=0;
    this->rating=rating;
}

void teatru::set_denumire_piesa(string denumire_piesa)
{

    this->denumire_piesa=denumire_piesa;

}
void teatru::set_rating(int rating)
{
    this->rating=rating;
}
void teatru::set_nr_actori(int nr_actori)
{
    this->nr_actori=nr_actori;
}
void teatru::set_actori(actor *actori)
{
    this->actori=actori;
}
void teatru::citire(istream& in)
{
    int i;

    cout<<"\nDenumire piesa:";
    in.ignore();
    getline(in,denumire_piesa);
    cout<<"\nNr actori:";
    in>>nr_actori;
    cout<<"\nDate actori:   ";
    actori=new actor[nr_actori];
    for(i=0;i<nr_actori;i++){
        actori[i].citire(in);}

    cout<<"\nRating:";
    in>>rating;

}
istream& operator>>(istream& in,teatru& z){
    z.citire(in);
    return in;
}

void teatru::afisare(ostream& out)
{
    int i;
    out<<"\nNumele piesei este: "<<denumire_piesa;
    out<<"\nNr de actori: "<<nr_actori;
    for(i=0;i<nr_actori;i++)
        actori[i].afisare(out);
    out<<"\nRating:"<<rating<<"\n\n";
}

ostream& operator<<(ostream& out, teatru& z){
    z.afisare(out);
    return out;
}

teatru& teatru::operator=(teatru &z){
    denumire_piesa=z.denumire_piesa;
    nr_actori=z.nr_actori;
    rating=z.rating;
}

/// modelul meniului a fost preluat de la laborator, de aceea arata foarte similar
void menu_output2()
{
    cout<<"\n\t MENIU2:";
    cout<<"\n===========================================\n";
    cout<<"1. Modificare denumire piesa"; cout<<"\n";
    cout<<"2. Modificare rating"; cout<<"\n";
    cout<<"3. Modificare numar si date actori"; cout<<"\n";
    cout<<"0. Iesire."; cout<<"\n";

}
void menu2(int i1,teatru *p)
{
    int option;
    int r,i,varsta_act;
    int nr_act;
    actor *actori;
    string s1;
    string nume_act;
    option=0;
    do
    {
        menu_output2();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;
        if (option==1)
        {
            cout<<"Dati noua denumire a piesei:";
            cin.ignore();
            getline(cin,s1);
            p[i1-1].set_denumire_piesa(s1);
        }
         if (option==2)
        {
            cout<<"Dati noul rating al piesei:";
            cin>>r;
            p[i1-1].set_rating(r);
        }
        if(option==3)
        {
            cout<<"Dati noul numar de actori:";
            cin>>nr_act;
            p[i1-1].set_nr_actori(nr_act);
            actori=new actor[nr_act];
            for(i=0;i<nr_act;i++)
            {
                cin>>actori[i];
            }
            p[i1-1].set_actori(actori);
        }
        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option<0||option>3)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause");
        system("cls");
    }while(option!=0);

}
void menu_output(){
    cout<<"\n Chisim Nicoleta Emilia - Tema 1 - 19: \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Citire date"; cout<<"\n";
    cout<<"2. Afisare date"; cout<<"\n";
    cout<<"3. Comparare piese"; cout<<"\n";
    cout<<"4. Modificare date piese"; cout<<"\n";
    cout<<"0. Iesire."; cout<<"\n";
}
void menu()
{
    int option;
    int n,i1,i2;
    teatru *p;
    option=0;

    do
    {
        menu_output();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;

        if (option==1)
        {
           cout<<"Dati numarul de obiecte n:";
           cin>>n;
           if (n>0){
                p=new teatru[n];
                for (int i=0;i<n;i++)
                    {cin>>p[i];
                    }

           }
           else
            cout<<"Valoarea n trebuie sa fie pozitiva";
        }
        if (option==2)
        {
            if (n!=0)
            {
                for (int i=0;i<n;i++)
                {

                cout<<"piesa nr "<<i+1<<" : ";
                cout<<p[i];}
            }
        }
        if (option==3)
        {

            cout<<" Alegeti indicii pieselor de comparat( acestia trebuie sa fie diferiti ):\n";
            cout<<"primul indice:";cin>>i1;
            cout<<"al doilea indice:";cin>>i2;
            if(i1<=n && i2<=n && i1!=i2){
            if(operator>(p[i1-1],p[i2-1])) cout<<"Piesa cu indicele "<<i1<<" are ratingul mai mare decat piesa cu indicele "<<i2;
            else{
                if (operator<(p[i1-1],p[i2-1])) cout<<"Piesa cu indicele "<<i2<<" are ratingul mai mare decat piesa cu indicele "<<i1;
                else cout<<"Piesele au ratingul egal";
            }}
            else cout<<" Indicii nu sunt corect alesi";
            }
            //if(i1==i2) cout<<"Ati ales aceeasi piesa de doua ori";
        if (option==4)
        {

           cout<<" Alegeti indicele piesei care trebuie modificata:\n";
           cin>>i1;
           if(i1<=n){
            system("pause");
            system("cls");
           menu2(i1,p);}
           else cout<<" Indicele nu poate fi mai mare decat n";
        }
        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option<0||option>4)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause");
        system("cls");
    }while(option!=0);
}

int main()
{
    menu();
    return 0;

}
