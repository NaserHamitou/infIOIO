#ifndef ETAT_EMPOISONNE_H
#define ETAT_EMPOISONNE_H

#include "EtatCreature.h"

class EtatEmpoisonne : public EtatCreature {

public :

	//Constructeur par parametre
	EtatEmpoisonne(const std::string& nom);

	//Constructeur par parametre
	EtatEmpoisonne(const std::string& nom, unsigned int duree);

	/*Methode appliquerEtat
	Param Creature& creature */
	void appliquerEtat(Creature& creature);

	//Methode estFini retourn boolean
	bool estFini();

	//operateur << surcharger
	friend std::ostream& operator<<(std::ostream& os, const EtatEmpoisonne& empoisonne);

};

#endif
