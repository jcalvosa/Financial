
#ifndef __CurrencyExchangePetition_hh__
#define __CurrencyExchangePetition_hh__


#include "restClient/IRestClient.hh"
#include "AttributesPetition.hh"

class CurrencyExchangePetition : public IRestClient, public AttributesPetition
{
  public:
    CurrencyExchangePetition();

    virtual ~CurrencyExchangePetition();

    void ask(const std::wstring & idCurrency1, const std::wstring & idCurrency2);

  private:
    // IClientePeticiones interfaz
    virtual void accept(std::wstringstream & mensaje);
};

#endif
