#include <iostream>
#include <stdlib.h>
using namespace std;

//lists in oop
///variabila si fct statica in clasa LDI
///functii virtuale in clasa Nod si in clasa LDI
///constructori parametrizati in Nod_dublu si LSI
///toate clasele au functii set si get
///upcasting/downcasting in meniu

class Nod
{
protected:
    int info;
    Nod *next;
public:
    ///constructor
    Nod(int info=0, Nod *next=NULL)
    {
        this->info=info;
        this->next=next;
    }
    ///copiere
    Nod(Nod&);
    ///destructor
    virtual ~Nod();
    ///atribuire
    Nod& operator=(Nod &z)
    {
        this->info=z.info;
        this->next=next;
        return *this;
    };
    friend istream& operator>>(istream &in, Nod& z);
    friend istream& operator<<(ostream &out, Nod& z);

    void set_info(int info)
    {
        this->info=info;
    };
    void set_next(Nod*)
    {
        this->next=next;
    };
    int get_info(){return info;};
    Nod* get_next(){return next;};

    friend bool operator>(const Nod& z1, const Nod& z2){return (z1.info>z2.info);}
    friend bool operator<(const Nod& z1, const Nod& z2){return (z1.info<z2.info);}
    friend class LDI;
    friend class LSI;
};
Nod::Nod(Nod &z)
{
    this->info=z.info;
    this->next=z.next;
}
Nod::~Nod()
{
    this->info=0;
    this->next=NULL;
}
///mosteneste Nod
class Nod_dublu: public Nod{
protected:
    Nod* ante;
public:
    Nod_dublu(int info=0,Nod *next=NULL, Nod *ante=NULL):Nod(info,next)
    {
        this->ante=ante;
    }
    Nod_dublu(Nod_dublu&);
    ~Nod_dublu();
    Nod_dublu& operator=(Nod_dublu &z)
    {
        Nod::operator=(z);
        this->ante=z.ante;
        return *this;
    };
    friend istream& operator>>(istream &in, Nod_dublu& z);
    friend istream& operator<<(ostream &out, Nod_dublu& z);
    void set_next(Nod*)
    {
        this->ante=ante;
    };
    Nod* get_ante(){return ante;};
    friend class LDI;
    friend class LSI;
};


Nod_dublu::Nod_dublu(Nod_dublu &z)
{
    this->ante=z.ante;
}
Nod_dublu::~Nod_dublu()
{
    this->ante=NULL;
}

class LDI{
protected:
    Nod_dublu *Front;
    Nod_dublu *End;
    ///variabila statica
    static int indice;
public:
    LDI(Nod_dublu *Front=NULL,Nod_dublu *End=NULL)
    {
        indice=indice+1;
        this->Front=Front;
        this->End=End;
    }
    LDI(LDI&z)
    {
        this->Front=z.Front;
        this->End=z.End;
    }
    virtual ~LDI();
    LDI& operator=(LDI &z)
    {
        this->Front=z.Front;
        this->End=z.End;
        return *this;
    };//supraincarcare atribuire
    void afisare(ostream& out);
    friend istream& operator>>(istream &in, LDI& z);
    friend ostream& operator<<(ostream &out, LDI& z);
    void adaugare_fata(int);
    void adaugare_sfarsit(int);
    ///functie statica
    static void numarObiecte(){ /// metoda statica de afisare a numarului de obiecte
        cout<<indice;
    }

    void set_Front(Nod_dublu* Front)
    {
        this->Front=Front;
    };
    void set_End(Nod_dublu* End)
    {
        this->End=End;
    };
    void set_indice(int indice)
    {
        this->indice=indice;
    }
    Nod_dublu* get_Front(){return Front;};
    Nod_dublu* get_End(){return End;};
    int get_indice(){return indice;};

    friend bool operator>(const LDI& z1, const LDI& z2)
    {

    }

};
int LDI::indice;
LDI::~LDI()
{
    this->Front=NULL;
    this->End=NULL;
}

void LDI::adaugare_fata(int d)
{
    Nod_dublu *temp;
    temp=new Nod_dublu();
    temp->info=d;
    temp->ante=NULL;
    temp->next=Front;
    if(Front==NULL)
        End=temp;
    else
        Front->ante=temp;
    Front=temp;
}
void LDI::adaugare_sfarsit(int d)
{
    Nod_dublu *temp;
    temp=new Nod_dublu();
    temp->info=d;
    temp->ante=End;
    temp->next=NULL;
    if(End==NULL)
        Front=temp;
    else
        End->next=temp;
    End=temp;
}

void LDI::afisare(ostream& out)
{
    Nod_dublu *afis=Front;
    while(afis!=NULL)
    {
        out<<afis->info<<endl;
        afis=(Nod_dublu*)afis->next;
    }

}
ostream& operator<<(ostream& out, LDI& z){
    z.afisare(out);
    return out;
}

class LSI: public LDI{
public:
    LSI(Nod_dublu* Front=NULL,Nod_dublu* End=NULL):LDI(Front,End){};
    LSI(LSI&z){};
    ~LSI(){};
    LSI& operator=(LSI &z);
    void afisare_s(ostream& out);
    friend istream& operator>>(istream &in, LSI& z);
    friend ostream& operator<<(ostream &out, LSI& z);
    void adaugare_sfarsit_lsi(int);
};
void LSI::adaugare_sfarsit_lsi(int d)
{
    Nod_dublu *temp;
    temp=new Nod_dublu();
    temp->info=d;
    temp->ante=NULL;
    temp->next=NULL;
    if(End==NULL)
        Front=temp;
    else
        End->next=temp;
    End=temp;
}

void LSI::afisare_s(ostream& out)
{
    Nod_dublu *afis=Front;
    while(afis!=NULL)
    {
        out<<afis->info<<endl;
        afis=(Nod_dublu*)afis->next;
    }

}
ostream& operator<<(ostream& out, LSI& z){
    z.afisare(out);
    return out;
}
void menu_output(){
    cout<<"\n Chisim Nicoleta Emilia 254 - Proiect 2 - Tema 1 \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Citeste n obiecte lista dublu inlantuita."; cout<<"\n";
    cout<<"2. Afiseaza cele n obiecte din lista dublu inlantuita."; cout<<"\n";
    /// folosire variabile si fct statice
    cout<<"3. Numarul total de elemente adaugate in liste(fct si var statica)."; cout<<"\n";
    cout<<"4. Citeste n obiecte lista simplu inlantuita."; cout<<"\n";
    cout<<"5. Afiseaza cele n obiecte din lista simplu inlantuita."; cout<<"\n";
    cout<<"6. Exemplu Upcasting."; cout<<"\n";
    cout<<"7. Exemplu Downcasting."; cout<<"\n";
    cout<<"0. Iesire."; cout<<"\n";
}
void menu()
{
    int option;
    option=0;
    int n=0;
    int n1=0;
    int i;
    int d;
    LDI *lista;
    LSI *lista_s;
    do
    {
        menu_output();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;

        if (option==1)
        {
           cout<<"Dati numarul de obiecte";
           cin>>n;
           lista=new LDI[n];
           for(i=0;i<n;i++)
           {
               cout<<"Elementul "<<i+1<<" este:";cin>>d;
               lista[i].adaugare_sfarsit(d);
           }

        }
        if (option==2)
        {
            if (n!=0)
            {
                for(int i=0;i<n;i++)
                       cout<<lista[i];
            }
        }
        if (option==3)
        {
            cout<<"Numarul de elemente este:";
            LDI::numarObiecte();
        }
        if (option==4)
        {
           cout<<"Dati numarul de obiecte";
           cin>>n1;
           lista_s=new LSI[n1];
           for(i=0;i<n1;i++)
           {
               cout<<"Elementul "<<i+1<<" este:";cin>>d;
               lista_s[i].adaugare_sfarsit_lsi(d);
           }
        }
        if (option==5)
        {

            if (n1!=0)
            {
                for(int i=0;i<n1;i++)
                       cout<<lista_s[i];
            }
        }
        if (option==6)
        {
           LSI s;
           int var;
           cout<<"Dati o valoare pentru s( element LSI):";
           cin>>var;
           s.adaugare_sfarsit_lsi(var);
           cout<<"facem conversia si afisam rezultatul(elementul LDI *d):";
           LDI *d=&s;
           cout<<*d;

        }
        if (option==7)
        {
           LDI d;
           int var;
           cout<<"Dati valoarea pentru d(element LDI):";
           cin>>var;
           d.adaugare_fata(var);
           LSI *s=(LSI*)&d;
           cout<<"facem conversia si afisam rezultatul (elementul LSI *s):";
           cout<<*s;

        }
        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option<0||option>8)
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
    menu();
    return 0;
}
