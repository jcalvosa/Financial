
#ifndef __PeticionCambioDivisa_hh__
#define __PeticionCambioDivisa_hh__


#include "clienteRest/IClientePeticiones.hh"
#include "PeticionAtributos.hh"

class PeticionCambioDivisa : public IClientePeticiones, public PeticionAtributos
{
  public:
    PeticionCambioDivisa();

    virtual ~PeticionCambioDivisa();

    void Solicita(const std::wstring & idDivisa1, const std::wstring & idDivisa2);

  private:
    // IClientePeticiones interfaz
    virtual void Acepta(std::wstringstream & mensaje);
};

#endif
