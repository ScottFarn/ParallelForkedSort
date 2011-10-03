#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int i;
pid_t pid;
int main(int argc, char *argv[])
{
    printf("INITIAL PPID %d\n", getppid());
    int num_proc=atoi(argv[1]);
    for (i=0; i<num_proc; i++)
        if (fork()==0)
        {

            printf("CHILD****************pid %d ppid %d \n", getpid(),getppid());
            if(i == (num_proc - 1))
            {
                printf("%d LEAF!\n", getpid());
            }
        }
        else
        {
            if (fork()!=0)
            {
                printf(" %d Root!\n", getpid());
                sleep(1);
                //wait(NULL);

                _exit(0);
            }
            else
            {

                printf("PARENT------------------pid %d ppid %d \n", getpid(),getppid());
            }
            if(i == (num_proc -1))
            {
                printf("%d LEAF! 4 shore?\n", getpid());
            }
            //printf("%d LEAF 4 sure?!\n", getpid());
        }

        return 0;
}
