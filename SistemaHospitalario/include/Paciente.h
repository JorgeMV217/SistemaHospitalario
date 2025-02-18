#ifndef PACIENTE_H
#define PACIENTE_H

#include "Persona.h"
#include <string>
#include <vector>

class Paciente : public Persona {
public:
    std::string fechaIngreso;

    Paciente();
    Paciente(std::string nombre, int id, std::string fechaIngreso);

    static void altaPaciente(std::vector<Paciente>& pacientes, std::string nombre, int id, std::string fechaIngreso);
    static void bajaPaciente(std::vector<Paciente>& pacientes, int id);
    static void listarPacientesDesdeArchivo();
    void guardarEnArchivo() const override;
    void mostrarInformacion() const override;

    std::string toString() const override;
	void fromString(const std::string& str) override;

};

#endif

