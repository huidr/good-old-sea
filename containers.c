/* C Containers: Arrays, 
                 Structures,
                 Unions,
                 Pointers */ 

#include <stdio.h>
#include <stdlib.h>                          // provides malloc
#include <math.h>

#define SIZE 5

int main() {

  //////////////////////////////////////////////////////////////
  /// Arrays
  //////////////////////////////////////////////////////////////

  int rolls[SIZE];                           // initialized with garbage values

  int primes[] = {2, 3, 5, 7, 11};           // size automatically assigned
  int evens[5] = {2, 4, 6, 8, 10};
  int odds[5]  = {1, 3};                     // last 3 elments set to 0
  
  printf("odds[2] : %d\n", odds[3]);         // 0

  odds[2] = 5;                               // access element by indexing
  *(odds+3) = 7;                             // access element by pointer

  printf("odds[2], odds[3] : %d %d\n", odds[2], *(odds+3));

  int matrix[3][3];                          // two-dimensional array
  for (int i = 0; i < 3; i++)                // row-major
    for (int j = 0; j < 3; j++)
      matrix[i][j] = i*j;
  
  //////////////////////////////////////////////////////////////
  /// Structures
  //////////////////////////////////////////////////////////////

  
  struct Complex {  // complex number
    double re;      // real part
    double im;      // imaginary part
  } z;              // z is a variable of Complex type

  printf("size = %lu\n", sizeof(struct Complex));  // use of sizeof operator

  struct Complex a = {1.0, -1.0}; // initialization, struct keyword neccessary
  struct Complex b = {2.4};       // initialize only real part

  double norm = sqrt(a.re*a.re + a.im*a.im); // accessing elements

  printf("size = %.2f\n", norm);

  // To eliminate including the keyword struct everytime during declarations, use typedef to define the struct

  typedef struct _Point {
    double xcor;
    double ycor;
    double zcor;
  } Point;                  // now use "Point" in lieu of "struct _Point"

  Point p1 = {2.4, -0.2, 3.8};

  /////////////////////////////////////////////////////////////
  /// Unions
  /////////////////////////////////////////////////////////////
  
  // allocates memory only for the largest data member and holds only one member at a time

  typedef union _Group {      // using typedef
    int iEle;
    double dEle;
    char cEle;
  } Group;
  
  printf("size = %lu\n", sizeof(Group));      // because we used typedef
  
  Group g = {10};                             // initialize iEle
  printf("Value of iEle : %d\n", g.iEle);     // of course, 10
  printf("Value of dEle : %.2f\n", g.dEle);   // holds the value 0.00
  printf("Value of cEle : %c\n", g.cEle);     // holds the empty character ' '

  g.cEle = 's';
  printf("Value of iEle : %d\n", g.iEle);     // holds the value 115, (ASCII)
  printf("Value of iEle : %c\n", g.iEle);     // 's'
  printf("Value of dEle : %.2f\n", g.dEle);   // 0.00
  printf("Value of cEle : %c\n", g.cEle);     // 's'
  printf("Value of cEle : %d\n", g.cEle);     // 115, (ASCII)

  // a structure or union cannot contain a member that has a variable length array type
  // it cannot also contain a member that is a pointer to a variable length array type
  
  ///////////////////////////////////////////////////////////////
  /// Pointers
  ///////////////////////////////////////////////////////////////
  
  int    *ip;      
  double *dp; 
  float  *fp;
  char   *cp;
  void   *vp;        // need a cast before use

  int num = 10;
  ip = &num;         // assigning address

  printf("Address of variable: %p\n", &num);           // note the use of %p (pointer type)
  printf("Value of pointer : %p\n", ip);
  printf("Value pointed to by pointer: %d\n", *ip);
  
  // an array variable is a const pointer to the first element
  int a[] = {1, 2, 3, 4, 5};
  int *pa = a;                   // pa can be used in lieu of a, except that pa is a variable pointer while a is a const pointer         

  // dynamic memory allocation: malloc-free
  int *ptr = (int *) malloc(sizeof(int));     // allocates memory of int size and assign its address to ptr
  printf("%p\n", ptr);                        // address stored in ptr
  printf("%x\n", *ptr);                       // 0, note the use of %x for int unsigned hex value

  *ptr = 7;
  printf("%d\n", *ptr);

  free(ptr);                                  // deallocate

  // pointer to struct
  typedef struct _Anime {
    char *name;
    char *genre;
  } Anime;

  Anime a1 = {"Bleach", "Action"};
  
  int c = 0;                                  // loop counter
  printf("Name : ");
  while (1) {                                 // infinite loop
    printf("%c", *(a1.name+c));
    c++;
    if (*(a1.name+c) == '\0') {               // end of string
      printf("\n");
      break;
    }
  }

  Anime *sptr = &a1;                          // pointer to Anime type

  c = 0;                                      // reset counter
  printf("Genre : ");
  while (1) {
    printf("%c", *(sptr->genre+c));           // use of -> operatorl
    c++;
    if (*(sptr->genre+c) == '\0') {           // end of string
      printf("\n");
      break;
    }
  }

  // (*sptr).name may be used in lieu of sptr->name
  
  // dynamically allocated arrays
  int *pray = (int *) malloc(sizeof(int)*4);           // size of 4

  pray[0] = 12; pray[1] = 6; pray[2] = 2; pray[3] = 24;         // used as array
  *pray = 16; *(pray+1) = 8; *(pray+2) = 14; *(pray+3) = 6;     // used as pointer
  free(pray);
  
  return 0;
}
