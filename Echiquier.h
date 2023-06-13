/*
 * Echiquier.h
 *
 *  Created on: 2014-10-10
 *      Author: etudiant
 */

#ifndef ECHIQUIER_H_
#define ECHIQUIER_H_

namespace labo6
{

class Echiquier
{
public:

	Echiquier();
	int operator()(int,int); // opérateur d'appel de fonction surchargé

private:
	int tableau[8][8];
};

} /* namespace labo6 */

#endif /* ECHIQUIER_H_ */
