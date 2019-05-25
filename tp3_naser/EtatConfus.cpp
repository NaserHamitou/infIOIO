#include "EtatConfus.h"
#include <ctime>

EtatConfus::EtatConfus(const std::string& nom) : EtatCreature(nom){
	type_ = TypeEtat_confus;
}

EtatConfus::EtatConfus(const std::string& nom, unsigned int duree) : EtatCreature(nom, duree) {
	type_ = TypeEtat_confus;
}

bool EtatConfus::peutAttaquer() {
	return (rand() % 2);
}

void EtatConfus::appliquerEtat(Creature& creature) {
<<<<<<< HEAD

=======
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
	int probabilite = rand() % 3;

	if (probabilite == 2) {
		if (creature.obtenirPointDeVie() < 100) 
			creature.modifierPointDeVie(creature.obtenirPointDeVie() - 5);
		else
		{
			creature.modifierPointDeVie(creature.obtenirPointDeVie() - 0.05 * creature.obtenirPointDeVie());
		}
	}

<<<<<<< HEAD
	duree_ = duree_ - 1;
=======
	duree_--;
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
}

bool EtatConfus::estFini() {

<<<<<<< HEAD
	srand(time(NULL));
=======
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
	return (duree_ <= 0 || (rand() % 3) == 1);
}


std::ostream& operator<<(std::ostream& os, const EtatConfus& confus) {
<<<<<<< HEAD
	os << "etat : " << confus.obtenirNom() << " durera " << std::endl;
=======
	
	os << "La creature est dans une etat " << confus.obtenirNom() << std::endl;
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
	
	return os;
}