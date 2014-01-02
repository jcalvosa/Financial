
#ifndef __PeticionIndustriasPorSector_hh__
#define __PeticionIndustriasPorSector_hh__

#include <map>

#include "clienteRest/IClientePeticiones.hh"
#include "PeticionAtributos.hh"


class PeticionIndustriasPorSector : public IClientePeticiones, public PeticionAtributos
{
  public:
    PeticionIndustriasPorSector();

    virtual ~PeticionIndustriasPorSector();

    void Solicita(const std::wstring & sector);

  private:
    static const std::map<Attrib, Value> _yahooSectorIds; 

    // IClientePeticiones interfaz
    virtual void Acepta(std::wstringstream & mensaje);
};

#endif
