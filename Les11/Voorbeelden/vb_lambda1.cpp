#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Adresboek {
   private:
      vector<string> adressen;	
   public:
      template<typename Func> 
      vector<string> zoekAdres(Func func){
         vector<string> resultaat;
         for(string s : adressen) {
            // functie oproepen die als argument aan zoekAdres meegegeven werd
            if (func(s)) 
               resultaat.push_back( s );
         }
         return resultaat;
      }
      
      Adresboek() {
      	adressen = {"HN@ugent.be","st@gmail.com","ab@Telenet.be",
		             "pd@ugent.be"};
      }
};

bool geen_hoofdletters(const string& s) {
   for (int i=0; i<s.size(); i++)
      if (isupper(s[i]))
         return false;
   return true;
}

int main() {
   Adresboek ab;

   vector<string> res1 = ab.zoekAdres(geen_hoofdletters);
   cout << "res1:" << endl;
   for (string s : res1)
      cout << s << endl;   
      
   vector<string> res2 = ab.zoekAdres(
      [](const string& addr){return addr.find(".be")!=string::npos;}
   );
   cout << endl << "res2:" << endl;
   for (string s : res2)
      cout << s << endl;
   
   //dit zal niet lukken
   //compileerfout: 
   //could not convert string to bool  
   /*  
   vector<string> res3 = ab.zoekAdres(
      [](const string& addr) -> string {return addr + " niet gevonden";}
   );
   */
   //zelfde fout als -> string weggelaten wordt
   
}




