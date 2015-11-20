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
    cout<<"\n";
}

template<typename T>
set<T> & operator<<(ostream& out, const set<T> &set)
{
    typename set<T>::const_iterator it;
    
    it = set.begin();

    if(set.size())
    {
        cout<<"{"<<*it;
        it++;

        while(it!=set.end())
        {
            cout<<","<<*it;
            it++;
        }
        cout<<"}";
    }
}

template<typename T>
queue<T> & operator<<(ostream& out,const queue<T> &the_queue)
{
    queue<T> tmp(the_queue);

    if(!tmp.empty())
    {
        cout<<"["<<tmp.front();
        tmp.pop();

        while(!tmp.empty())
        {
            cout<<"|"<<tmp.front();
	    tmp.pop();
        }
        cout<<"]";
    }
}

template<typename T>
stack<T> & operator<<(ostream& out, const stack<T> &the_stack)
{ 
	stack<T> tmp(the_stack);

	while(!tmp.empty())
	{
		cout<<"\n";
		cout<<tmp.top();
		tmp.pop();
	}
	cout<<"\n";
}

template<typename KEY, typename VALUE>
map<KEY,VALUE> & operator<<(ostream& out, const map<KEY,VALUE> &the_map)
{
	typename map<KEY,VALUE>::const_iterator it;

	for(it=the_map.begin();it!=the_map.end();++it)
	{
		cout<<it->first<<"->"<<it->second<<"\n";
	}
}

template<typename T>
ostream & operator<<(ostream& out,vector<T> &v)
{
    schrijf(v);
}

template<typename T>
void schrijf(vector<T> &v)
{
    if(v.size()>0)
    {
        cout<<"["<<v[0];
        for (int i = 1; i < v.size(); ++i) {
            cout <<" | "<< v[i] << " ";
        }
        cout<<"]";
    }
}


#endif
