#include "Medico.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>


Medico::Medico(std::string nombre, int id, std::string especialidad)
    : nombre(nombre), id(id), especialidad(especialidad) {
}

void Medico::altaMedico(std::vector<Medico>& medicos, std::string nombre, int id, std::string especialidad) {
    int nuevoID = obtenerUltimoID() + 1;
    Medico nuevoMedico(nombre, nuevoID, especialidad);
    medicos.push_back(nuevoMedico);
    guardarMedicoEnArchivo(nuevoMedico);
}

void Medico::bajaMedico(std::vector<Medico>& medicos, int id) {
    medicos.erase(std::remove_if(medicos.begin(), medicos.end(), [id](Medico& m) {
        return m.id == id;
        }), medicos.end());

    std::ifstream archivoEntrada("medicos.txt");
    std::ofstream archivoTemporal("medicos_temp.txt");

    if (archivoEntrada.is_open() && archivoTemporal.is_open()) {
        std::string linea;
        while (std::getline(archivoEntrada, linea)) {
            std::istringstream iss(linea);
            std::string medicoId;
            std::getline(iss, medicoId, ',');

            int idMedico;
            std::stringstream ss(medicoId);
            ss >> idMedico;
            if (idMedico != id) {
                archivoTemporal << linea << "\n";
            }

        }
        archivoEntrada.close();
        archivoTemporal.close();

        std::remove("medicos.txt");
        std::rename("medicos_temp.txt","medicos.txt");
    }
    else {
        std::cerr << "No se pudo abrir el archivo para modificar los datos de los medicos.\n";
    }


}

void Medico::listarMedicosDesdeArchivo() {
    std::ifstream archivo("medicos.txt");
    if (archivo.is_open()) { 
        std::string linea; 
        while (std::getline(archivo, linea)) { 
            std::istringstream iss(linea);
            std::string id, nombre, especialidad;
            std::getline(iss, id, ',');
            std::getline(iss, nombre, ',');
            std::getline(iss, especialidad, ',');
            std::cout << "ID: " << id << ", Nombre: " << nombre << ", Especialidad: " << especialidad << std::endl;
        }
        archivo.close(); 
    }
    else {
        std::cerr << "No se pudo abrir el archivo para leer los datos de los médicos.\n";
    }
}

void Medico::guardarMedicoEnArchivo(const Medico& medico) {
    std::ofstream archivo("medicos.txt", std::ios::app); // Abre el archivo en modo "append" para añadir sin borrar
    if (archivo.is_open()) {
        archivo << medico.id << "," << medico.nombre << "," << medico.especialidad << "\n";
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo para guardar los datos del médico.\n";
    }
}

void Medico::mostrarInformacionMedico(int id) {
    std::ifstream archivo("medicos.txt");
    if (archivo.is_open()) {
        std::string linea;
        bool encontrado = false;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string idStr, nombre, especialidad;
            std::getline(iss, idStr, ',');
            std::getline(iss, nombre, ',');
            std::getline(iss, especialidad, ',');

            int idMedico;
            std::stringstream ss(idStr);
            ss >> idMedico;

            if (idMedico == id) {
                std::cout << "Información del médico:\n";
                std::cout << "ID: " << idMedico << "\n";
                std::cout << "Nombre: " << nombre << "\n";
                std::cout << "Especialidad :" << especialidad << "\n";
                encontrado = true;
                break;
            }
        }
        archivo.close();
        if (!encontrado) {
            std::cout << "Médico con ID " << id << "no encontrado. \n";
        }

    }
    else {
        std::cerr << "No se pudo abrir el archivo para leer los datos de los médicos. \n";
    }
}

int Medico::obtenerUltimoID() {
    std::ifstream archivo("medicos.txt");
    int ultimoID = 0;
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string idStr;
            std::getline(iss, idStr, ',');

            int idMedico;
            std::stringstream ss(idStr);
            ss >> idMedico;
            ultimoID = idMedico;

        }
        archivo.close();
    }
    return ultimoID;
}
