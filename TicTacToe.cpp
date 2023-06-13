/**
 * \file TicTacToe.cpp
 * \brief  Jeu tic-tac-toe, implémentation de la classe TicTacToe
 */

#include "TicTacToe.h"

#include <iostream>
#include <iomanip>

using namespace std;

namespace labo7
{

/**
 * \brief Initialisation du tableau de jeu
 */
TicTacToe::TicTacToe()
{
	// initialisation du tableau de jeu
	for (int i = 0; i < TAILLE_MAX; i++)
	{//sur les lignes

		for (int j = 0; j < TAILLE_MAX; j++)
		{ //sur les colonnes

			m_tableau[i][j] = ' ';
		}
	}
}

/**
 * \brief Choix au joueur, de choisir sa position de jeu sur la ligne et sur la colonne.
 */
void TicTacToe::faireMouvement()
{

	afficherTableau();//affichage du tableau

	while (true)
	{
		if (xoMouvement('x'))
			break;
		if (xoMouvement('o'))
			break;

	}
}//fin de faireMouvement

/**
 * \brief Validation du choix de déplacement du joueur.
 * \param[in] p_x un entier qui représente la ligne où le joueur veut effectuer le mouvement.
 * \param[in] p_y un entier qui représente la colonne où le joueur veut effectuer le mouvement.
 * \return La case du tableau où le joueur veut effectuer son mouvement, la validité du mouvement.
 */
bool TicTacToe::validerMouvement(int p_x, int p_y)
{

	return (p_x >= 0 && p_x < 3 && p_y >= 0 && p_y < 3 && m_tableau[p_x][p_y] == ' ');

}//fin de la validation du mouvement

/**
 * \brief Methode permettant au joueur de faire son mouvement de jeu.
 * \param[in] p_symbole un entier qui correspond à la valeur ascii du joueur à qui c'est le tour de jouer ('x' ou 'o')
 * \return Un booléen qui montre l'état du jeu.
 */
bool TicTacToe::xoMouvement(int p_symbole)
{

	int x, y;
	cout << p_symbole << endl;
	do
	{

		cout << "Tour du joueur " << static_cast<char> (p_symbole) << "\n";
		cout << setw(3) << "Ligne (0,1,ou 2):";  // setw, la largeur poue l'éléement à afficher.
		cin >> x;
		cout << setw(3) << "Colonne (0,1,ou 2):";
		cin >> y;

		cout << "\n";

	} while (!validerMouvement(x, y));

	m_tableau[x][y] = p_symbole;
	afficherTableau();

	Etat etat = etatJeu();

	if (etat == GAGNE)
	{
		cout << "Le joueur " << p_symbole << " a gagné la partie\n";
		return true;
	}
	else if (etat == DESSIN)
	{

		cout << "Le jeu est un dessin\n";
		return true;
	}
	else
	{ // etat ==ENCOURS

		return false;
	}
}//fin de xoMouvement

/**
 * \brief Vérification de l'état du jeu si l'un des joueur vient de gagner ou pas encore.
 * \return l'état du jeu (GAGNANT, DESSIN, ENCOURS).
 */
TicTacToe::Etat TicTacToe::etatJeu()
{

	bool gagne = false;

	//verifie l'état du jeu sur la diagonale
	//commencant par la ligne 0 et la colonne 0 et ainsi de suite en diagonale
	if (m_tableau[0][0] != ' ')
	{

		int symbole = m_tableau[0][0];
		for (int i = 0; i < TAILLE_MAX; i++)
		{

			if (m_tableau[i][i] != symbole)
			{
				gagne = false;
				break;
			}
			else
			{
				gagne = true;
			}
		}

		if (gagne)
			return GAGNE;

	}//fin du cas 0


	//cas de la diagonale gauche
	if (m_tableau[TAILLE_MAX - 1][0] != ' ')
	{

		int symbole = m_tableau[TAILLE_MAX - 1][0];
		int j = TAILLE_MAX - 1;
		for (int i = 0; i < TAILLE_MAX; i++)
		{

			if (m_tableau[j][i] != symbole)
			{
				gagne = false;
				break;
			}
			else
			{
				gagne = true;
			}
			j--;
		}

		if (gagne)
			return GAGNE;

	}

	//cas des lignes
	for (int i = 0; i < TAILLE_MAX; i++)
	{
		int symbole = m_tableau[i][0];

		if (symbole != ' ')
		{ //cas valide

			for (int j = 0; j < TAILLE_MAX; j++)
			{ //on parcourt les colonnes

				if (symbole == m_tableau[i][j])
					gagne = true;
				else
				{
					gagne = false;
					break;
				}
			}
			if (gagne)
				return GAGNE;

		}//fin du if
	}

	// cas des colonnes
	//cas des lignes
	for (int i = 0; i < TAILLE_MAX; i++)
	{
		int symbole = m_tableau[0][i];

		if (symbole != ' ')
		{ //cas valide

			for (int j = 0; j < TAILLE_MAX; j++)
			{ //on parcourt les colonnes

				if (symbole == m_tableau[j][i])
					gagne = true;
				else
				{
					gagne = false;
					break;
				}
			}
			if (gagne)
				return GAGNE;

		}//fin du if
	}

	//cas non gagnant
	for (int i = 0; i < TAILLE_MAX; i++)
	{
		for (int j = 0; j < TAILLE_MAX; j++)
			if (m_tableau[i][j] == ' ')
				return ENCOURS;
	}
	return DESSIN;

}//fin de etatJeu

/**
 * \brief Affichage du tableau de jeu.
 */
void TicTacToe::afficherTableau()
{

	cout << "\n 0   1   2\n\n";

	for (int i = 0; i < TAILLE_MAX; ++i)
	{ //sur les lignes
		cout << i;
		for (int j = 0; j < TAILLE_MAX; ++j)
		{ //sur les colonnes

			cout << setw(3) << static_cast<char> (m_tableau[i][j]);

			if (j != 2)
			{
				cout << " |";
			}
		}

		if (i != 2)
			cout << "\n ____|____|____" << "\n     |    |    \n";

	}

	cout << "\n\n";

}//fin

} /* namespace labo7 */
