# cpp_sphinx_documentation

Sphinx documentation with C++, Doxygen and Sphinx

# Tutorials

- [Microsoft Devlog](https://devblogs.microsoft.com/cppblog/clear-functional-c-documentation-with-sphinx-breathe-doxygen-cmake/)

# Steps

- Write your C/C++ code
- Setup Doxygen with CMake
```cmake
find_package(Doxygen 
            REQUIRED dot
)
# For breathe
set(DOXYGEN_GENERATE_XML YES)
doxygen_add_docs(doxygen_documentation
    ${CMAKE_CURRENT_SOURCE_DIR}/cpp_exe # source dir
    COMMENT "Doxygen documentation"
)
```

- Run the target to generate your XML output
```bash
cmake --build [build_dir] --target doxygen_documentation
# output in [build_dir]/xml
```

- Install sphinx
```bash
python -m pip install sphinx
OR 
pip install -U sphinx
```

- Install sphinx Theme
```bash
pip install sphinx_rtd_theme
```
> TODO, Check for more themes

- Install sphinx extension for XML doxygen binding to sphinx
```bash
pip install breathe
```

- Generate Sphinx basic project
```bash
cd docs
sphinx-quickstart

> Seperate root and build dir (yes)
> Project Name ([set])
> Author Name ([set])
> Project Release ([set])
> Project language [en] = default
```

- Update `source/conf.py` -> `extensions`
```python
extensions = [
    'breathe'
]
breathe_default_project = 'my_project'

# Change
html_theme = 'sphinx_rtd_theme'
```

- Build documentation project WITHOUT xml inputs
```bash
cd docs/source
sphinx-build -b html . ../output
# see the output
```

- Update your `docs/source/index.rst` with breathe parameters
```rst
.. doxygennamespace:: nested::n
   :outline:
```
> TODO, Add more information for this section explaining breathe parameters

- Build documentation project WITH xml inputs (using CMAKE)
```cmake
find_program(sphinx_build
    NAMES "sphinx-build"
)
add_custom_target(sphinx_documentation
COMMAND ${sphinx_build} -b html -Dbreathe_projects.my_project=${CMAKE_CURRENT_BINARY_DIR}/xml . ../output
WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs/source
VERBATIM USES_TERMINAL
)

# Output now generated in `docs/output`
```

- Publish to Github Pages
> TODO, Copy output to root

> TODO, Use Github actions to publish
