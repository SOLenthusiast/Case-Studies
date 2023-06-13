/**
 * \file TempsPrincipal.cpp
 * \brief Programme pilote pour tester la classe Temps
 * \author etudiant
 * \version 0.1
 * \date 2014-10-10
 */

#include "Temps.h"
#include <iostream>
#include <fstream>

using namespace labo6;
using namespace std;

const int tailleTableau=5;

int main()
{
	Temps t0;
	cout << t0 << endl;
	Temps t;
	t.asgHeure(17);
	t.asgMinute(34);
	t.asgSeconde(25);

	cout << "Résultat d'un ajustement avec des valeurs valides:" << endl
			<< "  Heure: " << t.reqHeure() << "  Minute: " << t.reqMinute()
			<< "  Seconde: " << t.reqSeconde();

	t.asgHeure(234); // heure non valide, ajustée à 0.
	t.asgMinute(43);
	t.asgSeconde(6373); // seconde non valide, ajustée à 0.

	cout << "\n\nRésultat avec des valeurs non valables pour"
			<< " heure et seconde:\n  Heure: " << t.reqHeure() << "  Minute: "
			<< t.reqMinute() << "  Seconde: " << t.reqSeconde() << endl;

	cout << endl << "constructeur avec parametres invalides" << endl;
	Temps t1(23, 58, 58);
	cout << "\t" << t1 << " pour 23h 58mn 58s" << endl;

	cout << endl << "Test de la méthode tic" << endl;

	Temps t2(2, 20, 13);
	Temps t3(3, 59, 15);
	Temps t4(23, 59, 23);

	//test du passage à la minute suivante
	cout << endl << "Test passage a la minute suivante pour : " << t2 << endl;
	for (int i = 0; i < 60; i++)
	{
		t2.tic();
		cout << "\t" << t2 << endl;
	}

	cout << endl << "Test passage a l'heure suivante pour :  " << t3 << endl;
	for (int i = 0; i < 60; i++)
	{
		t3.tic();
		cout << "\t" << t3 << endl;
	}

	cout << endl << "Test passage au jour suivant pour : " << t4 << endl;
	for (int i = 0; i < 60; i++)
	{
		t4.tic();
		cout << "\t" << t4 << endl;
	}

	//tableau d'objets Temps
	Temps tableauTemps[tailleTableau];
	tableauTemps[1].asgTemps(2, 3, 4);
	tableauTemps[3].asgHeure(0);
	for (int i = 0; i < tailleTableau; i++)
	{
		cout << tableauTemps[i] << endl;
	}

	cout <<"Nombre d'objets Temps instanciés : "<< Temps::reqNbTemps()<<endl;

	ofstream sortie("temps.txt", ios::out); //ouverture d'un fichier texte en mode ecriture

	if (!sortie)
	{
		cerr << "Ouverture impossible" << endl;
		return 1;
	}
	for (int i = 0; i < tailleTableau; i++)
	{
		sortie << tableauTemps[i] << endl;
	}

	return 0;
}




