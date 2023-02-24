# See Also

Original Documentation: [NUS Brief](https://nus-cs1010.github.io/2223-s1/)

Pre-requisites:
    - [powershell](https://github.com/PowerShell/PowerShell)
    - [make](https://www.gnu.org/software/make/)
    - [gcc](https://gcc.gnu.org/)
    - [fd](https://github.com/sharkdp/fd)

## Commands

The following rules are provided by the [Makefile](Makefile):
    - clean: Delete the entire build directory (for deployment, perhaps)
    - purge: Delete intermediate object (.o) files
    - scaffold: Create empty directories to store the build artifacts
    - build: Build the object files and executables
    - run: Run the executables in ascending order
    - all: Shorthand for build and run

## Notes

The Makefile has been carefully curated and optimized to work on Windows platforms.
Only changed source code files will be recompiled upon `make build`.

> Please *DO NOT* use directory names in source code file names (i.e. src/hello/hello.c).
This is crucial as the Makefile uses pattern matching to recompile changed files.
Having directory names as substrings of the source code file names will result in
frequent but unnecessary re-compiling.

> Please *DO NOT* include a `main` function in the immediate source directory.
Each section (E.g. src/1, src/2) should have its own main function.
Only utility functions should abide in the top-level source directory.
The Makefile will automatically link the utility files for all sections to access.
