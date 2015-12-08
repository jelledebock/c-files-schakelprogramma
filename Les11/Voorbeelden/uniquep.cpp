#include <iostream>
#include <memory>
using namespace std;

void write_pointer(const unique_ptr<int> &p) {
   if (p) 
     cout << *p << endl; 
   else 
     cout << "empty\n";
}
int main () {
  unique_ptr<int> p1(new int(101));
  unique_ptr<int> p2; 
  
  cout << "p1: ";
  write_pointer(p1); 
  cout << "p2: ";
  write_pointer(p2); 
  
  // FOUT: 
  // p2 = p1;
  
  p2 = move(p1);                      
  cout << "p1: ";
  write_pointer(p1); 
  cout << "p2: ";
  write_pointer(p2); 

  (*p2)++;
  cout << "p2: ";
  write_pointer(p2);
  
  p2.reset();
  cout << "p2: ";
  write_pointer(p2); 
  
  return 0;
}
