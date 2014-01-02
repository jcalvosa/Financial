
#include <fstream>

#include "Currencies.hh"
#include "csv/CsvReader.hh"

Currencies::Currencies()
{
  std::wifstream file("../../data/IsoCurrencies.dat");

  if (file.is_open())
  {
    std::wstringstream buffer;

    buffer << file.rdbuf();

    file.close();

    CsvReader reader(false, buffer);

    reader.AddHeaderField(L"Id");
    reader.AddHeaderField(L"Iso Code");
    reader.AddHeaderField(L"#Decimals");
    reader.AddHeaderField(L"Description");

    reader >> _currencies;
  }
}

Currency Currencies::GetCurrency(const std::wstring & id)
{
  return Currency();
}
