
#include <iostream>

#include "peticionesRest/PeticionPosicionUltimoDia.hh"
#include "peticionesRest/PeticionTodosSectores.hh"
#include "peticionesRest/PeticionIndustriasPorSector.hh"
#include "peticionesRest/PeticionCompaniasPorIndustria.hh"
#include "peticionesRest/PeticionCambioDivisa.hh"
#include "iso/Currencies.hh"

int main(int, char **)
{
  // peticion de todos los sectores
  PeticionTodosSectores sectores;
  sectores.Solicita();
  std::wcout << "------------- Sectores --------------" << std::endl;
  std::wcout << sectores << std::endl;

  // peticiones de todas las industrias de cada sector
  PeticionIndustriasPorSector industrias;
  industrias.Solicita(L"Basic Materials");
  std::wcout << "------------- Industrias--------------" << std::endl;
  std::wcout << industrias << std::endl;

  // peticion de companias por industria
  PeticionCompaniasPorIndustria companias;
  companias.Solicita(L"Telecom Services - Foreign");
  std::wcout << "------------- Companias --------------" << std::endl;
  std::wcout << companias << std::endl;

  // peticion de la posicion del ultimo dia de google
  PeticionPosicionUltimoDia ultimoDiaCompania;
  ultimoDiaCompania.Solicita(L"GOOG");
  std::wcout << "------------- Google --------------" << std::endl;
  std::wcout << ultimoDiaCompania << std::endl;

  // listado de divisas
  std::wcout << "------------- Currencies --------------" << std::endl;
  Currencies & currencies = Currencies::Instance();

  for (auto iter = currencies.cbegin(); iter != currencies.cend(); ++iter)
  {
    std::wcout << *iter << std::endl;
  }

  // peticion de cambio entre divisas
  PeticionCambioDivisa cambioDivisa;
  auto div1Iter = currencies.cbegin();
  auto div2Iter = div1Iter + 1;

  auto div1Id = div1Iter->getValue(L"Id");
  auto div2Id = div2Iter->getValue(L"Id");

  cambioDivisa.Solicita(div1Id, div2Id);
  std::wcout << "------------- Cambio divisas --------------" << std::endl;
  std::wcout << cambioDivisa << std::endl;

  return 0;
}
