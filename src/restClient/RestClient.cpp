

#include <cstdlib>

#include "RestClient.hh"
#include "IRestClient.hh"

//
// complete properties list is in:
// https://code.google.com/p/yahoo-finance-managed/wiki/enumQuoteProperty
//

pplx::task<void> RestClient::ask(web::http::uri & uri, IRestClient * visitor)
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

      std::wstringstream answer = translateAnswer(response);

      visitor->accept(answer);
    }
  });
}

std::wstringstream RestClient::translateAnswer(web::http::http_response & response)
{
  using namespace concurrency::streams;

  std::wstringstream answer;

  while (!response.body().is_eof())
  {
    auto task = response.body().read().then([&](istream::int_type val)
    {
      answer << (char)val;
    });

    task.wait();
  }

  return answer;
}

