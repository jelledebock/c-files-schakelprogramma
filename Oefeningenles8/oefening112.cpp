#include <iostream>
#include <set>
#include <queue>

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
    
    //map
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
queue<T> & operator<<(ostream& out, const queue<T> &queue)
{
    std::queue<T> tmp = queue;

    if(!tmp.empty())
    {
        cout<<"["<<tmp.pop();
        
        while(!tmp.empty())
        {
            cout<<"|"<<tmp.pop();
        }
        cout<<"]";
    }
}
