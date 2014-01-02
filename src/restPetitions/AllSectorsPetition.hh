
#ifndef __AllSectorsPetition_hh__
#define __AllSectorsPetition_hh__

#include "restClient/IRestClient.hh"
#include "AttributesPetition.hh"


class AllSectorsPetition : public IRestClient, public AttributesPetition
{
  public:
    AllSectorsPetition();

    virtual ~AllSectorsPetition();

    void ask();

  private:
    // IClientePeticiones interfaz
    virtual void accept(std::wstringstream & mensaje);
};


#endif
