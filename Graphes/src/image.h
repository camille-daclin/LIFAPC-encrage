#ifndef IMAGE_
#define IMAGE_

using namespace std;

class Image{
    
    private:
        int *pixels;
        int hauteur;
        int largeur;

    public:
        Image (const string);

};

class Graph{
    private:
        Image *image;
        Pixel *pixel;
    public:
<<<<<<< HEAD
        //Constructeur - Destructeur
        Graph(Image, int, int);
        ~Graph();

        //Fonctions d'accès
        int get_global(Pixel *ligne, Pixel *colonne);
        //Pour récupérer ses voisins:
=======
        Graph(Image, int, int);
        ~Graph();

>>>>>>> 5e5bebd8add02b3a9d758266a67628568ebca772
        int get_nord(int);
        int get_sud(int);
        int get_est(int);
        int get_ouest(int);
<<<<<<< HEAD
        //Propriétés pixel
        


        void afficher();
        void sauvegarde();

=======

        


>>>>>>> 5e5bebd8add02b3a9d758266a67628568ebca772
};

#endif