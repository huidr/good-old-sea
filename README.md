<p align="center">
  <img src="images/logo.png" />
</p>

<h1 align="center">
  Good Old Sea
</h1>

<p align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />
  <img src="https://img.shields.io/badge/GNU%20Bash-4EAA25?style=for-the-badge&logo=GNU%20Bash&logoColor=white" />
  <img src="https://img.shields.io/badge/Emacs-%237F5AB6.svg?&style=for-the-badge&logo=gnu-emacs&logoColor=white" />
</p>
  
After so many years and decades, the world is still powered by the C programming language. Here are some source codes written entirely in C.

All the source files have been tested to compile and execute. All of them are written on Emacs. They are compiled and executed on bash. See the list of all source files below in `contents` section.

### Compilation

On bash, the source [io.c](io.c) can be compiled using `gcc` as follows:

```bash
gcc -o io io.c
```

A new executable file with the name `io` will be created in the same directory. Do the same for other source files.

### Execution

The executable file `io` which was created in the compilation step can now be run (executed) as follows:

```bash
./io
```

Do the same for other executables.

### Errors

Ideally, the compilation shouldn't generate any errors. However, compiling some source files such as [containers.c](containers.c) might generate an error due to `math.h` header file. In this case, compile as follows:

```bash
gcc -o containers containers.c -lm
```

Do the same for any source file that includes `math.h` as a header file.

### Commentation

The source files are commented well. This should help any new learner of C and anyone else in general.

### Contents

| Source                        | Topics          |
| :---                          | :---            |
| [preludes.c](preludes.c)      | Conversions, Operators, `typedef` |
| [containers.c](containers.c)  | C Containers: Arrays, Structures, Unions, Pointers |
| [methods.c](methods.c)        | Functions: Declaration, Definition, By Value, By Pointer, Recursion, Function Pointers |
| [io.c](io.c)                  | Standard I/O, File I/O, Read and Write Strings |

### Future

More source files shall be added soon.