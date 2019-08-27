#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <bitset>


using namespace std;

struct Doublelistnode{
	char bitvector[16];
	void* pageptr;
	int bclass;
	int bits;
	Doublelistnode* next;
	Doublelistnode* prev;
	Doublelistnode(int);
};

class Doublelist{
private:
	Doublelistnode* head;
	Doublelistnode* tail;
	int size;
	int cls;
public:
	Doublelist(int);
	~Doublelist();
    	void insert_front();
    	Doublelistnode* insert_back(void*);
   	int delete_front();
    	int delete_back();
    	bool is_empty();
    	void display();
	int search();
    	int length();
};

struct listnode{
	Doublelistnode* ptr;
	listnode* next;
	listnode();
};

class List{
private:
	listnode* head;
	int size;
public:
	List();
    	void insert(Doublelistnode*);
    	bool is_empty();
    	void display();
    	int length();
	int search(void*);
	void flip(void*,long);

};

class hashtable{
	int size;
	List** list;
public:
	hashtable(int);
	~hashtable();
	int hashfunction(void*,int);
	void insert(void*,Doublelistnode*);
	int search(void*);
	void flip(void*,long);
	void hashprint();
};


