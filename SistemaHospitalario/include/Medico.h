#ifndef MEDICO_H
#define MEDICO_H

#include "Persona.h"
#include <string>
#include <vector>

class Medico : public Persona {
public:
    std::string especialidad;

	Medico();
    Medico(std::string nombre, int id, std::string especialidad);

    static void altaMedico(std::vector<Medico>& medicos, std::string nombre, int id, std::string especialidad);
    static void bajaMedico(std::vector<Medico>& medicos, int id);
    static void listarMedicosDesdeArchivo();
    void guardarEnArchivo() const override;
    void mostrarInformacion() const override;

	std::string toString() const override;
	void fromString(const std::string& str) override;
};

#endif
