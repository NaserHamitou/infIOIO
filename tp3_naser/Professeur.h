#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "Dresseur.h"
#include "OutilScientifique.h"
using namespace std;

class Professeur : public Dresseur
{
public:
	//Constructeur parametre
	Professeur(const string& nom, const string& equipe, OutilScientifique* outil);

	//Constructeur par copie
	Professeur(const Professeur& prof);

	//Destructeur
	~Professeur();

	//La méthode de modification de l’attribut outil
	void modifierOutilScientifique(OutilScientifique* outil);

	//Methode soigner 
	void soigner(Creature& creature);

	//Operator surcharge = 
	Professeur& operator=(const Professeur& prof);

	//Methode utiliserOutil 
	void utiliserOutil(Creature& creature);






private:

	OutilScientifique* ptrOutilScientifique_;

};

#endif