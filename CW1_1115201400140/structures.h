#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define SHMSIZE 1024 

using namespace std;

union senum {
	int val;
	struct semid_ds *buff;
	unsigned short *array;
};

struct item
{
	public:
	int pid;
	int type;
	double timepaint;
	double timeconstruct;
	item(int,int,double);
	
};

void up(int,int);
void down(int,int);
void shmcleanup (int, item*);
void semcleanup (int,int);
