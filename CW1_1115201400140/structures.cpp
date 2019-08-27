#include "structures.h"

item::item(int id,int t,double time){
	pid=id;
	type=t;
	timeconstruct=time;
	cout<<"Item with pid "<<pid<<" type "<<type<<" created in time "<<(double)time/CLOCKS_PER_SEC<<endl;;
}


void up(int semid,int num){
	struct sembuf semopr;
	semopr.sem_num = num;
	semopr.sem_op = +1;
	semopr.sem_flg = 0;
	if(semop(semid, &semopr, 1)==-1){
		perror("Error in up semaphore\n");
		cout<<"Sem id= "<<semid<<endl;
		exit(1);
	}
}

void down(int semid,int num){
	struct sembuf semopr;
	semopr.sem_num = num;
	semopr.sem_op = -1;
	semopr.sem_flg = 0;
	if(semop(semid, &semopr, 1)==-1){
		perror("Error in up semaphore\n");
		cout<<"Sem id= "<<semid<<endl;
		exit(1);
	}
}

void shmcleanup (int shm_id, item *addr)
{
	if((shmdt (addr)) == -1 ){
		perror ("Error in following shared memory region detach.\n");
		printf("shm region : %d\n",shm_id);
		exit (1);
	}
	if((shmctl (shm_id, IPC_RMID, 0)) == -1 ){
		perror ("Error in following shared memory region delete.\n");
		printf("shm region : %d\n",shm_id);
		exit (1);
	}
}

void semcleanup (int sem_id,int num)
{

	if((semctl(sem_id,num,IPC_RMID,0)) == -1){
		perror ("Error in deleting semaphores .\n");
	    exit (1);
	}		


}
