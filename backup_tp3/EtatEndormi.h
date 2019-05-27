#ifndef ETAT_ENDORMI_H
#define ETAT_ENDORMI_H

#include "EtatCreature.h"

class EtatEndormi : public EtatCreature {

public :
	EtatEndormi(const std::string& nom);
	EtatEndormi(const std::string& nom, unsigned int duree);

	bool peutAttaquer();
	void appliquerEtat(Creature& creature);
	bool estFini();

};

std::ostream& operator<<(std::ostream& os, const EtatEndormi& endormi);

#endif
