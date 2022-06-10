#include "figure.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<Figure*> figures;
    figures.push_back(new Carre(5));
    figures.push_back(new Cercle(1));
    figures.push_back(new Rectangle(5,2));

    for (auto figure : figures)
    {
        figure->afficher();
        cout<< "Perimetre : " << figure->perimetre() << endl;
        cout<< "Aire : " << figure->aire() << endl;
    }

    for(int i(0); i<figures.size(); ++i)
    {
        delete figures[i];  //On libère la i-ème case mémoire allouée
        figures[i] = 0;  //On met le pointeur à 0 pour éviter les soucis
    }

}