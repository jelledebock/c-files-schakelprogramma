#define _USE_MATH_DEFINES // for C++
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;


class Figuur{
	public:
		virtual double omtrek()const = 0;
		virtual double oppervlakte()const = 0;
		virtual void schrijf_soort(ostream & out)const = 0;
		virtual void zet_afmetingen_op_nul() = 0;
		friend ostream& operator<<(ostream& out, const Figuur & f){
			f.schrijf_soort(out);
			out<<" met omtrek "<<f.omtrek()<<" en oppervlakte "<<f.oppervlakte();		
			return out;	
		}		
};

class Cirkel : public Figuur{
	private:
		double straal;
		void schrijf_soort(ostream & out)const{
			out<<"cirkel";
		}
	public:
		Cirkel(double s):straal(s){}
		double omtrek()const{
			return 2*M_PI*straal;
		}
		double oppervlakte()const{
			return M_PI*straal*straal;	
		}
		void zet_afmetingen_op_nul(){
			straal = 0;
		}
};

class Rechthoek : public Figuur{
	private:
		double lengte, breedte;	
		void schrijf_soort(ostream & out)const{
			out<<"rechthoek";
		}
	public:
		Rechthoek(double l, double b):lengte(l),breedte(b){}
		double omtrek()const{
			return 2*(lengte+breedte);
		}
		double oppervlakte()const{
			return lengte*breedte;	
		}		
		void zet_afmetingen_op_nul(){
			lengte = 0;
			breedte = 0;
		}
};

class Vierkant : public Rechthoek{
	private:		
		void schrijf_soort(ostream & out)const{
			out<<"vierkant";
		}
	public:
		Vierkant(double z):Rechthoek(z,z){}
};

Figuur* lees_figuur(ifstream &in)
{
    string type;
    double arg1,arg2;
    string line_s;

    getline(in,line_s);

    stringstream line(line_s);
    
    line>>type;    
    
    if(type=="cirkel")
    {
        line>>arg1;
        return new Cirkel(arg1);
    }
    else if(type=="rechthoek")
    {
        line>>arg1;
        line>>arg2;
        return new Rechthoek(arg1,arg2);
    }
    else if(type=="vierkant")
    {
        line>>arg1;
        return new Vierkant(arg1);        
    }
    else return NULL;

}
