#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <map>

using namespace std;

template<typename T>
void schrijf(T &);

int main(int argc, char *argv[])
{
    //set
    set<char> charset;
    charset.insert('a');
    charset.insert('b');
    schrijf(charset);
    //queue
    queue<char> charqueue;
    charqueue.push('a');
    charqueue.push('b');
    schrijf(charqueue);
    //stack
    stack<char> charstack;
    charstack.push('a');
    charstack.push('b');
    schrijf(charstack);
    //map
    map<char,string> the_map;
    the_map['a'] = "Jelle";
    the_map['b'] = "James";
    schrijf(the_map);

    return 0;
}

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
