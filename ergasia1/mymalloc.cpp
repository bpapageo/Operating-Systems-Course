#include "mymalloc.h"

int set=0,flag=0;
void *p1,*p2,*p3;
Doublelist** table;
hashtable hash(4093);


void* mymalloc(size_t cbytes){
	void* pp=NULL;
	Doublelistnode* p4;
	if(cbytes>4096){
		pp=malloc(cbytes);
		return pp;
	}
	else{
		if(cbytes<=32){
			cbytes=32;
		}
		else{	
			unsigned int top=32;
			while(cbytes>=top){
				top*=2;
			}
			cbytes=top;
		}
	}
	if(set==0){
	p1=malloc(1048576),p2=p1;
	cout<<"arx.diefthynsi se 16adiko "<<p1<<endl;
	long p=(long)p1;
	long pend=p+1048576;
	pend=pend-(pend%4096);
	long pstart=p+(4096-p%4096);
	cout<<"efthygrammismenh arxh se 10diko "<<pstart<<endl;
	cout<<"efthygrammismeno telos se 10diko "<<pend<<endl;
	p1=p1+(pstart - p);
	p3=p1+(pend - pstart);
	cout<<"arx.diefthynsi se 16adiko "<<p1<<endl;
	cout<<"tel.diefthynsi se 16adiko "<<p3<<endl;
	table =new Doublelist*[8];
	table[0]=new Doublelist(32);
	table[1]=new Doublelist(64);
	table[2]=new Doublelist(128);
	table[3]=new Doublelist(256);
	table[4]=new Doublelist(512);
	table[5]=new Doublelist(1024);
	table[6]=new Doublelist(2048);
	table[7]=new Doublelist(4096);
	set=1;
	}
	if(p1!=p3){
		switch (cbytes)
		{
		case 32:	
			if(table[0]->search()==-1){
				p4=table[0]->insert_back(p1);
				hash.insert(p1,p4);
				p1=p1+4096;
			}
			break;

		case 64:
			if(table[1]->search()==-1){
				p4=table[1]->insert_back(p1);
				hash.insert(p1,p4);
				p1=p1+4096;
			}	
			break;
	
		case 128:
			if(table[2]->search()==-1){
				p4=table[2]->insert_back(p1);
				hash.insert(p1,p4);
				p1=p1+4096;
			}
			break;
	
		case 256:
			if(table[3]->search()==-1){
				p4=table[3]->insert_back(p1);
				hash.insert(p1,p4);
				p1=p1+4096;
			}
			break;
	
		case 512:
			if(table[4]->search()==-1){
				p4=table[4]->insert_back(p1);
				hash.insert(p1,p4);
				p1=p1+4096;
			}
			break;
	
		case 1024:
			if(table[5]->search()==-1){
				p4=table[5]->insert_back(p1);
				hash.insert(p1,p4);
				p1=p1+4096;
			}
			break;
	
		case 2048:
			if(table[6]->search()==-1){
				p4=table[6]->insert_back(p1);
				hash.insert(p1,p4);
				p1=p1+4096;
			}
			break;
	
		case 4096:
			if(table[7]->search()==-1){
				p4=table[7]->insert_back(p1);
				hash.insert(p1,p4);
				p1=p1+4096;
			}
			break;
		
		default:
			cout<<"Something went wrong"<<endl;
			break;
		
		}
	}
	else{
		p1=malloc(1048576),p2=p1;
		cout<<"arx.diefthynsi se 16adiko "<<p1<<endl;
		long p=(long)p1;
		long pend=p+1048576;
		pend=pend-(pend%4096);
		long pstart=p+(4096-p%4096);
		cout<<"efthygrammismenh arxh se 10diko "<<pstart<<endl;
		cout<<"efthygrammismeno telos se 10diko "<<pend<<endl;
		p1=p1+(pstart - p);
		p3=p1+(pend - pstart);
		cout<<"arx.diefthynsi se 16adiko "<<p1<<endl;
		cout<<"tel.diefthynsi se 16adiko "<<p3<<endl;
		switch (cbytes)
		{
		case 32:	
			if(table[0]->search()==-1){
				p4=table[0]->insert_back(p1);
				hash.insert(p1,p4);
				p1=p1+4096;
			}
			break;

		case 64:
			if(table[1]->search()==-1){
				p4=table[1]->insert_back(p1);
				hash.insert(p1,p4);
				p1=p1+4096;
			}	
			break;
	
		case 128:
			if(table[2]->search()==-1){
				p4=table[2]->insert_back(p1);
				hash.insert(p1,p4);
				p1=p1+4096;
			}
			break;
	
		case 256:
			if(table[3]->search()==-1){
				p4=table[3]->insert_back(p1);
				hash.insert(p1,p4);
				p1=p1+4096;
			}
			break;
	
		case 512:
			if(table[4]->search()==-1){
				p4=table[4]->insert_back(p1);
				hash.insert(p1,p4);
				p1=p1+4096;
			}
			break;
	
		case 1024:
			if(table[5]->search()==-1){
				p4=table[5]->insert_back(p1);
				hash.insert(p1,p4);
				p1=p1+4096;
			}
			break;
	
		case 2048:
			if(table[6]->search()==-1){
				p4=table[6]->insert_back(p1);
				hash.insert(p1,p4);
				p1=p1+4096;
			}
			break;
	
		case 4096:
			if(table[7]->search()==-1){
				p4=table[7]->insert_back(p1);
				hash.insert(p1,p4);
				p1=p1+4096;
			}
			break;
		
		default:
			cout<<"Something went wrong"<<endl;
			break;
		
		}
	}


	table[3]->display();
	//hash.hashprint();	

	return p1-4096;


}

void myfree(void* ptr){

	long p=(long)ptr;
	long pp=p-(p%4096);
	ptr=ptr - (p -pp);
	long dist=p - pp;
	if(hash.search(ptr)==1){
		free(ptr);
	}
	else{
		hash.flip(ptr,dist);

	}

}


