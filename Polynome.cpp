/**
 * \file Polynome.cpp
 * \brief implémentation des fonctionnalités de la classe Polynome.
 * \author etudiant
 * \version 0.1
 * \date 2014-10-17
 */

#include "Polynome.h"
#include <sstream>
#include "math.h"

using namespace std;
namespace labo7
{
/**
 * \brief Création d'un polynôme nul de degré n et initialisation du tableau des coefficients
 * \param[in] p_ordre, l'ordre du polynome
 */
Polynome::Polynome(int p_ordre): m_ordre(p_ordre) // liste d'initialisation
{
	for(int i=0;i<=m_ordre;i++)
	{
		m_coefficients[i] = 0.0;
	}
}

/**
 * \brief Insertion du ième terme dont le coefficient est passé en paramètre
 * \param[in] p_terme, ième terme pour l'insertion du coefficient.
 * \param[in] p_coefficient, le coefficient a inséré à la ième terme.
 */
void Polynome::insertionCoefficient(int p_terme,float p_coefficient)
{
	m_coefficients[p_terme-1] = p_coefficient;
}

/**
 * \brief Récupération de l'ordre du polynôme.
 * \return l'ordre.
 */
int Polynome::reqOrdre() const
{
	return m_ordre;
}

/**
 * \brief Récupération du coéfficient pour chaque ième terme.
 * \return un tableau contenant les coefficients du polynome.
 */
float Polynome::reqCoefficient(int p_terme) const
{
	return m_coefficients[p_terme];
}

/**
 * \brief Evaluation du polynôme pour une valeur de x donné
 * \param[in] p_pointEvaluation, la valeur de x pour l'évaluation du polynôme.
 * \return le résultat de l'évaluation du polynôme.
 */
float Polynome::evaluerPolynome(float p_pointEvaluation) const
{
	float resultat = 0;

	for (int i = 0; i <= reqOrdre(); ++i)
	{
		resultat += reqCoefficient(i)*pow(p_pointEvaluation,i);
	}

	return resultat;
}

/**
 * \brief Surcharge de l’opérateur << pour permettre
 *        d’envoyer dans un flux de sortie ostream la représentation de la forme d'un polynôme
 * \param[in] p_os un flux de sortie.
 * \param[in] p_polynome l'objet à sortir.
 * \return un flux de sortie pour permettre les appels en cascade.
 */
ostream & operator<<(ostream & p_os, Polynome & p_polynome)
{

	for(int i=0;i<=p_polynome.reqOrdre();i++)
	{
		p_os << p_polynome.reqCoefficient(i) <<"x" << "^" << i;
		if (i < p_polynome.reqOrdre()) p_os <<" + ";
	}
	return p_os;
}
} /* namespace labo7 */
