//
//  CreatureMagique.cpp
//  tp3
//
//  Created by Rania Abid on 2019-05-28.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#include "CreatureMagique.h"

CreatureMagique::CreatureMagique(const std::string& nom, unsigned int attaque,unsigned int defense, unsigned int pointDeVie, unsigned int energie,int bonus) :Creature(nom,attaque,defense,pointDeVie,energie),bonus_(bonus)
{
}
//constructeur pae copie
CreatureMagique::CreatureMagique(const CreatureMagique& creatureMagique): Creature(creatureMagique)
{
    bonus_=creatureMagique.bonus_;
}

CreatureMagique& CreatureMagique::operator=(const CreatureMagique& creatureMagique)
{
    if (this!=&creatureMagique)
    {
        nom_ = creatureMagique.nom_;
        attaque_ = creatureMagique.attaque_;
        defense_ = creatureMagique.defense_;
        pointDeVie_ = creatureMagique.pointDeVie_;
        pointDeVieTotal_ = creatureMagique.pointDeVieTotal_;
        energie_ = creatureMagique.energie_;
        energieTotal_ = creatureMagique.energieTotal_;
        experience_ = creatureMagique.experience_;
        experienceNecessaire_ = creatureMagique.experienceNecessaire_;
        niveau_ = creatureMagique.niveau_;
        pouvoirs_ = creatureMagique.pouvoirs_;
        delete etat_;
        if (creatureMagique.etat_ == nullptr)
            etat_ = new EtatCreature("normal");
        else
        {
            etat_ = new EtatCreature(*(creatureMagique.obtenirEtat()));
        }
        
        bonus_ = creatureMagique.bonus_;
    }
    return *this;
    
}
std::ostream& operator<<(std::ostream& os, const CreatureMagique& creatureMagique)
{
    os<<"La créature magique"<<static_cast<Creature>(creatureMagique);
    return os;
    
}
void CreatureMagique::attaquer(const Pouvoir& pouvoir, Creature& creature)
{
    Creature::attaquer(pouvoir, creature);
    if ((this->obtenirPointDeVie() + bonus_) <= this->obtenirPointDeVieTotal())
        this->modifierPointDeVie(this->obtenirPointDeVie() + bonus_);
    else {
        this->modifierPointDeVie(this->obtenirPointDeVieTotal());
    }
    
}
