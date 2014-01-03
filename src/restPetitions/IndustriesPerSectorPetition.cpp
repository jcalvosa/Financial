
#include <string>
#include <cpprest/uri.h>
#include <iostream>
#include <algorithm>

#include "IndustriesPerSectorPetition.hh"
#include "restClient/RestClient.hh"
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
  IndustriesPerSectorPetition::_yahooSectorIds = FillYahooSectorsId();

IndustriesPerSectorPetition::IndustriesPerSectorPetition() : 
  AttributesPetition()
{
}

IndustriesPerSectorPetition::~IndustriesPerSectorPetition()
{
}

void IndustriesPerSectorPetition::ask(const std::wstring & sector)
{
  static const std::wstring url = L"http://biz.yahoo.com/p/csv/";
  std::wstring petition = url;

  petition.append(GetYahooSectorId(_yahooSectorIds, sector));
  petition.append(L"conameu.csv");

  web::http::uri uriPetition(petition);
  RestClient::ask(uriPetition, this).wait();
}

void IndustriesPerSectorPetition::accept(std::wstringstream & mensaje)
{
  CsvReader reader(true, mensaje);

  reader >> getAttribs();
}

