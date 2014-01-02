

#ifndef __ClienteRest_hh_
#define __ClienteRest_hh_

#include <cpprest/http_client.h>
#include <cpprest/uri.h>

class IClientePeticiones;

class ClienteRest
{
  public:
    static pplx::task<void> Solicita(web::http::uri & uri, 
                                    IClientePeticiones * visitor);

  private:
    static std::wstringstream TraduceRespuesta(web::http::http_response & response);
};




#endif
