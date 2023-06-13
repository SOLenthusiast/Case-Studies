/*
 * principal.cpp
 *
 *  Created on: 2014-09-26
 *      Author: etudiant
 */

#include "fonctions.h"

int main()
{
	string nomFichier;
	string nomFichierSauvegarde;
	int nombreMots = 0;
	string mots[NOMBRE_MAX_MOTS];

	cout << "Donnez le nom du fichier a lire" << endl;
	getline(cin,nomFichier);

	//lire le fichier
	nombreMots = lireListe(nomFichier, mots);
	cout << "Liste de mots : " << endl;

	afficheListe(mots, nombreMots);

	//pour compter le nombre de mots lus
	cout << "Nombre de redondances: " << compteRedondances(mots, nombreMots) << endl;

	//ajouter à chaque mots, le nombre de caractères les composant
	ajouterNombreCaracteres(mots, nombreMots);

	//sauvegarde de l'ajout
	cout << "Donnez le nom du fichier de sauvegarde " << endl;

	getline(cin,nomFichierSauvegarde);
	sauveListe(nomFichierSauvegarde, mots, nombreMots);

	return 0;
}



