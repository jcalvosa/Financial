


#include <string>
#include <cpprest/uri.h>
#include <iostream>

#include "PeticionTodosSectores.hh"
#include "clienteRest/ClienteRest.hh"
#include "csv/CsvReader.hh"


PeticionTodosSectores::PeticionTodosSectores()
{
}

PeticionTodosSectores::~PeticionTodosSectores()
{
}

void PeticionTodosSectores::Solicita()
{
  static const std::wstring url = L"http://biz.yahoo.com/p/csv/s_conameu.csv";

  web::http::uri uriPeticion(url);
  ClienteRest::Solicita(uriPeticion, this).wait();
}

void PeticionTodosSectores::Acepta(std::wstringstream & mensaje)
{
  // first line set column names
  // Sectors,"1-Day Price Chg %","Market Cap","P/E","ROE %",
  // "Div. Yield %","Debt to Equity","Price to Book",
  // "Net Profit Margin (mrq)","Price To Free Cash Flow (mrq)"

  CsvReader reader(true, mensaje);

  reader >> getAttribs();
}

