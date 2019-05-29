//
//  EtatEmpoisonne.cpp
//  tp3
//
//  Created by Rania Abid on 2019-05-25.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#include "EtatEmpoisonne.h"

EtatEmpoisonne:: EtatEmpoisonne(const std::string& nom):EtatCreature(nom)
{
    type_=TypeEtat_empoisonne;
}
EtatEmpoisonne :: EtatEmpoisonne(const std::string& nom, unsigned int duree):EtatCreature(nom,duree)
{
    type_=TypeEtat_empoisonne;
    
}

std::ostream& operator<<(std::ostream& o, const EtatEmpoisonne& etatEmpoisonne)
{
    o<<"l'etat est : "<<etatEmpoisonne.nom_<<std::endl;
    return o;
    
}

void EtatEmpoisonne:: appliquerEtat(Creature& creature)
{
    duree_--;
    creature.modifierPointDeVie(creature.obtenirPointDeVie()-5);
    
}

bool  EtatEmpoisonne:: estFini() const
{
    return (duree_<=0);
}
