#ifndef ETAT_EMPOISONNE_H
#define ETAT_EMPOISONNE_H

#include "EtatCreature.h"

class EtatEmpoisonne : public EtatCreature {

public :

<<<<<<< HEAD
	//Constructeur par parametre
	EtatEmpoisonne(const std::string& nom);

	//Constructeur par parametre
	EtatEmpoisonne(const std::string& nom, unsigned int duree);

	/*Methode appliquerEtat
	Param Creature& creature */
	void appliquerEtat(Creature& creature);

	//Methode estFini retourn boolean
=======
	EtatEmpoisonne(const std::string& nom);

	EtatEmpoisonne(const std::string& nom, unsigned int duree);

	void appliquerEtat(Creature& creature);
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
	bool estFini();

};

<<<<<<< HEAD
//operateur << surcharger
=======
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
std::ostream& operator<<(std::ostream& os, const EtatEmpoisonne& empoisonne);

#endif
