/* Functions : Declaration and definition,
               Call and return by value,
               Call and return by pointer,
               Recursion,
               Function pointers */

#include <stdio.h>
#include <stdlib.h>

int main() {

  /////////////////////////////////////////////////////////////////
  // Declaration and definition 
  /////////////////////////////////////////////////////////////////
  
  // declaration/prototype
  int ifunc(int x, int y);                   // x, y are formal parameters
  int ifunp();                               // can be called by any number of arguments
  void vfunc(int *x);                        // cannot return a value but can have a return; statement
  void vfunv(void);                          // can be called only without argument 

  // definition
  // the code is given after main()

  // calls
  int max = ifunc(3, 5);                     // call by value, return by value
  printf("%d\n", max);

  int eight = ifunp();                       // return by value
  printf("%d\n", eight);

  int *p = (int *) malloc(sizeof(int));
  *p = 9;
  vfunc(p);                                  // call by pointer
  printf("%d\n", *p);                        // 10

  vfunv();
  free(p);
  
  /////////////////////////////////////////////////////////////////
  /// Call and return by value
  /////////////////////////////////////////////////////////////////

  // call by value: examples shown above
  // return by value: examples shown above

  // in call by value, new variables are created inside the function definition to which values of the arguments are assigned, this causes some time overhead.
  // since the variables the function work with are totally different from the variables used in function call, the changes made in the function are not reflected back to the calling function

  /////////////////////////////////////////////////////////////////
  /// Call and return by pointer
  /////////////////////////////////////////////////////////////////

  // call by pointer: examples shown above
  // return by pointer

  int* rpfunc(int*, int*);                      // return by pointer, parameter names not necessary in function prototype
  // function definition given after main()

  int *p1 = (int *) malloc(sizeof(int));
  int *p2 = (int *) malloc(sizeof(int)); 
  *p1 = 5; *p2 = 8;
  *rpfunc(p1, p2) = 10;                         // classic use of return by pointer

  printf("*p1 : %d\n", *p1);
  printf("*p2 : %d\n", *p2);

  // passing array to function
  int sumArray(int a[], int n);
  // function definition given after main()

  int arr[] = {1, 2, 3, 4, 5};
  int sum = sumArray(arr, 5);                   // the const pointer pointing to the first element is passed
  printf("Sum : %d\n", sum);

  ////////////////////////////////////////////////////////////////
  /// Recursion
  ////////////////////////////////////////////////////////////////

  // prototypes
  unsigned int factorial(unsigned int n);
  unsigned int nOnes(unsigned int n);           // number of 1's in the binary representation of n

  printf("Factorial of 5 : %d\n", factorial(5));
  printf("Number of 1's in the binary representation of 69 : %d\n", nOnes(69));

  // two or more functions can be co-recursive, that is, f() calling g() and g() calling f(). at least one of the functions must have an exit condition

  ///////////////////////////////////////////////////////////////
  /// Function pointers
  ///////////////////////////////////////////////////////////////
  
  unsigned int (*fooptr)(unsigned int) = &factorial;          // fooptr is a pointer to a function whose return type is unsigned int and whose parameter is unisigned int

  int val = (*fooptr)(10);
  printf("Factorial of 10 : %d\n", val);

  // a function pointer typically stores the start of executable code.

  // the following is another way of using function pointers
  fooptr = factorial;                             // & removed
  val = fooptr(8);                                // * removed
  printf("Factorial of 8 : %d\n", val);
  
  // Unlike other pointers, we do not allocate de-allocate memory using function pointers.

  // array of function pointers
  unsigned int (*farray[])(unsigned int) = {factorial, nOnes};

  val = (*farray[0])(6);                          // facorial(6)
  printf("Factorial of 6 : %d\n", val);
  val = (*farray[1])(86);                         // nOnes(86)
  printf("Number of 1's in the binary representation of 86 : %d\n", val);

  // function pointers, like other pointers, may be passed to or returned from a function.
  
  return 0;
}

// definition
int ifunc(int x, int y) {
  if (x>y)
    return x;
  else
    return y;
}

int ifunp() {
  return 8;
}

void vfunc(int *x) {
  ++(*x);
  return;
}

void vfunv(void) {
  printf("What can I do? I am totally void. \n");
  return;
}

int* rpfunc(int *a, int *b) {
  if (*a > *b)
    return a;                                 // return a pointer;
  else
    return b;
}

int sumArray(int a[], int n) {                // the size of the array is passed
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += a[i];
  return sum;
}

////////////////////////////////////////////////////////////////
/// Recursion
////////////////////////////////////////////////////////////////

unsigned int factorial(unsigned int n) {
  if (n > 0)
    return n * factorial(n-1);
  else
    return 1;
}

unsigned int nOnes(unsigned int n) {
  if (n==0)
    return 0;
  else if (n%2 == 0)
    return nOnes(n/2);
  else
    return 1 + nOnes(n/2);
}
