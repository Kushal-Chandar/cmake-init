include_guard()

# ----------------------------------------------------------------------------
#   Configure file
# ----------------------------------------------------------------------------
configure_file(
  ${CMAKE_INIT_SOURCE_DIR}/configuration/config.h.ini
  ${CMAKE_INIT_SOURCE_DIR}/configuration/config.h
  ESCAPE_QUOTES
  @ONLY)

# ----------------------------------------------------------------------------
#   A lib that has private and public headers
# ----------------------------------------------------------------------------
add_library(configuration_header STATIC)
set_target_properties(configuration_header PROPERTIES LINKER_LANGUAGE CXX)
target_sources(configuration_header
               PRIVATE ${CMAKE_INIT_SOURCE_DIR}/configuration/config.h)
