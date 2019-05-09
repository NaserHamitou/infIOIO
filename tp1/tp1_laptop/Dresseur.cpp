#include "Dresseur.h"

Dresseur::Dresseur() {
	nom_ = "";
	creatures_ = nullptr;
	nombreCreatures_ = 0;
	nombreCreaturesMax_ = 2;
	objetMagique_ = ObjetMagique();
}

Dresseur::Dresseur(string& nom) {
	nom_ = nom;
}

Dresseur::~Dresseur() {
	for (int i = 0; i < nombreCreatures_; i++) {
		delete creatures_[i];
	}

	delete[] creatures_;
	creatures_ = nullptr;
}

string Dresseur::obtenirNom() {
	return nom_;
}

void Dresseur::modifierNom(string& nom){
	nom_ = nom;
}

ObjetMagique Dresseur::obtenirObjetMagique(){
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(ObjetMagique& objetMagique){
	objetMagique_ = objetMagique;
}

void Dresseur::utiliserObjetMagique(Creature* creature){
	creature->modifierPointDeVie(objetMagique_.obtenirBonus());
	creature->modifierEnergie(objetMagique_.obtenirBonus());
}


unsigned int Dresseur::obtenirNombreCreatures(){
	return nombreCreatures_;
}

Creature** Dresseur::obtenirCreatures(){
	return creatures_;
}

void Dresseur::modifierCreature(Creature** creatures){
	creatures_ = creatures;
}


bool Dresseur::ajouterCreature(Creature& creature){

	//verifie si on possede la creature 
	for (int i = 0; i < nombreCreatures_; i++) {
		if (creature.obtenirNom() == creatures_[i]->obtenirNom())
			return false;
	}

	//verifie si le tableau est rempli
	if (nombreCreatures_ == nombreCreaturesMax_) {

		//Creer un tableau qui a le double taille et on copie les elements dans ce nouveau tableau
		nombreCreaturesMax_ *= 2;
		Creature** listCreatures = new Creature*[nombreCreaturesMax_];
		for (int i = 0; i < nombreCreatures_; i++)
			listCreatures[i] = creatures_[i];

		listCreatures[nombreCreatures_] = &creature;
		delete[] creatures_;
		creatures_ = listCreatures;
	}

	else{
		creatures_[nombreCreatures_] = &creature;
	}

	nombreCreatures_++;
	return true;
	
}

bool Dresseur::retirerCreature(string& nom){

	for (unsigned i = 0; i < nombreCreatures_; i++) {
		if (creatures_[i]->obtenirNom() == nom) {
			delete creatures_[i];
			return true;
		}
		else
		{
			return false;
		}
	}
	

}

void Dresseur::affichage(){

	cout << nom_ << "possede " << nombreCreatures_ << " creatures." << endl;
}
