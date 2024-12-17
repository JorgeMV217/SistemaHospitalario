#include "Cita.h"
#include <iostream>
#include <algorithm>
#include <fstream>

CitaMedica::CitaMedica(int idPaciente, int idMedico, std::string fecha, bool esUrgente)
    : idPaciente(idPaciente), idMedico(idMedico), fecha(fecha), esUrgente(esUrgente) {
}

void CitaMedica::asignarCita(std::vector<CitaMedica>& citas, int idPaciente, int idMedico, std::string fecha, bool esUrgente) {
    CitaMedica nuevaCita(idPaciente, idMedico, fecha, esUrgente);
    citas.push_back(nuevaCita);
    guardarCitaEnArchivo(nuevaCita);
}

void CitaMedica::cancelarCita(std::vector<CitaMedica>& citas, int idPaciente, int idMedico) {
    citas.erase(std::remove_if(citas.begin(), citas.end(), [idPaciente, idMedico](CitaMedica& c) { return c.idPaciente == idPaciente && c.idMedico == idMedico; }), citas.end());
}

void CitaMedica::listarCitas(const std::vector<CitaMedica>& citas) {
    for (const auto& cita : citas) {
        std::cout << "ID Paciente: " << cita.idPaciente << ", ID Médico: " << cita.idMedico << ", Fecha: " << cita.fecha << ", Urgente: " << (cita.esUrgente ? "Sí" : "No") << std::endl;
    }
}

void CitaMedica::guardarCitaEnArchivo(const CitaMedica& cita) {
    std::ofstream archivo("citas.txt", std::ios::app); // Abre el archivo en modo "append" para añadir sin borrar
    if (archivo.is_open()) {
        archivo << cita.idPaciente << "," << cita.idMedico << "," << cita.fecha << "," << (cita.esUrgente ? "Sí" : "No") << "\n";
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para guardar los datos de la cita.\n";
    }
}
