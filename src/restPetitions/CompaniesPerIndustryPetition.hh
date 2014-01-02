

#ifndef __PeticionCompaniasPorIndustria_hh__
#define __PeticionCompaniasPorIndustria_hh__

#include "clienteRest/IClientePeticiones.hh"
#include "PeticionAtributos.hh"

class PeticionCompaniasPorIndustria : public IClientePeticiones, public PeticionAtributos
{
  public:
    PeticionCompaniasPorIndustria();

    virtual ~PeticionCompaniasPorIndustria();

    void Solicita(const std::wstring & industry);

  private:
    // IClientePeticiones interfaz
    virtual void Acepta(std::wstringstream & mensaje);
};

#endif
