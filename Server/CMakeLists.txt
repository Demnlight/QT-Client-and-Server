cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ServerProject VERSION 1.0.0 LANGUAGES CXX)

find_package(PostgreSQL REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_check_modules(PQXX REQUIRED libpqxx)

find_package(Qt6 REQUIRED COMPONENTS Widgets Network)
qt_standard_project_setup()

add_subdirectory(src)