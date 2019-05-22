//
//  Professeur.cpp
//  tp3
//
//  Created by Rania Abid on 2019-05-22.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#include "Professeur.h"

Professeur::Professeur(const std::string& nom, const std::string& equipe, OutilScientifique* outilScientifique):outilScientifique_(outilScientifique),Dresseur(nom, equipe)
{
}

Professeur::Professeur(const Professeur& professeur):outilScientifique_(professeur.outilScientifique_), Dresseur(professeur.obtenirNom(),professeur.obtenirEquipe())
{
}

Professeur::~Professeur()
{
    delete outilScientifique_;
}
OutilScientifique* Professeur::obtenirOutilScientifique()const
{
    return outilScientifique_;
    
}

void Professeur::modifierOutilScientifique(OutilScientifique* outilScientifique)
{
    outilScientifique_=outilScientifique;
}
void Professeur:: soigner(Creature& creatures)//
{
    creatures.nom_=
    
    
}
Professeur& Professeur::operator=(const Professeur& professeur)
{
    if (this != &professeur) {
        nom_ = professeur.nom_;
        equipe_=professeur.equipe_;
        if (professeur.outilScientifique_ != nullptr) {
            delete outilScientifique_;
            this->outilScientifique_ = new OutilScientifique(*(professeur.outilScientifique_));
        }
        else {
            outilScientifique_ = nullptr;
        }
        creatures_ = professeur.creatures_;
        objetMagique_=professeur.objetMagique_;
    }
    
    return *this;
}

void Professeur::utiliserOutil(Creature& creature)
{
    outilScientifique_->utiliser(c);//
}
