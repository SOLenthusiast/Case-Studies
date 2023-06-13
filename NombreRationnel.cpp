/**
 * \file NombreRationnel.cpp
 * \brief Implémentation de la classe NombreRationnel
 * \author etudiant
 * \version 0.1
 * \date 2014-10-10
 */

#include "NombreRationnel.h"
#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;
namespace labo6 {

/**
 * \brief Constructeur avec paramètres,
 *        s'il n'y a pas de valeur en paramètre le numérateur est à 0 et le dénominateur à 1.
 * \param[in] p_n, pour le numérateur.
 * \param[in] p_d, pour le dénominateur.
 */
NombreRationnel::NombreRationnel( int p_n, int p_d )
{
    assert(p_d!=0); //empêche que le dénominateur soit égal à 0
    m_numerateur = p_n;
    m_denominateur = p_d;
    reduction();
}

/**
 * \brief Fonction permettant de réduire un fraction en la simplifiant.
 */
void NombreRationnel::reduction()
{
    int plusGrand, pgcd = 1;
    plusGrand = ( m_numerateur > m_denominateur ) ? m_numerateur: m_denominateur;

    for ( int i = 2; i <= plusGrand; ++i )
         if ( m_numerateur % i == 0 && m_denominateur % i == 0 )
             pgcd = i;

    m_numerateur /= pgcd;
    m_denominateur /= pgcd;
}

/**
 * \brief Surchage de l'opérateur + pour l'addition de deux fractions
 * \param[in] p_a, fraction courant
 * \return la somme des fractions.
 */
NombreRationnel NombreRationnel::operator+( const NombreRationnel & p_a )
{
    NombreRationnel somme;
    somme.m_numerateur =  m_numerateur * p_a. m_denominateur +  m_denominateur * p_a. m_numerateur;
    somme. m_denominateur =  m_denominateur * p_a. m_denominateur;
    somme.reduction();
    return somme;
}

/**
 * \brief Surcharge de l'opérateur * pour la multiplication de deux fractions.
 * \param[in] p_m, fraction courant.
 * \return le produit des fractions.
 */
NombreRationnel NombreRationnel::operator*( const NombreRationnel & p_m )
{
    NombreRationnel produit;

    produit. m_numerateur =  m_numerateur * p_m. m_numerateur;
    produit. m_denominateur =  m_denominateur * p_m. m_denominateur;
    produit.reduction();
    return produit;
}

/**
 * \brief Surcharge de l'opérateur / pour la division de deux fractions.
 * \param[in] p_d, fraction courant.
 * \return la division des fractions.
 */
NombreRationnel NombreRationnel::operator/(const NombreRationnel & p_d )
{
    NombreRationnel division;

    if ( p_d.m_numerateur != 0 )
    {
        division.m_numerateur = m_numerateur * p_d.m_denominateur;
        division.m_denominateur = m_denominateur * p_d.m_numerateur;
        division.reduction();
    }
    else
    {
        cout << "Division par zero : fin du programme" << endl;
        exit( 1 );
    }
    return division;
}

/**
 * \brief Surcharge de l'opérateur > pour la supériorité entre de deux fractions.
 * \param[in] p_pg, fraction courant.
 * \return vrai ou faux si c'est supérieur.
 */
bool NombreRationnel::operator>( const NombreRationnel & p_pg ) const
{
    if ( static_cast<double>( m_numerateur ) / static_cast<double>( m_denominateur ) >
        static_cast<double>( p_pg.m_numerateur ) / static_cast<double>( p_pg.m_denominateur ) )
        return true;
    else
        return false;
}

/**
 * \brief Surcharge de l'opérateur == pour l'égalité entre de deux fractions.
 * \param[in] p_e, fraction courant.
 * \return vrai ou faux si c'est égal.
 */
bool NombreRationnel::operator==( const NombreRationnel & p_e ) const
{
    if (m_numerateur == p_e.m_numerateur &&
	    (m_numerateur == 0 || m_denominateur == p_e.m_denominateur ))
        return true;
    else
        return false;
}

/**
 * \brief Affichage sous forme d'une fraction.
 */
void NombreRationnel::afficherRationnel() const
{
	cout << m_numerateur << "/" << m_denominateur << endl;
}

} /* namespace labo6 */
