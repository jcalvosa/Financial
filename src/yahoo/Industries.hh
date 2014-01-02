
#ifndef __YahooIndustries_hh__
#define __YahooIndustries_hh__

#include <map>
#include <string>

#include "utils/Singleton.hh"
#include "csv/AttribsSet.hh"

class Industries : public Singleton<Industries>
{
  public:
    std::wstring GetIndustryId(const std::wstring & s);

  private:
    Industries();

    std::map<Attrib, Value> _industries;
    
    friend class Singleton<Industries>;
};


#endif

