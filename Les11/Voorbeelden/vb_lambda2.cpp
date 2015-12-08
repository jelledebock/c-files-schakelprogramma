#include <string>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

class Adresboek {
   private:
      vector<string> adressen;	
   public:
      vector<string> zoekAdres(function<bool (const string&)> func){
         vector<string> resultaat;
         for(string s : adressen) {
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

bool geen_hoofdletters(const string & s) {
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
   
   //dit zal nog steeds niet lukken
   //compileerfout: 
   //no matching function for call to zoekAdres  
   /* 
   vector<string> res3 = ab.zoekAdres(
      [](const string& addr) -> string {return addr + " niet gevonden";}
   );
   */
}




