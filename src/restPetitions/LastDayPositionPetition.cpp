
#include <string>
#include <cpprest/uri.h>
#include <iostream>

#include "LastDayPositionPetition.hh"
#include "restClient/RestClient.hh"
#include "csv/CsvReader.hh"


LastDayPositionPetition::LastDayPositionPetition()
{
}

LastDayPositionPetition::~LastDayPositionPetition()
{
}

void LastDayPositionPetition::ask(const std::wstring & id)
{
  static const std::wstring url_anterior = L"http://download.finance.yahoo.com/d/quotes.csv?s=";
  static const std::wstring flags = L"&f=d1opv&e=.csv";

  std::wstring petition = url_anterior + id + flags;

  web::http::uri uriPetition(petition);
  RestClient::ask(uriPetition, this).wait();
}

void LastDayPositionPetition::accept(std::wstringstream & message)
{
  CsvReader reader(false, message);

  reader.AddHeaderField(L"Last trade date");
  reader.AddHeaderField(L"Open value");
  reader.AddHeaderField(L"Close value");
  reader.AddHeaderField(L"Volume");

  reader >> getAttribs();
}

