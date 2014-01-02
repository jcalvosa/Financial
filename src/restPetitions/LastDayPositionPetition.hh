
#ifndef __PeticionPosicionUltimoDia_h__
#define __PeticionPosicionUltimoDia_h__

#include <string>

#include "clienteRest/IClientePeticiones.hh"
#include "PeticionAtributos.hh"


class PeticionPosicionUltimoDia : public IClientePeticiones, public PeticionAtributos
{
  public:
    PeticionPosicionUltimoDia();

    virtual ~PeticionPosicionUltimoDia();

    void Solicita(const std::wstring & id);

  private:
    // ICliente interfaz
    virtual void Acepta(std::wstringstream & mensaje);
};

#endif
