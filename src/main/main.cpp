
#include <iostream>

#include "restPetitions/LastDayPositionPetition.hh"
#include "restPetitions/AllSectorsPetition.hh"
#include "restPetitions/IndustriesPerSectorPetition.hh"
#include "restPetitions/CompaniesPerIndustryPetition.hh"
#include "restPetitions/CurrencyExchangePetition.hh"
#include "iso/Currencies.hh"

int main(int, char **)
{
  // all sectors
  AllSectorsPetition sectors;
  sectors.ask();
  std::wcout << "------------- Sectors --------------" << std::endl;
  std::wcout << sectors << std::endl;

  // all industries from sector
  IndustriesPerSectorPetition industries;
  industries.ask(L"Basic Materials");
  std::wcout << "------------- Industries--------------" << std::endl;
  std::wcout << industries << std::endl;

  // all companies from industry
  CompaniesPerIndustryPetition companies;
  companies.ask(L"Telecom Services - Foreign");
  std::wcout << "------------- Companies --------------" << std::endl;
  std::wcout << companies << std::endl;

  // last company position
  LastDayPositionPetition lastDay;
  lastDay.ask(L"GOOG");
  std::wcout << "------------- Last day - Google --------------" << std::endl;
  std::wcout << lastDay << std::endl;

  // currency list
  std::wcout << "------------- Currencies --------------" << std::endl;
  Currencies & currencies = Currencies::Instance();

  for (auto iter = currencies.cbegin(); iter != currencies.cend(); ++iter)
  {
    std::wcout << *iter << std::endl;
  }

  // currency exchage
  CurrencyExchangePetition currencyExchange;
  auto div1Iter = currencies.cbegin();
  auto div2Iter = div1Iter + 1;

  auto div1Id = div1Iter->getValue(L"Id");
  auto div2Id = div2Iter->getValue(L"Id");

  currencyExchange.ask(div1Id, div2Id);
  std::wcout << "------------- Currency exchange --------------" << std::endl;
  std::wcout << currencyExchange << std::endl;

  return 0;
}
