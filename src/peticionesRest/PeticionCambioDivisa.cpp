
#include <cpprest/uri.h>

#include "PeticionCambioDivisa.hh"

#include "clienteRest/ClienteRest.hh"
#include "csv/CsvReader.hh"

PeticionCambioDivisa::PeticionCambioDivisa() :
  PeticionAtributos()
{
}

PeticionCambioDivisa::~PeticionCambioDivisa()
{
}

void PeticionCambioDivisa::Solicita(const std::wstring & idDivisa1, 
                                    const std::wstring & idDivisa2)
{
  static const std::wstring url = L"http://finance.yahoo.com/d/quotes.csv?e=.csv&f=sl1d1t1&s=";
  std::wstring peticion = url;

  peticion.append(idDivisa1);
  peticion.append(idDivisa2);
  peticion.append(L"=X");

  web::http::uri uriPeticion(peticion);
  ClienteRest::Solicita(uriPeticion, this).wait();
}

void PeticionCambioDivisa::Acepta(std::wstringstream & mensaje)
{
  CsvReader reader(false, mensaje);

  reader.AddHeaderField(L"Symbol");
  reader.AddHeaderField(L"Last Trade Price Only");
  reader.AddHeaderField(L"Last Trade Date");
  reader.AddHeaderField(L"Last Trade Time");

  reader >> getAttribs();
  return;
}

