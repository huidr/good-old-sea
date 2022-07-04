/* Flow : Statements,
          if else, switch,
          Loops: while, do while, for
          Jumps: break, continue, return, goto, exit()
          */

#include <stdio.h>
#include <stdlib.h>

int main() {

  //////////////////////////////////////////////////////////////////////
  /// STATEMENTS
  //////////////////////////////////////////////////////////////////////

  printf("STATEMENTS\n");
  
  // single statements ends with a semi-colon
  unsigned ui = 10;

  // null statements has only a semi-colon
  ;

  // compound or block statement has one or several statements inside braces
  // new block, new scope
  {
    char ch = 't';                                   // has block scope
    printf("ch = %c\n", ch);
    printf("ui = %u\n", ui);                         // still in scope
  } // end of block, variable ch not accessive here

  // new block, can re-declare variables defined outside the block
  {
    signed ui = -4;
    printf("ui = %hi\n", ui);                        // ui = -4
  }// the scope of signed ui ends here

  printf("ui = %u\n", ui);                           // the old value in scope again
  
  // nested blocks
  {
    char ch = 'x';
    double db = 3.14;
    {
      char ch = 's';                                 // re-defined
      double db = 2.78;                              // re-defined
      printf("ch = %c\n", ch);                       // ch = s
      printf("db = %.2f\n", db);                     // db = 2.78
    }
    printf("ch = %c\n", ch);                         // ch = x
    printf("db = %.2f\n", db);                       // db = 3.14
  }

  printf("\n");

  /////////////////////////////////////////////////////////////////////
  /// if else, switch statements
  /////////////////////////////////////////////////////////////////////

  printf("IF ELSE, SWITCH STATEMENTS\n");

  char ch = 'y';
  
  // if else if
  if (ch == 's')
    printf("ch == 's'\n");
  else if (ch == 'u')                                       // can have multiple else if constructs or can have none
    printf("ch == 'u'\n");
  else                                                      // optional
    printf("I am tired.\n");

  // if else if can be replaced by conditional (ternary) operator
  ch == 's' ? printf("correct\n") : printf("false\n");
      
  // switch is a good substitute for a long else if construct
  switch(ch) {
  case 's':
    printf("ch == 's'\n");
    break;
  case 'u':
    printf("ch == 'u'\n");
    break;
  default:
    printf("I am tired.\n");
  }

  // another switch construct
  unsigned val = 147;
  switch (val % 4) {
  case 0:
  case 2:
    printf("%d is even.\n", val);
    break;
  default:
    printf("%d is odd.\n", val);
  }

  printf("\n");

  /////////////////////////////////////////////////////////////////////
  /// LOOPS
  /////////////////////////////////////////////////////////////////////

  printf("LOOPS: WHILE, DO WHILE, FOR\n");

  // while loop: check condition first and then evaluate
  {
    int c = 0;                                            // loop counter
    while (c < 10) {
      ch += 1;                                            // ch = ch + 1, compound assignment
      c++;                                                // update loop counter, without this the loop iterates infinitely
    }
  }

  // do while: evaluate the statements and then check condition
  {
    int c = 0;                                            // loop counter
    do {
      ch -= 1;
      c++;
    } while (c < 10);                                     // note the comma
  }

  printf("ch = %c\n", ch);

  // for loop variations
  
  // multiple loop control variables
  for (int i = 0, j = 5; i < 5; i++, j--) {
    printf("i = %d, j = %d\n", i, j);
  }

  // different conditional expressions
  for (int i = 0; (i != 3)&&(i < 5); i++) {               // stops when i = 3
    printf("i = %d, ", i);
  }

  printf("\n");

  // expressions are optional
  // for loop can replicate the functionality of while loop
  unsigned c = 0;
  for ( ; c < 5 ; ) {
    printf("c = %u\n", c);
    c++;                                                  // update counter without which the loop becomes infinite
  }

  // another interesting for loop
  for ( ; ; ) {
    printf("c = %u\n", c);
    c++;
    if (c == 8)
      break;                                            
  }

  printf("\n");

  ////////////////////////////////////////////////////////////////////
  /// JUMPS: break, continue, return, exit()
  ////////////////////////////////////////////////////////////////////

  printf("JUMP STATEMENTS\n");

  // break used to leave a loop or switch: examples given above

  // continue: skip the rest of the loop body and go to the conditional expression straightaway for the next iteration

  for ( ; c < 12 ; c++ ) {
    if (c == 10)
      continue;
    printf("c == %u\n", c);
  }
  
  // return : used to return a value or terminate a function, see in methods.c (another source code file)

  // labelled statements
  foo: c += 1;                                     // the scope of a label is the current function
  printf("c is now %u.\n", c);

  // goto : go to the labelled statement
  if (c <= 15)
    goto foo;

  // notice that the above code has the same functinality as a for loop or while loop
  // goto statements can replicate loops although this may lead to confusion and hence are not recommended

  // exit() : requires stdlib.c header, terminates the program
  if (c == 15)
    exit(0);
  
  return 0;
}
