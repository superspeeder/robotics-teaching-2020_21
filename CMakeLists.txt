project(RoboticsCXX LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(RoboticsCXX_Teaching0 teaching_0.cpp)
add_executable(RoboticsCXX_Teaching1 teaching_1.cpp)
add_executable(RoboticsCXX_Teaching2 teaching_2.cpp)

add_executable(RoboticsCXX_Lesson1 src/lesson_1.cpp)
add_executable(RoboticsCXX_Lesson2 src/lesson_2.cpp)
add_executable(RoboticsCXX_Lesson3 src/lesson_3.cpp)
add_executable(RoboticsCXX_Lesson4 src/lesson_4.cpp)
