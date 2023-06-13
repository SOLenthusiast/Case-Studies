//
//  validationFormat.h
//  tp1
//
//  Created by Mohamed Boubacar on 2014-10-21.
//  Copyright (c) 2014 Mohamed Boubacar. All rights reserved.
//

#ifndef tp1_validationFormat_h
#define tp1_validationFormat_h

#include <stdio.h>
#include <iostream>
#include <string>


enum
{
    OK, ERREUR
};

bool validerNas(const std::string& unNas);
bool validerFormatFichier(std::istream& p_is);


#endif
