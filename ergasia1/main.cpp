#include "mymalloc.h"

int main(int argc,char* argv[]){
int* p;

cout<<"1st call"<<endl;
p=(int*)mymalloc(1234);
cout<<"2nd call"<<endl;
p=(int*)mymalloc(1234);
cout<<"3rd call"<<endl;
p=(int*)mymalloc(1234);
cout<<"4th call"<<endl;
p=(int*)mymalloc(1234);
cout<<"5th call"<<endl;
p=(int*)mymalloc(1234);
cout<<"6th call"<<endl;
p=(int*)mymalloc(1234);

for(int k=0;k<=250;k++){
cout<<k+7<<" call"<<endl;
p=(int*)mymalloc(223);
}
cout<<"p "<<p<<endl;
myfree(p-64);
myfree(p+64);

mymalloc(223);
mymalloc(223);
return 0;
}
