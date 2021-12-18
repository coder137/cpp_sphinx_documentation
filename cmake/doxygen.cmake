find_package(Doxygen 
            REQUIRED dot
)
message("Doxygen Found: ${DOXYGEN_FOUND}")
message("Doxygen Version: ${DOXYGEN_VERSION}")

set(DOXYGEN_EXCLUDE_PATTERNS 
    *test/*
    *mock/*
)

# For breathe
set(DOXYGEN_GENERATE_XML YES)
set(DOXYGEN_SEPARATE_MEMBER_PAGES YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
set(DOXYGEN_EXTRACT_ALL YES)
# Misc
set(DOXYGEN_MARKDOWN_SUPPORT NO)
set(DOXYGEN_WARN_IF_UNDOCUMENTED YES)

doxygen_add_docs(doxygen_documentation
    ${CMAKE_CURRENT_SOURCE_DIR}/cpp_exe
    COMMENT "Doxygen documentation"
)
