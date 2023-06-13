/**
 * \file Temps.cpp
 * \brief Implantation de la classe Temps
 * \author etudiant
 * \date 2014-10-10
 * \version 1.0
 */

#include "Temps.h"

#include <time.h>
#include <sstream>

using namespace std;
namespace labo6 {

int Temps::nbTemps = 0;  //Initialisation d'un membre static

/**
 * \brief constructeur par défaut,
 *        la valeur par défaut est celle du système ajusté selon l'heure de Greenwich.
 */
Temps::Temps() {

	m_seconde = time(NULL); // nombre de secondes depuis 1970
	m_heure = m_seconde / 3600; // nombre d'heures depuis 1970
	m_heure = m_heure % 24; // nombre d'heures aujourd'hui
	m_heure = m_heure - 4; // nombre d'heures aujourd'hui à Québec(fuseau horaire)
	m_minute = m_seconde / 60; // nombre de minutes depuis 1970
	m_minute = m_minute % (24 * 60); // nombre de minutes aujourd'hui
	m_minute = m_minute % 60; // nombre de minutes dans la dernière heure
	m_seconde = m_seconde % (24 * 3600); // nombre de secondes aujourd'hui
	m_seconde = m_seconde % 3600; // nombre de secondes dans la dernière heure
	m_seconde = m_seconde % 60; // nombre de secondes dans la dernière minute
	nbTemps++;
}

/**
 * \brief constructeur avec paramètres,
 * 	      les valeurs passées non valides sont mises à zéro.
 * \param[in] p_heure >=0 et <24
 * \param[in] p_minute >=0 et <60
 * \param[in] p_seconde >=0 et <60
 */
Temps::Temps(int p_heure, int p_minute, int p_seconde)
{
	asgTemps(p_heure, p_minute, p_seconde);
	nbTemps++;
}

/**
 * \brief destructeur, nécessaire pour mettre à jour l'attribut de classe nbTemps
 */
Temps::~Temps()
{
	nbTemps--;
}

/**
 * \brief fonction accesseur récupérant l'heure
 * \return l'heure
 */
int Temps::reqHeure() const
{
	return m_heure;
}

/**
 * \brief fonction accesseur récupérant les minutes
 * \return les minutes
 */
int Temps::reqMinute() const
{
	return m_minute;
}

/**
 * \brief fonction accesseur récupérant les secondes
 * \return les secondes
 */
int Temps::reqSeconde() const
{
	return m_seconde;
}

/**
 * \brief fonction accesseur récupérant le nombre d'objets Temps instanciés
 * \return le nombre d'objets Temps instanciés
 */
int Temps::reqNbTemps()
{
	return nbTemps;
}

/**
 * \brief assigne l'attribut de l'heure avec la valeur passée en paramètre
 *        et si la valeur passée est invalide, m_heure est mis à 0.
 * \param[in] p_heure >=0 et <24
 */
void Temps::asgHeure(int p_heure)
{
	m_heure = (p_heure >= 0 && p_heure < 24) ? p_heure : 0;
}

/**
 * \brief assigne l'attribut des minutes avec la valeur passée en paramètre
 *        et si la valeur passée est invalide, m_minute est mis à 0.
 * \param[in] p_minute >=0 et <60
 */
void Temps::asgMinute(int p_minute)
{
	m_minute = (p_minute >= 0 && p_minute < 60) ? p_minute : 0;
}

/**
 * \brief assigne l'attribut des secondes avec la valeur passée en paramètre
 *        et si la valeur passée est invalide, m_seconde est mis à 0.
 * \param[in] p_seconde >=0 et <60
 */
void Temps::asgSeconde(int p_seconde)
{
	m_seconde = (p_seconde >= 0 && p_seconde < 60) ? p_seconde : 0;
}

/**
 * \brief méthode retournant une chaine contenant l'ensemble des attributs formatés.
 * \return un objet string
 */
std::string Temps::reqTempsFormate()
{
	ostringstream os;
	os << ((m_heure == 0 || m_heure == 12) ? 12 : m_heure % 12) << ":"
			<< (m_minute < 10 ? "0" : "") << m_minute << ":"
			<< (m_seconde < 10 ? "0" : "") << m_seconde
			<< (m_heure < 12 ? " AM" : " PM");
	return os.str();
}

/**
 * \brief méthode assignant les attributs de l'objet courant avec les valeurs passées en paramètre.
 *		Si les valeurs ne sont pas valides, l'attribut correspondant est mis à 0.
 * \param[in] p_heure >=0 et <24
 * \param[in] p_minute >=0 et <60
 * \param[in] p_seconde >=0 et <60
 */
void Temps::asgTemps(int p_heure, int p_minute, int p_seconde)
{
	asgHeure(p_heure);
	asgMinute(p_minute);
	asgSeconde(p_seconde);
}

/**
 * \brief Surcharge de l’opérateur << pour permettre 
 *        d’envoyer dans un flux de sortie ostream un objet Temps.
 * \param[in] p_os un flux de sortie.
 * \param[in] p_temps l'objet à sortir
 * \return un flux de sortie pour permettre les appels en cascade
 */
std::ostream & operator <<(std::ostream & p_os, Temps & p_temps)
{
	p_os << p_temps.reqTempsFormate();
	return p_os;
}

/**
 * \brief Incrémentation d'une seconde l'objet courant.
 */
void Temps::tic()
{
	asgSeconde(m_seconde + 1);
	if (m_seconde == 0)
	{
		asgMinute(m_minute + 1);
		if (m_minute == 0)
		{
			asgHeure(m_heure + 1);
		}
	}
}

} /* namespace labo6 */
