/**
 * \file NombreRationnelPrincipal.h
 * \author etudiant
 * \version 0.1
 * \date 2014-10-10
 */

#ifndef NOMBRERATIONNEL_H_
#define NOMBRERATIONNEL_H_

namespace labo6
{

typedef long long verylong;

class NombreRationnel
{
public:

	NombreRationnel( int = 0, int = 1 );

    // Surcharge des opérateurs "+, -, *, /"
    NombreRationnel operator+( const NombreRationnel& );
    NombreRationnel operator-( const NombreRationnel& );
    NombreRationnel operator*( const NombreRationnel& );
    NombreRationnel operator/( const NombreRationnel& );

    // accésseur, pas de modification de la valeur des attributs
    bool operator>( const NombreRationnel& ) const;
    bool operator<( const NombreRationnel& ) const;
    bool operator>=( const NombreRationnel& ) const;
    bool operator<=( const NombreRationnel& ) const;
    bool operator==( const NombreRationnel& ) const;
    bool operator!=( const NombreRationnel& ) const;

    void afficherRationnel() const;

private:
    int m_numerateur;
    int m_denominateur;
    void reduction();  // pour la réduction des fractions
};

} /* namespace labo6 */

#endif /* NOMBRERATIONNEL_H_ */
