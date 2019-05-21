#ifndef DRESSEUR_H
#define DRESSEUR_H

#include<vector>
#include <string>
#include "Creature.h"

#define MAX_NOMBRE_CREATURES 2

class Dresseur
{
public:
	
	//constructeur par defaut 
	Dresseur(); // A MODIFIER... (si necessaire)

	//constructeur par parametre
	Dresseur(const string& nom, const string& equipe); // A MODIFIER... (si necessaire)

	//Destructeur
	~Dresseur(); // A MODIFIER... (si necessaire)

	/*Methode obtenir nom 
	retourne un string nom_ */
	string obtenirNom() const;

	/*Methode modifierNom
	Param string& nom */
	void modifierNom(const string& nom);
	
	/*Methode obtenirNombreCreatures
	Retourne int nombreCreatures_ */
	unsigned int obtenirNombreCreatures() const; // A MODIFIER... (si necessaire)

	/*Methode obtenirCreatures 
	Param string& nom
	Retourne Creatures* */
	Creature* obtenirCreatures(const string& nom) const; // A MODIFIER... (si necessaire)

	/*Methode modifierCreature 
	Param vector<Creature*> creature */
	void modifierCreature(vector<Creature*> creatures); // A MODIFIER... (si necessaire)              /* !! NOT SURE !! */

	/*Methode obtenirObjetMagique 
	retourne ObjetMagique */
	ObjetMagique obtenirObjetMagique() const;


	void modifierObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);
	
	bool ajouterCreature(Creature* creature); // A MODIFIER... (si necessaire)            /* RE-CHECK */
	bool enleverCreature(const string& nom); // A MODIFIER... (si necessaire)                   /* RE-CHECK */

	friend ostream &operator<<(ostream& os, const Dresseur &dresseur);

	bool operator==(const Dresseur& dresseur) const;

	bool operator==(const string& nom) const;

	friend bool operator==(const string& nom, const Dresseur& dresseur);

private:
	string nom_;
	ObjetMagique objetMagique_;
	vector<Creature*> creatures_;
	string equipe_;

	// ___TP2____


};

#endif