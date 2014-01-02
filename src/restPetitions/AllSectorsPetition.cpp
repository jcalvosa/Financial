


#include <string>
#include <cpprest/uri.h>
#include <iostream>

#include "AllSectorsPetition.hh"
#include "restClient/RestClient.hh"
#include "csv/CsvReader.hh"


AllSectorsPetition::AllSectorsPetition() : AttributesPetition()
{
}

AllSectorsPetition::~AllSectorsPetition()
{
}

void AllSectorsPetition::ask()
{
  static const std::wstring url = L"http://biz.yahoo.com/p/csv/s_conameu.csv";

  web::http::uri uriPeticion(url);
  RestClient::ask(uriPeticion, this).wait();
}

void AllSectorsPetition::accept(std::wstringstream & mensaje)
{
  // first line set column names
  // Sectors,"1-Day Price Chg %","Market Cap","P/E","ROE %",
  // "Div. Yield %","Debt to Equity","Price to Book",
  // "Net Profit Margin (mrq)","Price To Free Cash Flow (mrq)"

  CsvReader reader(true, mensaje);

  reader >> getAttribs();
}

