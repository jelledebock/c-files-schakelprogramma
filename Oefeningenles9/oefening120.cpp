#include<vector>

template<typename T>
class Schijf
{
	public:
		Schijf();
		~Schijf();
		Schijf(const Schijf &schijf);
	private:
		T* a;
};

template<typename T>
class Doos
{
	public:
		Doos();
		~Doos();
		Doos(const Doos &doos);
	private:
		std::vector<T> b(4);
		T* c;
		T* d[3];

};

template<typename T>
Schijf::Schijf()
{
	a = NULL;
}

Schijf::~Schijf()
{
	if(a)
		delete a;
}

Schijf::Schijf(const Schijf &schijf)
{
	a = schijf;
}
