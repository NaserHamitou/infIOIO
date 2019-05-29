//
//  pouvoirSoporifique.h
//  tp3
//
//  Created by Rania Abid on 2019-05-28.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#ifndef pouvoirSoporifique_h
#define pouvoirSoporifique_h
#include <iostream>
#include "Pouvoir.h"
#include "EtatEndormi.h"


class pouvoirSoporifique:public Pouvoir
{
public:
    pouvoirSoporifique(const std::string& nom,unsigned int nombreDeDegat, unsigned int energieNecessaire);
    pouvoirSoporifique(const std::string& nom,unsigned int nombreDeDegat, unsigned int energieNecessaire,int duree);
    
    friend std::ostream& operator<<(std::ostream& os, const pouvoirSoporifique& pouvoirSoporifique);
    void appliquerEffetOffensif(Creature& creatureEnnemie);

private:
    int duree_;
};

#endif /* pouvoirSoporifique_h */
