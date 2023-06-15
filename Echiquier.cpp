/*
 *  Echiquier.cpp
 */

#include "Echiquier.h"

namespace labo6
{

Echiquier::Echiquier()
{
	for(int toto = 0; toto < 8; ++toto)
		for(int toto2 = 0; toto2 < 8; ++toto2)
			tableau[toto][toto2] = toto2;
}

int Echiquier::operator()(int r, int c)
{
	return tableau[r][c];
}


} /* namespace labo6 */
