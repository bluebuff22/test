option(HLSL_COPY_GENERATED_SOURCES "Copy generated sources if different" Off)

add_custom_target(HCTGen)

if (WIN32 AND NOT DEFINED HLSL_AUTOCRLF)
  find_program(git_executable NAMES git git.exe git.cmd)
  execute_process(COMMAND ${git_executable} config --get core.autocrlf
                  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                  TIMEOUT 5
                  RESULT_VARIABLE result
                  OUTPUT_VARIABLE output
                  OUTPUT_STRIP_TRAILING_WHITESPACE)
  if( result EQUAL 0 )
    set(val Off)
    if (output STREQUAL "true")
      set(val On)
    endif()
    set(HLSL_AUTOCRLF ${val} CACHE BOOL "Is core.autocrlf enabled in this clone")
    message(STATUS "Git checkout autocrlf: ${HLSL_AUTOCRLF}")
  endif()
endif()

function(add_hlsl_hctgen mode)
  cmake_parse_arguments(ARG
    "BUILD_DIR;CODE_TAG"
    "OUTPUT"
    ""
    ${ARGN})

  if (NOT ARG_OUTPUT)
    message(FATAL_ERROR "add_hlsl_hctgen requires OUTPUT argument")
  endif()
 
  set(temp_output ${CMAKE_CURRENT_BINARY_DIR}/${ARG_OUTPUT}.tmp)
  set(full_output ${CMAKE_CURRENT_SOURCE_DIR}/${ARG_OUTPUT})
  if (ARG_BUILD_DIR)
    set(full_output ${CMAKE_CURRENT_BINARY_DIR}/${ARG_OUTPUT})
  endif()
  set(hctgen ${LLVM_SOURCE_DIR}/utils/hct/hctgen.py)
  set(hctdb ${LLVM_SOURCE_DIR}/utils/hct/hctdb.py)
  set(hctdb_helper ${LLVM_SOURCE_DIR}/utils/hct/hctdb_instrhelp.py)
  set(output ${full_output})

  set(copy_sources Off)
  if(ARG_BUILD_DIR OR HLSL_COPY_GENERATED_SOURCES)
    set(copy_sources On)
  endif()

  if(ARG_CODE_TAG)
    set(input_flag --input ${full_output})
  endif()

  # If we're not copying the sources, set the output for the target as the temp
  # file, and define the verification command
  if(NOT copy_sources)
    set(output ${temp_output})
    set(verification COMMAND ${CMAKE_COMMAND} -E compare_files ${temp_output} ${full_output})
  endif()
  if(WIN32 AND NOT HLSL_AUTOCRLF)
    set(force_lf "--force-lf")
  endif()
  set(hct_dependencies ${LLVM_SOURCE_DIR}/utils/hct/gen_intrin_main.txt
                       ${hctgen}
                       ${hctdb}
                       ${hctdb_helper})
  add_custom_command(OUTPUT ${temp_output}
                     COMMAND ${PYTHON_EXECUTABLE}
                             ${hctgen} ${force_lf}
                             ${mode} --output ${temp_output} ${input_flag}
                     COMMENT "Building ${ARG_OUTPUT}..."
                     DEPENDS ${hct_dependencies}
                     )
  if(copy_sources)
    add_custom_command(OUTPUT ${full_output}
                      COMMAND ${CMAKE_COMMAND} -E copy_if_different
                              ${temp_output} ${full_output}
                      DEPENDS ${temp_output}
                      COMMENT "Updating ${ARG_OUTPUT}..."
                      )
  endif()
  add_custom_target(${mode} ${verification} DEPENDS ${output})
  add_dependencies(HCTGen ${mode})
endfunction()
