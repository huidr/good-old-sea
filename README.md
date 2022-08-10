<p align="center">
  <img class="logo" src="images/logo.png" height="150vh"/>
</p>

<h2 align="center">
  Good Old Sea
</h2>

<p align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />
  <img src="https://img.shields.io/badge/GNU%20Bash-4EAA25?style=for-the-badge&logo=GNU%20Bash&logoColor=white" />
  <img src="https://img.shields.io/badge/Emacs-%237F5AB6.svg?&style=for-the-badge&logo=gnu-emacs&logoColor=white" />
</p>
  
After so many years and decades, the world is still powered by the C programming language. Here are some source codes written entirely in C (the ANSI standard).

All the source files have been tested to compile and execute. All of them are written on Emacs. They are compiled and executed on bash. See the list of all source files below in `contents` section. The source files are commented well. This should help any new learner of C and anyone else in general. A reference card is [here](reference/CRefCard.v2.2.pdf).

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

### Contents

| Source                        | Topics          |
| :---                          | :---            |
| [preludes.c](preludes.c)      | Conversions, operators, `typedef` |
| [flow.c](flow.c)              | Statements, `if else`, `switch`, loops, jumps |
| [containers.c](containers.c)  | C containers: arrays, structures, unions, pointers |
| [methods.c](methods.c)        | Functions: declaration, definition, by value, by pointer, recursion, variable arguments, function pointers |
| [io.c](io.c)                  | Standard I/O, file I/O, read and write strings |
| [preprocessor.c](preprocessor.c) | Preprocessor directives: unconditional and conditional, parametrized macros, standard macros |
| [library.c](library.c)        | `time.h`, `unistd.h` |

### Efficient C

Some tips and rules of thumb on writing efficient C code would be:

#### Jumps/branches are expensive.

And as such, their use should be minimized. For example, function call require two jumps and as such, short functions should be replaced by `inline` functions.

Iteration should be preferred over recursion.

Replace long `if else if` chain with a `switch`. The compiler sometimes optimizes the switch into some table lookup with a single jump. If a switch is not possible, put the most likely clause (or common clauses) at the beginning of the 'if' chain.

Move loops inside function calls. For example, instead of writing
```c
for (i = 0; i < 10; i++) DoSomething();
```
write the following instead
```c
DoSomething() {
  for (i = 0; i < 10; i++) { ... } }
```
#### On using variables

Reduce the number of local variables. They are normally stored on the stack. If there are few, they can be stored in registers in which case, the function gets the benefit of the faster memory access of data stored in registers and avoids the overhead of setting up a stack frame.

Reduce the number of function parameters. Because of the same reason as above &mdash; they are stored on stack.

When declaring object variables, use initialization instead of assignment. For example,
```c
Color c(black);
```
is more efficient than
```c
Color c; c = black;
```

Delay declaring local variables.

Use the smallest possible data type. In most cases, an `unsigned int` (usually 4 bytes) or even `unsigned short` (usually 2 bytes) gets the job done.

#### On using functions

If you do not need a return value from a function, do no define one.

Make default class constructors as lightweight as possible.

#### Operations

Wherever possible, replace multiplication by shift operations ``>>`` and ``<<``.

For most classes, use the operators +=, -=, *=, and /= instead of the operators +, -, *, and /.

For basic data types, use the operators +, -, *, and / instead of the operators +=, -=, *=, and /=.

For objects, use the prefix operator (++obj) instead of the postfix operator (obj++). A copy of the object must be made with the postfix operator (which thus involves an extra call to the constructor and destructor), whereas the prefix operator does not need a temporary copy.

### Future

More source files shall be added soon. Some of the existing code shall be also updated. More tips on writing efficient C code shall be added.
