/* Library : time.h,
             unistd.h */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>             // provides time()
#include <unistd.h>           // provides sleep()

int main() {

  ///////////////////////////////////////////////////////////////////////////
  /// time.h
  ///////////////////////////////////////////////////////////////////////////

  // difftime()
  time_t time_1, time_2;                                            // time_t variables
  time(&time_1);                                                    // current time
  for (unsigned sec = 0; sec < 6; sec++) {
    sleep(1);                                                       // pause for 1 sec
  }
  time(&time_2);
  printf("The difference in time = %.2f\n", difftime(time_2, time_1));    // the time difference
  // difftime() can be used to compute runtime of a segment of a source code

  
  
  return 0;
}
