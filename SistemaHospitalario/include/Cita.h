#ifndef CITA_H
#define CITA_H

#include <string>
#include <vector>

class CitaMedica {
public:
    int idCita;
    int idPaciente;
    int idMedico;
    std::string fecha;
    bool esUrgente;

    CitaMedica(int idCita, int idPaciente, int idMedico, std::string fecha, bool esUrgente);

    static void asignarCita(std::vector<CitaMedica>& citas, int idCita, int idPaciente, int idMedico, std::string fecha, bool esUrgente);
    static void cancelarCita(std::vector<CitaMedica>& citas, int idCita);
    static void listarCitasDesdeArchivo();
    static void guardarCitaEnArchivo(const CitaMedica& cita);
    static int obtenerUltimoID();
};

#endif
