

#ifndef __RestClient_hh__
#define __RestClient_hh__

#include <cpprest/http_client.h>
#include <cpprest/uri.h>

class IRestClient;

class RestClient
{
  public:
    static pplx::task<void> ask(web::http::uri & uri, IRestClient * visitor);

  private:
    static std::wstringstream translateAnswer(web::http::http_response & response);
};




#endif
