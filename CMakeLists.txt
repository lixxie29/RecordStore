cmake_minimum_required(VERSION 3.22)
project(RecordStore)

set(CMAKE_CXX_STANDARD 14)

add_executable(RecordStore main.cpp
        Record.cpp
        Record.h
        Repository.cpp
        Repository.h
        UserInterface.cpp
        UserInterface.h
        Controller.cpp
        Controller.h
        Undo.cpp
        Undo.h)