#ifndef ATTAQUEMAGIQUECONFUSION_H
#define ATTAQUEMAGIQUECONFUSION_H

#include "AttaqueMagique.h"

class AttaqueMagiqueConfusion : public AttaqueMagique
{
public :

	AttaqueMagiqueConfusion();

	AttaqueMagiqueConfusion(int duree);

	virtual ~AttaqueMagiqueConfusion();

	std::string obtenirTypeAttaque() const override;

	void appliquerAttaque(Creature& creature) override;

	bool estFini() override;


};

#endif