#include <ostream>

using namespace std;
class Breuk
{
    public:
        Breuk();
        Breuk (int teller, int noemer);
        Breuk (int teller);
        Breuk operator+(Breuk& breuk);
        Breuk operator-(Breuk& breuk);
        Breuk operator*(Breuk& breuk);
        Breuk operator/(Breuk& breuk);
        Breuk& operator+=(Breuk& breuk);
        Breuk& operator/=(Breuk& breuk);
        Breuk& operator-=(Breuk& breuk);
        Breuk& operator*=(Breuk& breuk);
        Breuk& vermenigvuldigd_met(const Breuk& breuk);

        bool operator==(const Breuk& breuk);
        int getTeller() const;
        int getNoemer() const;

        friend std::ostream& operator<<(std::ostream &out, const Breuk& breuk);
        friend std::istream& operator>>(std::istream &in, Breuk& breuk);
    private:
        int teller = 0;
        int noemer = 0;
};

