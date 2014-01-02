
#include <algorithm>
#include <fstream>

#include "Industries.hh"
#include "csv/CsvReader.hh"

Industries::Industries()
{
  std::wifstream file("../../data/YahooCompanies.dat");

  if (file.is_open())
  {
    std::wstringstream buffer;

    buffer << file.rdbuf();

    file.close();

    CsvReader reader(false, buffer);

    while (!buffer.eof())
    {
      AttribValue val;

      reader >> val;
      _industries.insert(std::make_pair(val.first, val.second));
    }
  }
}

std::wstring Industries::GetIndustryId(const std::wstring & s)
{
  auto iter = std::find_if(_industries.cbegin(), _industries.cend(), 
                          [&](const std::map<Attrib, Value>::value_type & par)
                          {
                            return par.first == s;
                          });

  if (iter != _industries.cend())
  {
    return iter->second;
  }
  
  return std::wstring();
}
