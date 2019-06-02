#ifndef ATTAQUEMAGIQUE_H
#define ATTAQUEMAGIQUE_H

#include <iostream>
#include <string>
#include "Creature.h"

class AttaqueMagique
{

public :

	AttaqueMagique();

	AttaqueMagique(int duree);

	~AttaqueMagique();

	int obtenirDuree();

	void modifierDuree(int duree);

	std::string obtenirTypeAttaque() const;

	virtual void appliquerAttaque(Creature& creature) = 0;

	bool estFini();

	friend std::ostream& operator<<(std::ostream& os, const AttaqueMagique& attaqueM);

protected :

	unsigned int duree_;   

};

#endif
