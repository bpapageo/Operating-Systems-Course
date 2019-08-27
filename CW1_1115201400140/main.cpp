#include "structures.h"

int main(int argc,char *argv[]){
 
	//check if argument Y has given
	if(argc!=2){
		 printf("You have not given the right number of arguments\n");
		 exit(1);
	}	
	int pid,semid,shmidbeforePaint,shmidafterPaint,shmidaftercheck,status,w1inbeforepaint,w2inbeforepaint,w3inbeforepaint;
	int w1inafterpaint,w2inafterpaint,w3inafterpaint,ischanged,w1check,w2check,w3check;
	item *beforePaint,*afterPaint,*aftercheck;
	union senum arg;
	int Y=atoi(argv[1]);
	srand(time(NULL));
	item** buff1=new item*[Y];
	item** buff2=new item*[Y];
	item** buff3=new item*[Y];
	 
	/* CREATING 10 SEMAPHORES */
	if ((semid = semget (IPC_PRIVATE, 10, IPC_CREAT|0666)) == -1 ) {
	   perror ("Error in semaphores creation.\n");
	   exit (1);
	}// if creation of semaphores get failed

	/* Init semaphores(1st-3rd to 0 and 2nd-4th to 1) */
	arg.val=1;
	if((semctl(semid,0,SETVAL,arg)) == -1){
	   perror ("Error in 1st semaphore initialization.\n");
	   exit (1);
	}
	arg.val=0;
	if((semctl(semid,1,SETVAL,arg)) == -1){
		perror ("Error in 2nd semaphore initialization.\n");
	    exit (1);
	}
	arg.val=0;
	if((semctl(semid,2,SETVAL,arg)) == -1){
		perror ("Error in 3rd semaphore initialization.\n");
	    exit (1);
	}
	arg.val=1;
	if((semctl(semid,3,SETVAL,arg)) == -1){
		perror ("Error in 4th semaphore initialization.\n");
	    exit (1);
	}
	arg.val=0;
	if((semctl(semid,4,SETVAL,arg)) == -1){
		perror ("Error in 5th semaphore initialization.\n");
	    exit (1);
	}
	arg.val=0;
	if((semctl(semid,5,SETVAL,arg)) == -1){
		perror ("Error in 6th semaphore initialization.\n");
	    exit (1);
	}
	arg.val=0;
	if((semctl(semid,6,SETVAL,arg)) == -1){
		perror ("Error in 7th semaphore initialization.\n");
	    exit (1);
	}
	arg.val=0;
	if((semctl(semid,7,SETVAL,arg)) == -1){
		perror ("Error in 8th semaphore initialization.\n");
	    exit (1);
	}
	arg.val=0;
	if((semctl(semid,8,SETVAL,arg)) == -1){
		perror ("Error in 9th semaphore initialization.\n");
	    exit (1);
	}
	arg.val=0;
	if((semctl(semid,9,SETVAL,arg)) == -1){
		perror ("Error in 10th semaphore initialization.\n");
	    exit (1);
	}
	// SET UP SHARED MEMORY SEGMENTS
	 
	if ((shmidbeforePaint = shmget (IPC_PRIVATE, sizeof(item), 0666 | IPC_CREAT)) == -1 ) {
	 	perror ("Error in beforePaint shared memory region setup.\n");
	    exit (1);
	}// if shared memory beforePaint get failed
	 
	if ((shmidafterPaint = shmget (IPC_PRIVATE, sizeof(item), 0666 | IPC_CREAT)) == -1 ) {
	 	perror ("Error in afterPaint shared memory region setup.\n");
	    exit (1);
	}// if shared memory afterPaint get failed

	if ((shmidaftercheck = shmget (IPC_PRIVATE, 3*sizeof(item), 0666 | IPC_CREAT)) == -1 ) {
	 	perror ("Error in afterPaint shared memory region setup.\n");
	    exit (1);
	}// if shared memory aftercheck get failed
	 
	// attach the shared memory segments
	if((beforePaint = (item *) shmat (shmidbeforePaint, 0, 0)) ==(item *) -1){
		perror ("Error in beforePaint shared memory region attach.\n");
	    exit (1);
	}// if attach of shared memory beforePaint get failed
	 
	if((afterPaint = (item *) shmat (shmidafterPaint, 0, 0)) ==(item *) -1){
		perror ("Error in afterPaint shared memory region attach.\n");
	    exit (1);
	}// if attach of shared memory afterPaint get failed 
	if((aftercheck = (item *) shmat (shmidaftercheck, 0, 0)) ==(item *) -1){
		perror ("Error in afterPaint shared memory region attach.\n");
	    exit (1);
	}// if attach of shared memory aftercheck get failed 

	 
	 
	w1inbeforepaint=0;//initialized with value 1
	w2inbeforepaint=1;//initialized with value 0
	w3inbeforepaint=2;//initialized with value 0
	w1inafterpaint=3;//initialized with value 1
	w2inafterpaint=4;//initialized with value 0
	w3inafterpaint=5;//initialized with value 0
	ischanged=6;///initialized with value 0
	w1check=7;//initialized with value 0
	w2check=8;//initialized with value 0
	w3check=9;//initialized with value 0

	for(int i=0;i<8;i++){
		pid=fork();
		if(pid==0){//Producer
			if(i==0){
				////Construction stadium
				for(int j =0;j<Y;j++){
					down(semid,w1inbeforepaint);
					clock_t time=clock();
					buff1[j]=new item(getpid(),1,(double)time/CLOCKS_PER_SEC);
					time = clock();
					buff1[j]->timepaint=(double)time/CLOCKS_PER_SEC;
					memcpy(beforePaint,buff1[j],sizeof(item));
					up(semid,ischanged);				
				}
			}			
			else if(i==1){
				////Construction stadium
				for(int j =0;j<Y;j++){
					down(semid,w2inbeforepaint);
					clock_t time=clock();
					buff2[j]=new item(getpid(),2,(double)time/CLOCKS_PER_SEC);
					time = clock();
					buff2[j]->timepaint=(double)time/CLOCKS_PER_SEC;
					memcpy(beforePaint,buff2[j],sizeof(item));
					up(semid,ischanged);
				}

			}
			else if(i==2){
				////Construction stadium
				for(int j =0;j<Y;j++){
					down(semid,w3inbeforepaint);
					clock_t time=clock();
					buff3[j]=new item(getpid(),3,(double)time/CLOCKS_PER_SEC);
					time = clock();
					buff3[j]->timepaint=(double)time/CLOCKS_PER_SEC;
					memcpy(beforePaint,buff3[j],sizeof(item));
					up(semid,ischanged);
				}

			}
			else if(i==3){
				double sum=0;
				///Painting stadium
				for(int j =0;j<3*Y;j++){
					usleep(3);
					down(semid,ischanged);				
					sum+=(double)((beforePaint->timepaint)-(beforePaint->timeconstruct))/CLOCKS_PER_SEC;
					memcpy(afterPaint,beforePaint,sizeof(item));
					if(beforePaint->type==1){
						up(semid,w2inbeforepaint);
						up(semid,w1inafterpaint);
					}
					else if(beforePaint->type==2){
						up(semid,w3inbeforepaint);
						up(semid,w2inafterpaint);
					}	
					else{
						up(semid,w1inbeforepaint);
						up(semid,w3inafterpaint);
					}			
				}
				sum=sum/(3*Y);
				cout<<"Mean time waiting for painting: "<<sum<<endl;
			}
			else if(i==4){
				///checking 1 stadium
				for(int j =0;j<Y;j++){
					usleep(1);
					down(semid,w1inafterpaint);
					memcpy(aftercheck,afterPaint,sizeof(item));
					up(semid,w1check);
				}
			}
			else if(i==5){
				///checking 2 stadium
				for(int j =0;j<Y;j++){
					usleep(1);
					down(semid,w2inafterpaint);
					memcpy(aftercheck+sizeof(item),afterPaint,sizeof(item));
					up(semid,w2check);
				}
			}
			else if(i==6){
				///checking 3 stadium
				for(int j =0;j<Y;j++){
					usleep(1);
					down(semid,w3inafterpaint);
					memcpy(aftercheck+2*sizeof(item),afterPaint,sizeof(item));
					up(semid,w3check);

				}
			}
			else if(i==7){
				///Final set up stadium
				double sum=0;
				for(int j =0;j<Y;j++){
					down(semid,w1check);
					down(semid,w2check);
					down(semid,w3check);
					usleep(2);
					int pid1=aftercheck->pid;
					clock_t time1=aftercheck->timeconstruct;
					int pid2=(aftercheck+sizeof(item))->pid;
					int pid3=(aftercheck+2*sizeof(item))->pid;
					clock_t time2=clock();
					sum+=(double)(time2-time1)/CLOCKS_PER_SEC;
					cout<<"Product "<<j+1<<" with pid "<<pid1<<pid2<<pid3<<" created"<<endl;
				}
				sum=sum/Y;
				cout<<"Mean time for creating a product: "<<sum<<endl;
			}
			return 0;
		}
		else if(pid<0){
			perror("Error in fork(pid<0)\n");
			exit(1);
		}
	}

	for (;;) {
	    // Remove the zombie process, and get the pid and return code
	    pid = wait(&status);
	    if (pid < 0) {
	        if (errno == ECHILD) {
	            printf("All children have exited\n");
	            break;
	        }
	        else {
	                perror("Could not wait");
	        }
	    }
	    else {
	        //printf("Child %d exited with status %d\n", pid, status);
	    }
	}
	/* remove semaphores */
	semcleanup(semid,10);
	 
	/* detach and remove shared memory segments */
	shmcleanup(shmidbeforePaint,beforePaint);
	shmcleanup(shmidafterPaint,afterPaint);
	shmcleanup(shmidaftercheck,aftercheck);

	 
	 return 0;
	 
}
 
