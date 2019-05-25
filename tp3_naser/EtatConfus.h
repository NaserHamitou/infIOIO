#ifndef ETAT_CONFUS_H
#define ETAT_CONFUS_H

#include "EtatCreature.h"

class EtatConfus : public EtatCreature{

public:

	//Constructeur par parametre
	EtatConfus(const std::string& nom);

	//Constructeur par parametre
	EtatConfus(const std::string& nom, unsigned int duree);

<<<<<<< HEAD
	/*Methode peutAttaquer
	retourn boolean */
	bool peutAttaquer();

	/*Methode appliquerEtat
	Param Creature& creature */
	void appliquerEtat(Creature& creature);

	//Methode estFini retourn boolean
	bool estFini();

private :

	int duree_;
	   
};

//operateur << surcharger
=======
	bool peutAttaquer();
	void appliquerEtat(Creature& creature);
	bool estFini();
	   
};

>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
std::ostream& operator<<(std::ostream& os, const EtatConfus& confus);

#endif