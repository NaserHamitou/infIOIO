#ifndef ETAT_EMPOISONNE_H
#define ETAT_EMPOISONNE_H

#include "EtatCreature.h"

class EtatEmpoisonne : public EtatCreature {

public :

	EtatEmpoisonne(const std::string& nom);

	EtatEmpoisonne(const std::string& nom, unsigned int duree);

	void appliquerEtat(Creature& creature);
	bool estFini();

};

std::ostream& operator<<(std::ostream& os, const EtatEmpoisonne& empoisonne);

#endif
