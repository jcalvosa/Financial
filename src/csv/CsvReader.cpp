
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "CsvReader.hh"

CsvReader::CsvReader(bool header, std::wstringstream & ss, unsigned skipLines) :
  _header(header),
  _stream(ss),
  _skipLines(skipLines)
{
}
  
void CsvReader::AddHeaderField(const std::wstring & field)
{
  _headerFields.push_back(field);
}

CsvReader & CsvReader::operator>>(AttribValue & attribvalue)
{
  std::wstring field;
  std::getline(_stream, field, L',');
  attribvalue.first = field;
  std::getline(_stream, field);
  attribvalue.second = field;

  return *this;
}

CsvReader & CsvReader::operator>>(AttribsSetVector & attribsSet)
{
  std::vector<std::wstring> datos;
  std::wstring line, field;
  bool firstLine = true;
  unsigned linesSkipped = 0;

  for (size_t numberOfFields = 0; !std::getline(_stream, line).eof(); firstLine = false)
  {
    // count number of ocurrences of separator
    if (firstLine)
    {
      std::for_each(line.begin(), line.end(), 
                    [&](std::wstring::value_type & val)
                    {
                      if (val == L',')
                      {
                        ++numberOfFields;
                      }
                    });
    }

    if ((!_header) || (_header && !firstLine))
    {
      while (linesSkipped++ < _skipLines)
      {
        std::getline(_stream, line);
      }
    }

    std::wstringstream aux(line);

    std::vector<std::wstring> & data = (firstLine && _header) ? _headerFields : datos;
    
    data.clear();

    for (size_t count = 0; count < numberOfFields + 1; count++)
    {
      std::getline(aux, field, L',');

      // delete all " ocurrences from header and data
      field.erase(std::remove(field.begin(), 
                              field.end(), '"'), 
                  field.end());

      data.push_back(field);
    }

    //aux >> field;
    //field.erase(std::remove(field.begin(), 
    //                        field.end(), '"'), 
    //            field.end());

    //data.push_back(field);

    if (!firstLine || !_header)
    {
      AttribsSet attribs;
      
      for (size_t idx = 0; idx < data.size(); ++idx)
      {
        AttribValue att = std::make_pair(_headerFields[idx], datos[idx]);

        attribs << att;
      }

      attribsSet << attribs;
    }
  }

  return *this;
}

