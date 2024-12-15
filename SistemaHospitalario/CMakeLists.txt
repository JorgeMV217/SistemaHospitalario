# CMakeList.txt: proyecto de CMake para SistemaHospitalario, incluya el origen y defina
# la lógica específica del proyecto aquí.
#

# Agregue un origen al ejecutable de este proyecto.

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SistemaHospitalario PROPERTY CXX_STANDARD 20)
endif()

# TODO: Agregue pruebas y destinos de instalación si es necesario.
include_directories(include)

add_executable(SistemaHospitalario src/Paciente.cpp src/Medico.cpp src/Cita.cpp src/SistemaHospitalario.cpp main.cpp)