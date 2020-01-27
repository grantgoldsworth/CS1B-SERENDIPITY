cmake_minimum_required(VERSION 3.15)
project(A4)

set(CMAKE_CXX_STANDARD 14)

add_executable(A4 main.cpp functions.h CashierFunction.cpp InventoryFunction.cpp ReportsFunction.cpp GetChoice.cpp BookInformation.cpp invmenu.cpp inventory.h reports.h reports.cpp)