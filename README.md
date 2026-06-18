# GoGo-Code

## Tools
- [CMake 4.0.0+](https://cmake.org/)
- [Ninja](https://ninja-build.org/)
- [Conan 2.0+](https://conan.io/)

### Build conan required
```bash
cd ChatAsio
conan install . --build=missing
cmake --preset conan-release
cmake --build build/Release
```

### Build without conan
```bash
cd Hello
cmake -B build -G Ninja .
cmake --build build
```

### Bazinga compilation
```bash
cl /EHsc /W4 /std:c++20 0001.cpp 		# for msvc
clang++ -Wall -g -std=c++20 0001.cpp 	# for clang
g++ -Wall -g -std=c++20 0001.cpp 		# for g++
```
