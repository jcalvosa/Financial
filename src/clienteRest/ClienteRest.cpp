

#include <cstdlib>

#include "ClienteRest.hh"
#include "IClientePeticiones.hh"


//
// la lista de propiedades de la peticion se encuentra en 
// https://code.google.com/p/yahoo-finance-managed/wiki/enumQuoteProperty
//

// peticion de situacion de Google
// n: nombre
// s: simbolo
// l1: ultimo precio de negociacion
// o: precio de apertura
// p: precio de cierre anterior
const std::wstring url = 
  L"http://download.finance.yahoo.com/d/quotes.csv?s=GOOG&f=nsl1op&e=.csv";

pplx::task<void> ClienteRest::Solicita(web::http::uri & uri, 
                                       IClientePeticiones * visitor)
{
  web::http::client::http_client client(uri);

  auto task = client.request(web::http::methods::GET);

  return task.then([=](web::http::http_response response)
  {
    auto responseCode = response.status_code();

    std::cout << "Server returned returned status code " << responseCode << std::endl;

    if (responseCode == 200)
    {
      // In this example, we print the length of the response to the console.
      std::cout << "Content length is " << response.headers().content_length() << " bytes." << std::endl;

      std::wstringstream respuesta = TraduceRespuesta(response);

      visitor->Acepta(respuesta);
    }
  });
}

std::wstringstream ClienteRest::TraduceRespuesta(web::http::http_response & response)
{
  using namespace concurrency::streams;

  std::wstringstream respuesta;

  while (!response.body().is_eof())
  {
    auto task = response.body().read().then([&](istream::int_type val)
    {
      //std::stringstream respuesta;
      respuesta << (char)val;
    });

    task.wait();
  }

  return respuesta;
}

