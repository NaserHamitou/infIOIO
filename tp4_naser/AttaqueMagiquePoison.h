#ifndef ATTAQUEMAGIQUEPOISON_H
#define ATTAQUEMAGIQUEPOISON_H

#include "Creature.h"
#include "AttaqueMagique.h"

class AttaqueMagiquePoison : public AttaqueMagique
{

public :

	//constructeur par defaut
	AttaqueMagiquePoison();

	//constructeur par param
	AttaqueMagiquePoison(int duree);

	//destructeur
	virtual ~AttaqueMagiquePoison();

	/* methode obtenirTypeAttaque
	retourne un string */
	std::string obtenirTypeAttaque() const override;

	/* methode appliquerAttaque
	Param Creature& creature */
	void appliquerAttaque(Creature& creature) override;

	bool estFini() override;



};

#endif
