#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Persoon{
    string voornaam;
    string naam;
    int leeftijd;
    Persoon(const string & v, const string & n, int l){
        voornaam = v; naam = n; leeftijd = l;
    }
};
ostream& operator<<(ostream & out, const Persoon & p){
    out<<p.naam <<" "<<p.voornaam<<" ("<<p.leeftijd<<")";
    return out;
}
class Groep : public vector<Persoon>{
    public:

        template <class Func>
            Persoon geef_extremum(Func func){
                /*niet met auto-lus: index aanpassen is zuiniger*/
                int  index_beste = 0;
                for(int i=1; i<size(); i++){
                    if(func(operator[](i),operator[](index_beste))){
                        index_beste = i;
                    } }
                return operator[](index_beste);
            }
};
int main(){
    Groep gr;
    gr.push_back(Persoon("Ann","Nelissen",12));
    gr.push_back(Persoon("Bert","Mertens",22));
    gr.push_back(Persoon("Celle","Lauwers",55));
    cout<<"Eerste qua naam:     " << gr.geef_extremum([](Persoon &pers, Persoon &beste){return pers.naam<beste.naam;})<<endl;
    cout<<"Eerste qua voornaam: " << gr.geef_extremum([](Persoon &pers, Persoon &beste){return pers.voornaam<beste.voornaam;})<<endl;
    cout<<"Jongste:             " << gr.geef_extremum([](Persoon &pers, Persoon &beste){return pers.leeftijd<beste.leeftijd;})<<endl;
    cout<<"Oudste:              " << gr.geef_extremum([](Persoon &pers, Persoon &beste){return pers.leeftijd>beste.leeftijd;})<<endl;
    return 0;
}

