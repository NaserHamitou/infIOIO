#ifndef POLYLAND_H
#define POLYLAND_H

#include "Dresseur.h"
#include "Creature.h"
#define MAX_DRESSEURS 100
#define MAX_CREATURES 1000
#define MAX_OBJET_MAGIQUE 100
#define MAX_POUVOIRS 10

class PolyLand
{
public:
	PolyLand(); // A MODIFIER... (si necessaire)
	~PolyLand(); // A MODIFIER... (si necessaire)

	vector<Creature*> getTab() const;
	
	bool ajouterDresseur(Dresseur* dresseur); // A MODIFIER... (si necessaire)
	bool ajouterCreature(Creature& creature); // A MODIFIER... (si necessaire)

	bool retirerDresseur(const string& nom); // A MODIFIER... (si necessaire)
	bool retirerCreature(const string& nom); // A MODIFIER... (si necessaire)

	Dresseur* choisirDresseurAleatoire(); // A MODIFIER... (si necessaire)
	Creature* choisirCreatureAleatoire(); // A MODIFIER... (si necessaire)

	bool attraperCreature(Dresseur* dresseur,  Creature* creature); // A MODIFIER... (si necessaire)
	bool relacherCreature(Dresseur* dresseur, const string& nomCreature); // A MODIFIER... (si necessaire)

	//operateurs pour dresseurs
	/*Param Dresseur* dresseur 
	retourn reference vers PolyLand */
	PolyLand& operator+=(Dresseur* dresseur);
	PolyLand& operator-=(const Dresseur* dresseur);

	//operateurs pour creatures
	/*Param Creature& creature
	retourn reference vers PolyLand */
	PolyLand& operator+=(Creature& creature);
	PolyLand& operator-=(const Creature& creature);

	//operateurs d'affichage 
	friend ostream& operator<<(ostream& os, const PolyLand& poly);

	//________TP2_______

private:
	vector<Dresseur*> dresseurs_;
	vector<Creature*> creatures_;

	//________TP2_______

};
#endif