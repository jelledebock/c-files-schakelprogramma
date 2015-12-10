#include "figuren.h"
#include <memory>

class Blokkendoos : vector<unique_ptr<Figuur>>{
    private:
        unique_ptr<Figuur> max_opp;
        void schrijf(ostream&)const;
    public:
        Blokkendoos();
        Blokkendoos(const string & bestandsnaam);
        unique_ptr<Figuur> geef_figuur_met_grootste_oppervlakte();
        void push_back(unique_ptr<Figuur> figuur);
        friend ostream& operator<<(ostream& out, const Blokkendoos& l){
            l.schrijf(out);
            return out; }
};

int main(){
    Blokkendoos<Figuur> blokkendoos("figuren.txt");
    cout<<endl<<"ALLE FIGUREN: ";
    cout<<blokkendoos<<endl;
    cout<<endl<<"DE 3 GROOTSTE, van groot naar klein: "<<endl;
    for(int i=0; i<3; i++){
        cout<<"figuur met grootste opp:    "<<*blokkendoos.geef_figuur_met_grootste_oppervlakte()<<endl;
    }
    cout<<endl<<"DE NIEUWE BLOKKENDOOS BEVAT DEZE 3 NIET MEER: ";
    cout<<blokkendoos<<endl;
    return 0; 
}
