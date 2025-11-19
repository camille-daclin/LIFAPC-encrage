#ifndef PIXEL_
#define PIXEL_

class pixel
{
    private:

    unsigned char niveau_de_gris;

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
    pixel(unsigned char ndg, unsigned int ou, unsigned int es, unsigned int no, unsigned int su);
    
    //Destructeur par desaut
    ~pixel();

    //procedure remplir_pixel [entier bdg] - prend en parametre le 
    //niveau de gris et remplit la valeur dans pixel 
    void remplir_couleur_pixel(unsigned char ndg);

    // procedure remplir_voisins_pixel [entiers posotoves ou , es, no ,su]
    //remplit les voisinages de pixel
    void remplir_voisins_pixel(unsigned int ou, unsigned int es, unsigned int no, unsigned int su);  


    //Procedure qui fait la meme fonctionement que le constructeur par recopie regarder ligne 21
    void deconstruir_pixel(unsigned char ndg, unsigned int ou, unsigned int es, unsigned int no, unsigned int su);

    // Operator =
    void operator =(pixel pix);

    //Operator == return true si deux pixels sont egaux
    bool operator ==(pixel pix);

};

#endif