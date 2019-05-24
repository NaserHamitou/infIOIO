#include "EtatConfus.h"

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
	int probabilite = rand() % 3;

	if (probabilite == 2) {
		if (creature.obtenirPointDeVie() < 100) 
			creature.modifierPointDeVie(creature.obtenirPointDeVie() - 5);
		else
		{
			creature.modifierPointDeVie(creature.obtenirPointDeVie() - 0.05 * creature.obtenirPointDeVie());
		}
	}

	duree_--;
}

bool EtatConfus::estFini() {

	return (duree_ <= 0 || (rand() % 3) == 1);
}


std::ostream& operator<<(std::ostream& os, const EtatConfus& confus) {
	
	os << "La creature est dans une etat " << confus.obtenirNom() << std::endl;
	
	return os;
}