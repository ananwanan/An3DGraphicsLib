# An3DGraphicsLib

An3DGraphicsLib is a small C++ 3D math library focused on core transformation primitives for 3D graphics.

## Overview

- Provides a `matrix4` class for 4x4 transformation matrices
- Provides a simple `vector3` class for 3D vectors
- Builds a static library and a sample executable using CMake
- Includes Doxygen-generated HTML documentation in the `html/` directory

## Features

- Identity matrix creation
- Translation, rotation (around Z axis), and scale operations on `matrix4`
- Simple 3D vector storage in `vector3`
- Debug output support for matrices

## Project structure

- `CMakeLists.txt` — CMake build configuration
- `main.cpp` — sample application demonstrating library usage
- `3d/` — public header files
- `3d/src/` — library source files
- `build/` — generated CMake build output
- `html/` — generated Doxygen documentation

## Build Instructions

### Prerequisites

- CMake 3.10 or later
- A C++ compiler with C++11 support or newer

```

  GLFW (system or vcpkg)
  Linux:
  sudo apt install libglfw3-dev
  Or vcpkg:
  vcpkg install glfw3
```

### Build from source

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

On Windows with PowerShell:

```powershell
mkdir build
cd build
cmake ..
cmake --build .
```

## Run

After building, run the sample executable from the build directory:

```bash
./An3DGraphicsLib
```

On Windows:

```powershell
.\An3DGraphicsLib.exe
```

## Documentation

Doxygen HTML documentation is available in the `html/` directory. Open `html/index.html` in a browser to view the generated API documentation.

## Usage

The library exposes the `anan3d` namespace. Example use in `main.cpp`:

```cpp
#include <matrix4.h>

using namespace anan3d;

int main()
{
    matrix4 m;
    m.debug();
    return 0;
}
```

## License

No license is specified in this repository. Add a `LICENSE` file if you want to apply an open source license.
