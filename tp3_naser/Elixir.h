#ifndef ELIXIR_H
#define ELIXIR_H

#include "PotionMagique.h"

class Elixir : public PotionMagique {

public :

<<<<<<< HEAD
	//Constructeur par defaut
	Elixir();

	//Constructeur par parametre
	Elixir(const std::string &nom, int bonus);

	/* methode utiliserSur 
	Param Creature& creature */
	void utiliserSur(Creature& creature) const;

	//Operateur << surcharger
=======
	Elixir();
	Elixir(const std::string &nom, int bonus);

	void utiliserSur(Creature& creature) const;

>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
	friend std::ostream& operator<<(std::ostream& os, const Elixir& elixir);

};

#endif
