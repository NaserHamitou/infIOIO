#ifndef ETAT_CONFUS_H
#define ETAT_CONFUS_H

#include "EtatCreature.h"

class EtatConfus : public EtatCreature{

public:

	//Constructeur par parametre
	EtatConfus(const std::string& nom);

	//Constructeur par parametre
	EtatConfus(const std::string& nom, unsigned int duree);

	/*Methode peutAttaquer
	retourn boolean */
	bool peutAttaquer();

	/*Methode appliquerEtat
	Param Creature& creature */
	void appliquerEtat(Creature& creature);

	//Methode estFini retourn boolean
	bool estFini();

	//operateur << surcharger
	friend std::ostream& operator<<(std::ostream& os, const EtatConfus& confus);

private :

	int duree_;
	   
};


#endif