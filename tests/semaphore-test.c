#include <semaphore.h>
#include <stddef.h>
#include <fcntl.h>

sem_t *sem;

int main(int argc, char *argv[])
{
  sem = (sem_t *)calloc(1, sizeof(sem_t));
  
  if(sem_init(sem, 0, 0) < 0)
    {
      perror("seminit");
      exit(1);
    }

  printf("Traffic light appears\n");

  if(sem_post(sem) < 0)
    {
      perror("sempost");
      exit(1);
    }
  printf("Traffic light is green\n");
  if(sem_wait(sem) < 0)
    {
      perror("semwait");
      exit(1);
    }
  printf("Traffic light is red\n");
  //if(sem_close(sem) < 0)
  //{
  //  perror("semclose");
      //exit(1);
  //}
  // printf("All traffic lights are out\n");
  //if(sem_unlink(sem) < 0)
  //{
  //  perror("semunlink");
  //  exit(1);
  //}
  //printf("Traffic light has disappeared\n");
}
