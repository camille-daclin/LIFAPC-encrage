#include <iostream>
#include <string>
#include "image.h"

using namespace std;

int main(int argc, char* argv[])
{
    string fichier_entree = "test.ascii.pgm";
    string fichier_sortie = "resultat.pgm";
    float sigma = 30.0;
    float alpha = 2.0;
    int H = 100;
    
    // Lecture des paramètres en ligne de commande
    if (argc > 1) fichier_entree = argv[1];
    if (argc > 2) fichier_sortie = argv[2];
    if (argc > 3) sigma = atof(argv[3]);
    if (argc > 4) alpha = atof(argv[4]);
    if (argc > 5) H = atoi(argv[5]);
    
    cout << "=== Encrage d'image avec 2 couleurs ===" << endl;
    cout << "Fichier d'entree: " << fichier_entree << endl;
    cout << "Fichier de sortie: " << fichier_sortie << endl;
    cout << "Parametres: sigma=" << sigma << ", alpha=" << alpha << ", H=" << H << endl;
    cout << endl;
    
    // Chargement de l'image
    cout << "Etape 1: Chargement de l'image..." << endl;
    Image img(fichier_entree, sigma, alpha, H);
    img.afficher();
    cout << endl;
    
    // NOUVEAU : Afficher les capacités (optionnel)
    cout << "=== Affichage des capacites (pour verification) ===" << endl;
    img.afficher_capacites();
    cout << endl;
    
    // Calcul du flot maximal
    cout << "Etape 2: Calcul du flot maximal..." << endl;
    img.calculer_flot_maximal();
    cout << endl;
    
    // Binarisation
    cout << "Etape 3: Binarisation de l'image..." << endl;
    img.binariser();
    cout << endl;
    
    // Sauvegarde
    cout << "Etape 4: Sauvegarde du resultat..." << endl;
    img.sauvegarder(fichier_sortie);
    cout << endl;
    
    cout << "=== Traitement termine ===" << endl;
    
    return 0;
}