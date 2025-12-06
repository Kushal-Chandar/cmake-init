include_guard()

function(get_latest_annotated_tag out_ver out_sha1 out_date)
  find_package(Git QUIET)
  if(NOT GIT_FOUND)
    message(WARNING "Git not found. Using default version.")
    return()
  endif()

  execute_process(
    COMMAND "${GIT_EXECUTABLE}" describe --abbrev=0 --match "v*"
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
    OUTPUT_VARIABLE _tag
    RESULT_VARIABLE _err
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
  if(_err)
    message(WARNING "git describe failed. Using default version.")
    return()
  endif()

  set(${out_ver} "${_tag}" PARENT_SCOPE)
  message(STATUS "PROJECT VERSION: ${_tag}")

  execute_process(
    COMMAND "${GIT_EXECUTABLE}" rev-list -n 1 "${_tag}"
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
    OUTPUT_VARIABLE _sha1
    RESULT_VARIABLE _err
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
  if(NOT _err)
    set(${out_sha1} "${_sha1}" PARENT_SCOPE)
    message(STATUS "PROJECT VERSION SHA1: ${_sha1}")
  endif()

  execute_process(
    COMMAND "${GIT_EXECUTABLE}" log -1 --format=%ad --date=local "${_tag}"
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
    OUTPUT_VARIABLE _date
    RESULT_VARIABLE _err
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
  if(NOT _err)
    set(${out_date} "${_date}" PARENT_SCOPE)
    message(STATUS "PROJECT VERSION DATE: ${_date}")
  endif()
endfunction()

# Defaults (used when git/auto versioning fails or is disabled)
set(PROJ_VER "v0.1.0")
set(PROJ_VER_SHA1 "")
set(PROJ_VER_DATE "")

if(ENABLE_AUTOMATIC_VERSIONING)
  get_latest_annotated_tag(PROJ_VER PROJ_VER_SHA1 PROJ_VER_DATE)
endif()

# Always derive major/minor/patch from PROJ_VER, regardless of how it was set
string(REGEX REPLACE "^v([0-9a-zA-Z-]+)\\..*"                "\\1" PROJ_VER_MAJOR "${PROJ_VER}")
string(REGEX REPLACE "^v[0-9a-zA-Z-]+\\.([0-9a-zA-Z-]+).*"   "\\1" PROJ_VER_MINOR "${PROJ_VER}")
string(REGEX REPLACE "^v[0-9a-zA-Z-]+\\.[0-9a-zA-Z-]+\\.([0-9a-zA-Z-]+).*"
                     "\\1" PROJ_VER_PATCH "${PROJ_VER}")
