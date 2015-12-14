// kerstcadeautje...
// aan te vullen waar gevraagd.

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const char AFSLUITTEKEN = '*';
const char SPATIE = '$'; 

class Weefpatroon;


class Knoop{
    friend class Weefpatroon;		
    int x,y;
    char kar; 
    Knoop * links;
    Knoop * rechts;
    Knoop * boven;
    Knoop * onder;	
    public:
    Knoop(int _x, int _y):links(0),rechts(0),boven(0),onder(0),x(_x),y(_y){}		
};


class Weefpatroon{
    vector<vector<Knoop*> > m;
    int aantal_rijen;
    int aantal_kolommen;
    vector<Knoop*> hoofdrij;
    vector<Knoop*> hoofdkolom;

    void legVerbindingen();
    void initialiseer_hoofdrij();
    void initialiseer_hoofdkolom();



    public:
    Weefpatroon(int aantal_r, int aantal_k);
    Weefpatroon(int aantal_r, int aantal_k, const string & bestandsnaam);	 

    void schrijf_via_basis(ostream & out)const;  // TO DO

    void schrijf_horizontaal()const;
    void schrijf_verticaal()const;
    void verwijder(int x, int y);  // TO DO
    void voeg_toe(int x, int y);   // TO DO
};


    Weefpatroon::Weefpatroon(int aantal_r, int aantal_k)
:aantal_rijen(aantal_r),aantal_kolommen(aantal_k),m(aantal_r),
    hoofdrij(aantal_k),hoofdkolom(aantal_r)
{
    for(int i=0; i<aantal_r; i++){
        m[i] = vector<Knoop*>(aantal_k,0);
        for(int j=0; j<aantal_k; j++){
            m[i][j] = new Knoop(i,j);
        }
    }
    legVerbindingen();
    initialiseer_hoofdrij();
    initialiseer_hoofdkolom();
}

Weefpatroon::Weefpatroon(int aantal_r, int aantal_k, const string & bestandsnaam):Weefpatroon(aantal_r,aantal_k){
    ifstream input(bestandsnaam);
    char karakter;
    int index=0;
    input>>karakter;
    while(!input.fail()){
        m[index/aantal_k][index%aantal_k]->kar = karakter;
        index++;
        input>>karakter;	
    }
    input.close();	
}

// Dit kan in een testfase van pas komen.
// Hier worden ALLE knopen uitgeschreven,
// ook diegene die niet meer in het weefpatroon zitten.
// Wat je hier kan aanvullen:
//   vervang de voorwaarde in de if, zodat knopen die
//   NIET meer in het weefpatroon zitten,
//   tussen haakjes komen te staan. 	 
void Weefpatroon::schrijf_via_basis(ostream & out)const{
    for(int i=0; i<aantal_rijen; i++){
        for(int j=0; j<aantal_kolommen; j++){
            if((m[i][j]->links && m[i][j]->links->rechts==m[i][j])){
                out<<" "<<m[i][j]->kar<<" ";
            }
            else{
                out<<"("<<m[i][j]->kar<<")";
            }
        }
        out<<endl;
    }		
}

void Weefpatroon::legVerbindingen(){
    for(int i=0; i<aantal_rijen; i++){
        for(int j=0; j<aantal_kolommen; j++){
            m[i][j]->boven = m[(i+aantal_rijen-1)%aantal_rijen][j];
            m[i][j]->onder = m[(i+1)%aantal_rijen][j];
            m[i][j]->links = m[i][(j+aantal_kolommen-1)%aantal_kolommen];
            m[i][j]->rechts = m[i][(j+1)%aantal_kolommen];				
        }	
    }
}

void Weefpatroon::initialiseer_hoofdrij(){
    for(int i=0; i<aantal_kolommen; i++){
        hoofdrij[i] = m[0][i];	
    }
}	

void Weefpatroon::initialiseer_hoofdkolom(){	
    for(int i=0; i<aantal_rijen; i++){
        hoofdkolom[i] = m[i][0];	
    }
}

// zal enkel uitschrijven als een bepaalde rij een AFSLUITTEKEN (*) bevat
// en vervangt SPATIE ($) door echte spatie
void Weefpatroon::schrijf_horizontaal()const{
    for(int i=0; i<hoofdkolom.size(); i++){
        Knoop* loper = hoofdkolom[i];
        loper = loper->rechts;
        while(loper->kar != AFSLUITTEKEN && loper != hoofdkolom[i]){
            loper = loper->rechts;
        }
        if(loper->kar==AFSLUITTEKEN){			
            loper = loper->rechts;
            while(loper->kar != AFSLUITTEKEN){
                if(loper->kar == SPATIE){
                    cout<<" ";
                }
                else{
                    cout<<loper->kar;
                }
                loper = loper->rechts;
            }
        }
        cout<<" ";
    }
}

// zal enkel uitschrijven als een bepaalde kolom een AFSLUITTEKEN (*) bevat
// en vervangt SPATIE ($) door echte spatie
void Weefpatroon::schrijf_verticaal()const{
    for(int i=0; i<hoofdrij.size(); i++){
        Knoop* loper = hoofdrij[i];
        loper = loper->onder;
        while(loper->kar != AFSLUITTEKEN && loper != hoofdrij[i]){
            loper = loper->onder;
        }
        if(loper->kar==AFSLUITTEKEN){			
            loper = loper->onder;
            while(loper->kar != AFSLUITTEKEN){
                if(loper->kar == SPATIE){
                    cout<<" ";
                }
                else{
                    cout<<loper->kar;
                }
                loper = loper->onder;
            }
        }
        cout<<" ";
    }
}


// zorg dat de knoop op positie x,y
// (opnieuw) voorkomt in het weefpatroon.
// Dus zijn buren moeten naar hem verwijzen.
void Weefpatroon::voeg_toe(int x, int y){	
    Knoop *add = m[x][y];
    //refix linker en rechter buur
    add->links->rechts = add;
    add->rechts->links = add;
    //refix boven en onder buur
    add->boven->onder = add;
    add->onder->boven = add;

    if(add->links && add->links == hoofdrij[y])
        hoofdrij[y]=add;
    if(add->boven == hoofdkolom[x])
        hoofdkolom[x]=add;
}


// zorg dat de knoop op positie x,y
// niet (meer) voorkomt in het weefpatroon.
// Let op: indien hoofdkolom[x] en/of hoofdrij[y]
// naar deze knoop verwijst, moet die verwijzing naar de buurman
// verlegd worden! 
void Weefpatroon::verwijder(int x, int y){
    Knoop *tmp=m[x][y];
    tmp->links->rechts = tmp->rechts;
    tmp->rechts->links = tmp->links;

    Knoop *boven = tmp->boven;
    tmp->onder->boven = boven;
    tmp->boven->onder = tmp->onder;

    if(hoofdkolom[x] && hoofdkolom[x]==tmp)
        hoofdkolom[x]=tmp->rechts;
    if(hoofdrij[y] && hoofdrij[y]==tmp)
        hoofdrij[y]=tmp->onder;
}

void verwijder(Weefpatroon & dl, const string & bestandsnaam){
    ifstream input(bestandsnaam);
    int i,j;
    input>>i>>j;
    while(!input.eof()){
        dl.verwijder(i,j);	
        input>>i>>j;
    }
    input.close();
}

void voeg_toe(Weefpatroon & dl, const string & bestandsnaam){
    ifstream input(bestandsnaam);
    int i,j;
    input>>i>>j;
    while(!input.eof()){
        dl.voeg_toe(i,j);	
        input>>i>>j;
    }
    input.close();
}

int main(){

    Weefpatroon weefpatroon(24,24,"kerstcadeautje.txt");

    cout<<endl<<"Eerste cadeautje: "<<endl;
    verwijder(weefpatroon,"indices_weg_voor_horizontaal_verhaal.txt");	
    weefpatroon.schrijf_via_basis(cout); // kleine test; zie boven voor idee om 
    // dit uitschrijven nuttig te maken 
    cout<<endl<<endl;	                                     
    weefpatroon.schrijf_horizontaal();   // het echte cadeau

    voeg_toe(weefpatroon,"indices_weg_voor_horizontaal_verhaal.txt");

    cout<<endl<<endl<<"Tweede cadeautje: "<<endl;
    verwijder(weefpatroon,"indices_weg_voor_verticaal_verhaal.txt");	
    weefpatroon.schrijf_via_basis(cout); // kleine test; zie boven voor idee om 
    // dit uitschrijven nuttig te maken 
    cout<<endl<<endl;	
    weefpatroon.schrijf_verticaal();

    return 0;
}


















