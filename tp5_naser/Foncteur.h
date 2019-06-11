#ifndef  FRONTEUR
#define  FRONTEUR

#include "Dresseur.h"
#include <string>
#include <stdlib.h>

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 6

//Froncteur permettant d'obtenir l'attaque de la créature passée en argument
class FoncteurObtenirAttaqueCreature
{
public:
    FoncteurObtenirAttaqueCreature() {}
    ~FoncteurObtenirAttaqueCreature() {}

    unsigned int operator() (const Creature* creature) const {
        return creature->obtenirAttaque();
    }
};

class FoncteurComparerCreatures
{
public :
	FoncteurComparerCreatures() {}
	~FoncteurComparerCreatures() {}

	bool operator() (const Creature* creature1, const Creature* creature2) const {
		return creature1->obtenirAttaque() < creature2->obtenirAttaque();
	}

};

class FoncteurComparerDresseurs
{
public:
	FoncteurComparerDresseurs() {}
	~FoncteurComparerDresseurs() {}

	bool operator() (const Dresseur* dresseur1, const Dresseur* dresseur2) const {
		return dresseur1->obtenirNom() < dresseur2->obtenirNom();
	}
};

class FoncteurComparerPouvoirs
{
public :
	FoncteurComparerPouvoirs() {}
	~FoncteurComparerPouvoirs() {}

	bool operator() (const Pouvoir* pouvoir1, const Pouvoir* pouvoir2) const {
		return pouvoir1->obtenirNombreDeDegat() < pouvoir2->obtenirNombreDeDegat();
	}

};

class FoncteurCreaturesDeMemeNom
{
public:
	FoncteurCreaturesDeMemeNom() {}
	FoncteurCreaturesDeMemeNom(std::string nom) :nomCreature_(nom){}
	~FoncteurCreaturesDeMemeNom() {}

	bool operator() (const Creature* creature) const {
		return creature->obtenirNom() == nomCreature_;
 	}

private :
	std::string nomCreature_;
};

class FoncteurEgalCreatures
{
public:
	FoncteurEgalCreatures(){}
	~FoncteurEgalCreatures(){}

	bool operator() (const Creature* creature) const {
		return(*creature_ == *creature);
	}



private :
	Creature* creature_;

};

class FoncteurCreatureVie
{
public:
	FoncteurCreatureVie() {}
	FoncteurCreatureVie(int min, int max) :vieMax_(max), vieMin_(min) { compteur_ = 0; }
	~FoncteurCreatureVie() {}

	int obtenirCompteur() const { return compteur_; }

	void operator() (Creature* creature){
		if (vieMin_ <= creature->obtenirPointDeVie() + 1 && creature->obtenirPointDeVie() + 1 >= vieMax_)
			creature->modifierPointDeVie(creature->obtenirPointDeVie() + 1);
	}

private:
	int vieMin_;
	int vieMax_;
	int compteur_;
};

class FoncteurGenerateurNombresAlea
{
public:
	FoncteurGenerateurNombresAlea() : borneMin_(RAND_MIN_DEFAUT), borneMax_(RAND_MAX_DEFAUT) {}
	FoncteurGenerateurNombresAlea(int min, int max) : borneMin_(min), borneMax_(max){}

	int operator()() const {
		srand(time(NULL));
		return (rand() % (borneMax_- borneMin_ + 1) + borneMin_);
	}

private:
	int borneMin_;
	int borneMax_;
};

#endif