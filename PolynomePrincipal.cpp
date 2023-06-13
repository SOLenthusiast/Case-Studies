/**
 * \file PolynomePrincipal.cpp
 * \brief Programme pilote démontrant les fonctionnalités des méthodes développées.
 * \author etudiant
 * \version 0.1
 * \date 2014-10-17
 */

#include "Polynome.h"
#include <iostream>
#include "math.h"

using namespace labo7;
using namespace std;

int main()
{
	Polynome P1(5);

	Polynome P2;

	cout << "Polynôme de degré nul: " << "P2 = " << P2 << endl;

	cout << "Polynôme de degré: " << P1.reqOrdre() << endl;
	cout << "P1 = " << P1  << endl;
	cout << endl;

	//insertion des coefficients
	/**for(int i=1;i<=P1.reqOrdre()+1;i++)
	{
		P1.insertionCoefficient(i,i);
	}**/

	// insertion du ième terme dont le coefficient est passé en paramètre
	P1.insertionCoefficient(2,1.2);

	// Affichage du polynome modifié au ième terme
	cout << "P1 modifié à la ième terme = " << P1  << endl;
	cout << endl;

	cout << "Résultat de l'évaluation du polynôme pour une valeur de x: " << P1.evaluerPolynome(1) << endl;

	return 0;
}


