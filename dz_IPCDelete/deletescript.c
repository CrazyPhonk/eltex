#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    int *array;    /* Указатель на разделяемую память */
    int shmid;     /* IPC дескриптор для области разделяемой памяти */
    int new = 1;   /* Флаг необходимости инициализации элементов массива */
    char pathname[] = "sys1.c"; // Имя файла, c
    char pathname2[] = "sys2.c"; // Имя файла, 
    char * addr;
    key_t key;  
    key_t key2;  
     /* IPC ключ */
    if((key = ftok(pathname,1)) < 0){
        printf("Can\'t generate key1\n");
        exit(-1);
    }
    if((key2 = ftok(pathname2,0)) < 0){
        printf("Can\'t generate key2\n");
        exit(-1);
    }
    shmid = shmget(key, 3*sizeof(int), 0666);
    if (shmid < 0){
        perror("shmget\n");
    }
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    if (shmctl(shmid, IPC_RMID, 0) < 0) {
        perror("shmctl");
        exit(1);
    }
    shmid = shmget(key2, 3*sizeof(int), 0666);
    if (shmid < 0){
        perror("shmget\n");
    }
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    if (shmctl(shmid, IPC_RMID, 0) < 0) {
        perror("shmctl");
        exit(1);
    }
    return 0;
}