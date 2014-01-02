

#ifndef __AttributesPetition_hh__
#define __AttributesPetition_hh__

#include "csv/AttribsSetVector.hh"

class AttributesPetition
{
  public:
    AttributesPetition();

    virtual ~AttributesPetition();

    const AttribsSetVector & getAttribs() const   { return _attribs; }
    AttribsSetVector & getAttribs()               { return _attribs; }

  private:
    AttribsSetVector _attribs;
};

std::wostream & operator<<(std::wostream & os, const AttributesPetition & p);

#endif



