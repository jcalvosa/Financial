

#ifndef __IClientePeticiones_h__
#define __IClientePeticiones_h__


#include <sstream>

class IClientePeticiones
{
  public:
    virtual ~IClientePeticiones() {}
    virtual void Acepta(std::wstringstream & mensaje) = 0;
};


#endif
