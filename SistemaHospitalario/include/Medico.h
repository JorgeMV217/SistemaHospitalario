#ifndef MEDICO_H
#define MEDICO_H

#include <string>
#include <vector>

class Medico {
public:
    std::string nombre;
    int id;
    std::string especialidad;

    Medico(std::string nombre, int id, std::string especialidad);

    static void altaMedico(std::vector<Medico>& medicos, std::string nombre, int id, std::string especialidad);
    static void bajaMedico(std::vector<Medico>& medicos, int id);
    static void listarMedicosDesdeArchivo();
    static void guardarMedicoEnArchivo(const Medico& medico);
    static int obtenerUltimoID();
    static void mostrarInformacionMedico(int id);
};

#endif
