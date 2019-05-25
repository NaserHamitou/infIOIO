#ifndef GREENBULL_H
#define GREENBULL_H

#include"ObjetMagique.h"

class GreenBull : public ObjetMagique {

public :
<<<<<<< HEAD

	//Constructeur par defaut
	GreenBull();

	//Constructeur par param
	GreenBull(const std::string &nom, int bonus);

	/*methode utiliserSur 
	Param Creature& creature */
	void utiliserSur(Creature& creature) const;

	//operateur << surcharger
=======
	GreenBull();
	GreenBull(const std::string &nom, int bonus);

	void utiliserSur(Creature& creature) const;

>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
	friend std::ostream& operator<<(std::ostream& os, const GreenBull& potion);

};

#endif
