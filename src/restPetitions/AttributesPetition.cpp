

#include "AttributesPetition.hh"


AttributesPetition::AttributesPetition()
{
}

AttributesPetition::~AttributesPetition()
{
}

std::wostream & operator<<(std::wostream & os, const AttributesPetition & p)
{
  for (auto sectInfoIter = p.getAttribs().cbegin();
        sectInfoIter != p.getAttribs().cend();
        ++sectInfoIter)
  {
    os << *sectInfoIter << std::endl;
  }

  return os;
}

