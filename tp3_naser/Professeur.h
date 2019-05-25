#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "Dresseur.h"
#include "OutilScientifique.h"
using namespace std;

class Professeur : public Dresseur
{
public:
	//Constructeur parametre
	Professeur(const string& nom, const string& equipe);

	//Constructeur par copie
	Professeur(const Professeur& prof);

	//Destructeur
	~Professeur();

	//La méthode de modification de l’attribut outil
	void modifierOutilScientifique(OutilScientifique* outil);

	//Methode soigner 
	void soigner(Creature& creature) const;

	//Operator surcharge = 
	Professeur& operator=(const Professeur& prof);

	//Methode utiliserOutil 
<<<<<<< HEAD
	void utiliserOutil(Creature& creature) const;
=======
	void utiliserOutil(Creature& creature);
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df


private:

	OutilScientifique* outilScientifique_;

};

#endif