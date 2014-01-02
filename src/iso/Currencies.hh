

#ifndef __IsoCurrencies_hh__
#define __IsoCurrencies_hh__

#include "utils/Singleton.hh"
#include "csv/AttribsSetVector.hh"


class Currency : public AttribsSet
{
};

class Currencies : public Singleton<Currencies>
{
  public:
    typedef AttribsSetVector::iterator iterator;
    typedef AttribsSetVector::const_iterator const_iterator;

    iterator begin()              { return _currencies.begin(); }
    iterator end()                { return _currencies.end(); }

    const_iterator cbegin() const { return _currencies.cbegin(); }
    const_iterator cend() const   { return _currencies.cend(); }

    Currency GetCurrency(const std::wstring & id);

  private:
    Currencies();

    AttribsSetVector _currencies;
    
    friend class Singleton<Currencies>;
};


#endif

