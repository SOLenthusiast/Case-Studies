/**
 * \file NombreRationnelPrincipal.cpp
 * \brief Programme pilote pour tester la classe NombreRationnel
 */

#include <iostream>
#include "NombreRationnel.h"

using namespace labo6;
using namespace std;

int main()
{
	NombreRationnel rat1(5, 3);
	NombreRationnel rat2(2, 4);
	NombreRationnel rat3(3, 4);

	//NombreRationnel rat10;
	//rat10.afficherRationnel();

	cout << "Exemple 1: " << endl;
	rat1.afficherRationnel();

	cout << "Exemple 2: " << endl;
	rat2.afficherRationnel();

	cout << "Exemple 3: " << endl;
	rat3.afficherRationnel();

	cout << "Addition: " << endl;
	NombreRationnel rat4 = rat1 + rat2;
	rat4.afficherRationnel();

	cout << "Multiplication: " << endl;
	NombreRationnel rat5 = rat2 * rat3;
	rat5.afficherRationnel();

	return 0;
}
