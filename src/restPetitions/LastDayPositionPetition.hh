
#ifndef __LastDayPositionPetition_hh__
#define __LastDayPositionPetition_hh__

#include <string>

#include "restClient/IRestClient.hh"
#include "AttributesPetition.hh"


class LastDayPositionPetition : public IRestClient, public AttributesPetition
{
  public:
    LastDayPositionPetition();

    virtual ~LastDayPositionPetition();

    void ask(const std::wstring & id);

  private:
    // ICliente interfaz
    virtual void accept(std::wstringstream & message);
};

#endif
