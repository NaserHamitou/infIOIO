//
//  Professeur.cpp
//  tp3
//
//  Created by Rania Abid on 2019-05-22.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#include "Professeur.h"

Professeur::Professeur(const std::string& nom, const std::string& equipe) : Dresseur(nom, equipe)
{
    outilScientifique_ = nullptr;
}

Professeur::Professeur(const Professeur& prof) {
    nom_ = prof.nom_;
    equipe_ = prof.equipe_;
    if(prof.outilScientifique_ != nullptr)
        outilScientifique_ = new OutilScientifique(*prof.outilScientifique_);
    else
    {
        outilScientifique_ = nullptr;
    }
    creatures_ = prof.creatures_;
}

Professeur::~Professeur() {
    delete outilScientifique_;
    outilScientifique_ = nullptr;
}
OutilScientifique* Professeur::obtenirOutilScientifique()const
{
    return outilScientifique_;
    
}

void Professeur::modifierOutilScientifique(OutilScientifique* outilScientifique)
{
    outilScientifique_=outilScientifique;
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
    outilScientifique_->utiliser(creature);
}

void Professeur::soigner(Creature& creature) const
{
    creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
    creature.modifierEnergie(creature.obtenirEnergieTotale());
}
