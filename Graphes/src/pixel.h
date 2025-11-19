#ifndef PIXEL_
#define PIXEL_

class pixel
{
    private:

    unsigned char niveau_de_gris;

    unsigned int x;
    unsigned int y;

    unsigned int ouest;
    unsigned int est;
    unsigned int nord;
    unsigned int sud;

    public:

    //Constructeur par defaut toutes les voisins sont -1 et les 
    //valeus de couleur mets en 0
    pixel();

    //Constructeur par recopie, prend en parametres les valeurs de 
    //niveau_de_gris, ouest, est, nord, sud 
    pixel(unsigned int x, unsigned int y, unsigned char ndg);

    //Destructeur par desaut
    ~pixel();

    //procedure remplir_pixel [entier bdg] - prend en parametre le 
    //niveau de gris et remplit la valeur dans pixel 
    void remplir_couleur_pixel(unsigned char ndg);

    // procedure remplir_voisins_pixel [entiers posotoves ou , es, no ,su]
    //remplit les voisinages de pixel
    void remplir_voisins_pixel();  


    //Procedure deconstruir_pixel  - remplit les couleurs et des voisins de 
    void refair_pixel(unsigned char ndg, unsigned int x1 , unsigned int y1);

    // procedure remplir_coordonnes [entiers x y ] - identifie la place 
    //de pixel dans la grille 
    void remplir_coordonnes(unsigned int x1 , unsigned int y1);

    // Operator =
    void operator =(pixel pix);

    //Operator == return true si deux pixels sont egaux
    bool operator ==(pixel pix);

    //affiche les coordonnes , niveau de gris et voisins de pixel 
    void afficher_donnes_pixel();

    void test_fonctionement_pixel();
};

#endif