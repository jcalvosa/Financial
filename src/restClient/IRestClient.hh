

#ifndef __IRestClient_hh__
#define __IRestClient_hh__


#include <sstream>

class IRestClient
{
  public:
    virtual ~IRestClient() {}

    virtual void accept(std::wstringstream & message) = 0;
};


#endif
