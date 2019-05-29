//
//  pouvoirPoison.h
//  tp3
//
//  Created by Rania Abid on 2019-05-27.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#ifndef pouvoirPoison_h
#define pouvoirPoison_h

#include <iostream>
#include "Pouvoir.h"
#include "EtatEmpoisonne.h"


class pouvoirPoison:public Pouvoir
{
public:
    pouvoirPoison(const std::string& nom,
                  unsigned int nombreDeDegat, unsigned int energieNecessaire);
    pouvoirPoison(const std::string& nom,
                  unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);
    
    friend std::ostream& operator<<(std::ostream& os, const pouvoirPoison& pouvoirpoison);
     void appliquerEffetOffensif(Creature& creatureEnnemie);

private:
    int duree_;
};
#endif /* pouvoirPoison_h */
