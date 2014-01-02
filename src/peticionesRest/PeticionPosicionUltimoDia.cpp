
#include <string>
#include <cpprest/uri.h>
#include <iostream>

#include "PeticionPosicionUltimoDia.hh"
#include "clienteRest/ClienteRest.hh"
#include "csv/CsvReader.hh"


PeticionPosicionUltimoDia::PeticionPosicionUltimoDia()
{
}

PeticionPosicionUltimoDia::~PeticionPosicionUltimoDia()
{
}

void PeticionPosicionUltimoDia::Solicita(const std::wstring & id)
{
  static const std::wstring url_anterior = L"http://download.finance.yahoo.com/d/quotes.csv?s=";
  static const std::wstring flags = L"&f=d1opv&e=.csv";

  std::wstring peticion = url_anterior + id + flags;

  web::http::uri uriPeticion(peticion);
  ClienteRest::Solicita(uriPeticion, this).wait();
}

void PeticionPosicionUltimoDia::Acepta(std::wstringstream & mensaje)
{
  CsvReader reader(false, mensaje);

  reader.AddHeaderField(L"Last trade date");
  reader.AddHeaderField(L"Open value");
  reader.AddHeaderField(L"Close value");
  reader.AddHeaderField(L"Volume");

  reader >> getAttribs();
}

