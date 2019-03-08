cmake_minimum_required(VERSION 3.13)
project(mini_lang_compiler C)

set(CMAKE_C_STANDARD 11)

add_executable(mini_lang_compiler src/cfg.c src/mesinkarakter.c src/scanner.c src/stack.c)