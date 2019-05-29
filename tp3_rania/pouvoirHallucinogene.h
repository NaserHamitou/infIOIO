//
//  pouvoirHallucinogene.h
//  tp3
//
//  Created by Rania Abid on 2019-05-28.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#ifndef pouvoirHallucinogene_h
#define pouvoirHallucinogene_h
#include <iostream>
#include "Pouvoir.h"
#include "EtatConfus.h"


class pouvoirHallucinogene:public Pouvoir
{
public:
    pouvoirHallucinogene(const std::string& nom,unsigned int nombreDeDegat, unsigned int energieNecessaire);
    pouvoirHallucinogene(const std::string& nom,unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);
    
    friend std::ostream& operator<<(std::ostream& os, const pouvoirHallucinogene& pouvoirHallucinogene);
    void appliquerEffetOffensif(Creature& creatureEnnemie);
    
private:
    int duree_;

};
#endif /* pouvoirHallucinogene_h */
