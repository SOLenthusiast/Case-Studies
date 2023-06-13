/**
 * \file Temps.h
 * \brief Prototype de la classe Temps
 * \author etudiant
 * \version 0.1
 * \date 2014-10-10
 */

#ifndef TEMPS_H_
#define TEMPS_H_

#include "Temps.h"

#include <string>

namespace labo6 {

/**
 * \class Temps
 * \brief Classe Temps permettant de modéliser les objets temps
 */
class Temps {
public:
	friend std::ostream& operator<<(std::ostream&, Temps&);

	Temps(); // constructeur par défaut
	Temps(int p_heure, int p_minute, int p_seconde); // construsteur avec paramètre

	~Temps(); //destructeur

	//Accesseurs
	int reqHeure() const; //getHeure() ==reqHeure()
	int reqMinute() const;
	int reqSeconde() const;
	std::string reqTempsFormate();
	static int reqNbTemps();  //membre static

	//Mutateurs
	void asgHeure(int p_heure);  // setHeure(int heure) == asgHeure(int heure)
	void asgMinute(int p_minute);
	void asgSeconde(int p_seconde);
	void asgTemps(int p_heure, int p_minute, int p_seconde);

	//méthode tic
	void tic();

private:
	int m_heure; // 0 - 23
	int m_minute; // 0 - 59
	int m_seconde; // 0 - 59
	static int nbTemps;

};

} /* namespace labo6 */

#endif /* TEMPS_H_ */
