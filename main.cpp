#include <iostream>
#include <cstring>

using namespace std;

class Perioada
{
private:
    char* data_inc;
    char* data_fin;

public:
    Perioada(); //constructor fara param
    Perioada(char* data_inc, char* data_fin); //constructor cu param
    Perioada(const Perioada& P1); //copy constructor
    Perioada& operator = (const Perioada& P1); //supraincarcarea opertaorului egal
    ~Perioada(); //destructor

    //getters
    char* getdata_inc();
    char* getdata_fin();

    //setters
    void setdata_inc(char* data_inc);
    void setdata_fin(char* data_fin);

    //citire si afisare
    friend istream& operator>>(istream& in, Perioada& P1);
    friend ostream& operator<< (ostream& out, const Perioada& P1);

};

char* Perioada::getdata_inc() {return this->data_inc;}
char* Perioada::getdata_fin() {return this->data_fin;}

void Perioada::setdata_inc(char* data_inc)
{
    if(this->data_inc!=NULL)
        delete[] this->data_inc;
    this->data_inc=new char[strlen(data_inc)+1];
    strcpy(this->data_inc,data_inc);
}

void Perioada::setdata_fin(char* data_fin)
{
    if(this->data_fin!=NULL)
        delete[] this->data_fin;
    this->data_fin=new char[strlen(data_fin)+1];
    strcpy(this->data_fin,data_fin);
}

Perioada::Perioada()
{
    this->data_inc = new char [strlen("01/01/1900")+1];
    strcpy(this->data_inc, "01/01/1900");

    this->data_fin = new char [strlen("12/04/1976")+1];
    strcpy(this->data_fin, "12/04/1976");
}

Perioada::Perioada(char* data_inc, char* data_fin)
{
    this->data_inc = new char [strlen(data_inc)+1];
    strcpy(this->data_inc, data_inc);

    this->data_fin = new char [strlen(data_fin)+1];
    strcpy(this->data_fin, data_fin);

}

Perioada::Perioada(const Perioada& P1)
{
    this->data_inc = new char [strlen(P1.data_inc)+1];
    strcpy(this->data_inc, P1.data_inc);

    this->data_fin = new char [strlen(P1.data_fin)+1];
    strcpy(this->data_fin, P1.data_fin);

}

Perioada& Perioada::operator= (const Perioada& P1)
{
    if( this!= &P1 )
    {
        if( this->data_inc != NULL)
            delete[] this->data_inc;

        if( this->data_fin != NULL)
            delete[] this->data_fin;

        this->data_inc = new char [strlen(P1.data_inc)+1];
        strcpy(this->data_inc, P1.data_inc);

        this->data_fin = new char [strlen(P1.data_fin)+1];
        strcpy(this->data_fin, P1.data_fin);

    }

    return* this;

}

Perioada::~Perioada()
{
    if( this->data_inc != NULL)
        delete[] this->data_inc;

    if( this->data_fin != NULL)
        delete[] this->data_fin;
}

istream& operator>>(istream& in, Perioada& P1)
{
    char a[101], b[101];
    in>>a>>b;

    if(P1.data_inc!=NULL)
        delete[] P1.data_inc;

    if(P1.data_fin!=NULL)
        delete[] P1.data_fin;

    P1.data_inc = new char[strlen(a)+1];
    P1.data_fin = new char[strlen(b)+1];

    strcpy(P1.data_inc, a);
    strcpy(P1.data_fin, b);

    return in;
}

ostream& operator<< (ostream& out, const Perioada& P1)
{
    out<<P1.data_inc<<" "<<P1.data_fin;

    return out;
}


class Curent_artistic
{
private:
    char* denumire;
    Perioada perioada_desfasurarii;

public:
    Curent_artistic();
    Curent_artistic(char* denumire, Perioada perioada_desfasurarii);
    Curent_artistic(const Curent_artistic& C1); //copy constructor
    Curent_artistic& operator = (const Curent_artistic& C1); //supraincarcarea operatorului egal
    ~Curent_artistic(); //destructor

    //getters
    char* getdenumire();

    //setters
    void setdenumire(char* denumire);

    //citire si afisare
    friend istream& operator>>(istream& in, Curent_artistic& C1);
    friend ostream& operator<< (ostream& out, const Curent_artistic& C1);

};

char* Curent_artistic::getdenumire() {return this->denumire;}

void Curent_artistic::setdenumire(char* denumire)
{
    if(this->denumire!=NULL)
        delete[] this->denumire;
    this->denumire=new char[strlen(denumire)+1];
    strcpy(this->denumire,denumire);
}

Curent_artistic::Curent_artistic()
{
    this->denumire = new char[strlen("curent anonim")+1];
    strcpy(this->denumire,"curent anonim");

    this->perioada_desfasurarii;
}

Curent_artistic::Curent_artistic(char* denumire, Perioada perioada_desfasurarii)
{
    this->denumire = new char[strlen(denumire)+1];
    strcpy(this->denumire,denumire);

    this->perioada_desfasurarii=perioada_desfasurarii;
}

Curent_artistic::Curent_artistic(const Curent_artistic& C1)
{
    this->denumire = new char[strlen(C1.denumire)+1];
    strcpy(this->denumire,C1.denumire);

    this->perioada_desfasurarii=C1.perioada_desfasurarii;
}

Curent_artistic& Curent_artistic::operator= (const Curent_artistic& C1)
{
    if(this != &C1)
    {
        if(this->denumire!=NULL)
            delete[] this->denumire;

        this->denumire = new char[strlen(C1.denumire)+1];
        strcpy(this->denumire,C1.denumire);

        this->perioada_desfasurarii=C1.perioada_desfasurarii;

    }

    return* this;
}

Curent_artistic::~Curent_artistic()
{
    if(this->denumire!=NULL)
        delete[] this->denumire;

}

istream& operator>>(istream& in, Curent_artistic& C1)
{
    char a[100];
    in>>a;

    if(C1.denumire!=NULL)
        delete[] C1.denumire;


    C1.denumire = new char[strlen(a)+1];
    strcpy(C1.denumire, a);

    in>>C1.perioada_desfasurarii;

    return in;
}

ostream& operator<< (ostream& out, const Curent_artistic& C1)
{
    out<<C1.denumire<<" "<<C1.perioada_desfasurarii;

    return out;
}


class Artist
{
private:
    char* nume;
    char* prenume;
    const int ID_artist;
    static int contorArtist;
    bool in_viata;
    Curent_artistic curent_aderent;
    Perioada perioada_vietii;

public:
    Artist(); //constructor fara parametrii
    Artist(char* nume, char* prenume, bool in_viata); //constructor cu mai multi parametrii
    Artist(char* nume, char* prenume, bool in_viata, Curent_artistic curent_aderent, Perioada perioada_vietii); //constructor cu toti
    Artist(const Artist& A1); //copy constructor
    Artist& operator = (const Artist& A1); //supraincarcarea operatorului egal
    ~Artist(); //destructor

    //getters
    char* getnume();
    char* getprenume();
    bool getin_viata();
    const int getID_artist();
    static int getcontorArtist();

    //setters
    void setnume(char* nume);
    void setprenume(char* prenume);
    void setin_viata(bool in_viata);

    //citire/afisare
    friend istream& operator>>(istream& in, Artist& A1);
    friend ostream& operator<< (ostream& out, const Artist& A1);


};

char* Artist::getnume(){return this->nume;}
char* Artist::getprenume(){return this->prenume;}
bool Artist::getin_viata(){return this->in_viata;}
const int Artist::getID_artist(){return this->ID_artist;}
int Artist::getcontorArtist(){return contorArtist;}


void Artist::setnume(char* nume)
{
    if(this->nume!=NULL)
        delete[] this->nume;
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
}

void Artist::setprenume(char* prenume)
{
    if(this->prenume!=NULL)
        delete[] this->prenume;
    this->prenume=new char[strlen(prenume)+1];
    strcpy(this->prenume,prenume);
}

void Artist::setin_viata(bool in_viata)
{
    this->in_viata=in_viata;
}


int Artist::contorArtist=1000;

Artist::Artist():ID_artist(contorArtist++)
{
    this->nume = new char[strlen("fara nume")+1];
    strcpy(this->nume,"fara nume");

    this->prenume = new char[strlen("fara prenume")+1];
    strcpy(this->prenume,"fara prenume");

    this->in_viata=0;

    this->curent_aderent;

    this->perioada_vietii;

}

Artist::Artist(char* nume, char* prenume, bool in_viata):ID_artist(contorArtist++)
{
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume,nume);

    this->prenume = new char[strlen(prenume)+1];
    strcpy(this->prenume,prenume);

    this->in_viata=in_viata;

    this->curent_aderent;

    this->perioada_vietii;
}

Artist::Artist(char* nume, char* prenume, bool in_viata, Curent_artistic curent_aderent, Perioada perioada_vietii):ID_artist(contorArtist++)
{
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume,nume);

    this->prenume = new char[strlen(prenume)+1];
    strcpy(this->prenume,prenume);

    this->in_viata=in_viata;

    this->curent_aderent=curent_aderent;

    this->perioada_vietii=perioada_vietii;
}

Artist::Artist(const Artist& A1):ID_artist(A1.ID_artist)
{
    this->nume = new char[strlen(A1.nume)+1];
    strcpy(this->nume,A1.nume);

    this->prenume = new char[strlen(A1.prenume)+1];
    strcpy(this->prenume,A1.prenume);

    this->perioada_vietii=A1.perioada_vietii;

    this->in_viata=A1.in_viata;

    this->curent_aderent=A1.curent_aderent;
}

Artist& Artist::operator= (const Artist& A1)
{
    if(this != &A1)
    {
        if(this->nume!=NULL)
            delete[] this->nume;

        this->nume = new char[strlen(A1.nume)+1];
        strcpy(this->nume,A1.nume);

        if(this->prenume!=NULL)
            delete[] this->prenume;

        this->prenume = new char[strlen(A1.prenume)+1];
        strcpy(this->prenume,A1.prenume);

        this->in_viata=A1.in_viata;

        this->perioada_vietii=A1.perioada_vietii;

        this->curent_aderent=A1.curent_aderent;

    }

    return* this;
}

Artist::~Artist()
{
    if(this->nume!=NULL)
        delete[] this->nume;
    if(this->prenume!=NULL)
        delete[] this->prenume;

}

istream& operator>>(istream& in, Artist& A1)
{
    char a[100],b[100];
    in>>a>>b;

    if(A1.nume!=NULL)
        delete[] A1.nume;

    A1.nume = new char[strlen(a)+1];
    strcpy(A1.nume, a);

    if(A1.prenume!=NULL)
        delete[] A1.prenume;

    A1.prenume = new char[strlen(b)+1];
    strcpy(A1.prenume, b);

    in>>A1.in_viata>>A1.curent_aderent>>A1.perioada_vietii;

    return in;
}

ostream& operator<< (ostream& out, const Artist& A1)
{
    out<<A1.nume<<" "<<A1.prenume<<" "<<A1.in_viata<<" "<<A1.ID_artist<<" "<<A1.curent_aderent<<" "<<A1.perioada_vietii;

    return out;
}

class Exponat
{
private:
    char* denumire;
    int anul_aparitiei;
    const int ID_exponat;
    static int contorExpo;
    Artist artist_exponat;
    Curent_artistic curent;

public:
    Exponat(); //constructor fara parametrii
    Exponat(char* denumire, int anul_aparitiei, const int ID_exponat, Artist artist_exponat, Curent_artistic curent);
    Exponat(const Exponat& E); //copy constructor
    Exponat& operator = (const Exponat& E); //supraincarcarea operatorului egal
    ~Exponat(); //destructor

    //getters
    int getanul_aparitiei();
    const int getID_exponat();

    //setters
    void setdenumire(char* denumire);
    void setanul_aparitiei(int anul_aparitiei);

    //citire/afisare
    friend istream& operator>>(istream& in, Exponat& E);
    friend ostream& operator<< (ostream& out, const Exponat& E);

    //metode
    bool exponate_dupa1900();
};

const int Exponat::getID_exponat(){return this->ID_exponat;}
int Exponat::getanul_aparitiei(){return anul_aparitiei;}

void Exponat::setdenumire(char* denumire)
{
    if(this->denumire!=NULL)
        delete[] this->denumire;
    this->denumire=new char[strlen(denumire)+1];
    strcpy(this->denumire,denumire);
}

void Exponat::setanul_aparitiei(int anul_aparitiei)
{
    this->anul_aparitiei=anul_aparitiei;
}


int Exponat::contorExpo=2000;

Exponat::Exponat():ID_exponat(contorExpo++)
{
    this->denumire = new char[strlen("fara denumire")+1];
    strcpy(this->denumire,"fara denumire");

    this->anul_aparitiei=0;

    this->artist_exponat;

    this->curent;

}

Exponat::Exponat(char* denumire, int anul_aparitiei, const int ID_exponat, Artist artist_exponat, Curent_artistic curent):ID_exponat(contorExpo++)
{
    this->denumire = new char[strlen(denumire)+1];
    strcpy(this->denumire,denumire);

    this->anul_aparitiei=anul_aparitiei;

    this->artist_exponat=artist_exponat;

    this->curent=curent;
}

Exponat::Exponat(const Exponat& E):ID_exponat(E.ID_exponat)
{
    this->denumire = new char[strlen(E.denumire)+1];
    strcpy(this->denumire,E.denumire);

    this->artist_exponat=E.artist_exponat;

    this->anul_aparitiei=E.anul_aparitiei;

    this->curent=E.curent;
}

Exponat& Exponat::operator= (const Exponat& E)
{
    if(this != &E)
    {
        if(this->denumire!=NULL)
            delete[] this->denumire;

        this->denumire = new char[strlen(E.denumire)+1];
        strcpy(this->denumire,E.denumire);


        this->artist_exponat=E.artist_exponat;

        this->anul_aparitiei=E.anul_aparitiei;

        this->curent=E.curent;

    }

    return* this;
}

istream& operator>>(istream& in, Exponat& E)
{
    char a[100];
    in>>a;

    if(E.denumire!=NULL)
        delete[] E.denumire;

    E.denumire = new char[strlen(a)+1];
    strcpy(E.denumire, a);

    in>>E.anul_aparitiei>>E.artist_exponat>>E.curent;

    return in;

}

ostream& operator<< (ostream& out, const Exponat& E)
{
    out<<E.denumire<<" "<<E.anul_aparitiei<<" "<<E.ID_exponat<<" "<<E.artist_exponat<<" "<<E.curent;

    return out;
}

Exponat::~Exponat()
{
    if(this->denumire!=NULL)
        delete[] this->denumire;

}


bool Exponat::exponate_dupa1900()
{
    if(this->anul_aparitiei>1900)
        return true;
    else
        return false;
}


class Expozitie
{
private:
    char* denumire;
    Curent_artistic curent;
    int nrArtisti;
    Artist* artisti_expusi;
    Perioada perioada_desfasurarii_expozitiei;

public:
    Expozitie();
    Expozitie(const Expozitie& ex); //copy constructor
    Expozitie& operator = (const Expozitie& ex); //supraincarcarea operatorului egal
    ~Expozitie(); //destructor

    //getter
    int getnrArtisti();

    //citire/afisare
    friend istream& operator>>(istream& in, Expozitie& ex);
    friend ostream& operator<< (ostream& out, const Expozitie& ex);

    //metode
    void detalii_Artisti();

};

int Expozitie::getnrArtisti()
{
    return this->nrArtisti;
}

Expozitie::Expozitie()
{
    this->denumire = new char[strlen("fara denumire")+1];
    strcpy(this->denumire,"fara denumire");

    this->curent;

    this->nrArtisti=0;

    this->artisti_expusi=NULL;

    this->perioada_desfasurarii_expozitiei;

}


Expozitie::Expozitie(const Expozitie& ex)
{
    this->denumire = new char[strlen(ex.denumire)+1];
    strcpy(this->denumire,ex.denumire);

    this->curent=ex.curent;

    this->nrArtisti=ex.nrArtisti;

    this->artisti_expusi= new Artist[nrArtisti+1];
    for(int i=0;i<=nrArtisti;i++)
        artisti_expusi[i]=ex.artisti_expusi[i];

    this->perioada_desfasurarii_expozitiei=ex.perioada_desfasurarii_expozitiei;
}

Expozitie& Expozitie::operator= (const Expozitie& ex)
{
    if(this != &ex)
    {
        if(this->denumire!=NULL)
            delete[] this->denumire;

        this->denumire = new char[strlen(ex.denumire)+1];
        strcpy(this->denumire,ex.denumire);

        this->curent=ex.curent;

        this->nrArtisti=ex.nrArtisti;

        if(this->artisti_expusi!=NULL)
            delete[] this->artisti_expusi;

        this->artisti_expusi= new Artist[nrArtisti+1];
        for(int i=0;i<=nrArtisti;i++)
             artisti_expusi[i]=ex.artisti_expusi[i];

        this->perioada_desfasurarii_expozitiei=ex.perioada_desfasurarii_expozitiei;

    }

    return* this;
}

Expozitie::~Expozitie()
{
    if(this->denumire!=NULL)
        delete[] this->denumire;

    if(this->artisti_expusi!=NULL)
        delete[] this->artisti_expusi;

}

istream& operator>>(istream& in, Expozitie& ex)
{
    char a[100];
    in>>a;

    if(ex.denumire!=NULL)
        delete[] ex.denumire;


    in>>ex.curent>>ex.nrArtisti;

    ex.artisti_expusi = new Artist[ex.nrArtisti+1];
    for(int i=0;i<ex.nrArtisti;i++)
        in>>ex.artisti_expusi[i];

    in>>ex.perioada_desfasurarii_expozitiei;

    return in;

}

ostream& operator<< (ostream& out, const Expozitie& ex)
{
    out<<ex.denumire<<" "<<ex.curent<<" "<<ex.nrArtisti<<" "<<ex.perioada_desfasurarii_expozitiei<<endl;
    for(int i=0;i<ex.nrArtisti;i++)
        out<<ex.artisti_expusi[i]<<" ";


    return out;
}

void Expozitie::detalii_Artisti()
{
    for(int i=0;i<this->nrArtisti;i++)
        cout<<this->artisti_expusi[i].getnume()<<" "<<this->artisti_expusi[i].getprenume()<<endl;
}

class Angajat {
private:
    char* nume;
    char* prenume;
    int* shifts;
    float day;
    float salariu;

    const int ID_angajat;
    static int contorId_angajat;

public:
    Angajat();

    Angajat(const Angajat& a); //copy constructor
    Angajat& operator = (const Angajat& a); //supraincarcarea operatorului egal
    ~Angajat();


    friend ostream& operator<<(ostream&, const Angajat& p);
    friend istream& operator>>(istream&, Angajat& p);



};

int Angajat::contorId_angajat=3000;

Angajat::Angajat():ID_angajat(contorId_angajat++)
{
    this->nume=new char[strlen("Nume")+1];
    strcpy(this->nume,"Nume");

    this->prenume=new char[strlen("Prenume")+1];
    strcpy(this->prenume,"Prenume");

    this->shifts=new int[8];
    for(int i=1;i<=7;i++)
        shifts[i]=0;


    this->day=0;

    this->salariu=0;
}

Angajat::Angajat(const Angajat& p):ID_angajat(contorId_angajat++)
{

    this->nume=new char[strlen(p.nume+1)];
    strcpy(this->nume,p.nume);

    this->prenume=new char[strlen(p.prenume+1)];
    strcpy(this->prenume,p.prenume);

    //this->bool=new bool[8] dar nu are sens, am 7 zile setate
    this->shifts=p.shifts;

    this->day=p.day;

    this->salariu=p.salariu;

}

Angajat& Angajat::operator= (const Angajat& p)
{

    if(this!=&p)
    {
            if(this->nume!=NULL)
                delete[] this->nume;

            if(this->prenume!=NULL)
                delete[] this->prenume;

            if(this->shifts!=NULL)
                delete[] this->shifts;

            this->nume=new char[strlen(p.nume+1)];
            strcpy(this->nume,p.nume);

            this->prenume=new char[strlen(p.prenume+1)];
            strcpy(this->prenume,p.prenume);

            this->shifts=new int[8];
            for(int i=1;i<=7;i++)
              this->shifts[i]=p.shifts[i];

            this->day=p.day;
            this->salariu=p.salariu;

            return *this;

    }
}


 Angajat::~Angajat ()
 {
    if(this->nume!=NULL)
            delete[] this-> nume;

    if(this->prenume!=NULL)
            delete[] this-> prenume;

    if(this->shifts!=NULL)
            delete[] this->shifts;
}

istream& operator>>(istream& in, Angajat& ex)
{
    char a[100],b[100];
    in>>a>>b;

    if(ex.nume!=NULL)
        delete[] ex.nume;
    ex.nume= new char[strlen(a)+1];
    strcpy(ex.nume,a);

    if(ex.prenume!=NULL)
        delete[] ex.prenume;
    ex.prenume= new char[strlen(b)+1];
    strcpy(ex.prenume,b);

    ex.shifts=new int[8];
    for(int i=1;i<=7;i++)
        in>>ex.shifts[i];


    in>>ex.day>>ex.salariu;

    return in;

}

ostream& operator<< (ostream& out, const Angajat& ex)
{
    out<<ex.nume<<" "<<ex.prenume<<" "<<ex.day<<" "<<ex.salariu<<" ";
    for(int i=1;i<=7;i++)
        out<<ex.shifts[i]<<" ";


    return out;
}


int main()
{
   Expozitie e;
   //cin>>e;
   //e.detalii_Artisti();
   //for(int i=0;i<e.getnrArtisti();i++)
    //e.artisti_expusi[i].dupa_1900();
    //cout

   Perioada p("11/11/11","22/22/22");
   Curent_artistic c("simbolism",p);
   Artist a("alex","marius",1,c,p);
   cout<<a;

    return 0;
}
