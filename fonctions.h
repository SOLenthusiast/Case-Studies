/*
 * fonctions.h
 *
 *  Created on: 2014-09-26
 *      Author: etudiant
 */

#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <iostream>
#include <string>

const int L_MOTS_MAX = 20;
const int NOMBRE_MAX_MOTS = 20;

using namespace std;

enum
{
	OK, ERREUR
};

int lireListe(const string& p_nomFichier, string p_liste[NOMBRE_MAX_MOTS]);
void afficheListe(string p_liste[NOMBRE_MAX_MOTS], int p_nombreMot);
int compteRedondances(string p_liste[NOMBRE_MAX_MOTS], int p_nombreMot);
void ajouterNombreCaracteres(string p_liste[NOMBRE_MAX_MOTS], int p_nombreMot);
void sauveListe(const string& p_nomFichier, string p_liste[NOMBRE_MAX_MOTS], int p_nombreMot);


#endif /* FONCTIONS_H_ */
