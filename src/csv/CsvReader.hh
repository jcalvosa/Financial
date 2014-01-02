


#ifndef __CsvReader_hh__
#define __CsvReader_hh__

#include <string>
#include <sstream>
#include <vector>

#include "AttribsSetVector.hh"

class CsvReader
{
  public:
    CsvReader(bool header, std::wstringstream & ss, unsigned skipLines = 0);

    void AddHeaderField(const std::wstring & field);

    CsvReader & operator>>(AttribValue & attribvalue);
    CsvReader & operator>>(AttribsSetVector & attribs);

  private:
    bool _header;
    std::wstringstream & _stream;
    unsigned _skipLines;
    std::vector<std::wstring> _headerFields;
};



#endif
