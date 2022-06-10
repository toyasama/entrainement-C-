#ifndef DEF_FIGURE
#define DEF_FIGURE


class Figure 
{
    public:
        virtual int perimetre() const = 0;
        virtual int aire() const = 0;
        virtual void afficher()const;

};

class Triangle : public Figure
{
    public:
        Triangle(int base,int hauteur);
        virtual int aire()const;
        virtual void afficher()const;

    private:
        int m_base;
        int m_hauteur;
};

class Carre : public Figure
{
    public:
        Carre(int cote);
        virtual int perimetre() const;
        virtual int aire()const;
        virtual void afficher()const;

    private:
        int m_cote;
};

class Rectangle : public Figure
{
    public:
        Rectangle(int longueur,int largeur);
        virtual int perimetre() const;
        virtual int aire()const;
        virtual void afficher()const;

    private:
        int m_longueur;
        int m_largeur;
};


class Cercle : public Figure
{
    public:
        Cercle(int rayon);
        virtual int perimetre() const;
        virtual int aire()const;
        virtual void afficher()const;

    private:
        int m_rayon;
};

#endif //FIGURE