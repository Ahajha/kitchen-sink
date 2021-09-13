# kitchen-sink
Testing repository for learning new technologies

## building
Run:
```
cmake -B build && cmake --build build
```
to build. The resulting executable will be `./build/sink`.

If you encounter errors relating to clang, you may have to specify the compiler manually. If on a \*nix system, try
```
cmake -B build -D CMAKE_CXX_COMPILER=g++ && cmake --build build
```
instead. (Clang, at time of writing, has poor support of C++ ranges.)
