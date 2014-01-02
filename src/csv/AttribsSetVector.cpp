

#include "AttribsSetVector.hh"

AttribsSetVector::AttribsSetVector() 
{
}

AttribsSetVector & AttribsSetVector::operator<<(const AttribsSet & a)
{
  _attribsSec.push_back(a);
  return *this;
}
