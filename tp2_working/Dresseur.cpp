#include "Dresseur.h"
#include <iostream>

Dresseur::Dresseur() :nom_(""), objetMagique_(ObjetMagique()), equipe_("") {
	for (int i = 0; i < creatures_.size(); i++)
		creatures_[i] = nullptr;
}; // A MODIFIER... (si necessaire)

Dresseur::Dresseur(const string& nom, const string& equipe): nom_(nom), objetMagique_(ObjetMagique()), equipe_(equipe)
{
	for (int i = 0; i < creatures_.size(); i++)
		creatures_[i] = nullptr;
	// A MODIFIER... (si necessaire)
}


Dresseur::~Dresseur() // A MODIFIER... (si necessaire)
{
	creatures_.clear();
}

string Dresseur::obtenirNom() const
{
	return nom_;
}

void Dresseur::modifierNom(const string& nom)
{
	nom_ = nom;
}

unsigned int Dresseur::obtenirNombreCreatures() const
{
	return creatures_.size();
}

Creature* Dresseur::obtenirCreatures(const string& nom) const // A MODIFIER... (si necessaire)
{
	for (int i = 0; i < creatures_.size(); i++) {
		if (*creatures_[i] == nom)
			return creatures_[i];
	}

}

void Dresseur::modifierCreature(vector<Creature*> creatures) // A MODIFIER... (si necessaire)
{
	creatures_ = creatures;

	/*for (int i = 0; i < MAX_NOMBRE_CREATURES ; i++) 
		*creatures_[i] = *creatures[i];*/
}

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

void Dresseur::utiliserObjetMagique(Creature* creature)
{

	if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= objetMagique_.obtenirBonus()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}
	if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > objetMagique_.obtenirBonus()) {
		creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}
}

bool Dresseur::ajouterCreature(Creature* creature) // A MODIFIER... (si necessaire)
{

	if (creatures_.size() < MAX_NOMBRE_CREATURES) {
		for (unsigned int i = 0; i < creatures_.size(); i++) {
			if (*creatures_[i] == *creature)
				return false;
		}
	}
	
	
	creatures_.push_back(creature);
	cout << nom_ << " possede " << creature->obtenirNom() << endl;
	return true;

}

bool Dresseur::enleverCreature(const string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < creatures_.size(); i++) {
		if (creatures_[i]->obtenirNom() == nom) {
			creatures_[i] = creatures_[creatures_.size() - 1];
			creatures_.pop_back();
			return true;
		}
	}
	return false;
}

ostream &operator<<(ostream& os, const Dresseur& dresseur) {
	os << dresseur.nom_ << " possede " << dresseur.creatures_.size() << " creature(s) et appartient a l'equipe " << dresseur.equipe_ << endl;
	return os;
 }

bool Dresseur::operator==(const Dresseur& dresseur) const {

	int nbrCreaturesIdentique = 0;

	for (int i = 0; i < creatures_.size(); i++) {
		for (int j = 0; j < dresseur.creatures_.size(); j++) {
			if (creatures_[i] == dresseur.creatures_[j])
				nbrCreaturesIdentique++;
		}
	}

	return(creatures_.size() == nbrCreaturesIdentique && creatures_.size() == dresseur.creatures_.size());
}

bool Dresseur::operator==(const string& nom) const {
	return (nom_ == nom);
}

bool operator==(const string& nom, const Dresseur& dresseur) {
	return(nom == dresseur.nom_);
}




// ___TP2___
