cmake_minimum_required(VERSION 3.5)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(esp32app)

set_target_properties(idf_component_main PROPERTIES LINKER_LANGUAGE C)
set_target_properties(idf_component_internal PROPERTIES LINKER_LANGUAGE C)
set_target_properties(idf_component_utils PROPERTIES LINKER_LANGUAGE C)
set_target_properties(idf_component_wifi PROPERTIES LINKER_LANGUAGE C)