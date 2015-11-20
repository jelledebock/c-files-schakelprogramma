#include <iostream>
#include <vector>
#include "containers.h"

using namespace std;

template<typename T>
void oef1()
{
	std::vector<T> v{1,4};
	v.push_back({1,3});
	schrijf(v);
}

int main(int argc, char *argv[])
{
	oef1();
	return 0;
}



