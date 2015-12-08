#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    bool even=false;
    bool open_success;
    bool reading_ok=false;

    if(argc>1)
    {
        vector<ifstream> input(argc-1);

        //Open files
        for(int i = 1; i<argc-1; i++)
        {
            input[i].open(argv[i],ios::in);        
            open_success=input[i].is_open();
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
                int i = 0+linenum%2; //check even or odd
                while(i<argc-1 && reading_ok)
                {
                    line="";
                    getline(input[i],line);
                    output<<line;
                    reading_ok = input[i].good();
                    i+=2;
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
