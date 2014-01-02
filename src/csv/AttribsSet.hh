
#ifndef __AttribsContainer_h__
#define __AttribsContainer_h__

#include <set>
#include <string>


typedef std::wstring Attrib;
typedef std::wstring Value;
typedef std::pair<Attrib, Value> AttribValue;

struct CompareFunctor
{
  bool operator()(const AttribValue & a, const AttribValue & b) const
  {
    return a.first < b.first;
  }
};

class AttribsSet
{
  public:
    typedef std::set<AttribValue, CompareFunctor> Container;

    AttribsSet();

    void clear();
    void add(const AttribValue & a);
    void remove(const AttribValue & a);

    Value getValue(const Attrib & att) const;

    const Container & container() const       { return _attribs; }
    Container & container()                   { return _attribs; }

    Container::iterator begin()               { return _attribs.begin(); }
    Container::const_iterator cbegin() const  { return _attribs.cbegin(); }
    Container::iterator end()                 { return _attribs.end(); }
    Container::const_iterator cend() const    { return _attribs.cend(); }

    AttribsSet & operator<<(const AttribValue & attrib);

  private:
    Container _attribs;
};

std::wostream & operator<<(std::wostream & os, const AttribsSet & s);


#endif

