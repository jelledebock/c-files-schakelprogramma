// opmerking: ga ook eens na wat er gebeurt als de
// move-constructor en -operator in commentaar staan

#include <iostream>
#include <vector>
using namespace std;

class A {
   public:
   	  A() : grA(0),tabA(0) {}
      A(const vector<int> &v, int i=0, int *p=0);
      A(const A &a);
      A(A &&a);
      ~A() {
      	 cout << "destructor A" << endl;
	     delete[] tabA;
	  }
      A& operator=(const A&);
      A& operator=(A&&);
      A operator*(int f) const;
      void print() const;
      
   private:
      int grA;
      int *tabA;
      vector<int> vA;
};

A::A(const vector<int> &v,int i, int *p) : vA(v),grA(i),tabA(0) {
   if (grA > 0) {
   	   tabA = new int[grA];
       for(int i=0 ; i<grA ; i++)
          tabA[i] = p[i];
   }
}

A::A(const A &a) : vA(a.vA),grA(a.grA),tabA(0) {
   cout << "copy constructor" << endl;
   if (grA > 0) {
   	   tabA = new int[grA];
       for(int i=0 ; i<grA ; i++)
          tabA[i] = a.tabA[i];
   }
}


A::A(A &&a) : vA(move(a.vA)),grA(a.grA),tabA(a.tabA) {
   cout << "move constructor" << endl;
   a.grA = 0;
   a.tabA = 0;
}


A& A::operator=(const A& a) {
   cout << "= operator" << endl;
   if(this != &a) {
   	  vA = a.vA;
      delete[] tabA;
      grA = a.grA;
      if (grA > 0) {
   	     tabA = new int[grA];
         for(int i=0 ; i<grA ; i++){
            tabA[i] = a.tabA[i];
         }
      }
   }
   return *this;
}


A& A::operator=(A&& a) {
   cout << "move operator" << endl;
   if(this != &a) {
   	  vA = move(a.vA);
      delete[] tabA;
      grA = a.grA;
      tabA = a.tabA;
      a.grA = 0;
      a.tabA = 0;
   }
   return *this;
}


A A::operator*(int f) const {
   A res;
   res.grA = grA;
   if (grA > 0) {
   	   res.tabA = new int[grA];
       for(int i=0 ; i<grA ; i++)
          res.tabA[i] = tabA[i] * f;   	
   }
   res.vA.reserve(vA.size());
   for (int i=0; i<vA.size(); i++)
      res.vA.push_back(vA[i] *f);
   return res;
}

void A::print() const {
   for (int i=0 ; i<grA ; i++)
      cout << tabA[i] << "  ";
   cout << endl;
   for (int i: vA)
      cout << i << "  ";
   cout << endl;
}

int main (){
   A a3, a5, a6;
   int pA[4] = {12, 7, 16, 11};
   vector<int> v = {-3, -9, -15};
   A a1(v, 4, pA);
   cout << "a1.print();" << endl;
   a1.print();
 
   cout << endl << "A a2(a1);" << endl;  
   A a2(a1);
   cout << "a1.print();" << endl;
   a1.print(); 
   cout << "a2.print();" << endl;
   a2.print(); 
   
   cout << endl << "a3 = a1;" << endl;
   a3 = a1;
   cout << "a1.print();" << endl;
   a1.print(); 
   cout << "a3.print();" << endl;
   a3.print();      

   cout << endl << "A a4(move(a1));" << endl;
   A a4(move(a1));
   cout << "a1.print();" << endl;
   a1.print(); 
   cout << "a4.print();" << endl;
   a4.print(); 

   cout << endl << "a5 = move(a2);" << endl;
   a5 = move(a2);
   cout << "a2.print();" << endl;
   a2.print(); 
   cout << "a5.print();" << endl;
   a5.print(); 
   
   cout << endl << "a6 = a3*2;" << endl;
   a6 = a3*2;
   cout << "a3.print();" << endl;
   a3.print(); 
   cout << "a6.print();" << endl;
   a6.print(); 
          
   return 0;
}
