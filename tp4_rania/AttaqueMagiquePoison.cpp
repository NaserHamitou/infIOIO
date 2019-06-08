//
//  AttaqueMagiquePoison.cpp
//  tp4
//
//  Created by Rania Abid on 2019-05-31.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#include "AttaqueMagiquePoison.h"

AttaqueMagiquePoison::AttaqueMagiquePoison():AttaqueMagique(2) //duree_ =2????
{}


AttaqueMagiquePoison::AttaqueMagiquePoison(int duree):AttaqueMagique(duree)
{}


AttaqueMagiquePoison::~AttaqueMagiquePoison()
{}
std::string AttaqueMagiquePoison::obtenirtypeAttaque() const
{
    return "AttaqueMagiquePoison";
}

void AttaqueMagiquePoison::appliquerAttaque(Creature & creature)
{
    if (duree_ > 0 && creature.obtenirEnergie() >= 5)
    {
        unsigned int energie = creature.obtenirEnergie();
        if (rand() % 3 == 0)
        {
            creature.modifierEnergie(energie - 2);
        }
        duree_--;
    }
}

bool AttaqueMagiquePoison::estFini()
{
    return(duree_==0);
}
