
#include <algorithm>

#include "AttribsSet.hh"

AttribsSet::AttribsSet()
{
}

void AttribsSet::clear()
{
  _attribs.clear();
}

void AttribsSet::add(const AttribValue & a)
{
  _attribs.insert(a);
}

void AttribsSet::remove(const AttribValue & a)
{
  _attribs.erase(a);
}

Value AttribsSet::getValue(const Attrib & att) const
{
  auto iter = std::find_if(cbegin(), cend(), [&](const AttribValue & attVal)
                                              {
                                                return attVal.first == att;
                                              });

  if (iter != cend())
  {
    return iter->second;
  }

  return Value();
}

AttribsSet & AttribsSet::operator<<(const AttribValue & attrib)
{
  AttribValue att = std::make_pair(attrib.first, attrib.second);
  add(att);
  return *this;
}

std::wostream & operator<<(std::wostream & os, const AttribsSet & s)
{
  for (auto & iter = s.cbegin(); iter != s.cend(); ++iter)
  {
    os << iter->first << " - " << iter->second << "\n";
  }

  return os;
}
