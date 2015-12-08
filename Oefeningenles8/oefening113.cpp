#include <iostream>
#include <vector>
#include <queue>
#include "containers.h"
#define AANTAL 5
using namespace std;

template<typename T> void oef1()
{

    std::vector<T> v(3,1);
    v.push_back(1);
    v.push_back(3);
    schrijf(v);
}

void oef2()
{
    queue<string> my_queue;
    my_queue.push("Een");
    my_queue.push("Twee");
    my_queue.push("Drie");
    schrijf(my_queue);
}

void oef3()
{
    vector<string> vector_array[AANTAL];
    vector_array[1].push_back("aap");
    vector_array[1].push_back("noot");
    vector_array[1].push_back("mies");
    schrijf<string>(vector_array,AANTAL);
}

int main(int argc, char *argv[])
{
    oef1<int>();
    oef2();
    oef3();
    return 0;
}



