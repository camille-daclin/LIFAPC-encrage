#ifndef Pixel_
#define Pixel_

class Pixel
{
    private:

    //couleur de pixel
    unsigned char niveau_de_gris;

    //cordonnais de pixel
    unsigned int x;
    unsigned int y;


    // les valeurs de voisins
    unsigned int ouest;
    unsigned int capacite_ouest;
    unsigned int flot_ouest;


    unsigned int est;
    unsigned int capacite_est;
    unsigned int flot_est;

    unsigned int nord;
    unsigned int capacite_nord;
    unsigned int flot_nord;

    unsigned int sud;
    unsigned int capacite_sud;
    unsigned int flot_sud;



    public:

    //Constructeur par defaut toutes les voisins sont -1 et les 
    //valeus de couleur mets en 0
    Pixel();

    //Constructeur par recopie, prend en parametres les valeurs de 
    //niveau_de_gris, ouest, est, nord, sud 
    Pixel(unsigned int x, unsigned int y, unsigned char ndg);

    //Destructeur par desaut
    ~Pixel();

    //procedure remplir_Pixel [entier bdg] - prend en parametre le 
    //niveau de gris et remplit la valeur dans Pixel 
    void remplir_couleur_pixel(unsigned char ndg);

    // procedure remplir_voisins_Pixel [entiers posotoves ou , es, no ,su]
    //remplit les voisinages de Pixel
    void remplir_voisins_pixel();  


    //Procedure deconstruir_Pixel  - remplit les couleurs et des voisins de 
    void refair_pixel(unsigned char ndg, unsigned int x1 , unsigned int y1);

    // procedure remplir_coordonnes [entiers x y ] - identifie la place 
    //de Pixel dans la grille 
    void remplir_coordonnes(unsigned int x1 , unsigned int y1);

    // Operator =
    void operator =(Pixel pix);

    //Operator == return true si deux Pixels sont egaux
    bool operator ==(Pixel pix);

    //return true si les deux pixels sont des voisins 
    bool verifier_voisines(Pixel pix);

    //procedudes de changement des capacites
    void changer_capacite_ouest(unsigned int cap_ou);
    void changer_capacite_est(unsigned int cap_es);
    void changer_capacite_nord(unsigned int cap_no);
    void changer_capacite_sud(unsigned int cap_su);

    //procedudes de changement des flots
    void changer_flot_ouest(unsigned int flot_ou);
    void changer_flot_est(unsigned int flot_es);
    void changer_flot_nord(unsigned int flot_no);
    void changer_flot_sud(unsigned int flot_su);

    //affiche les coordonnes , niveau de gris et voisins de Pixel 
    void afficher_donnes_pixel();

    void test_fonctionement_pixel();
};

#endif