#ifndef DEF_GARAGE
#define DEF_GARAGE
#include <vector>
using namespace std;
class Vehicule
{
    public:
    Vehicule(int prix,int date_fabrique);           //Construit un véhicule d'un certain prix
    virtual void affiche() const;
    virtual ~Vehicule();
    virtual int nbrRoues() const =0; // rend cette classe mère virtual pure (abstraite) => Qu'on ne peut pas créer de classe de cette instance

    protected:
    int m_prix;
    int m_date_fabrique;
    int m_nbr_roues;
};

class Voiture: public Vehicule
{
    public:
    Voiture(int prix, int portes,int date_fabrique);
    //Construit une voiture dont on fournit le prix et le nombre de portes
    virtual void affiche() const;
    virtual int nbrRoues() const;
    virtual ~Voiture();


    private:
    int m_portes;
};

class Moto : public Vehicule 
{
    public:
    Moto(int prix, double vitesseMax, int date_fabrique );
    //Construit une moto d'un prix donné et ayant une certaine vitesse maximale
    virtual void affiche() const;
    virtual int nbrRoues() const;
    virtual ~Moto();
 
    private:
    double m_vitesse;
    
};

class Camion : public Vehicule
{
    public:
        Camion(int prix, int poids, int date_fabrique);
        virtual void affiche() const;
        virtual ~Camion();
        virtual int nbrRoues() const;
};

class Garage 
{
    public:
        Garage(vector<Vehicule*> liste_vehicule);
        void afficherInfo(vector<Vehicule*>liste_vehicule);
        void ajouterVehicules(vector<Vehicule*>liste_vehicule);
        void supprimerVehicules(vector<Vehicule*>liste_vehicule);
        ~Garage();
        
};

#endif // DEF_GARAGE