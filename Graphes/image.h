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
        Graph(Image, int, int);
        ~Graph();

        int get_nord(int);
        int get_sud(int);
        int get_est(int);
        int get_ouest(int);

        


};

#endif