

#include <cpprest/uri.h>

#include "PeticionCompaniasPorIndustria.hh"
#include "clienteRest/ClienteRest.hh"
#include "csv/CsvReader.hh"
#include "yahoo/Industries.hh"

PeticionCompaniasPorIndustria::PeticionCompaniasPorIndustria() :
  PeticionAtributos()
{
}

PeticionCompaniasPorIndustria::~PeticionCompaniasPorIndustria()
{
}

void PeticionCompaniasPorIndustria::Solicita(const std::wstring & industry)
{
  static const std::wstring url = L"http://biz.yahoo.com/p/csv/";
  std::wstring peticion = url;

  peticion.append(Industries::Instance().GetIndustryId(industry));
  peticion.append(L"conameu.csv");

  web::http::uri uriPeticion(peticion);
  ClienteRest::Solicita(uriPeticion, this).wait();
}

void PeticionCompaniasPorIndustria::Acepta(std::wstringstream & mensaje)
{
  CsvReader reader(true, mensaje, 2);

  reader >> getAttribs();
}

