cmake_minimum_required(VERSION 3.16)
project(suan_fa_tu_jie_note)

set(CMAKE_CXX_STANDARD 14)

add_executable(binary_search
        binary_search.c)

add_executable(selection_sort
        selection_sort.c)

add_executable(sum_recursion
        divide_and_conquer/sum_recursion.c)

add_executable(quick_sort
        divide_and_conquer/quick_sort.c)

add_executable(dqueue_test
        graph/dqueue/test.c
        graph/dqueue/dqueue.h
        graph/dqueue/dqueue.c)

add_executable(math_demo
        basic/math_demo.c)

add_executable(bubble_sort
        sort/bubble_sort.c)


