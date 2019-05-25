#ifndef POTIONMAGIQUE_H
#define POTIONMAGIQUE_H

#include "ObjetMagique.h"

class PotionMagique : public ObjetMagique
{
public:
<<<<<<< HEAD
	//Constructeur par defaut
	PotionMagique();

	//Constructeur par param
	PotionMagique(const std::string &nom, int bonus);

	/*methode utiliserSur
	Param Creature& creature */
	void utiliserSur(Creature& creature) const;

	//operateur << surcharger
=======
	PotionMagique();
	PotionMagique(const std::string &nom, int bonus);

	void utiliserSur(Creature& creature) const;

>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
	friend std::ostream& operator<<(std::ostream& os, const PotionMagique& potion);


};

#endif