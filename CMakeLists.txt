cmake_minimum_required(VERSION 3.5)
#
# Checking for most recent ESP-IDF
#
message("ESP_IDF path: " $ENV{IDF_PATH})
message("Project path: " ${CMAKE_CURRENT_SOURCE_DIR})

execute_process(COMMAND "git" "pull" WORKING_DIRECTORY $ENV{IDF_PATH})
execute_process(COMMAND "git" "submodule" "update" "--init" "--recursive" WORKING_DIRECTORY $ENV{IDF_PATH} RESULT_VARIABLE git_result OUTPUT_VARIABLE git_out)

#
# Setting linker settings for components
#
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(app)

MACRO(SUBDIRLIST result curdir)
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
    SET(dirlist "")
    FOREACH (child ${children})
        IF (IS_DIRECTORY ${curdir}/${child})
            LIST(APPEND dirlist ${child})
        ENDIF ()
    ENDFOREACH ()
    SET(${result} ${dirlist})
ENDMACRO()

MACRO(REGISTER_LINKER)
    SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR}/components)
    FOREACH (subdir ${SUBDIRS})
        message("Setting linker for " ${subdir})
        set_target_properties(idf_component_${subdir} PROPERTIES LINKER_LANGUAGE C)
        message("\t done.")
    ENDFOREACH ()
 
    set_target_properties(idf_component_main PROPERTIES LINKER_LANGUAGE C)
ENDMACRO()

message("Parsing components...")
REGISTER_LINKER()

# resetting SDK Config
file(READ sdkconfig-template SDKCONFIG_TEMPLATE)
file(WRITE sdkconfig ${SDKCONFIG_TEMPLATE})
