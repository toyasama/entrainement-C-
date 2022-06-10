#include "figure.hpp"
#include <iostream>
#define _USE_MATH_DEFINES // for C++
#include <cmath>
using namespace std;


//Classe mère

void Figure :: afficher() const
{
    cout << " Je suis une figure\n ";
}

// Class filles 
//Triangle

Triangle :: Triangle(int base, int hauteur) : m_base(base),m_hauteur(hauteur)
{

}

// int Triangle::perimetre()const
// {
//     cout << "Impossible d'afficher le périmètre, pas assez de valeurs \n";
//     return 0;
// }

int Triangle::aire()const
{
    return m_base*m_hauteur;
}

void Triangle::afficher()const
{
    cout << "Ceci est un triangle ";
}

//Carre

Carre::Carre(int cote):m_cote(cote)
{}

void Carre::afficher()const
{
    cout << "Ceci est un Carre\n";
}

int Carre::perimetre()const
{
    return m_cote*4;
}

int Carre::aire()const
{
    return pow(m_cote,2);
}

//Rectangle

Rectangle::Rectangle(int longueur, int largeur):m_longueur(longueur),m_largeur(largeur)
{}

void Rectangle::afficher()const
{
    cout << "Ceci est un Rectangle\n";
}

int Rectangle::perimetre()const
{
    return (m_longueur+m_largeur)*2;
}

int Rectangle::aire()const
{
    return (m_longueur*m_largeur)/2;
}

//Cercle

Cercle::Cercle(int rayon):m_rayon(rayon)
{}

void Cercle::afficher()const
{
    cout << "Ceci est un Cercle\n";
}

int Cercle::perimetre()const
{
    return 2*M_PI*m_rayon;
}

int Cercle::aire()const
{
    return M_PI*pow(m_rayon,2);
}