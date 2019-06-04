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

	virtual ~AttaqueMagique() = default;

	int obtenirDuree();

	void modifierDuree(int duree);

	virtual std::string obtenirTypeAttaque() const = 0;

	virtual void appliquerAttaque(Creature& creature) = 0;

	virtual bool estFini();

	virtual friend std::ostream& operator<<(std::ostream& os, const AttaqueMagique& attaqueM);

protected :

	unsigned int duree_;   

};

#endif
