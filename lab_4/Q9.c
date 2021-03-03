#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <pthread.h>

#define NUM_THREADS 5     /* define the total number of processes we want */

float total=0;    /* Set global variable */
pthread_mutex_t mutexsum;

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
    pthread_mutex_lock (&mutexsum);
    oldtotal = total;
    total = oldtotal + result;
    pthread_mutex_unlock (&mutexsum);

    /* Print running total so far. */
    printf("Total is %f\n",total);

    pthread_exit((void*) 0);
} // code to be continued

int main()
{
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    void *status;
    int rc;
    long t;

    printf("\n"); /* bit of whitespace */

    pthread_mutex_init(&mutexsum, NULL);
    
    /* performing dot multiplication through the initialisation of the
       pthreads */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    /* to loop and create the required number of processes */
    /* NOTE carefully how only the child process is left to run */
    for(t=0;t<NUM_THREADS;t++)
    {  
          /* give a message about the proc ID */
            printf("IN MAIN: creating thread %ld\n", t);

             /* call the function to do some computation */
             rc = pthread_create(&threads[t], &attr, compute, (void *)t);
             if (rc){
               printf("ERROR: return code from pthread_create() is %d\n", rc);
               exit(-1);
             }
    }
    pthread_attr_destroy(&attr);

    for(t=0; t<NUM_THREADS; t++)
    {
      pthread_join(threads[t], &status);
    }

    pthread_mutex_destroy(&mutexsum);
    pthread_exit(NULL);
 }
