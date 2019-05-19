#ifndef DRESSEUR_H
#define DRESSEUR_H

#include<vector>
#include <string>
#include "Creature.h"

#define MAX_NOMBRE_CREATURES 2

class Dresseur
{
public:
	Dresseur(); // A MODIFIER... (si necessaire)
	Dresseur(const string& nom, const string& equipe); // A MODIFIER... (si necessaire)
	~Dresseur(); // A MODIFIER... (si necessaire)

	string obtenirNom() const;
	void modifierNom(const string& nom);
	
	unsigned int obtenirNombreCreatures() const; // A MODIFIER... (si necessaire)

	Creature* obtenirCreatures(const string& nom) const; // A MODIFIER... (si necessaire)
	void modifierCreature(vector<Creature*> creatures); // A MODIFIER... (si necessaire)              /* !! NOT SURE !! */

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