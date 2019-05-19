#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include<vector>
#include "ObjetMagique.h"
#include "Pouvoir.h"

class Creature
{
public:
	//Constructeur par defaut
	Creature(); // A MODIFIER... (si necessaire)

	//Constructeur par parametre
	Creature(const string& nom, unsigned int attaque, 
		unsigned int defense, unsigned int pointDeVie, unsigned int energie); // A COMPLETER... (si necessaire)

	//Constructeur par copy
	Creature(const Creature& creature); 

	//Destructeur 
	~Creature(); // A MODIFIER... (si necessaire)
	
	string obtenirNom() const;
	unsigned int obtenirAttaque() const;
	unsigned int obtenirDefense() const;
	unsigned int obtenirPointDeVie() const;
	unsigned int obtenirPointDeVieTotal() const;
	unsigned int obtenirEnergie() const;
	unsigned int obtenirEnergieTotale() const;
	unsigned int obtenirExperience() const;
	unsigned int obtenirExperienceNecessaire() const;
	unsigned int obtenirNiveau() const;
	vector<Pouvoir*> obtenirPouvoirs() const; // A MODIFIER... (si necessaire)    /*!! NOT SURE !!*/

	void apprendrePouvoir(const Pouvoir& pouvoir);   /* ??? bool ou void ???*/ 
	void oublierPouvoir(Pouvoir* pouvoir);           /*???? prend en parametre: un pointeur -> selon le main ou une reference -> selon la surcharge de == ????*/

	void attaquer(Pouvoir& pouvoir, Creature& creature);// A MODIFIER... (si necessaire)
	int experienceGagnee(const Creature& creature);
	
	void modifierAttaque(unsigned int attaque);
	void modifierDefense(unsigned int defense);
	void modifierPointDeVie(unsigned int pointDeVie);
	void modifierEnergie(unsigned int energie);
	void modifierExperience(unsigned int experience);
	void modifierNiveau(unsigned int niveau);
	void modifierPouvoirs(const vector<Pouvoir*>& pouvoirs); // A MODIFIER... (si necessaire)

	/* operateur surcharge ==  
	Param Creature& creature
	retourne boolean */
	bool operator==(const Creature& creature) const;

	/* operateur surcharge == 
	Param string& nom 
	retourne boolean */
	bool operator==(const string& nom) const;

	/*operateur surcharge == 
	Param string& nom
	Parm Creature& creature 
	retourne boolean */
	friend bool operator==(const string& nom, const Creature& creature);

	/*operateur surcharhe <<
	Param ostream os
	Param Creature& creature 
	retourne un type ostream */
	friend ostream &operator<<(ostream& os, const Creature& creature);

	// _________TP2___________

private:

	string nom_;
	unsigned int attaque_;
	unsigned int defense_;
	unsigned int pointDeVie_;
	unsigned int pointDeVieTotal_;
	unsigned int energie_;
	unsigned int energieTotal_;
	unsigned int experience_;
	unsigned int experienceNecessaire_;
	unsigned int niveau_;
	vector<Pouvoir*> pouvoirs_
	
	// _________TP2___________
	
};

#endif