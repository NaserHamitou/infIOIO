#ifndef ELIXIR_H
#define ELIXIR_H

#include "PotionMagique.h"

class Elixir : public PotionMagique {

public :

	//Constructeur par defaut
	Elixir();

	//Constructeur par parametre
	Elixir(const std::string &nom, int bonus);

	/* methode utiliserSur 
	Param Creature& creature */
	void utiliserSur(Creature& creature) const;

	//Operateur << surcharger
	friend std::ostream& operator<<(std::ostream& os, const Elixir& elixir);

};

#endif
