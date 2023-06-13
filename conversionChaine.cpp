/*
 * conversionChaine.cpp
 *
 *  Created on: 2014-09-26
 *      Author: etudiant
 */

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main()
{
	char chaine_c[] =
			"2979403 2 16.99 Câble DVI-D Dual-Link Mâle à Mâle de six Pieds Noir ";

	string chaine_str = chaine_c;
	istringstream is_chaine(chaine_c);

	int reference;
	is_chaine >> reference;

    int quantite;
	is_chaine >> quantite;

	float prix;
	is_chaine >> prix;

	char buffer[256];
	is_chaine.ignore();
	is_chaine.getline(buffer, 255);
	string designation = buffer;

	cout << "Référence: " << reference << endl;
	cout << "Quantité: " << quantite << endl;
	cout<< "Prix: " << prix << endl;
	cout << "Désignation: " << designation << endl;

	return 0;
}



