/**
 * \file TicTacToe.h
 * \brief Prototype des fonctions de la classe TicTacToe
 * \author etudiant
 * \version 0.1
 * \date 2014-10-17
 */

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

const int TAILLE_MAX = 3;

namespace labo7
{
/**
 * \class TicTacToe
 * \brief Prototype des fonctions de la classe
 */
class TicTacToe
{
public:
	enum Etat {GAGNE, DESSIN, ENCOURS};

		TicTacToe();
		void faireMouvement();
		void afficherTableau();
		bool validerMouvement(int, int);
		bool xoMouvement(int);
		Etat etatJeu();

private:

		int m_tableau[TAILLE_MAX][TAILLE_MAX];
};

} /* namespace labo7 */

#endif /* TICTACTOE_H_ */
