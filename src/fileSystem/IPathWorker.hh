

#ifndef __IPathWorker_hh__
#define __IPathWorker_hh__

#include <string>

class IPathWorker
{
  public:
    virtual ~IPathWorker() {}

    void workPath(const std::wstring & path) = 0;
    void workFile(const std::wstring & file) = 0;
};


#endif
