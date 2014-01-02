
#ifndef __IndustriesPerSectorPetition_hh__
#define __IndustriesPerSectorPetition_hh__

#include <map>

#include "restClient/IRestClient.hh"
#include "AttributesPetition.hh"


class IndustriesPerSectorPetition : public IRestClient, public AttributesPetition
{
  public:
    IndustriesPerSectorPetition();

    virtual ~IndustriesPerSectorPetition();

    void ask(const std::wstring & sector);

  private:
    static const std::map<Attrib, Value> _yahooSectorIds; 

    // IClientePeticiones interfaz
    virtual void accept(std::wstringstream & mensaje);
};

#endif
