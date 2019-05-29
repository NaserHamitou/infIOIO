//
//  EtatEndormi.cpp
//  tp3
//
//  Created by Rania Abid on 2019-05-25.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#include "EtatEndormi.h"

EtatEndormi::EtatEndormi(const std::string& nom):EtatCreature(nom)
{
    type_=TypeEtat_endormi;
}

EtatEndormi::EtatEndormi(const std::string& nom, unsigned int duree):EtatCreature(nom,duree)
{
    type_=TypeEtat_endormi;
}

std::ostream& operator<<(std::ostream& o, const EtatEndormi& etatEndormi)
{
    o<<"etat"<<etatEndormi.nom_<<std::endl;
    return o;
}

void EtatEndormi:: appliquerEtat(Creature& creature)
{
    if (duree_>0)
        duree_--;
}

bool EtatEndormi:: peutAttaquer() const
{
    return false;
    
}

bool EtatEndormi:: estFini() const
{
    return(duree_<=0);
       
    
}
