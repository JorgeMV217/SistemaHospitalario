#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
public:
    std::string nombre;
    int id;

    Persona();
    Persona(std::string nombre, int id);

    virtual void guardarEnArchivo() const = 0;
    virtual void mostrarInformacion() const = 0;
    virtual std::string toString() const = 0;
    virtual void fromString(const std::string& str) = 0;
};

#endif
