/* Preludes : Conversions, 
              Operators,
              typedef */

#include <stdio.h>
#include <stdlib.h>

int main() {

  /////////////////////////////////////////////////////////////////////
  /// CONVERSIONS
  /////////////////////////////////////////////////////////////////////

  printf("CONVERSIONS\n");
  
  // char is unsigned int by default
  char ch = 'g';
  unsigned ui = 4;
  printf("ch = %c\n", ch);
  printf("ch = %d\n", ch);                          // char as unsigned int
  printf("ui = %u\n", ui);

  // char can be put in arithmetic operations with int
  printf("Sum = ch + ui = %d\n", ch + ui);          // sum as int
  printf("Sum = ch + ui = %c\n", ch + ui);          // sum as char

  // ANSI C converts all char and short operands, whether signed or unsigned, to int.

  // enum
  // assign names to integral constants
  enum Status {off = 0, on = 1};                    // enum definition
  enum Status bulb = off;                           // variable declaration
  printf("bulb = off = %d\n", bulb);                // 0
  bulb = on;
  printf("bulb = on = %d\n", bulb);                 // 1

  // default values
  enum Week {Mon, Tue, Wed, Thu, Fri, Sat, Sun};
  enum Week day;
  day = Mon;
  printf("day = Mon = %d\t", day);                  // 0
  day = Tue;
  printf("day = Tue = %d\t", day);                  // 1
  day = Wed;
  printf("day = Wed = %d\t", day);                  // 2
  day = Thu;
  printf("day = Thu = %d\t", day);                  // 3
  day = Fri;
  printf("day = Fri = %d\t", day);                  // 4
  day = Sat;
  printf("day = Sat = %d\t", day);                  // 5
  day = Sun;
  printf("day = Sun = %d\n", day);                  // 6

  // enum : another intereting example
  enum Num {two = 2, three, four, six = 6};
  enum Num num;
  num = two;
  printf("num = two = %d\n", num);                  // 2
  num = three;
  printf("num = three = %d\n", num);                // 3
  num = four;
  printf("num = four = %d\n", num);                 // 4
  num = six;
  printf("num = six = %d\n", num);                  // 6
  
  printf("\n");

  /////////////////////////////////////////////////////////////////////
  /// Operators
  /////////////////////////////////////////////////////////////////////

  printf("OPERATORS\n");
  
  // the unary operator ~ (bitwise not) yields the 1's complement of its operand
  printf("1's complement of 10 = %d\n", ~10);

  // sizeof()
  printf("Size of unsigned int is %lu\n", sizeof(unsigned int));

  // cast operator
  short sh = (short) ui;                            // unsigned int to short
  printf("sh = %d\n", sh);
  float pi = 3.14159;
  double radius = 2.4;
  unsigned area = (unsigned) pi * radius * radius;
  printf("Area = %u\n", area);

  // bitwise and
  printf("5 & 8 = %d\n", 5&8);                      // perform and operation bit by bit on their binary representations and result is converted to decimal representation

  // bitwise or
  printf("5 | 8 = %d\n", 5|8);                      // perform or operation bit by bit on their binary representations and result is converted to decimal representation

  // bitwise xor
  printf("5 ^ 8 = %d\n", 5^8);                      // perform xor (exclusive or) operation bit by bit on their binary representations and result is converted to decimal representation

  // bitwise complement
  printf("~8 = %d\n", ~8);

  // right shift
  printf("12 >> 2 = %d\n", 12>>2);                  // shifts all bits towards right by certain number of specified bits
  // in the above code, all bits in the binary representation of 12 are shifted towards right by 2 bits and the result is converted back decimal representation
  // while shifting new 0s are added to the left side

  // left shift
  printf("12 << 2 = %d\n", 12 << 2);                // shifts all bits towards left by certain number of specified bits
  // while shifting new 0s are added to the right side

  // comma operator
  // a pair of expressions separated by a comma is evaluated left to right, and the value of the left expression is discarded
  // this operator associates left to right.
  int val = (5, 8, 10);                             // val = 10
  printf("val = %d\n", val);
  
  int foo = (val = 4, val + 7) - 3;                 // foo = 8
  printf("foo = %d\n", foo);
  printf("val = %d\n", val);                        // val = 4

  printf("\n");

  /////////////////////////////////////////////////////////////////////
  /// typedef
  /////////////////////////////////////////////////////////////////////

  printf("TYPEDEF\n");
  
  // typedef defines synonyms of a data type
  typedef int intarray[10];                         // intarray is now a data type
  intarray ia;                                      // ia is an array of 10 integers

  // cool use of typedef
  typedef struct {                                  // defines Complex
    double re, im;
  } Complex;

  typedef union {
    int aa;
    float ff;
    char ss;
  } Foo;                                            // defines Foo
  
  Complex z = {-1, 1};                              // struct variable declaration
  Foo fuu = {'u'};                                  // union variable declaration

  printf("re = %.f, im = %.f\n", z.re, z.im);
  printf("fuu.ss = %c\n", fuu.ss);

  return 0;
}
