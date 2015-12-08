#include <iostream>
#include <memory>
using namespace std;

void write_pointer(shared_ptr<int> p) {
   if (p) 
     cout << *p << endl; 
   else 
     cout << "empty\n";
}
int main () {
  shared_ptr<int> p1(new int(101));
  shared_ptr<int> p2; 
  
  cout << "p1: ";
  write_pointer(p1); 
  cout << "p2: ";
  write_pointer(p2); 
  
  p2 = p1;
                        
  cout << "p1: ";
  write_pointer(p1); 
  cout << "p2: ";
  write_pointer(p2); 

  (*p2)++;
  cout << "p1: ";
  write_pointer(p1);
  cout << "p2: ";
  write_pointer(p2);
  
  p2.reset();
  cout << "p1: ";
  write_pointer(p1);
  cout << "p2: ";
  write_pointer(p2); 
  
  return 0;
}
