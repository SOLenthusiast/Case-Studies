/**
 * \file Polynome.h
 * \brief Prototype des fonctions de la classe Polynome
 * \author etudiant
 * \version 0.1
 * \date 2014-10-17
 */

#ifndef POLYNOME_H_
#define POLYNOME_H_

#include <iostream>
const int ORDRE_MAX = 10;

namespace labo7
{

/**
 * \class Polynome
 * \brief Prototype des fonctions de la classe
 */
class Polynome
{
public:
	friend std::ostream& operator<<(std::ostream&, Polynome&);

	Polynome(int p_ordre = 0);

	void insertionCoefficient(int p_terme,float p_coefficient);
	int reqOrdre() const;
	float reqCoefficient(int p_ordre) const;
	float evaluerPolynome(float p_pointEvaluation) const;

private:
	int m_ordre;
	float m_coefficients[ORDRE_MAX];

};

} /* namespace labo7 */

#endif /* POLYNOME_H_ */
