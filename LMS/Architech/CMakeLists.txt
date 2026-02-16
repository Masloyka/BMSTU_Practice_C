cmake_minimum_required(VERSION 3.10)
project(LinkedList C)

set(LIST linked_list.c)

add_executable(program main.c ${LIST})