#ifndef ETAT_CONFUS_H
#define ETAT_CONFUS_H

#include "EtatCreature.h"

class EtatConfus : public EtatCreature{

public:
	EtatConfus(const std::string& nom);
	EtatConfus(const std::string& nom, unsigned int duree);

	bool peutAttaquer();
	void appliquerEtat(Creature& creature);
	bool estFini();
	   
};

std::ostream& operator<<(std::ostream& os, const EtatConfus& confus);

#endif