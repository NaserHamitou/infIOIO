#include "ObjetMagique.h"

ObjetMagique::ObjetMagique(){}

ObjetMagique::ObjetMagique(const string &nom, int bonus) {
	nom_ = nom;
	bonus_ = bonus;
}

ObjetMagique::~ObjetMagique(){}

string ObjetMagique::obtenirNom() {
	return nom_;
}

int ObjetMagique::obtenirBonus() {
	return bonus_;
}

void ObjetMagique::modifierNom(string& nom) {
	nom_ = nom;
}

void ObjetMagique::modifierBonus(int bonus) {
	bonus_ = bonus;
}

void ObjetMagique::affichage() {
	cout << "l'objet " << nom_ << " fournit un bonus de " << bonus_ << endl;
}
