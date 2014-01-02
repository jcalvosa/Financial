
#ifndef __PeticionTodosSectores_h__
#define __PeticionTodosSectores_h__

#include "clienteRest/IClientePeticiones.hh"
#include "PeticionAtributos.hh"


class PeticionTodosSectores : public IClientePeticiones, public PeticionAtributos
{
  public:
    PeticionTodosSectores();

    virtual ~PeticionTodosSectores();

    void Solicita();

  private:
    // IClientePeticiones interfaz
    virtual void Acepta(std::wstringstream & mensaje);
};


#endif
