cmake_minimum_required(VERSION 3.10)
project(API C)

set(HTTP http/http.c)
set(NET net/net.c)

add_executable(program main.c ${HTTP} ${NET})