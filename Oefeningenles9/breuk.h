#include <ostream>

using namespace std;
namespace Breuk_namespace
{
    class Breuk
    {
        public:
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
            int getTeller() const;
            int getNoemer() const;

            friend std::ostream& operator<<(std::ostream &out, const Breuk& breuk);

        private:
            int teller = 0;
            int noemer = 0;
    };

}
