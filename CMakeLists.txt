cmake_minimum_required(VERSION 4.1)
project(Automatyfinal_2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Automatyfinal_2
        keyboard.c
        keyboard.h
        led.c
        led.h
        main.c)
