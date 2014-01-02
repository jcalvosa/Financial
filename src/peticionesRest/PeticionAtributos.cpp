

#include "PeticionAtributos.hh"


PeticionAtributos::PeticionAtributos()
{
}

PeticionAtributos::~PeticionAtributos()
{
}

std::wostream & operator<<(std::wostream & os, const PeticionAtributos & p)
{
  for (auto sectInfoIter = p.getAttribs().cbegin();
        sectInfoIter != p.getAttribs().cend();
        ++sectInfoIter)
  {
    os << *sectInfoIter << std::endl;
  }

  return os;
}

