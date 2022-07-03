/* IO : Standard input/output
        File input/ouput
        Strings */

#include <stdio.h>
#include <stdlib.h>

int main() {

  /////////////////////////////////////////////////////////////////////////
  /// Standard output
  /////////////////////////////////////////////////////////////////////////  

  printf("STANDARD OUTPUT\n");
  
  char          cc = 's';
  int           in = 24;
  double        db = 7345.7639;
  int          *pt = (int *) malloc(sizeof(int));
  char         *ar = "Programmer";
  unsigned      us = 19;
  signed short  ss = -4;
  unsigned long ul = 264;

  // output
  printf("%c\n", cc);                    // %c  : character
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
  printf("%d %c\n", in, cc);             // note the space in between %d and %c
  
  // input
  printf("Waiting for an input ... enter [int] [char]\n");
  scanf("%d %c", &in, &cc);              // input integer, char
  // always input together in one line

  // output the new values
  printf("%d %c\n", in, cc);

  char *name = (char *) malloc(sizeof(char) * 10);
  
  // input
  printf("Waiting for an input ... enter a string\n");
  scanf("%s", name);                              // note that there is no &

  // output the new string value
  printf("%s\n", name);
  printf("\n");
  
  //////////////////////////////////////////////////////////////////////
  /// File input
  //////////////////////////////////////////////////////////////////////

  printf("FILE INPUT\n");

  FILE *fp = NULL;                                // pointer to handle io using buffers

  unsigned inum;

  fp = fopen("number", "r");                      // open in read mode
  if (!fp) {
    fprintf(stderr, "Failed to open file.\n");    // standard error msg
    exit(1);                                      // provided by stdlib.h
  }
  // fscanf() reads a set of data from a file
  fscanf(fp, "%d", &inum);
  printf("%d\n", inum);
  fclose(fp);                                     // clear buffers and close file

  fp = fopen("text", "r");
  char ch;                                        // to get each character from the file one by one

  if (!fp) {
    fprintf(stderr, "Failed to open file.\n");
    exit(1);
  }

  // getc() gets individual character from file
  do {
    ch = getc(fp);
    printf("%c", ch);
  } while (ch != '\n');                           // until newline
  fclose(fp);
  
  // getw() gets integer from file

  printf("\n");
  
  //////////////////////////////////////////////////////////////////////
  /// File output
  //////////////////////////////////////////////////////////////////////

  printf("FILE OUTPUT\n");
  
  fp = fopen("plain.txt", "w");                      // write mode
  if (!fp) {
    fprintf(stderr, "Failed to open file.\n");
    exit(1);
  }

  char *waifu = "Kurisu Makise";
  unsigned c = 0;

  do {
    // putc writes individual character to a file
    // if the file extension of the file is not specified, the output is a binary file
    putc(*(waifu+c), fp);                           // note the argument list
    if (*(waifu+c) == '\0') {                       // end of string
      putc('\n', fp);
      break;
    }
    c++;
  } while (1);
  fclose(fp);

  fp = fopen("plain.txt", "r");
  while ( (ch = getc(fp)) != EOF) {
    printf("%c", ch);
  }

  unsigned age = 22;
  
  // fprintf() writes a set of data to file
  fp = fopen("record", "w");
  printf("Writing to file now ...\n");
  fprintf(fp, "Name : %s\t Age : %u\n", waifu, age);  // note the argument list
  printf("Wrote to file.\n");
  fclose(fp);

  // fscanf() to retrieve a set of data from file
  char sentence[50];
  fp = fopen("record", "r");
  printf("Checking what is written ...\n");
  c = 0;                                              // loop counter
  while (c < 7) {
    fscanf(fp, "%s", sentence);
    if (*sentence == EOF) {
      printf("\n");
      break;
    }
    printf("%s ", sentence);
    c++;
  }

  printf("\n\n");

  // file i/o functions: getc(), getw(), putc(), fprintf(), fscanf()

  // getchar(), putchar()
  
  //////////////////////////////////////////////////////////////////////
  /// Read and write strings
  //////////////////////////////////////////////////////////////////////

  printf("READ AND WRITE STRINGS\n");

  char *str = "C programming";                         // str[] = "C programming";
  printf("%s\n", str);                                 // print string

  str = "Kisuke Urahara";                              // string changed
  printf("%s\n", str);                                 // output the change

  char *substr_1 = (char *) malloc(sizeof(char) * 10);
  char *substr_2 = (char *) malloc(sizeof(char) * 10);

  // read and tokenize
  sscanf(str, "%s %s", substr_1, substr_2);            // tokenize by space
  printf("Input string to be parsed : %s\n", str);     // Kisuke Urahara
  printf("Token 1 : %s\n", substr_1);                  // Kisuke
  printf("Token 2 : %s\n", substr_2);                  // Urahara

  free(substr_1);
  free(substr_2);

  char *date = "25 December 1996";
  printf("%s\n", str);

  int day = 0, year = 0;
  char *month = (char *) malloc(sizeof(char) * 10);

  // read and tokenize
  sscanf(date, "%d %s %d", &day, month, &year);         // note the use of &
  printf("Date to be parsed : %s\n", date);
  printf("Day : %d\n", day);
  printf("Month : %s\n", month);
  printf("Year : %d\n", year);

  free(month);

  printf("\n");
  
  return 0;
}
