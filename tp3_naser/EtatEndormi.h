#ifndef ETAT_ENDORMI_H
#define ETAT_ENDORMI_H

#include "EtatCreature.h"

class EtatEndormi : public EtatCreature {

public :
<<<<<<< HEAD

	//Constructeur par parametre
	EtatEndormi(const std::string& nom);

	//Constructeur par parametre
	EtatEndormi(const std::string& nom, unsigned int duree);

	/*Methode peutAttaquer
	retourn boolean */
	bool peutAttaquer() const;

	/*Methode appliquerEtat
	Param Creature& creature */
	void appliquerEtat(Creature& creature);

	//Methode estFini retourn boolean
	bool estFini();

	//operateur << surcharger
	friend std::ostream& operator<<(std::ostream& os, const EtatEndormi& endormi);

private :

	int duree_;

};

=======
	EtatEndormi(const std::string& nom);
	EtatEndormi(const std::string& nom, unsigned int duree);

	bool peutAttaquer();
	void appliquerEtat(Creature& creature);
	bool estFini();

};

std::ostream& operator<<(std::ostream& os, const EtatEndormi& endormi);
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df

#endif
