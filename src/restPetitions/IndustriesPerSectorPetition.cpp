
#include <string>
#include <cpprest/uri.h>
#include <iostream>
#include <algorithm>

#include "PeticionIndustriasPorSector.hh"
#include "clienteRest/ClienteRest.hh"
#include "csv/CsvReader.hh"


std::map<Attrib, Value> FillYahooSectorsId()
{
  std::map<Attrib, Value> s;
  
  s.insert(std::make_pair(L"Basic Materials", L"1"));
  s.insert(std::make_pair(L"Conglomerates", L"2"));
  s.insert(std::make_pair(L"Consumer Goods", L"3"));
  s.insert(std::make_pair(L"Financial", L"4"));
  s.insert(std::make_pair(L"Healthcare", L"5"));
  s.insert(std::make_pair(L"Industrial Goods", L"6"));
  s.insert(std::make_pair(L"Services", L"7"));
  s.insert(std::make_pair(L"Technology", L"8"));
  s.insert(std::make_pair(L"Utilities", L"9"));

  return s;
}

std::wstring GetYahooSectorId(const std::map<Attrib, Value> & a, const std::wstring & s)
{
  auto iter = std::find_if(a.cbegin(), a.cend(), 
                          [&](const std::map<Attrib, Value>::value_type & par)
                          {
                            return par.first == s;
                          });

  if (iter != a.cend())
  {
    return iter->second;
  }
  
  return std::wstring();
}


const std::map<Attrib, Value> 
  PeticionIndustriasPorSector::_yahooSectorIds = FillYahooSectorsId();

PeticionIndustriasPorSector::PeticionIndustriasPorSector()
{
}

PeticionIndustriasPorSector::~PeticionIndustriasPorSector()
{
}

void PeticionIndustriasPorSector::Solicita(const std::wstring & sector)
{
  static const std::wstring url = L"http://biz.yahoo.com/p/csv/";
  std::wstring peticion = url;

  peticion.append(GetYahooSectorId(_yahooSectorIds, sector));
  peticion.append(L"conameu.csv");

  web::http::uri uriPeticion(peticion);
  ClienteRest::Solicita(uriPeticion, this).wait();
}

void PeticionIndustriasPorSector::Acepta(std::wstringstream & mensaje)
{
  CsvReader reader(true, mensaje);

  reader >> getAttribs();
}

