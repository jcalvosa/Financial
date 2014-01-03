

#ifndef __RecursiveDirectoryLookOver_hh__
#define __RecursiveDirectoryLookOver_hh__

#include <string>

class IPathWorker;

class RecursiveDirectoryLookOver
{
  public:
    static void lookOver(const std::wstring & p, IPathWorker & w);
};


#endif
