#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <pthread.h>

#define NUM_THREADS 5     /* define number of threads*/

float total=0;    /* Set global variable */

void *compute(void *threadid)     /* compute function just does something. */
{
    int i;
    float oldtotal=0, result=0;

    /* for a large number of times */
    for(i=0;i<2000000000;i++)
      result = sqrt(1000.0) * sqrt(1000.0);

    /* Print the result – should be no surprise */
    printf("Result is %f\n",result);

    /* to keep a running total in the global variable total */
    oldtotal = total;
    total = oldtotal + result;

    /* Print running total so far. */
    printf("Total is %f\n",total);

    pthread_exit(NULL);
} // code to be continued

int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    float result=0;

    printf("\n"); /* bit of whitespace */

    /* to loop and create the required number of processes */
    /* NOTE carefully how only the child process is left to run */
    for(t=0;t<NUM_THREADS;t++)
    {
          /* give a message about the thread ID */
            printf("IN MAIN: creating thread %ld\n", t);

             /* call the function to do some computation */
             rc = pthread_create(&threads[t], NULL, compute, (void *)t);
             if (rc){
               printf("ERROR: return code from pthread_create() is %d\n", rc);
               exit(-1);
             }
             /* After computation, quit. OR process creation will bom! */
             break;
    }
    pthread_exit(NULL);
 }
