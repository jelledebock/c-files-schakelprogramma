#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main () {
  vector<set<int>> v;
  for (int i=1; i<=3; i++) {
  	set<int> s1, s2;
	for (int j=0; j<5; j++)
  	   s1.insert(i*j);
  	v.push_back(s1);
  	s1.insert(i*5);
  	s2 = s1;
  	s1.insert(i*6);
  	cout << "s1: ";
  	for (int j: s1)
  	   cout << j << " ";
  	cout << endl;
  	cout << "s2: ";
  	for (int j: s2)
  	   cout << j << " ";
  	cout << endl;
  }
  
  cout << "v:" << endl;
  for (int i=0; i<3; i++) {
     for (int j:v[i])
        cout << j << " ";
  	 cout << endl;
  }
  return 0;
}
