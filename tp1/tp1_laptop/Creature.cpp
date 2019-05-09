#include"Creature.h"

Creature::Creature() {
	nom_ = "";
	attaque_ = 0;
	defense_ = 0;
	pointDeVie_ = 0;
	pointDeVieTotal_ = 0;
	energie_ = 0;
	energieTotal_ = 0;
	experience_ = 0;
	experienceNecessaire_ = 0;
	niveau_ = 0;
	pouvoir_ = Pouvoir();

}

Creature::Creature(string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie, Pouvoir pouvoir) {

	nom_ = nom;
	attaque_ = attaque;
	defense_ = defense;
	pointDeVie_ = pointDeVie;
	pointDeVieTotal_ = pointDeVie;
	energie_ = energie;
	energieTotal_ = energie;
	experienceNecessaire_ = 100;
	niveau_ = 0;
	pouvoir_ = pouvoir;

}

Creature::~Creature(){}

string Creature::obtenirNom(){
	return nom_;

}

unsigned int Creature::obtenirDefense(){
	return defense_;
}

unsigned int Creature::obtenirPointDeVie() {
	return pointDeVie_;
}

unsigned int Creature::obtenirPointDeVieTotal() {
	return pointDeVieTotal_;
}

unsigned int Creature::obtenirEnergie() {
	return energie_;
}

unsigned int Creature::obtenirEnergieTotale(){
	return energieTotal_;
}

unsigned int Creature::obtenirExperience() {
	return experience_;
}

unsigned int Creature::obtenirExperienceNecessaire() {
	return experienceNecessaire_;
}

unsigned int Creature::obtenirNiveau() {
	return niveau_;
}

unsigned int Creature::obtenirAttaque() {
	return attaque_;
}

Pouvoir Creature::obtenirPouvoir() {
	return pouvoir_;
}

void Creature::attaquer(Creature & creature)
{
	if (energie_ >= pouvoir_.obtenirManaNecessaire()) {
		if (creature.obtenirPointDeVie() >= 0) {
			//Calcul du nombre de degat selon une formule 
			unsigned int degat = (pouvoir_.obtenirNombreDeDegat())* (attaque_ / 2 - creature.defense_);
			int tentative = rand() % 6;
			//l'attaque rate une fois sur 6
			if (tentative != 3) {
				cout << nom_ << " lance " << pouvoir_.obtenirNom() << " qui inflige " << degat << " degat a " << creature.obtenirNom() << endl;
				if (degat > creature.obtenirPointDeVie()) {
					creature.modifierPointDeVie(0);
					int xp = experienceGagnee(creature);
					cout << nom_ << " a gagné " << xp << " XP" << endl;
				}
				else
					creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
				cout << creature.obtenirNom() << " a encore " << creature.obtenirPointDeVie() << " PV" << endl;
				energie_ -= pouvoir_.obtenirManaNecessaire();
			}
			else {
				cout << "Attaque " << pouvoir_.obtenirNom() << " a échouée" << endl;
			}
		}
		else
			cout << "Vous deja avez vaincu " << creature.obtenirNom() << endl;
	}

}

int Creature::experienceGagnee(Creature& creature)
{
	if (creature.obtenirPointDeVie() <= 0) {
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirAttaque() + 5 - attaque_) * (creature.obtenirDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) {
			//Cas ou la creature va monter d'un niveau
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else {
			//Sinon elle recupère juste de l'expérience
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}