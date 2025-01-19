#include "Cita.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

CitaMedica::CitaMedica(int idCita, int idPaciente, int idMedico, std::string fecha, bool esUrgente)
    : idCita(idCita), idPaciente(idPaciente), idMedico(idMedico), fecha(fecha), esUrgente(esUrgente) {
}

void CitaMedica::asignarCita(std::vector<CitaMedica>& citas, int idCita, int idPaciente, int idMedico, std::string fecha, bool esUrgente) {
    int nuevoIDCita = obtenerUltimoID() + 1;
    CitaMedica nuevaCita(nuevoIDCita, idPaciente, idMedico, fecha, esUrgente);
    citas.push_back(nuevaCita);
    guardarCitaEnArchivo(nuevaCita);
}

void CitaMedica::cancelarCita(std::vector<CitaMedica>& citas, int idCita) {
    citas.erase(std::remove_if(citas.begin(), citas.end(), [idCita](CitaMedica& c) {
        return c.idCita == idCita;
        }), citas.end());

    std::ifstream archivoEntrada("citas.txt");
    std::ofstream archivoTemporal("citas_temp.txt");

    if (archivoEntrada.is_open() && archivoTemporal.is_open()) {
        std::string linea;
        while (std::getline(archivoEntrada, linea)) {
            std::istringstream iss(linea);
            std::string idCitaStr;
            std::getline(iss, idCitaStr, ',');

            int idCitaArchivo;
            std::stringstream ss(idCitaStr);
            ss >> idCitaArchivo;
            if (idCitaArchivo != idCita) {
                archivoTemporal << linea << "\n";
            }
        }
        archivoEntrada.close();
        archivoTemporal.close();

        std::remove("citas.txt");
        std::rename("citas_temp.txt", "citas.txt");
    }
    else {
        std::cerr << "No se pudo abrir el archivo para modificar los datos de las citas.\n";
    }
    
}

void CitaMedica::listarCitasDesdeArchivo() {
    std::ifstream archivo("citas.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string idCita, idPaciente, idMedico, fecha, esUrgente;
            std::getline(iss, idCita, ',');
            std::getline(iss, idPaciente, ',');
            std::getline(iss, idMedico, ',');
            std::getline(iss, fecha, ',');
            std::getline(iss, esUrgente, ',');
            std::cout << "ID Cita: " << idCita << ", ID Paciente: " << idPaciente << ", ID Médico: " << idMedico << ", Fecha: " << fecha << ", Urgente: " << esUrgente << std::endl;
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
        archivo << cita.idCita << "," << cita.idPaciente << "," << cita.idMedico << "," << cita.fecha << "," << (cita.esUrgente ? "Sí" : "No") << "\n";
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para guardar los datos de la cita.\n";
    }
}

void CitaMedica::mostrarInformacionCita(int idCita) {
    std::ifstream archivo("citas.txt");
    if (archivo.is_open()) {
        std::string linea;
        bool encontrado = false;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string idCitaStr, idPaciente, idMedico, fecha, esUrgente;
            std::getline(iss, idCitaStr, ',');
            std::getline(iss, idPaciente, ',');
            std::getline(iss, idMedico, ',');
            std::getline(iss, fecha, ',');
            std::getline(iss, esUrgente, ',');

            int idCitaArchivo;
            std::stringstream ss(idCitaStr);
            ss >> idCitaArchivo;

            if (idCitaArchivo == idCita) {
                std::cout << "Información de la cita:\n";
                std::cout << "ID: " << idCitaArchivo << "\n";
                std::cout << "ID del paciente: " << idPaciente << "\n";
                std::cout << "ID del médico: " << idMedico << "\n";
                std::cout << "Fecha: " << fecha << "\n";
                std::cout << "¿Es Urgente? " << esUrgente << "\n";
                encontrado = true;
                break;
            }
        }
        archivo.close();
        if (!encontrado) {
            std::cout << "Cita con ID " << idCita << "no encontrada. \n";
        }

    }
    else {
        std::cerr << "No se pudo abrir el archivo para leer los datos de las citas. \n";
    }
}


int CitaMedica::obtenerUltimoID() {
    std::ifstream archivo("citas.txt");
    int ultimoID = 0;
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string idCitaStr;
            std::getline(iss, idCitaStr, ',');

            int idCita;
            std::stringstream ss(idCitaStr);
            ss >> idCita;
            ultimoID = idCita;      
            
        }
        archivo.close();
        return ultimoID;
    }else {
        std::cerr << "No se pudo abrir el archivo para leer los datos de las citas.\n";
    }
    return ultimoID;
}
