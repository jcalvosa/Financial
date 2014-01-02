

#ifndef __PeticionAtributos_hh__
#define __PeticionAtributos_hh__

#include "csv/AttribsSetVector.hh"

class PeticionAtributos
{
  public:
    PeticionAtributos();

    virtual ~PeticionAtributos();

    const AttribsSetVector & getAttribs() const   { return _attribs; }
    AttribsSetVector & getAttribs()               { return _attribs; }

  private:
    AttribsSetVector _attribs;
};

std::wostream & operator<<(std::wostream & os, const PeticionAtributos & p);

#endif



