#include<iostream>
#include"pixel.h"

using namespace std;


pixel::pixel()
{
    x = 1000;
    y = 1000;
    niveau_de_gris = 0;
    ouest = 1000;
    est = 1000;
    nord = 1000;
    sud = 1000;
}

pixel::pixel(unsigned int x1, unsigned int y1, unsigned char ndg)
{
    x = x1;
    y = y1;
    niveau_de_gris = ndg;
    this->remplir_voisins_pixel();
}

pixel::~pixel()
{
    //pas de pointeurs sur tas donc destr. ne fait rien
}



void pixel::remplir_couleur_pixel(unsigned char ndg)
{
    niveau_de_gris = ndg;
}


void pixel::remplir_voisins_pixel()
{
    if(x != 1000 && y != 1000)
    {
        ouest = x - 1;
        est = x + 1;
        nord = y - 1;
        sud = y + 1;     
    }
}


void pixel::remplir_coordonnes(unsigned int x1 , unsigned int y1)
{
    x = x1; 
    y = y1;
    this->remplir_voisins_pixel();
}


void pixel::refair_pixel(unsigned char ndg, unsigned int x1 , unsigned int y1)
{
    niveau_de_gris = ndg;
    this->remplir_coordonnes(x1, y1);
    this->remplir_voisins_pixel();
}

void pixel::operator =(pixel pix)
{
    niveau_de_gris = pix.niveau_de_gris;
    x = pix.x;
    y = pix.y;
    this->remplir_voisins_pixel();
}

bool pixel::operator ==(pixel pix)
{
    if(niveau_de_gris == pix.niveau_de_gris && x == pix.x && y == pix.y)
    {
        return true;
    }else
    {
        return false;
    }
}

void pixel::afficher_donnes_pixel()
{
    cout << "couleur: " << niveau_de_gris << "; x: " << x << "; y: "<< y << " voisins: ";
    cout <<"Nord(" << nord << "," << y <<") ";
    cout <<"Sud(" << sud << "," << y <<") ";
    cout <<"Est(" << x << "," << est <<") ";
    cout <<"Ouest(" << x << "," << ouest <<") "<<endl; 
}


void pixel::test_fonctionement_pixel()
{
    pixel p1;
    pixel p2(10,11,124);
    p1.afficher_donnes_pixel();
    p2.afficher_donnes_pixel();

    p1.remplir_couleur_pixel(224);
    p1.afficher_donnes_pixel();
    p1.remplir_coordonnes(14,16);
    p1.afficher_donnes_pixel();

    p1.refair_pixel(44,43,11);
    p1.afficher_donnes_pixel();

    pixel p3;
    p3 = p2;
    if(p3 == p2)
    {
        p3.afficher_donnes_pixel();
    }
}
