#include "Professeur.h"

Professeur::Professeur(const string& nom, const string& equipe) : Dresseur(nom, equipe)
{
	outilScientifique_ = nullptr;
}

Professeur::Professeur(const Professeur& prof) {
	nom_ = prof.nom_;
	equipe_ = prof.equipe_;
<<<<<<< HEAD
	if(prof.outilScientifique_ != nullptr)
		outilScientifique_ = new OutilScientifique(*prof.outilScientifique_);
	else
	{
		outilScientifique_ = nullptr;
	}
=======
	outilScientifique_ = new OutilScientifique(*prof.outilScientifique_);
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
	creatures_ = prof.creatures_;
}

Professeur::~Professeur() {
<<<<<<< HEAD
	delete outilScientifique_;
	outilScientifique_ = nullptr;
=======
		delete outilScientifique_;
		outilScientifique_ = nullptr;
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
}

void Professeur::modifierOutilScientifique(OutilScientifique* outil) {
	
	delete outilScientifique_;
	outilScientifique_ = nullptr;
	outilScientifique_ = new OutilScientifique(*outil);
}

void Professeur::soigner(Creature& creature) const {
	creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
	creature.modifierEnergie(creature.obtenirEnergieTotale());
}

Professeur& Professeur::operator=(const Professeur& prof) {

	if (this != &prof) {
		nom_ = prof.nom_;
		equipe_ = prof.equipe_;
		delete outilScientifique_;
		outilScientifique_ = new OutilScientifique(*prof.outilScientifique_);
	}

	return *this;

}

<<<<<<< HEAD
void Professeur::utiliserOutil(Creature& creature) const {
=======
void Professeur::utiliserOutil(Creature& creature) {
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
	outilScientifique_->utiliser(creature);
}

