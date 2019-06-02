#ifndef ATTAQUEMAGIQUEPOISON_H
#define ATTAQUEMAGIQUEPOISON_H

#include "AttaqueMagique.h"

class AttaqueMagiquePoison : public AttaqueMagique
{

public :

	//constructeur par defaut
	AttaqueMagiquePoison();

	//constructeur par param
	AttaqueMagiquePoison(int duree);

	//destructeur
	~AttaqueMagiquePoison();

	/* methode obtenirTypeAttaque
	retourne un string */
	std::string obtenirTypeAttaque() const;

	/* methode appliquerAttaque
	Param Creature& creature */
	void appliquerAttaque(Creature& creature);

	bool estFini();



};

#endif
