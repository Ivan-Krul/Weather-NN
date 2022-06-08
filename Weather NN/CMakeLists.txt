# CMakeList.txt: проект CMake для Weather NN; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

set(APP_ICON_RESOURCE_WINDOWS "WeatherNN.rc")


# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeTarget "Weather NN.cpp" ${APP_ICON_RESOURCE_WINDOWS})

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
