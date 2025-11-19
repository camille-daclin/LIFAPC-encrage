#include<iostream>
#include"pixel.h"

using namespace std;


pixel::pixel()
{
    niveau_de_gris = 0;
    ouest = -1;
    est = -1;
    nord = -1;
    sud = -1;
}

pixel::pixel(unsigned char ndg, unsigned int ou, unsigned int es, unsigned int no, unsigned int su)
{
    niveau_de_gris = ndg;
    ouest = ou;
    est = es;
    nord = no;
    sud = su;
}

pixel::~pixel()
{
    //pas de pointeurs sur tas donc destr. ne fait rien
}



void pixel::remplir_couleur_pixel(unsigned char ndg)
{
    niveau_de_gris = ndg;
}


void pixel::remplir_voisins_pixel(unsigned int ou, unsigned int es, unsigned int no, unsigned int su)
{
    ouest = ou;
    est = es;
    nord = no;
    sud = su;  
}


void pixel::deconstruir_pixel(unsigned char ndg, unsigned int ou, unsigned int es, unsigned int no, unsigned int su)
{
    niveau_de_gris = ndg;
    ouest = ou;
    est = es;
    nord = no;
    sud = su;  
}

void pixel::operator =(pixel pix)
{
    niveau_de_gris = pix.niveau_de_gris;
    ouest = pix.ouest;
    est = pix.est;
    nord = pix.nord;
    sud = pix.sud;  
}

bool pixel::operator ==(pixel pix)
{
    if(niveau_de_gris == pix.niveau_de_gris && ouest == pix.ouest && est == pix.est && nord == pix.nord && sud == pix.sud)
    {
        return true;
    }else
    {
        return false;
    }
}