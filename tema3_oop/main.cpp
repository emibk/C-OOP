#include <iostream>
#include <stdlib.h>
#include<tr1/unordered_map>
#include <algorithm>
#include <string>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;


/// geterii sunt fct constante
///constructorul de copiere are obiect const
/// fct si variabila statica in cls plata
///variabile statice in clasele template
///dynamic_cast in meniu
class plata
{
protected:
    double suma;
    int zi;
    string luna;
    int an;

    static int nr_plati;
public:
    plata(double suma=0,int zi=0,string luna="",int an=0)
    {
        nr_plati++;
        this->suma=suma;
        this->zi=zi;
        this->luna=luna;
        this->an=an;
    }
    virtual ~plata()
    {
        suma=0;
        zi=0;
        luna="";
        an=0;
    }
    plata(const plata &z)
    {
        suma=z.suma;
        zi=z.zi;
        luna=z.luna;
        an=z.an;
    }
    int get_suma() const{return suma;}
    void set_suma(int s){suma=s;}

    int get_zi()const {return zi;}
    void set_zi(int z){zi=z;}

    string get_luna()const{return luna;}
    void set_luna(string l){luna=l;}

    int get_an()const{return an;}
    void set_an(int a){an=a;}

    friend istream& operator>>(istream &in, plata& z);
    friend ostream& operator<<(ostream &out, plata& z);
    virtual void citire(istream &in);
    virtual void afisare(ostream &out);

    plata& operator=(const plata &z)
    {
        suma=z.suma;
        zi=z.zi;
        luna=z.luna;
        an=z.an;
        return *this;
    }

    static void numarPlati()
    {
        cout<<nr_plati;
    }

    void afisare_suma();
};

int plata::nr_plati=0;
void plata::afisare_suma()
{
    cout<<suma;
}
void plata::afisare(ostream &out)
{
    out<<"Suma este: "<<suma<<endl;
    out<<"Data este: "<<zi<<"."<<luna<<"."<<an;
}
ostream& operator<<(ostream& out, plata& z)
{
    z.afisare(out);
    return out;
}

void plata::citire(istream& in)
{
    cout<<"Suma platita :";
    in>>suma;
    cout<<endl<<"Ziua platii:";
    in>>zi;
    cout<<endl<<"Luna platii:";
    in>>luna;
    cout<<endl<<"Anul platii:";
    in>>an;
}
istream& operator>>(istream& in,plata& z)
{
    z.citire(in);
    return in;
}
class card: public plata
{
private:
    int client_nou;
    string nume_pers;
    int nr;
public:
    card(int client_nou=0,string nume_pers="",int nr=0,int suma=0,int zi=0,string luna="",int an=0):plata(suma,zi,luna,an)
    {
        this->client_nou=client_nou;
        this->nume_pers=nume_pers;
        this->nr=nr;
    }
    ~card()
    {
        client_nou=0;
        nume_pers="";
        nr=0;
    }
    card(const card &z)
    {
        client_nou=z.client_nou;
        nume_pers=z.nume_pers;
        nr=z.nr;
    }
    int get_client_nou()const{return client_nou;}
    //friend istream& operator>>(istream &in, card& z);
    //friend ostream& operator<<(ostream &out, card& z);
    void citire(istream &in);
    void afisare(ostream &out);

    card& operator=(const card &z)
    {
        client_nou=z.client_nou;
        nume_pers=z.nume_pers;
        nr=z.nr;
        return *this;
    }

};
void card::citire(istream& in)
{
    plata::citire(in);
    cout<<"Este client nou? 1-da, 0-nu:";
    in>>client_nou;
    cout<<"Nume persoana:";
    in.ignore();
    getline(in,nume_pers);
    cout<<"\nnr card:";
    in>>nr;
}
istream& operator>>(istream& in,card& z)
{
    z.citire(in);
    return in;
}
void card::afisare(ostream &out)
{
    if(client_nou==1) out<<"Client nou:"<<endl;
    else out<<"Client vechi:"<<endl;
    plata::afisare(out);

    out<<endl<<"Numele persoanei: "<<nume_pers<<endl;
    out<<"Nr card: "<<nr<<endl;
}
ostream& operator<<(ostream& out, card& z)
{
    z.afisare(out);
    return out;
}

class cash:public plata
{
public:
    cash(int suma=0,int zi=0,string luna="",int an=0):plata(suma,zi,luna,an)
    {
    }
    ~cash()
    {
    }
    //friend istream& operator>>(istream &in, cash& z);
    //friend ostream& operator<<(ostream &out, cash& z);
    void afisare(ostream &out);
    void citire(istream &in);
};

void cash::citire(istream& in)
{
    plata::citire(in);
}
istream& operator>>(istream& in,cash& z)
{
    z.citire(in);
    return in;
}
void cash::afisare(ostream &out)
{
    plata::afisare(out);
}
ostream& operator<<(ostream& out, cash& z)
{
    z.afisare(out);
    return out;
}


class cec:public plata
{
public:
    cec(double suma=0,int zi=0,string luna="",int an=0):plata(suma,zi,luna,an)
    {
    }
    ~cec()
    {
    }
   // friend istream& operator>>(istream &in, cec& z);
    //friend ostream& operator<<(ostream &out, cec& z);
    void afisare(ostream &out);
    void citire(istream &in);

};

void cec::citire(istream& in)
{
    plata::citire(in);
}
istream& operator>>(istream& in,cec& z)
{
    z.citire(in);
    return in;
}
void cec::afisare(ostream &out)
{
    plata::afisare(out);
}
ostream& operator<<(ostream& out, cec& z)
{
    z.afisare(out);
    return out;
}





template <class t> class gestiune
{
    t *v;
    int nr;
    static int nr_total_plati;
public:
    gestiune(t *p=NULL, int n=0)
    {
        nr_total_plati++;
        nr=n;
        v=new t[n];
        for(int i=0;i<n;i++)
        {
            v[i]=p[i];
        }
    }
    gestiune(gestiune &a)
    {
        nr_total_plati=a.nr_total_plati;
        nr=a.nr;
        v=new t[nr];
        for(int i=0;i<nr;i++)
        {
            v[i]=a.v[i];
        }
    }
    ~gestiune()
    {
        delete [] v;
    }

    int get_nr() {return nr;}
    t get_v(int i) {return v[i];}
    friend istream& operator >>(istream &in, gestiune <t> &g)
    {
        cout<<"Introduceti numarul de plati: ";
        in>>g.nr;
        g.v=new t[g.nr];
        cout<<"Introduceti platile: \n";
        for(int i=0;i<g.nr;i++){
           in>>g.v[i];
           cout<<"\n";
        }
        g.nr_total_plati=g.nr_total_plati+g.nr-1;
        return in;
    }
    friend ostream& operator <<(ostream &out, gestiune<t> &g)
    {

        out<<"S-au facut "<<g.nr<<" plati noi:"<<"\n";
        for(int i=0;i<g.nr;i++)
            out<<endl<<g.v[i]<<"\n";
        cout<<endl;
        cout<<"nr total de plati:"<<g.nr_total_plati;
        return out;
    }
    gestiune operator+=(gestiune<t>& z)
    {
        nr++;
        v[nr-1]=z;
        return *this;
    }
};
template<class t>
int  gestiune<t>::nr_total_plati=0;

template <> class gestiune <card>
{
    card* v;
    int nr;
    static int nr_clienti;
    static int nr_total_plati_card;
    string nume_client;
public:
    gestiune(card *p=NULL, int n=0,string nume="")
    {
        nr_total_plati_card++;
        nr=n;
        v=new card[n];
        for(int i=0;i<n;i++)
        {
            v[i]=p[i];
            if(v[i].get_client_nou()==1) nr_clienti++;
        }
        nume_client=nume;
    }
    gestiune(gestiune &a)
    {
        nr=a.nr;
        nr_clienti=0;
        v=new card[nr];
        for(int i=0;i<nr;i++)
        {
            v[i]=a.v[i];
            if(v[i].get_client_nou()==1) nr_clienti++;
        }
        nume_client=a.nume_client;
    }
    ~gestiune()
    {
        delete [] v;
    }

    int get_nr() {return nr;}
    card get_v(int i) {return v[i];}
    friend istream& operator >>(istream &in, gestiune <card> &g)
    {
        cout<<"Introduceti numarul de plati: ";
        in>>g.nr;
        g.v=new card[g.nr];
        cout<<"Introduceti platile\n";
        for(int i=0;i<g.nr;i++)
        {
            in>>g.v[i];

            if (g.v[i].get_client_nou()==1)
                    g.nr_clienti+=1;
           cout<<"\n";
        }
        g.nr_total_plati_card=g.nr_total_plati_card+g.nr-1;
        return in;
    }
    friend ostream& operator <<(ostream &out, gestiune<card> &g)
    {

        for(int i=0;i<g.nr;i++)
            out<<endl<<g.v[i]<<"\n";
        cout<<"Nr de clienti de pana acum:"<<g.nr_clienti;
        cout<<endl;
        cout<<"Nr total de plati pana acum:"<<g.nr_total_plati_card;
        return out;
    }

    gestiune operator+=(card& z)
    {
        nr++;
        v[nr-1]=z;
        return *this;
    }

};
int gestiune<card>::nr_clienti;
int gestiune<card>::nr_total_plati_card;
void menu_output()
{
    cout<<"\nCHISIM NICOLETA EMILIA-TEMA 3-EX1\n";
    cout<<"\n\t\tMENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Citeste informatii plati. --- UPCAST & LATE-BINDING";
    cout<<"\n";
    cout<<"2. Afisare informatii plati.";
    cout<<"\n";
    cout<<"3. Contorizare plati--DYNAMIC_CAST.";
    cout<<"\n";
    cout<<"4. Afisare nr plati.(fct si variabila statica)";
    cout<<"\n";
    cout<<"5. Template cec";
    cout<<"\n";
    cout<<"6. Template cash";
    cout<<"\n";
    cout<<"7. Template card";
    cout<<"\n";
    cout<<"0. Iesire.";
    cout<<"\n";
}

void tip1(plata *p, int &i, std::tr1::unordered_map<int,plata*> &l) {
    string s;
    cout<<"\n";
    cout<<"Introduceti tipul platii "<<i+1<<": ";
    cin>>s;

    if(s!="cash" && s!="cec" && s!="card")
        cout<<"Selectie invalida! Incercati cash, card sau cec";
    if(s=="cash")
        {

                p=new cash;
                cin>>*p;
                l[i]=p;
        }
    if(s=="card")
            {
               p=new card;
               cin>>*p;
               l[i]=p;
            }
    if(s=="cec")
        {
            p=new cec;
            cin>>*p;
            l[i]=p;
        }
}

void menu1()
{
    int option;
    option=0;
    int n=0;
    plata **v;
    std::tr1::unordered_map<int,plata*>plati;

    do
    {
        menu_output();
        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;
        if (option==1)
        {


            cout<<"Dati nr de obiecte:";
	        cin>>n;
	        if(n>0){
	        v=new plata*[n];
            for(int i=0;i<n;i++)
                tip1(v[i],i,plati);

            }

            else
                cout<<"Numarul introdus trebuie sa fie pozitiv.\n";
        }

        if(option==2)
        {
            if(n>0){
            for(int i=0;i<n;i++)
            {
                cout<<*plati[i]<<endl<<endl;}}
            else cout<<"Dati valoare pentru n. Reveniti la 1";
        }
        if(option==3)
        {
            int N_cash,N_card,N_cec;
            N_cash=N_card=N_cec=0;
            if(n>0)
            {
                for(int i=0;i<n;i++)
                {
                    cash *p1=dynamic_cast<cash*>(plati[i]);
                    card *p2=dynamic_cast<card*>(plati[i]);
                    cec *p3=dynamic_cast<cec*>(plati[i]);
                    if(p1) N_cash++;
                    if(p2) N_card++;
                    if(p3) N_cec++;
                }
               cout<<"Nr plati card="<<N_card<<endl;
               cout<<"Nr plati cash="<<N_cash<<endl;
               cout<<"Nr plati cec="<<N_cec<<endl;
            }
            else cout<<"Dati o valoare valida pt n. Reveniti la 1";
        }

        if(option==4)
        {
           plata::numarPlati();
        }
        if(option==5)
        {
            gestiune<cec>x;
            cin>>x;
            cout<<x<<endl;
        }
        if(option==6)
        {
            gestiune<cash>x;
            cin>>x;
            cout<<x;
        }
        if(option==7)
        {
            gestiune<card>x;
            cin>>x;
            cout<<x;
        }
        if (option==0)
        {
            cout<<"\nEXIT\n\n";
        }
        if (option<0||option>7)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause");
        system("cls");
    }
    while(option!=0);
}



int main()
{
    menu1();
    return 0;
}
