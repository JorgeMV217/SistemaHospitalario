# CMakeList.txt: proyecto de CMake para SistemaHospitalario, incluya el origen y defina
# la lógica específica del proyecto aquí.
#

# Agregue un origen al ejecutable de este proyecto.
add_executable (SistemaHospitalario   "include/Paciente.h" "include/Medico.h" "include/Cita.h" "src/Cita.cpp" "src/Medico.cpp" "src/Paciente.cpp" "main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SistemaHospitalario PROPERTY CXX_STANDARD 20)
endif()

# TODO: Agregue pruebas y destinos de instalación si es necesario.
