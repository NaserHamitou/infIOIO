#include "PolyLand.h"

Pouvoir::Pouvoir() {
	nom_ = "";
	nombreDeDegat_ = 0;
	manaNecessaire_ = 0;
}

Pouvoir::Pouvoir(const string& nom,
	unsigned int nombreDeDegat, unsigned int manaNecessaire) {
	nom_ = nom;
	nombreDeDegat_ = nombreDeDegat;
	manaNecessaire_ = manaNecessaire;
}

Pouvoir::~Pouvoir(){}

unsigned int Pouvoir::obtenirNombreDeDegat(){
	return nombreDeDegat_;
}

unsigned int Pouvoir::obtenirManaNecessaire() {
	return manaNecessaire_;
}

string Pouvoir::obtenirNom() {
	return nom_;
}

void Pouvoir::modifierNombreDeDegat(unsigned int nombreDegat) { nombreDeDegat_ = nombreDegat; }

void Pouvoir::modifierManaNecessarie(unsigned int manaNecessaire) { manaNecessaire_ = manaNecessaire; }

void Pouvoir::modifierNom(string& nom) { nom_ = nom; }

void Pouvoir::description() {
	cout << "Son pouvoir est : " << nom_ << " necessite " << manaNecessaire_ << " d'energie et inflige " << nombreDeDegat_ << " degats" << endl;
}