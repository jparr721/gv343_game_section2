# GVSU CIS 343 Section 02 - Project #2
'Not On My Block' is a collaborative, fun class project created by Ira Woodring.
To build from source, follow your platform-specific instructions below:
* Linux (EOS)
* Windows (64-bit)
* MacOS

## Windows (64-bit)
To develop *Not On My Block* in Windows, there is currently only build instructions for CLion.

1. First, install SFML from https://www.sfml-dev.org/. (Make sure you install the MinGW 64-bit compiler, and the corresponding GCC version of SFML)
2. Make sure the `CMakeLists.txt` file is in your project root directory.
3. After installing SFML for 64-bit Windows, copy *the entire directory* to your project root, and rename it to `SFML-2.5.0-win64`. (*This is important because the `CMakeLists.txt` file looks for this exact directory*)
4. Copy all of the `*.dll` extensions from `SFML-2.5.0-win64/bin` and place them under CLion's `cmake-build-debug`. 
5. Locate your installation of MinGW from SFML (ex. mine is `C:\mingw64\bin`), and copy all `*.dll` extensions from this folder, and place them under `cmake-build-debug` as well.
6. Run the project from within CLion. 

*NOTE:* You've just statically linked all of mingw and SFML source files. Dynamically linking libraries in CLion is possible, but wasn't feasible at this point in time. Feedback/support is apprecaited.