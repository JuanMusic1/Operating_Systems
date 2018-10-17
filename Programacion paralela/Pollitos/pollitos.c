#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t pollito1, pollito2, pollito3, pollito4, pollito5, pollito6;




int counter;
pthread_mutex_t lock;

void * comer();


int  count = 0;

#define COMIDA_DISPONIBLE  1000


	 
 int main(){
    pthread_t thread1, thread2;
    //pthread_create( &thread1, NULL, &functionCount1, NULL);
    //pthread_create( &thread2, NULL, &functionCount2, NULL);
    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL);
    printf("Final count: %d\n",count);

	exit(EXIT_SUCCESS);



    int i = 0;
    int err;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    while(i < 2)
    {
        //err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }

    //pthread_join(tid[0], NULL);
    
    //pthread_join(tid[1], NULL);
    //pthread_mutex_destroy(&lock);

    return 0;

}
