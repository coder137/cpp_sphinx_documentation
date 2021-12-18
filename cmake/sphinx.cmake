find_program(sphinx_build
    NAMES "sphinx-build"
)
add_custom_target(sphinx_documentation
COMMAND ${sphinx_build} -b html -Dbreathe_projects.cpp_sphinx_documentation=${CMAKE_CURRENT_BINARY_DIR}/xml . ../output
WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs/source
VERBATIM USES_TERMINAL
)
