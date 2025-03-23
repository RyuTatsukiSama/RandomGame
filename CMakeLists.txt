cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(RandomGame)

# Utilisation du standard C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Recherche automatique de tous les fichiers .cpp (récursivement dans les sous-dossiers)
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/*.cpp")
list(FILTER SOURCES EXCLUDE REGEX "CMakeCXXCompilerId\\.cpp")

# Création de l'exécutable
add_executable(RandomGame ${SOURCES})