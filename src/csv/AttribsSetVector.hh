

#ifndef __AttribsSetVector_hh__
#define __AttribsSetVector_hh__

#include <vector>
#include "AttribsSet.hh"


class AttribsSetVector
{
  typedef std::vector<AttribsSet> Container;

  public:
    typedef Container::iterator iterator;
    typedef Container::const_iterator const_iterator;

    AttribsSetVector();

    AttribsSetVector & operator<<(const AttribsSet & a);

    iterator begin()              { return _attribsSec.begin(); }
    iterator end()                { return _attribsSec.end(); }
    const_iterator cbegin() const { return _attribsSec.cbegin(); }
    const_iterator cend() const   { return _attribsSec.cend(); }

  private:
    std::vector<AttribsSet> _attribsSec;
};





#endif

