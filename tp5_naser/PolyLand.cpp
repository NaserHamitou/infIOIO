/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description:
*/
#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

bool PolyLand::attraperCreature(Dresseur* dresseur, Creature* creature)
{
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const std::string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

std::ostream& operator<<(const std::ostream os,  PolyLand& poly) {   /* NOT SURE */

	poly.listMaitre_.sort([](Dresseur* dresseur1,Dresseur* dresseur2)-> bool { return dresseur1->obtenirNom() < dresseur2->obtenirNom(); });
	poly.listCompagnon_.sort([](Creature* creature1, Creature* creature2) -> bool { return creature1->obtenirAttaque() < creature2->obtenirAttaque(); });
	for_each(poly.listMaitre_.begin(), poly.listMaitre_.end(), [](Dresseur* dresseur) { cout << dresseur->obtenirNom() << "\t";} );
	for_each(poly.listCompagnon_.begin(), poly.listCompagnon_.end(), [](Creature* creature) { cout << creature->obtenirNom() << "\t"; });
	
}

