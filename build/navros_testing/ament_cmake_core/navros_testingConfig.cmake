# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_navros_testing_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED navros_testing_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(navros_testing_FOUND FALSE)
  elseif(NOT navros_testing_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(navros_testing_FOUND FALSE)
  endif()
  return()
endif()
set(_navros_testing_CONFIG_INCLUDED TRUE)

# output package information
if(NOT navros_testing_FIND_QUIETLY)
  message(STATUS "Found navros_testing: 0.0.0 (${navros_testing_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'navros_testing' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${navros_testing_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(navros_testing_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${navros_testing_DIR}/${_extra}")
endforeach()
