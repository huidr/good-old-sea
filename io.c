/* IO : Standard input/output
        Files,
        Strings */

#include <stdio.h>
#include <stdlib.h>

int main() {

  /////////////////////////////////////////////////////////////////////////
  /// Standard output
  /////////////////////////////////////////////////////////////////////////  

  char          ch = 's';
  int           in = 24;
  double        db = 7345.7639;
  int          *pt = (int *) malloc(sizeof(int));
  char         *ar = "Programmer";
  unsigned      us = 19;
  signed short  ss = -4;
  unsigned long ul = 264;

  // output
  printf("%c\n", ch);                    // %c  : character
  printf("%d\n", in);                    // %d  : integer
  printf("%.2f\n", db);                  // %f  : float / double
  printf("%e\n", db);                    // %e  : scientic notation
  printf("%x\n", in);                    // %x  : print hex value
  printf("%p\n", pt);                    // %p  : pointer
  printf("%s\n", ar);                    // %s  : string
  printf("%lf\n", db);                   // %lf : float (long)
  printf("%u\n", us);                    // %u  : unsigned
  printf("%hi\n", ss);                   // %hi : signed int (short)
  printf("%lu\n", ul);                   // %lu : unsigned int, unsigned long

  // multiple output
  printf("%d %c\n", in, ch);             // note the space in between %d and %c
  
  // input
  scanf("%d %c", &in, &ch);              // input integer, char
  // always input together in one line

  // output the new values
  printf("%d %c\n", in, ch);

  char *name = (char *) malloc(sizeof(char) * 10);
  
  // input
  scanf("%s", name);                       // note that there is no &

  // output the new string value
  printf("%s\n", name);

  //////////////////////////////////////////////////////////////////////
  /// Files
  //////////////////////////////////////////////////////////////////////
  
  return 0;
}
