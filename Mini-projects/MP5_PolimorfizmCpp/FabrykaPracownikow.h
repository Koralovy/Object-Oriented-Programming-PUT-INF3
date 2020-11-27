#ifndef __FabrykaPracownikow_H__
#define __FabrykaPracownikow_H__
#include "Pracownik.h"
#include "FabrykaOsob.h"

class FabrykaPracownikow : public FabrykaOsob{
public:
    Pracownik* utworz();
};

#endif // __FabrykaPracownikow_H__