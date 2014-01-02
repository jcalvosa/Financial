

#ifndef __CompaniesPerIndustryPetition_hh__
#define __CompaniesPerIndustryPetition_hh__

#include "restClient/IRestClient.hh"
#include "AttributesPetition.hh"

class CompaniesPerIndustryPetition : public IRestClient, public AttributesPetition
{
  public:
    CompaniesPerIndustryPetition();

    virtual ~CompaniesPerIndustryPetition();

    void ask(const std::wstring & industry);

  private:
    virtual void accept(std::wstringstream & mensaje);
};

#endif
