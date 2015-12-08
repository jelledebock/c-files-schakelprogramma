#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    bool even=false;
    bool open_success;
    bool reading_ok=true;

    if(argc>1)
    {
        vector<ifstream> input(argc-1);

        //Open files
        for(int i = 1; i<argc; i++)
        {
            input[i-1].open(argv[i],ios::in);        
            open_success=input[i-1].is_open();
        }

        //Check if all files were opened
        if(open_success)
        {
            //Counter to get hold of the "line number"
            int linenum = 1;
            string line;
            //Open the outputfile
            ofstream output("mix.txt",ios::app);
            //Read from even files
            while(reading_ok)
            {
                //if even line, read even indexes, skip others
                //if odd line, read odd indexes, skip others
                int i = 0; //check even or odd
                bool even = (linenum%2==0);
                while(i<input.size() && reading_ok)
                {
                    line="";
                    reading_ok = getline(input[i],line);
                    if((even&&i%2==0)||(!even&&i%2==1))
                        output<<line;
                    i++;
                }
                linenum++;
            }

            //Close all files
            output.close();

            for(int i=0;i<argc-1;i++)
            {
                input[i].close();
            }
            cout<<"Successfully mixed the files!"<<endl;
        }
        else
        {
            cout<<"Opening the files failed!"<<endl;
        }
    }
    else{
        cout<<"Requires filenames!"<<endl;
    }
}
