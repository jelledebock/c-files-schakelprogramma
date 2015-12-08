#include <string>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

void overloop(const vector<int> &v, function<void (int)> f) {
	for (int g : v)
	   f(g);
}

int main() {
    int divisor = 3;
    vector<int> numbers { 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
    
    //onderstaande lukt niet!
    //compileerfout: divisor is not captured
    /*
    overloop(numbers, [] (int y) {
        if (y % divisor == 0)
            cout << y << endl;
    });
    */
    
    overloop(numbers, [divisor] (int y) {
        if (y % divisor == 0)
            cout << y << endl;
    });
    
    divisor = 2;
    overloop(numbers, [=] (int y) {
        if (y % divisor == 0)
            cout << y << endl;
    });
    
    int sum = 0;
    overloop(numbers, [divisor, &sum] (int y) {
        if (y % divisor == 0) {
           cout << y << endl;
           sum += y;
        }
    });   
	cout << sum << endl;
	//analoog aan [divisor, &sum] is
	//[&, divisor] en [=, &sum]
}



