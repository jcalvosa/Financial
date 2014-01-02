

#include <cpprest/uri.h>

#include "CompaniesPerIndustryPetition.hh"
#include "restClient/RestClient.hh"
#include "csv/CsvReader.hh"
#include "yahoo/Industries.hh"

CompaniesPerIndustryPetition::CompaniesPerIndustryPetition() :
  AttributesPetition()
{
}

CompaniesPerIndustryPetition::~CompaniesPerIndustryPetition()
{
}

void CompaniesPerIndustryPetition::ask(const std::wstring & industry)
{
  static const std::wstring url = L"http://biz.yahoo.com/p/csv/";
  std::wstring petition = url;

  petition.append(Industries::Instance().GetIndustryId(industry));
  petition.append(L"conameu.csv");

  web::http::uri uriPetition(petition);
  RestClient::ask(uriPetition, this).wait();
}

void CompaniesPerIndustryPetition::accept(std::wstringstream & mensaje)
{
  CsvReader reader(true, mensaje, 2);

  reader >> getAttribs();
}

