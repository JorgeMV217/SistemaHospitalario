#include "Cita.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

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

void CitaMedica::listarCitasDesdeArchivo() {
    std::ifstream archivo("../SistemaHospitalario/data/citas.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string idPaciente, idMedico, fecha, esUrgente;
            std::getline(iss, idPaciente, ',');
            std::getline(iss, idMedico, ',');
            std::getline(iss, fecha, ',');
            std::getline(iss, esUrgente, ',');
            std::cout << "ID Paciente: " << idPaciente << ", ID Médico: " << idMedico << ", Fecha: " << fecha << ", Urgente: " << esUrgente << std::endl;
        }
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para leer los datos de las citas.\n";
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