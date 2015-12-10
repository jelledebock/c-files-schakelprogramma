#include <iostream>
#include <functional>
#include <vector>
#include <fstream>

using namespace std;

ostream& operator<<(ostream& out, const vector<int> &the_vec)
{
    for(int element : the_vec)
    {
        out<<element;
        out<<"\t";
    }
    return out;
}

void vul_vector(vector<int> &a, vector<int> &b, vector<int> &c, function <int (int a, int b) > mathf)
{
    for(int i=0 ; i<a.size(); i++)
    {
        c[i]=mathf(a[i],b[i]);
    }
}

int main(){
    vector<int> a({0,1,2,3,4,5,6,7,8,9});
    vector<int> b({0,10,20,30,40,50,60,70,80,90});
    vector<int> c(10);

    vul_vector(a,b,c,[](int a, int b)->int{ return a+b;});
    cout<<"SOM:      "<<c<<endl;
    vul_vector(a,b,c,[](int a, int b)->int{ return a*b;});
    cout<<"PRODUCT:  "<<c<<endl;
    vul_vector(a,b,c,[](int a, int b)->int{ return a-b;});
    cout<<"VERSCHIL: "<<c<<endl;
    return 0; 
}




