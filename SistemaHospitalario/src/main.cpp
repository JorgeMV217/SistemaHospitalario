#include <iostream>
#include <vector>
#include <wchar.h>
#include <locale>
#include "Archivos.h"
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"


void gestionarPacientes(std::vector<Paciente>& pacientes) {
    int opcion;
    std::string nombre;
    int id;
    std::string fechaIngreso;

    do {
        std::cout << "\nGestión de Pacientes\n";
        std::cout << "1. Alta de paciente\n";
        std::cout << "2. Baja de paciente\n";
        std::cout << "3. Listar pacientes\n";
        std::cout << "4. Mostrar información de un paciente por ID\n";
        std::cout << "5. Volver al menú principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:
            std::cout << "Nombre: ";
            std::getline(std::cin, nombre);
            std::cout << "Fecha de Ingreso: ";
            std::getline(std::cin, fechaIngreso);
            Paciente::altaPaciente(pacientes, nombre, 0, fechaIngreso);
            break;
        case 2:
            std::cout << "ID del paciente a dar de baja: ";
            std::cin >> id;
            Paciente::bajaPaciente(pacientes, id);
            break;
        case 3:
            Paciente::listarPacientesDesdeArchivo();
            break;
        case 4:
            std::cout << "ID del paciente a mostrar: ";
            std::cin >> id;
			for (const Paciente& paciente : pacientes) {
				if (paciente.id == id) {
					paciente.mostrarInformacion();
					break;
				}
			}
            break;
        case 5:
            return;
        default:
            std::cout << "Opción no válida.\n";
            break;
        }
    } while (opcion != 4);
}

void gestionarMedicos(std::vector<Medico>& medicos) {
    int opcion;
    std::string nombre;
    int id;
    std::string especialidad;

    do {
        std::cout << "\nGestión de Médicos\n";
        std::cout << "1. Alta de médico\n";
        std::cout << "2. Baja de médico\n";
        std::cout << "3. Listar médicos\n";
        std::cout << "4. Mostrar información de un médico\n";
        std::cout << "5. Volver al menú principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:
            std::cout << "Nombre: ";
            std::getline(std::cin, nombre);
            std::cout << "Especialidad: ";
            std::getline(std::cin, especialidad);
            Medico::altaMedico(medicos, nombre, 0, especialidad);
            break;
        case 2:
            std::cout << "ID del médico a dar de baja: ";
            std::cin >> id;
            Medico::bajaMedico(medicos, id);
            break;
        case 3:
            Medico::listarMedicosDesdeArchivo();
            break;
        case 4:
            std::cout << "ID del médico a mostrar: ";
            std::cin >> id;
            for (const Medico& medico : medicos) {
                if (medico.id == id) {
                    medico.mostrarInformacion();
                    break;
                }
            }
                break;
        case 5:
            return;
        default:
            std::cout << "Opción no válida.\n";
            break;
            }
    } while (opcion != 5);
}

void gestionarCitas(std::vector<CitaMedica>& citas) {
    int opcion;
    int idCita;
    int idPaciente;
    int idMedico;
    std::string fecha;
    bool esUrgente;

    do {
        std::cout << "\nGestión de Citas\n";
        std::cout << "1. Asignar cita\n";
        std::cout << "2. Cancelar cita\n";
        std::cout << "3. Listar citas\n";
        std::cout << "4. Mostrar información de una cita\n";
        std::cout << "5. Volver al menú principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:
            std::cout << "ID del Paciente: ";
            std::cin >> idPaciente;
            std::cout << "ID del Médico: ";
            std::cin >> idMedico;
            std::cout << "Fecha (YYYY-MM-DD): ";
            std::cin >> fecha;
            std::cout << "Es urgente? (1 para sí, 0 para no): ";
            std::cin >> esUrgente;
            CitaMedica::asignarCita(citas, 0, idPaciente, idMedico, fecha, esUrgente);
            break;
        case 2:
            std::cout << "ID de la Cita: ";
            std::cin >> idCita;
            CitaMedica::cancelarCita(citas, idCita);
            break;
        case 3:
            CitaMedica::listarCitasDesdeArchivo();
            break;
        case 4:
            std::cout << "ID de la Cita a mostrar: ";
            std::cin >> idCita;
			for (const CitaMedica& cita : citas) {
				if (cita.idCita == idCita) {
					cita.mostrarInformacionCita(idCita);
					break;
				}
			}
            break;
        case 5:
            return;
        default:
            std::cout << "Opción no válida.\n";
            break;
        }
    } while (opcion != 5);
}

int main() {

    setlocale(LC_ALL, "");
    std::vector<Paciente> pacientes;
    std::vector<Medico> medicos;
    std::vector<CitaMedica> citas;

    int opcion;

    do {
        std::cout << "\nMenú Principal\n";
        std::cout << "1. Gestionar Pacientes\n";
        std::wcout << "2. Gestionar Médicos\n";
        std::cout << "3. Gestionar Citas\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            gestionarPacientes(pacientes);
            break;
        case 2:
            gestionarMedicos(medicos);
            break;
        case 3:
            gestionarCitas(citas);
            break;
        case 4:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opción no válida.\n";
            break;
        }
    } while (opcion != 4);

    return 0;
}
