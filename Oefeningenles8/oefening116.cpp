#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

void readlinenums(vector<int> &vec, char * path)
{
    ifstream input(path);
    int linenum;

    if(input.is_open())
    {
        input >> linenum;
        while(!input.eof())
        {
            vec.push_back(linenum);
            input >> linenum;
        }
    }
    else
    {
        cout<<"Error opening the linenum file"<<endl;
    }
}

map<int,string> readfile(const vector<int> &linenums, char * path)
{
    map<int, string> lines;
    string linebuffer;
    int linenum=1;
    ifstream input(path);

    if(input.is_open())
    {
        getline(input,linebuffer);

        while(!input.eof())
        {
            if(find(linenums.begin(),linenums.end(),linenum)!=linenums.end())
                lines[linenum] = linebuffer;
        
            linenum++;
            getline(input,linebuffer);
        }
    }
    else
    {
        cout<<"Error opening the textfile"<<endl;
    }
    return lines;
}

void printstory(const vector<int> &linenums, const map<int,string> &story) 
{
    for(int i=0;i<linenums.size();i++)
    {
        cout<<story.find(linenums[i])->second<<endl;
    }
}
int main(int argc, char * argv[])
{
    if(argc==3)
    {
        vector<int> linenums;
        
        cout<<"Reading linenumber..."<<endl;
        readlinenums(linenums, argv[1]);
        cout<<"Reading text..."<<endl;
        map<int,string> story = readfile(linenums, argv[2]);
        cout<<"Printing text..."<<endl;
        printstory(linenums,story);
    }
    else
    {
        cout<<"Specify the file with linenums and a file with text"<<endl;
    }
}


