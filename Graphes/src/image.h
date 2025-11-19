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
        //Constructeur - Destructeur
        Graph(Image im, float i, float j);
        ~Graph();

        //Fonctions pour avoir la capacité des arcs vers ses voisins
        int get_valuation(pixel *ligne, pixel *colonne);
        //Pour récupérer ses voisins:
        int get_nord(int);
        int get_sud(int);
        int get_est(int);
        int get_ouest(int);
        


        void afficher();
        void sauvegarde();

};

#endif