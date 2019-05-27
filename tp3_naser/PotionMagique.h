#ifndef POTIONMAGIQUE_H
#define POTIONMAGIQUE_H

#include "ObjetMagique.h"

class PotionMagique : public ObjetMagique
{
public:
	//Constructeur par defaut
	PotionMagique();

	//Constructeur par param
	PotionMagique(const std::string &nom, int bonus);

	/*methode utiliserSur
	Param Creature& creature */
	void utiliserSur(Creature& creature) const;

	//operateur << surcharger
	friend std::ostream& operator<<(std::ostream& os, const PotionMagique& potion);


};

#endif