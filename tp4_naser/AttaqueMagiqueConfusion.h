#ifndef ATTAQUEMAGIQUECONFUSION_H
#define ATTAQUEMAGIQUECONFUSION_H

#include "Creature.h"
#include "AttaqueMagique.h"

class AttaqueMagiqueConfusion : public AttaqueMagique
{
public :
	//constructeur par defaut
	AttaqueMagiqueConfusion();

	//constructeur par param
	AttaqueMagiqueConfusion(int duree);

	//destructeur
	virtual ~AttaqueMagiqueConfusion();

	/* methode obtenirTypeAttaque
	retourne un string */
	std::string obtenirTypeAttaque() const override;

	/* methode appliquerAttaque
	Param Creature& creature */
	void appliquerAttaque(Creature& creature) override;

	/* methode estFini
	retourne un bool */
	bool estFini() override;


};

#endif