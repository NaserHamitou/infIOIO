#ifndef ATTAQUEMAGIQUE_H
#define ATTAQUEMAGIQUE_H

#include <iostream>
#include <string>

class AttaqueMagique
{

public :

	AttaqueMagique(int duree);

	~AttaqueMagique();

	int obtenirDuree();

	void modifierDuree(int duree);

	std::string obtenirTypeAttaque() const;

	virtual void appliquerAttaque() = 0;

	bool estFini();

	friend std::ostream& operator<<(std::ostream& os, const AttaqueMagique& attaqueM);

protected :

	int duree_;   

};

#endif
