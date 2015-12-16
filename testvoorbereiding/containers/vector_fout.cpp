#include <iostream>
#include <vector>

using namespace std;

//even checken wat er gebeurt als we een vector toch "by value" doorgeven
//moraal van het verhaal is:
//    het gaat, maar het is niet verstandig aangezien je heel je vector 
//    kopieert wat een heel dure operatie is...


void schrijf(vector<int> my_vec)
{
    for(int i=0; i<my_vec.size(); i++)
        cout<<my_vec[i]<<endl;
}

int main()
{
    vector<int> the_vec = {1,4,3,5,7};

    schrijf(the_vec);
}

