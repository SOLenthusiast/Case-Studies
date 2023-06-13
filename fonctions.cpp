/*
 * fonctions.cpp
 *
 *  Created on: 2014-09-26
 *      Author: etudiant
 */

#include "fonctions.h"
#include <stdlib.h>
#include <fstream>
#include <sstream>

/**
 * \brief Fonction qui lire de charger en mémoire des informations qui se trouvent dans un fichier
 * \param[in] p_nomFichier une chaîne de caractères qui représente le nom du fichier
 * \param[in] p_liste[NOMBRE_MAX_MOTS] un tableau de chaînes de caractères qui va contenir les mots qui sont dans le fichier
 * \return nbMots un entier qui représente le nombre de mots présents dans le fichier
 */
int lireListe(const string& p_nomFichier, string p_liste[NOMBRE_MAX_MOTS])
{
	int nbMots = 0;
	//char buffer[256];

	ifstream fichier(p_nomFichier.c_str(), ios::in);//ouverture pour lecture en mode texte;
	if (!fichier)
	{
		cout << "Erreur d'ouverture du fichier\n";
		exit(ERREUR);
	}
	cout << std::endl;

	/**while(fichier.getline(buffer, 255))
	{
		nbMots++;
		p_liste[nbMots] = buffer;
	}**/
	while (getline(fichier, p_liste[nbMots]))
	{
		nbMots++;
	}

	fichier.close();

	return nbMots;
}

/**
 * \brief Fonction qui affiche les mots contenus dans un tableau
 * \param[in] p_liste[NOMBRE_MAX_MOTS] un tableau de chaînes de caractères
 * \param[in] p_n un entier qui représente le nombre de mots contenus dans le tableau
 */
void afficheListe(string p_liste[NOMBRE_MAX_MOTS], int p_nombreMot)
{
	int i;

	for (i = 0; i < p_nombreMot; i++)
	{
		cout << p_liste[i] << std::endl;
	}
}

/**
 * \brief Fonction qui compte le nombre de redondances d'un mot contenu dans un tableau de mots
 * \param[in] p_liste[NOMBRE_MAX_MOTS] un tableau de mots
 * \param[in] p_n un entier qui représente le nombre de mots contenus dans le tableau
 * \return redondances un entier qui contient le nombre de redondances
 */
int compteRedondances(string p_liste[NOMBRE_MAX_MOTS], int p_nombreMot)
{
	int i, j = 0, redondances = 0;
	string reference;

	for (i = 0; i < p_nombreMot; i++)
	{
		int dejaTraite = 0;
		reference = p_liste[i];
		// On cherche si le mot liste [i] a déjà été traité
		for (j = 0; j < i; j++)
		{
			if (p_liste[j].compare(reference) == 0)
			{
				dejaTraite = 1;
			}
		}

		// Si le mot liste [i] a déjà été traité alors
		//on ne compte pas le nombre de redondances.
		if (dejaTraite == 0)
		{
			for (j = i + 1; j < p_nombreMot; j++)
			{
				if (p_liste[j].compare(reference) == 0)
				{
					redondances++;//on a trouvé deux mots identiques
				}
			}
		}
	}

	return redondances;
}

/**
 * \brief Fonction qui ajoute à chaque mot sa longueur
 * \param[in] p_liste[NOMBRE_MAX_MOTS] un tableau de mots
 * \param[in] p_n un entier qui représente le nombre de mots contenus dans le tableau
 */
void ajouterNombreCaracteres(string p_liste[NOMBRE_MAX_MOTS], int p_nombreMot)
{
	int i;
	int longueur;
	ostringstream os;

	for (i = 0; i < p_nombreMot; i++)
	{
		longueur = p_liste[i].length();

		os << p_liste[i] << ", " << longueur;
		p_liste[i] = os.str();

		os.str(""); // vider le flux

	}
}

/**
 * \brief Fonction qui sauvegarde le contenu d'un tableau dans un fichier
 * \param[in] p_nomFichier une chaîne de caractères qui représente le nom du fichier de sauvegarde
 * \param[in] p_liste[NOMBRE_MAX_MOTS] un tableau de chaînes de caractères
 * \param[in] p_n un entier qui représente le nombre de mots contenus dans le tableau
 */
void sauveListe(const string& p_nomFichier, string p_liste[NOMBRE_MAX_MOTS], int p_nombreMot)
{
	int i;

	ofstream sortie(p_nomFichier.c_str(), ios::out); //ouverture pour l'écriture en mode texte
	// A: sortie est un pointeur non NULL
	if (sortie == NULL)
	{
		cout << "Erreur d'ouverture du fichier\n";
		exit(ERREUR);
	}
	//sauvegarde -> écriture fichier
	for (i = 0; i < p_nombreMot; i++)
	{
		sortie << p_liste[i] << endl;  // écriture dans le fichier
	}
	sortie.close();
}


