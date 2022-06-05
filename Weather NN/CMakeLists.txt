# CMakeList.txt: проект CMake для Weather NN; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeTarget "Weather NN.cpp" "Weather NN.h")
#add_subdirectory (CMakeTarget "Neural Network/Neural Network.cpp" "Neural Network/Neural Network.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
