# CMakeList.txt: PopPilot için CMake projesi, kaynağı ekleyin ve tanımlayın
# projeye özgü mantık burada bulunur.
#

cmake_minimum_required(VERSION 3.12)

# Proje adını belirleyin
project(PopPilot)

# Kaynağı bu projenin yürütülebilir dosyasına ekleyin.
add_executable(PopPilot 
    "PopPilot.c" 
    "PopPilot.h" 
    "GameEngine/Main.h" 
    "GameEngine/Imports.h" 
    "GameEngine/ScreenStuff/Screen.h" 
    "GameEngine/ScreenStuff/Layer.c" 
    "GameEngine/ScreenStuff/Screen.c" 
    "GameEngine/GameLoop/FrameController.c"
    "GameEngine/GameLoop/FrameController.h"
    "GameEngine/GameLoop/SystemInfo.c"
    "GameEngine/GameLoop/SystemInfo.h" 
    "GameEngine/ExtraFeatures.c"
)

# C++ standardını belirleyin
if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET PopPilot PROPERTY CXX_STANDARD 20)
endif()

# TODO: Gerekirse testleri ve yükleme hedeflerini ekleyin.
