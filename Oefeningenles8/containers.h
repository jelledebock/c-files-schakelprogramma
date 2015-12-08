#ifndef containers
#define containers

#include <set>
#include <queue>
#include <stack>
#include <map>
#include <vector>

using namespace std;


    template<typename T>
void schrijf(T &structuur)
{
    cout<<structuur;
    cout<<endl;
}

    template<typename T>
ostream & operator<<(ostream& out, const set<T> &set)
{
    typename set<T>::const_iterator it;

    it = set.begin();

    if(set.size())
    {
        out<<"{"<<*it;
        it++;

        while(it!=set.end())
        {
            out<<","<<*it;
            it++;
        }
        cout<<"}";
    }
}

    template<typename T>
ostream& operator<<(ostream& out,const queue<T> &the_queue)
{
    queue<T> tmp(the_queue);

    if(!tmp.empty())
    {
        out<<"["<<tmp.front();
        tmp.pop();

        while(!tmp.empty())
        {
            out<<"|"<<tmp.front();
            tmp.pop();
        }
        out<<"]";
    }
}

    template<typename T>
ostream& operator<<(ostream& out, const vector<T> &the_vec)
{
    int i=0; 
    if(the_vec.size()>0)
    {
        out<<"["<<the_vec[i];
        while(i<the_vec.size())
        {
            out<<"|"<<the_vec[i];

            i++;
        }
        out<<"]";
    }
}
    template<typename T>
ostream & operator<<(ostream& out, const stack<T> &the_stack)
{ 
    stack<T> tmp(the_stack);

    while(!tmp.empty())
    {
        out<<"\n";
        out<<tmp.top();
        tmp.pop();
    }
    cout<<"\n";
}

    template<typename KEY, typename VALUE>
ostream & operator<<(ostream& out, const map<KEY,VALUE> &the_map)
{
    typename map<KEY,VALUE>::const_iterator it;

    for(it=the_map.begin();it!=the_map.end();++it)
    {
        out<<it->first<<"->"<<it->second<<"\n";
    }
}
    template<typename T>
void schrijf(vector<T> &v)
{
    if(v.size()>0)
    {
        cout<<"["<<v[0];
        for (int i = 1; i < v.size(); ++i) 
        {
            cout <<" | "<< v[i] << " ";
        }
        cout<<"]";
    }
}

    template<typename T>
void schrijf(vector<T> v[], int aantal)
{
    cout<<"{";
    for(int i=0;i<aantal;i++)
    {
        cout<<"{";
        cout<<v[i];
        cout<<"}";
    }
    cout<<"}";
}    
#endif
