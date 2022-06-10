#include "garage.hpp"
#include <iostream>
using namespace std;

Vehicule::Vehicule(int prix, int date_fabrique)
    :m_prix(prix),m_date_fabrique(date_fabrique)
{}

void Vehicule::affiche() const
//J'en profite pour modifier un peu les fonctions d'affichage
{
    cout << "Ceci est un vehicule coutant " << m_prix << " euros." << endl;
}

Vehicule::~Vehicule() //Même si le destructeur ne fait rien, on doit le mettre !
{}

Voiture::Voiture(int prix, int portes, int date_fabrique)
    :Vehicule(prix, m_date_fabrique) ,m_portes(portes) 
{}

void Voiture::affiche() const
{
    cout << "Ceci est une voiture avec " << m_portes << " portes et coutant " << m_prix << " euros." << endl;
}

int Voiture::nbrRoues() const
{
    cout << "Une voiture a 4 roues" << endl;
    return 4;
}

Voiture::~Voiture()
{}

Moto::Moto(int prix, double vitesseMax, int date_fabrique)
    :Vehicule(prix, date_fabrique), m_vitesse(vitesseMax)
{}

void Moto::affiche() const
{
    cout << "Ceci est une moto allant a " << m_vitesse << " km/h et coutant " << m_prix << " euros." << endl;
    
}

int Moto::nbrRoues() const
{
    cout << "Une Moto a 2 roues" << endl;
    return 2;
}

Moto::~Moto()
{}

Camion::Camion(int prix, int poids, int date_fabrique)
        :Vehicule(prix, date_fabrique)
{

}

int Camion::nbrRoues() const
{
    cout << "Un Camion a 16 roues" << endl;
    return 16;
}



void Camion::affiche()const
{
    cout << "Ceci est un Camion fabrique en" << m_date_fabrique << " et qui coute " << m_prix << " euros." << endl;
}

Garage ::Garage(vector<Vehicule*> liste_vehicule) {}

void Garage ::afficherInfo(vector<Vehicule*>liste_vehicule)
{
    for (auto vehicules : liste_vehicule){
        cout << vehicules << "; ";
    }
}

void Garage ::ajouterVehicules(vector<Vehicule*>liste_vehicule)
{
    liste_vehicule.push_back(new Moto(2000, 212.5,2000)); 
}