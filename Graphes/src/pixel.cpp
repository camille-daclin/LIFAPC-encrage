#include<iostream>
#include"pixel.h"

using namespace std;


pixel::pixel()
{
    x = -1;
    y = -1;
    niveau_de_gris = 0;
    ouest = -1;
    est = -1;
    nord = -1;
    sud = -1;
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
    if(x != -1 && y != -1)
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