/* Preprocessor: Unconditional directives,
                 Conditional directives,
                 Parametrized macros,
                 Standard macros */

// pre-processor is just a text substitution tool which happens before compilation

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>                                             // provides va_list, etc

///////////////////////////////////////////////////////////////////////////
/// Unconditional directives
///////////////////////////////////////////////////////////////////////////

// macros are simply substituted by pre-processor before compile time. for example, the pre-processor will replace PI with 3.14

#define PI 3.14                                                 // constants
#define CIRC 1
#define RECT 2
#define AGE 20

// un-define a previousy defined macro
#undef AGE
#define AGE 36

/////////////////////////////////////////////////////////////////////////
/// Conditional directives
/////////////////////////////////////////////////////////////////////////

// A header file may be included more than one time directly or indirectly, this leads to problems of redeclaration of same variables/functions. To avoid this problem, directives like defined, ifdef and ifndef are used. 

// define a macro if it's not defined already
#ifndef PI
#define PI 3.14
#endif

// do something if a macro is defined already
#ifdef DEBUG
/* things to do when DEBUG is defined  */ 
#endif
// this is useful if we pass the -DDEBUG flag on gcc as this will define DEBUG, so we can turn debugging on and off on the fly

//////////////////////////////////////////////////////////////////////
/// Parametrized macros
//////////////////////////////////////////////////////////////////////

// macros can take arguments which are not checked for data type

#define MULTIPLY(x, y) x*y                                      // braces not necessary
#define PRODUCT(x,y) (x)*(y)
#define PRINT(x) (#x)                                           // # directive converts its argument in a string

// multiline macros that employ do-while(0)
// use \ to end each line except the last
#define PARITY(x) do { \
  if (x%2 == 0) printf("even\n"); \
  else          printf("odd\n"); \
  } while(0)
// the reason why we put while(0) is clear: we want it to execute it only once
// the semicolon after while(0) not neccessary here (why?)

// multiline macros using parenthesis instead of do-while(0)
#define SIGN(x) ({ \
  if (x>0)      printf("positive\n"); \
  else if (x<0) printf("negative\n"); \
  else          printf("zero\n"); \
    })

// token-pasting operator (##)
#define MERGE(x, y) x##y                                       // concatenates x and y
// the operator ## concatenates its operands

#define MAX(x,y) ((x > y) ? x : y)

/////////////////////////////////////////////////////////////////////////
/// Some Tips
/////////////////////////////////////////////////////////////////////////

// in general const should be preferred over #define
// a const is like a variable, it has an address retrievable by using a pointer or & operator unlike some susbtituted literal defined by #define

// in general inline functions are preferred over #define
// argumen taking macros can be confusing and give semantic errors

// inline function
static inline unsigned increment(unsigned x) {
  return x+1;
}
// inline functions are like macros in some sense, instead of calling, the body of the function replaces the function call

int main() {

  printf("MACROS\n");

  // using PRINT(x)
  printf("%s\n", PRINT(I am a C programmer!));

  // using MULTIPLY(x, y)
  printf("%d\n", MULTIPLY(4, 6));
  printf("%.2f\n", MULTIPLY(PI, 2));

  // macro arguments are not evaluated before macro expansion
  printf("%d\n", MULTIPLY(2 + 2, 3 + 4));                                  // gives the value 2 + 2*3 + 4, which might not be what the programmer intended
  printf("%d\n", PRODUCT(2 + 2, 3 + 4));                                   // the pre-processor replaces with (2 + 2) * (3 + 4)
  
  // using PARITY(x)
  PARITY(23);
  PARITY(16);
  // the pre-processor relaces PARITY(16); with the following code
  // do {
  //   if (16%2 == 0) printf("even\n");
  //   else           printf("odd\n");
  //   } while(0);
  // this explains why semi-colon wasn't necessary

  // using SIGN(x)
  SIGN(2.5);
  SIGN(-3.6);

  // using MERGE(x, y)
  printf("Merge of 4 and 8 is %d\n", MERGE(4, 8));                      // 48

  unsigned ui = 10;
  
  // using inline function
  ui = increment(10);
  printf("ui = %u\n", ui);

  // using MAX(x, y)
  printf("max(5, 8) = %d\n", MAX(5, 8));

  /////////////////////////////////////////////////////////////////////////
  /// Standard macros
  /////////////////////////////////////////////////////////////////////////
  
  printf("Source file : %s\n", __FILE__);                             // __FILE__ is the souce file name
  printf("Date of compilation : %s\n", __DATE__);                      // __DATE__ is the date of compilation
  printf("Time of compilation : %s\n", __TIME__);                      // __TIME__ is the time of compilation
  printf("Line number : %d\n", __LINE__);                              // __LINE__ is the line number in C code
  
  return 0;
}
// it is a good habit to enclose macro arguments in parenthesis to avoid semantic errors (caused by precedence and false grouping)
// macros are not stored in object file
// they remain active until they are un-defined or the end of source code is reached
