#include "EtatConfus.h"

EtatConfus::EtatConfus(const std::string& nom) : EtatCreature(nom){
	type_ = TypeEtat_confus;
}

EtatConfus::EtatConfus(const std::string& nom, unsigned int duree) : EtatCreature(nom, duree) {
	type_ = TypeEtat_confus;
}

