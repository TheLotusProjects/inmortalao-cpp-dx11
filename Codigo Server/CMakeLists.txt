cmake_minimum_required (VERSION 2.6)
project (Servidor)
# The version number.
set (Servidor_VERSION_MAJOR 1)
set (Servidor_VERSION_MINOR 0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAG} -std=c++11 -pthread")

find_package(PkgConfig)
pkg_check_modules(LIBBSONXX REQUIRED libbsoncxx)
pkg_check_modules(LIBMONGOCXX REQUIRED libmongocxx)
include_directories(${LIBMONGOCXX_INCLUDE_DIRS} ${LIBBSONCXX_INCLUDE_DIRS})
link_directories(${LIBMONGOCXX_LIBRARY_DIRS} ${LIBBSONCXX_LIBRARY_DIRS})

##################### MONGODB #########################
find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")
include_directories("/usr/local/include/libmongoc-1.0")
include_directories("/usr/local/include/libbson-1.0")
include_directories("/usr/local/lib")
include_directories("/usr/local/include")
#####################################################

include_directories("${PROJECT_BINARY_DIR}")
include_directories(${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/src)


add_library(libJson STATIC IMPORTED)
set_property(TARGET libJson PROPERTY IMPORTED_LOCATION ./lib/libjsoncpp.a)


file (GLOB DB_FILES "./src/DB/*.cpp" "./src/DB/*.h")
source_group("DB" FILES ${DB_FILES})

file (GLOB CONEXION_FILES "./src/Conexion/UDPConnection/*.cpp" "./src/Conexion/UDPConnection/*.h")
source_group("Conexion" FILES ${CONEXION_FILES})

file (GLOB CARGADORES_FILES "./src/Cargadores/*.cpp" "./src/Cargadores/*.h")
source_group("Cargadores" FILES ${CARGADORES_FILES})

file (GLOB MESSAGIN_FILES "./src/Conexion/Messagin/*.cpp" "./src/Conexion/Messagin/*.h")
source_group("Mensages" FILES ${MESSAGIN_FILES})

file (GLOB COMMON_FILES "./src/Common/*.cpp" "./src/Common/*.h")
source_group("Common" FILES ${COMMON_FILES})


# add the executable
add_executable(Servidor ./src/main.cpp ./src/Program.cpp ${DB_FILES} ${CONEXION_FILES} ${CARGADORES_FILES} ${MESSAGIN_FILES} ${COMMON_FILES})


target_link_libraries(Servidor libJson)


file (GLOB TESTING_FILES "./Testing/*.cpp" "./Testing/*.h")
source_group("Testing" FILES ${TESTING_FILES} )

# add the executable tests
add_executable(Test ${TESTING_FILES} ${DB_FILES} ${CONEXION_FILES} ${CARGADORES_FILES} ${MESSAGIN_FILES} ${COMMON_FILES})

target_link_libraries(Test gtest gtest_main libJson)

############## MONGODB  ############################
target_link_libraries(Servidor ${LIBMONGOCXX_LIBRARIES})
target_link_libraries(Servidor ${LIBBSONCXX_LIBRARIES})

target_link_libraries(Test ${LIBMONGOCXX_LIBRARIES})
target_link_libraries(Test ${LIBBSONCXX_LIBRARIES})



