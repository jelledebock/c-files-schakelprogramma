#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Schijf
{
    public:
        Schijf();
        ~Schijf();
        Schijf(const Schijf &schijf);
    private:
        Doos *a;
};

template<typename T>
class Doos
{
    public:
        Doos();
        Doos(vector<T> vec);
        Doos(Doos* c_);
        Doos(Schijf **d_);      
        ~Doos();
        Doos(const Doos &doos);
    private:
        vector<T*> b;
        T* c;
        T* **d;

};


template<typename T>
Doos<T>::Doos()
{
    b = vector<T*>(4); 
    c = NULL;
    d = new T[3];
}

template<typename T>
Doos<T>::Doos(vector<T> vec)
{
    b = vec;
}

template<typename T>
Doos<T>::Doos(Doos* c_)
{
    c = c_;
}

template<typename T>
Doos<T>::Doos(Schijf* **d_)
{
    d = d_;
}

template<typename T>
Doos<T>::~Doos()
{
   for(int i=0;i<3;i++)
   {
        delete d[i];
   }
   delete c;
   delete a;
}

template<typename T>
Schijf<T>::Schijf()
{
    a = NULL;
}

template<typename T>
Schijf<T>::~Schijf()
{
    if(a)
        delete a;
}

template<typename T>
Schijf<T>::Schijf(const Schijf &schijf) : a(schijf.a){}

template<typename T>
Doos<T>::Doos(const Doos &doos) : b(doos.b), c(doos.c), d(doos.c){}


int main()
{
    Schijf<int> startschijf();
    Doos<int> doos1();
    Doos<int> doos2(&doos1);
    Schijf<int> ** schijfbox1 = new Schijf<int>*[3];
    schijfbox1[0]=NULL;
    schijfbox1[1]=NULL;
    schijfbox1[2]=NULL;
    Schijf<int> ** schijfbox2 = new Schijf<int>*[3];
    schijfbox2[0]=new Schijf<int>();
    schijfbox2[1]=new Schijf<int>();
    schijfbox2[2]=NULL;
    Schijf<int> ** schijfbox3 = new Schijf<int>*[3];
    schijfbox3[0]=new Schijf<int>();
    schijfbox3[1]=new Schijf<int>();
    schijfbox3[2]=new Schijf<int>();
}



