#include "header.h"

int main(){

    printf( "\n Please input the size of the matrix \n");
    scanf("%d",&m);
    printf("\n size is: %d \n",m);

    printf("Please input number of threads:");
    scanf("%d",&threadCount);
    if(threadCount>8)
        threadCount = 1;
    printf("\n threads: %d\n",threadCount);

     printf( "\n Please input the turn you wish to run \n");
    scanf("%d",&inputTurn);
    printf("\n turns : %d \n",m);



    printf( "\n Please select option... Do you wish to consider the tradition of mourning the dead for 3 turns?(1/0) \n");
    scanf("%d",&traditions);
    printf("\n traditions is: %d \n",traditions);

    printf( "\n Please select option... Do you wish to consider the quarantine feature?(1/0)\n");
    scanf("%d",&quarantine);
    printf("\n quarantine is: %d \n",quarantine);

    pthread_mutex_init(&myLock1,NULL);
    //pthread_mutex_init(&myLock2,NULL);
    //pthread_mutex_init(&myLock3,NULL);
    sem_init(&barrier_sem, 0, 0);
    sem_init(&count_sem, 0, 1);

    counter = 0;
    barrierTH = threadCount;
    turnCount = 0;
    threadHome = 0;
    counterCount = 0;

    subjectsArray = (int *)malloc(m*2*m*sizeof(int ));


    for(i=0;i<m*m;i++){

        int immunity,age,initialState,futureState;
        futureState = m*m+i;

        if(getRandomNumberFromRange(0.0,10.0)<=1){

            immunity = IMMUNE_TH;
        }else{

            immunity = 0;
        }

        if(getRandomNumberFromRange(0.0,10.0)<=1 && immunity==0){

	        initialState = INCUBATED_TH;
        }else{

	        initialState = 0;
        }
            age = getRandomNumberFromRange(1,99);

            subjectsArray[i] = (immunity + initialState +age);
            subjectsArray[futureState] = (immunity + initialState +age);
            printf("\n-- subject: %d->%d  --intialized -|- immunity is: %d -|- state is: %d -|- age is: %d --> %d futureState: %d",i,futureState,immunity,initialState,age,subjectsArray[i],subjectsArray[futureState]);
    }


    for(i=0;i<m*m*2;i++)
        printf("\nsubject %d: %d",i,subjectsArray[i]);

    thread_handles = malloc(threadCount*sizeof(pthread_t));

    for(thread=0; thread<threadCount; thread++)
        pthread_create(&thread_handles[thread],NULL,child,(void*)thread);

    for(thread=0; thread<threadCount; thread++)
        pthread_join(thread_handles[thread],NULL);


    free(thread_handles);
    sem_destroy(&count_sem);
    sem_destroy(&barrier_sem);
    pthread_mutex_destroy(&myLock1);
    //pthread_mutex_destroy(&myLock2);
    //pthread_mutex_destroy(&myLock3);

    free(subjectsArray);



    return 0;
}
