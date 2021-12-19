Sphinx C/C++ usage
==================

See :doc:`important_links` for:

* Sphinx RST usage
* Sphinx RTD theme and examples
* Breathe Doxygen directives and usage

Tutorials
----------

`Microsoft Devlog <https://devblogs.microsoft.com/cppblog/clear-functional-c-documentation-with-sphinx-breathe-doxygen-cmake/>`_

Setup
------

* Install Doxygen
* Install Sphinx

.. code-block:: bash

    pip install -U sphinx
    # or
    python -m pip install sphinx

* Install Breathe

.. code-block:: bash

    pip install breathe

* Install sphinx theme
   * Find more themes at <https://sphinx-themes.org/

.. code-block:: bash

    pip install sphinx_rtd_theme

Usage
------

* Write your C/C++ code
* Setup Doxygen with CMake

.. code-block:: cmake

    find_package(Doxygen 
                REQUIRED dot
    )
    # For breathe
    set(DOXYGEN_GENERATE_XML YES)
    doxygen_add_docs(doxygen_documentation
        ${CMAKE_CURRENT_SOURCE_DIR}/cpp_exe # source dir
        COMMENT "Doxygen documentation"
    )

* Run Doxygen target to generate XML output

.. code-block:: bash

    cd build_dir
    cmake --build . --target doxygen_documentation
    # Output in build_dir/xml

* Generate Sphinx basic project

.. code-block:: bash

    cd docs
    sphinx-quickstart

    # > Seperate root and build dir (yes)
    # > Project Name ([set])
    # > Author Name ([set])
    # > Project Release ([set])
    # > Project language [en] = default

* Update ``source/conf.py`` -> ``extensions`` with breathe

.. code-block:: python

    extensions = [
        'breathe'
    ]
    breathe_default_project = 'my_project'

* Build Sphinx documentation WITHOUT Doxygen XML

.. code-block:: bash

    cd docs/source
    sphinx-build -b html . ../output
    # Output in docs/output

* Setup Sphinx with CMake and Doxygen XML

.. code-block:: cmake

    find_program(sphinx_build
        NAMES "sphinx-build"
    )
    add_custom_target(sphinx_documentation
        COMMAND ${sphinx_build} -b html -Dbreathe_projects.my_project=${CMAKE_CURRENT_BINARY_DIR}/xml . ../output
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs/source
        VERBATIM USES_TERMINAL
    )
    # Output now generated in `docs/output`


* Run Sphinx target to generate docs

.. code-block:: bash

    cd build_dir
    cmake --build . --target sphinx_documentation

* Customize your docs
   * Open ``docs/source``
   * Add/Remove/Update your files with breathe doxygen directives

* Publish to Github Pages `.github/workflows/pages.yml <../../../.github/workflows/pages.yml>`_
