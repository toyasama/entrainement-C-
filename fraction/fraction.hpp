#include <iostream>

class Fraction
{
    public:
        Fraction(int num,int den);
        Fraction(int num);
        Fraction();
        void affiche(std::ostream& flux) const ;
        Fraction& operator*=(Fraction const& autre);
        bool estEgal(Fraction const& autre) const;
    private:
        int m_numerateur;
        int m_denominateur;
};

bool operator==(Fraction const& a, Fraction const& b);
Fraction operator*(Fraction const& a, Fraction const& b);
std::ostream& operator<<(std::ostream& flux, Fraction const& fraction);