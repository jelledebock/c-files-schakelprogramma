#include <iostream>
#include <fstream>
#include <string> // nodig bij inlezen van een breuk
#include <sstream> // vergelijk met Scanner(String) in Java
#include <set>
#include "breuk.cpp"

using namespace std;

void deel1(){
    Breuk a(2,5);
    Breuk b(1,-2);
    cout << a << " + " << b << " = " << (a+b) << endl;
    cout << a << " - " << b << " = " << (a-b) << endl;
    cout << a << " * " << b << " = " << (a*b) << endl;
    cout << a << " / " << b << " = " << (a/b) << endl;
    cout << a << " += " << b << " geeft als resultaat dat de breuk " << a << " verandert in ";
    a += b;
    cout << a << endl;
    cout << a << " /= " << b << " geeft als resultaat dat de breuk " << a << " verandert in ";
    a /= b;
    cout << a << endl;
    cout << a << " -= " << b << " geeft als resultaat dat de breuk " << a << " verandert in ";
    a -= b;
    cout << a << endl;
    cout << a << " *= " << b << " geeft als resultaat dat de breuk " << a << " verandert in ";
    a *= b;
    cout << a << endl;

    Breuk c(2,3);
    Breuk d(3,4);
    Breuk e(1,2);
    (c *= d) += e;
    cout << "Indien hier 1 staat, heb je de operatoren *= en += goed geschreven: " << c << endl;

}

void deel2(){
    Breuk a(13,12);
    Breuk b(2);
    Breuk c;
    cout<<endl<<"Geef c op (onder de vorm teller/noemer, dus bvb 13/12): ";
    cin >> c;
    if(a == c){
        cout << a << " is gelijk aan " << c <<endl;
    }
    else{
        cout << a << " is niet gelijk aan " << c <<endl;
    }
    cout << a <<" * "<< b <<" * "<< c <<" = "<< (a*b*c) << endl << endl;
}

//TODO handle empty objects!!
void deel3(){
    Breuk d(2,10);
    Breuk e;
    cout << d << " is stambreuk: "<<is_stambreuk(d)<<endl;
    cout << d << " + " << e << " = " << (d+e)<<endl;
    cout << endl << endl;
    cout << "Ga heel goed na wat hieronder uitgeschreven wordt. ";
    cout << "Bij de start is d="<<d<<" en e="<<e<<"."<<endl;
    cout << "De regel code ";
    cout << "’cout << d << \" * \" << e << \" = \" << d.vermenigvuldigd_met(e)<<endl;’ ";
    cout << "geeft dit als resultaat:"<<endl;
    cout << d << " * " << e << " = " << d.vermenigvuldigd_met(e)<<endl;
    cout << "Is dat wat je verwachtte?"<<endl;
}
/*
   void deel4(){
   Breuk f(3,4);
   cout << endl << "Nu berekenen we gehele veelvouden van breuken: " << endl << endl;
   for(int i=0; i<10; i++){
   cout << "het "<<i<<"-voud van "<< f << " is " << (i*f) << " = " << (f*i) << endl;
   }
   cout << endl << "Al deze breuken in een verzameling: " << endl;
   set<Breuk> verz;
   for(int i=0; i<10; i++){
   verz.insert(i*f);
   }
   for(auto x : verz){
   cout<< x << endl;
   } }
   */

int main(){
    deel1();
    deel2();
    deel3();
    //    deel4();
    return 0; }
