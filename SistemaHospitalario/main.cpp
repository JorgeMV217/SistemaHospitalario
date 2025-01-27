#include <iostream>
#include <vector>
#include <wchar.h>
#include <locale>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

using namespace std;

void gestionarPacientes(vector<Paciente>& pacientes) {
    int opcion;
    string nombre;
    int id;
    string fechaIngreso;

    do {
        cout << "\nGesti�n de Pacientes\n";
        cout << "1. Alta de paciente\n";
        cout << "2. Baja de paciente\n";
        cout << "3. Listar pacientes\n";
        cout << "4. Mostrar informaci�n de un paciente por ID\n";
        cout << "5. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Fecha de Ingreso: ";
            getline(cin, fechaIngreso);
            Paciente::altaPaciente(pacientes, nombre, 0, fechaIngreso);
            break;
        case 2:
            cout << "ID del paciente a dar de baja: ";
            cin >> id;
            Paciente::bajaPaciente(pacientes, id);
            break;
        case 3:
            Paciente::listarPacientesDesdeArchivo();
            break;
        case 4:
            cout << "ID del paciente a mostrar: ";
            cin >> id;
            Paciente::mostrarInformacionPaciente(id);
            break;
        case 5:
            return;
        default:
            cout << "Opci�n no v�lida.\n";
            break;
        }
    } while (opcion != 4);
}

void gestionarMedicos(vector<Medico>& medicos) {
    int opcion;
    string nombre;
    int id;
    string especialidad;

    do {
        cout << "\nGesti�n de M�dicos\n";
        cout << "1. Alta de m�dico\n";
        cout << "2. Baja de m�dico\n";
        cout << "3. Listar m�dicos\n";
        cout << "4. Mostrar informaci�n de un m�dico\n";
        cout << "5. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Especialidad: ";
            getline(cin, especialidad);
            Medico::altaMedico(medicos, nombre, 0, especialidad);
            break;
        case 2:
            cout << "ID del m�dico a dar de baja: ";
            cin >> id;
            Medico::bajaMedico(medicos, id);
            break;
        case 3:
            Medico::listarMedicosDesdeArchivo();
            break;
        case 4:
            cout << "ID del m�dico a mostrar: ";
            cin >> id;
            Medico::mostrarInformacionMedico(id);
            break;
        case 5:
            return;
        default:
            cout << "Opci�n no v�lida.\n";
            break;
        }
    } while (opcion != 4);
}

void gestionarCitas(vector<CitaMedica>& citas, const vector<Paciente>& pacientes, const vector<Medico>& medicos) {
    int opcion;
    int idCita;
    int idPaciente;
    int idMedico;
    string fecha;
    bool esUrgente;

    do {
        cout << "\nGesti�n de Citas\n";
        cout << "1. Asignar cita\n";
        cout << "2. Cancelar cita\n";
        cout << "3. Listar citas\n";
        cout << "4. Mostrar informaci�n de una cita\n";
        cout << "5. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            cout << "ID del Paciente: ";
            cin >> idPaciente;
            cout << "ID del M�dico: ";
            cin >> idMedico;
            cout << "Fecha (YYYY-MM-DD): ";
            cin >> fecha;
            cout << "Es urgente? (1 para s�, 0 para no): ";
            cin >> esUrgente;
            CitaMedica::asignarCita(citas, 0, idPaciente, idMedico, fecha, esUrgente);
            break;
        case 2:
            cout << "ID de la Cita: ";
            cin >> idCita;
            CitaMedica::cancelarCita(citas, idCita);
            break;
        case 3:
            CitaMedica::listarCitasDesdeArchivo();
            break;
        case 4:
            cout << "ID de la Cita a mostrar: ";
            cin >> idCita;
            CitaMedica::mostrarInformacionCita(idCita);
            break;
        case 5:
            return;
        default:
            cout << "Opci�n no v�lida.\n";
            break;
        }
    } while (opcion != 4);
}

int main() {

    setlocale(LC_ALL, "");
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    vector<CitaMedica> citas;

    int opcion;

    do {
        cout << "\nMen� Principal\n";
        cout << "1. Gestionar Pacientes\n";
        wcout << "2. Gestionar M�dicos\n";
        cout << "3. Gestionar Citas\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            gestionarPacientes(pacientes);
            break;
        case 2:
            gestionarMedicos(medicos);
            break;
        case 3:
            gestionarCitas(citas, pacientes, medicos);
            break;
        case 4:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opci�n no v�lida.\n";
            break;
        }
    } while (opcion != 4);

    return 0;
}
