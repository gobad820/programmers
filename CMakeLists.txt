cmake_minimum_required(VERSION 3.31)
project(Programmers)

set(CMAKE_CXX_STANDARD 17)


# 1) 실행 파일은 모두 build/bin 에서 생성
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 기존에 사용하던 problems 자동 빌드 설정
file(GLOB_RECURSE PROBLEM_SRCS "${CMAKE_SOURCE_DIR}/problems/*.cpp")
foreach(src ${PROBLEM_SRCS})
    get_filename_component(bin ${src} NAME_WE)
    add_executable(${bin} ${src})
endforeach()
#add_executable(Programmers main.cpp
#        level_2/test.cc)
