//
//  MondeMagique.h
//  tp5
//
//  Created by Rania Abid on 2019-06-05.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#ifndef MondeMagique_h
#define MondeMagique_h
#include <iostream>
#include <list>

template <typename T, typename S>


class MondeMagique
{
public:
    MondeMagique();
    ~MondeMagique();
    std::list <T*> obtenirListMaitre();
    std::list <S*> obtenirListCompagnon();
    void ajouterMaitre(T* maitre); // jsuis pas sure ici si il prend en param un ptr ou un maitre tout court
    void ajouterCompagnon(S* compagnon);
    
    
    
    
    
private:
    std::list <T*> listMaitre_;
    std::list <S*> listCompagnon_;
    
};

#endif /* MondeMagique_h */
