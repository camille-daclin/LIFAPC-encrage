#include <iostream>
#include <string>
#include "image.h"

using namespace std;

int main(int argc, char* argv[])
{
    string fichier_source = "test.ascii.pgm";
    string fichier_res = "resultat.pgm";
    float sigma = 30.0;
    float alpha = 2.0;
    int H = 100;
    
    if (argc > 1) 
    {
        fichier_source = argv[1];
    }
    if (argc > 2)
    {
        fichier_res = argv[2];
    }
    if (argc > 3)
    {
        sigma = atof(argv[3]);
    }
    if (argc > 4)
    {
       alpha = atof(argv[4]); 
    } 
    if (argc > 5)
    {
        H = atoi(argv[5]);
    } 
    
    cout << "=== Encrage d'image avec 2 couleurs ===" << endl;
    cout << "Fichier source: " << fichier_source << endl;
    cout << "Fichier résultat: " << fichier_res << endl;
    cout << "Parametres: sigma=" << sigma << ", alpha=" << alpha << ", H=" << H << endl;
    cout << endl;
    
    cout << "Etape 1: Chargement de l'image :" << endl;
    Image img(fichier_source, sigma, alpha, H);
    img.afficher();
    cout << endl;
    
    // Afficher les capacités (pour pouvoir comparer avec les résultats du prof)
    cout << "=== Affichage des capacites ===" << endl;
    img.afficher_capacites();
    cout << endl;
    
    cout << "Etape 2: Calcul du flot maximal :" << endl;
    img.calculer_flot_maximal();
    cout << endl;

    cout << "Etape 3: Binarisation de l'image :" << endl;
    img.binariser();
    cout << endl;
    
    cout << "Etape 4: Sauvegarde du resultat" << endl;
    img.sauvegarder(fichier_res);
    cout << endl;
    
    cout << "=== Traitement fini ===" << endl;   
    return 0;
}