#ifndef GREENBULL_H
#define GREENBULL_H

#include"ObjetMagique.h"

class GreenBull : public ObjetMagique {

public :

	//Constructeur par defaut
	GreenBull();

	//Constructeur par param
	GreenBull(const std::string &nom, int bonus);

	/*methode utiliserSur 
	Param Creature& creature */
	void utiliserSur(Creature& creature) const;

	//operateur << surcharger
	friend std::ostream& operator<<(std::ostream& os, const GreenBull& potion);

};

#endif
