#include "Professeur.h"

Professeur::Professeur(const string& nom, const string& equipe) : Dresseur(nom, equipe)
{
	outilScientifique_ = nullptr;
}

Professeur::Professeur(const Professeur& prof) {
	nom_ = prof.nom_;
	equipe_ = prof.equipe_;
	if(prof.outilScientifique_ != nullptr)
		outilScientifique_ = new OutilScientifique(*prof.outilScientifique_);
	else
	{
		outilScientifique_ = nullptr;
	}
	creatures_ = prof.creatures_;
}

Professeur::~Professeur() {
	delete outilScientifique_;
	outilScientifique_ = nullptr;
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

void Professeur::utiliserOutil(Creature& creature) const {
	outilScientifique_->utiliser(creature);
}

ostream& operator<<(ostream& os, const Professeur& prof) {
	os << prof.nom_ << " possede " << prof.creatures_.size() <<
		" creature(s) et appartient a l'equipe " << prof.equipe_ << std::endl;
	os << "Il possede un outil : " << *(prof.outilScientifique_) << endl;
	return os;
}