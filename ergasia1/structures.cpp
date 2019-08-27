#include "structures.h"

Doublelistnode::Doublelistnode(int ss):bclass(-1){
	switch (ss)
	{
	case 32:	
		bclass=15;
		bits=128;
		break;

	case 64:
		bclass=7;
		bits=64;
		break;

	case 128:
		bclass=3;
		bits=32;
		break;

	case 256:
		bclass=1;
		bits=16;
		break;

	case 512:
		bclass=0;
		bits=8;
		break;

	case 1024:
		bclass=0;
		bits=4;
		break;

	case 2048:
		bclass=0;
		bits=2;
		break;

	case 4096:
		bclass=0;
		bits=1;
		break;
	
	default:
		cout<<"Something went wrong"<<endl;
		break;
	
	}
	for(int i=0;i<=bclass;i++){
		bitvector[i]=0;
	}
	bitvector[0]=128;
	for(int i=0;i<=bclass;i++){
		//cout<<bitset<8>(bitvector[i])<<endl;
	}
	next=NULL;
	prev=NULL;
	pageptr=NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Doublelist::Doublelist(int s):cls(s){
	head=tail=NULL;
	size=0;

}

Doublelist::~Doublelist(){
}

void Doublelist::insert_front(){
	Doublelistnode* temp = new Doublelistnode(cls);
	if(head==NULL){
		head=tail=temp;
	}
	else{
		head->prev=temp;
		temp->next=head;
		head=temp;
	}
	size++;
		
}

Doublelistnode* Doublelist::insert_back(void* ptr){
	Doublelistnode* temp = new Doublelistnode(cls);
	temp->pageptr=ptr;
	if(tail==NULL){
		head=tail=temp;
	}
	else{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;

	}
	size++;
	return tail;
}

int Doublelist::delete_front(){
	if(!is_empty()){
		Doublelistnode* temp = head;
		if(head==tail){
			tail=NULL;
		}
		head=head->next;
		head->prev = NULL;
		delete temp;
		size--;
		return 0;
	}
	return 0;
}

int Doublelist::delete_back(){
	if(!is_empty()){
		Doublelistnode* temp = head;
		if(head==tail){
			head=NULL;
		}
		tail = tail->prev;
		tail->next=NULL;
		delete temp;
		size--;
		return 0;
	}
	return 0;
}

bool Doublelist::is_empty(){
	if (size<=0){
		return true;
	}
	return false;
}

void Doublelist::display(){
	cout<<"$$$"<<endl;
	Doublelistnode* temp = head;
	while(temp!=NULL){
		for(int i=0;i<=head->bclass;i++){
			cout<<bitset<8>(temp->bitvector[i])<<endl;
		}
		cout<<temp->pageptr<<endl;
		cout<<"@@"<<endl;
		temp=temp->next;
	}
}

int Doublelist::search(){
	Doublelistnode* temp = head;
	while(temp!=NULL){
		for(int i=0;i<=(head->bclass);i++){
			if((head->bits)>=8){
				if(((temp->bitvector[i])&255)!=255){
					for(int j=7;j>=0;j--){
						if(((temp->bitvector[i] >> j) & 1)==0){
							temp->bitvector[i] |= 1 << j;
							return 0;
						}
					}	
				
				}
			}
			else if((head->bits)==4){
				if(((temp->bitvector[i])&255)<240){
					for(int j=4;j<=7;j++){
						if(((temp->bitvector[i] >> j) & 1)==0){
							temp->bitvector[i] |= 1 << j;
							return 0;
						}
					}
				}	
			
			}
			else if((head->bits)==2){
				if(((temp->bitvector[i])&255)<192){
					for(int j=6;j<=7;j++){
						if(((temp->bitvector[i] >> j) & 1)==0){
							temp->bitvector[i] |= 1 << j;
							return 0;
						}
					}
				}	
			
			
			}
			else if((head->bits)==1){
				if(((temp->bitvector[i])&255)<128){
						if(((temp->bitvector[i] >> 7) & 1)==0){
							temp->bitvector[i] |= 1 << 7;
							return 0;
						}	
				}
			
			}
		}
		temp=temp->next;
	}
	return -1;
}


int Doublelist::length(){
	return size;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
listnode::listnode(){
	next=NULL;
	ptr=NULL;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
List::List(){
	head=NULL;
	size=0;
}

void List::insert(Doublelistnode* nodept){
	listnode* temp = new listnode();
	temp->ptr=nodept;
	if(head==NULL){
		head=temp;
	}
	else{
		temp->next=head;
		head=temp;
	}
	size++;
		
}

bool List::is_empty(){
	if (size<=0){
		return true;
	}
	return false;
}

void List::display(){
	listnode* temp = head;
	while(temp!=NULL){
		cout<<temp->ptr<<endl;
		temp=temp->next;
	}

}

int List::length(){
	return size;
}

int List::search(void* pt){
	listnode* temp = head;
	while(temp!=NULL){
		if((temp->ptr->pageptr)==pt){
			return 0;
		}
		temp=temp->next;
	}
	return 1;

}

void List::flip(void* pt,long d){
	listnode* temp = head;
	int k;
	while(temp!=NULL){
		if((temp->ptr->pageptr)==pt){
			if((temp->ptr->bits)==128){
				if((d/32)<=7){
					k=0;
				}
				else if((d/32)<=15){
					k=1;
				}
				else if((d/32)<=23){
					k=2;
				}
				else if((d/32)<=31){
					k=3;
				}
				else if((d/32)<=39){
					k=4;
				}
				else if((d/32)<=47){
					k=5;
				}
				else if((d/32)<=55){
					k=6;
				}
				else if((d/32)<=63){
					k=7;
				}
				else if((d/32)<=71){
					k=8;
				}
				else if((d/32)<=79){
					k=9;
				}
				else if((d/32)<=87){
					k=10;
				}
				else if((d/32)<=95){
					k=11;
				}
				else if((d/32)<=103){
					k=12;
				}
				else if((d/32)<=111){
					k=13;
				}
				else if((d/32)<=119){
					k=14;
				}
				else if((d/32)<=127){
					k=15;
				}
				temp->ptr->bitvector[k] ^= 1 << (7 - (d/32)%8);
				return;		
			}
			else if((temp->ptr->bits)==64){
				if((d/64)<=7){
					k=0;
				}
				else if((d/64)<=15){
					k=1;
				}
				else if((d/64)<=23){
					k=2;
				}
				else if((d/64)<=31){
					k=3;
				}
				else if((d/64)<=39){
					k=4;
				}
				else if((d/64)<=47){
					k=5;
				}
				else if((d/64)<=55){
					k=6;
				}
				else if((d/64)<=63){
					k=7;
				}
				temp->ptr->bitvector[k] ^= 1 << (7 - (d/64)%8);
				return;		
	
			}
			else if((temp->ptr->bits)==32){
				if((d/128)<=7){
					k=0;
				}
				else if((d/128)<=15){
					k=1;
				}
				else if((d/128)<=23){
					k=2;
				}
				else if((d/128)<=31){
					k=3;
				}
				temp->ptr->bitvector[k] ^= 1 << (7 - (d/128)%8);
				return;		
	
			}
			else if((temp->ptr->bits)==16){
				if((d/256)>7){
					k=1;
				}
				else{
					k=0;
				}
				temp->ptr->bitvector[k] ^= 1 << (7 - ((d/256)%8));
				return;		
	
			}
			else if((temp->ptr->bits)==8){
				temp->ptr->bitvector[0] ^= 1 << (7 - (d/512));
				return;		
	
			}
			else if((temp->ptr->bits)==4){
				temp->ptr->bitvector[0] ^= 1 << (7 - (d/1024));
				return;		
	
			}
			else if((temp->ptr->bits)==2){;
				temp->ptr->bitvector[0] ^= 1 << (7-(d/2048));
				return;		
	
			}
			else if((temp->ptr->bits)==1){
				temp->ptr->bitvector[0] ^= 1 << (7 - (d/4096));
				return;		
	
			}
			
		}
		temp=temp->next;
	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int hashtable:: hashfunction(void* num,int size){

        long c=(long)num;

	return c%size;
}



hashtable::hashtable(int k):size(k){
	list = new List*[k];
	for(int i=0;i<k;i++){
		list[i]=new List();
	}
}

hashtable::~hashtable(){
	for(int i=0;i<size;i++){
		delete list[i];
	}
	delete []list;

}

void hashtable::insert(void* pt,Doublelistnode* nodept) { 
		list[hashfunction(pt,size)]->insert(nodept);
}


void hashtable::hashprint(){
	for(int i=0;i<size;i++){
		list[i]->display();
	}
}

int hashtable::search(void* pt){
		return list[hashfunction(pt,size)]->search(pt);
}

void hashtable::flip(void* pt,long d) { 
		list[hashfunction(pt,size)]->flip(pt,d);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
