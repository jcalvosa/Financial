
#include <cpprest/uri.h>

#include "CurrencyExchangePetition.hh"

#include "restClient/RestClient.hh"
#include "csv/CsvReader.hh"

CurrencyExchangePetition::CurrencyExchangePetition() :
  AttributesPetition()
{
}

CurrencyExchangePetition::~CurrencyExchangePetition()
{
}

void CurrencyExchangePetition::ask(const std::wstring & idCurrency1, 
                                   const std::wstring & idCurrency2)
{
  static const std::wstring url = L"http://finance.yahoo.com/d/quotes.csv?e=.csv&f=sl1d1t1&s=";
  std::wstring petition = url;

  petition.append(idCurrency1);
  petition.append(idCurrency2);
  petition.append(L"=X");

  web::http::uri uriPetition(petition);
  RestClient::ask(uriPetition, this).wait();
}

void CurrencyExchangePetition::accept(std::wstringstream & mensaje)
{
  CsvReader reader(false, mensaje);

  reader.AddHeaderField(L"Symbol");
  reader.AddHeaderField(L"Last Trade Price Only");
  reader.AddHeaderField(L"Last Trade Date");
  reader.AddHeaderField(L"Last Trade Time");

  reader >> getAttribs();
  return;
}

