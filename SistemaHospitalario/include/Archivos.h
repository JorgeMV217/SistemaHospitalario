#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <string>
#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

class Archivos {
public:
    static void guardarPaciente(const Paciente& paciente);
    static void eliminarPaciente(int id);
    static std::vector<Paciente> listarPacientes();
    static int obtenerUltimoIDPaciente();

    static void guardarMedico(const Medico& medico);
    static void eliminarMedico(int id);
    static std::vector<Medico> listarMedicos();
    static int obtenerUltimoIDMedico();

    static void guardarCita(const CitaMedica& cita);
    static void eliminarCita(int idCita);
    static std::vector<CitaMedica> listarCitas();
    static int obtenerUltimoIDCita();
};

#endif
