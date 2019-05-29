//
//  EtatConfus.cpp
//  tp3
//
//  Created by Rania Abid on 2019-05-22.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#include "EtatConfus.h"
EtatConfus:: EtatConfus(const std::string& nom):EtatCreature(nom)
{
    type_ = TypeEtat_confus;
}
EtatConfus :: EtatConfus(const std::string& nom, unsigned int duree):EtatCreature(nom,duree)
{
    type_ = TypeEtat_confus;
}

std::ostream& operator<<(std::ostream& o, const EtatConfus& etatConfus)
{
o<<"état confus"<< std::endl;
    return o;
}

void EtatConfus:: appliquerEtat(Creature& creature) //‡ appliquer sur la crÈature qui possËde ce pouvoir
{
    int probabilite = rand() % 3;
    
    if (probabilite == 2)
    {
    
    if (0,05*creature.obtenirPointDeVie()<5)
        creature.modifierPointDeVie(creature.obtenirPointDeVie()-5);
    else
        {
        creature.modifierPointDeVie(creature.obtenirPointDeVie()-(0,05*creature.obtenirPointDeVie()));
        }
        
    }
    duree_--;
    
}
bool EtatConfus::peutAttaquer() const //dÈtermine si l'Ètat de la crÈature lui permet d'attaquer
{
   
    return rand() %2;
}

bool EtatConfus::estFini() const //si vrai, informe la crÈature qu'elle peut retourner ‡ l'Ètat normal
{
  return (duree_ <= 0 || (rand() % 3) == 1);
}
