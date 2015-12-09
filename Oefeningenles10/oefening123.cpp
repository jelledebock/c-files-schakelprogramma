#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

struct Persoon{
    int leeftijd; // moet geheel en positief zijn
    string naam; // kan spaties bevatten
    string adres; // mag nummer bij in zitten
    int postcode; // moet tussen 1000 en 9999 liggen
};

void open_bestand(const char * path, ifstream &infile)
{
    infile.exceptions(ifstream::failbit | ifstream::badbit);
    try
    {
        infile.open(path);
    }catch(ifstream::failure e)
    {
        cerr<<"Error opening file";
    }
}

void sluit_bestand(ifstream &infile)
{
    infile.close();
}

void lees_positief_getal(int &x, ifstream &infile)
{
    int getal;
    if(infile>>getal && getal>0)
    {
        x = getal;
    }
    else
    {
        throw "You should enter a positive integer";
    }

}

void lees_getal_vier_cijfers(int &x, ifstream &infile)
{
    int y;
    try
    {
        lees_positief_getal(y,infile);
        if(y>=1000 && y<=9999)
        {
            x=y;
        }
        else throw "Postal code should be between 1000 and 9999, using 0 instead";
    }
    catch(const char *e)
    {
        cerr<<e<<", wrong 4 digit number read"<<endl;
        x=0;
    }
}

void lees_regel(string &regel, ifstream &infile)
{
    getline(infile,regel);
    if(infile.eof()) 
    {
        std::cerr << "Eof " << "\n"
            << "Error bits are: "
            << "\nfailbit: " << infile.fail() 
            << "\neofbit: " << infile.eof()
            << "\nbadbit: " << infile.bad() << std::endl;
    }
}

void lees(struct Persoon &persoon, ifstream &infile)
{
    try
    {
        lees_positief_getal(persoon.leeftijd,infile);
        lees_regel(persoon.naam,infile);
        lees_regel(persoon.adres,infile);
        lees_getal_vier_cijfers(persoon.postcode,infile);
        string buffer;
        lees_regel(buffer,infile);
    }
    catch(const char * &e)
    {
        cerr<<"Reading the age went wrong!"<<endl;
        string buffer;
        int getal;

        lees_regel(buffer,infile);
        lees_regel(buffer,infile);
        lees_getal_vier_cijfers(getal,infile);
        lees_regel(buffer,infile);

        persoon.leeftijd=-1;
    }
}

void schrijf(vector<Persoon> &personen)
{
    for(int i=0;i<personen.size();i++)
    {
        struct Persoon persoon = personen[i];
        cout<<persoon.naam<<" is "<<persoon.leeftijd<<" jaar oud en woont in "<<persoon.adres<<" (postcode "<<persoon.postcode<<")"<<endl;
    }
}
int main(int argc, char *argv[])
{
    vector<struct Persoon> personen;
    if(argc==2)
    {
        ifstream myfile;
        open_bestand(argv[1],myfile);
        while(myfile)
        {
            struct Persoon helper;
            try{
                lees(helper,myfile);
            }
            catch(const char * e)
            {
                cerr<<"Error: "<<e<<endl;
            }
            if(helper.leeftijd!=-1)
            {
                personen.push_back(helper);
                cout<<"Alweer een persoon in the books"<<endl;
            }
        }
        schrijf(personen);
        sluit_bestand(myfile);
        return 0;
    }
    else
    {
        throw "Enter a file with data!";
        return -1;
    }

}
