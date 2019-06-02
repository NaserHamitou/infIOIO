#ifndef ATTAQUEMAGIQUECONFUSION_H
#define ATTAQUEMAGIQUECONFUSION_H

#include "AttaqueMagique.h"

class AttaqueMagiqueConfusion :public AttaqueMagique
{
public :

	AttaqueMagiqueConfusion();

	AttaqueMagiqueConfusion(int duree);

	~AttaqueMagiqueConfusion();

	std::string obtenirTypeAttaque();

	void appliquerAttaque(Creature& creature);

	bool estFini();


};

#endif