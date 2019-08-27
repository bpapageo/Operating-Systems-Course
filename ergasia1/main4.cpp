#include "mymalloc.h"
 
struct student
{
    char name[30];
    int roll;
    float perc;
};
 
int main()
{
    struct student *pstd,*pstdd;
    int n,i;
     
    printf("Enter total number of elements: ");
    scanf("%d",&n);
     
    /*Allocate memory dynamically for n objetcs*/
    pstd=(struct student*)mymalloc(n*sizeof(struct student));
    //pstdd=(struct student*)mymalloc(n*sizeof(struct student));
	//myfree(pstd);
    pstdd=(struct student*)mymalloc(n*sizeof(struct student));
     
    if(pstd==NULL)
    {
        printf("Insufficient Memory, Exiting... \n");
        return 0;
    }
     
    /*read and print details*/
    for(i=0; i<n; i++)
    {
        printf("\nEnter detail of student [%3d]:\n",i+1);
        printf("Enter name: ");
        scanf(" "); /*clear input buffer*/
        gets((pstd+i)->name);
        printf("Enter roll number: ");
        scanf("%d",&(pstd+i)->roll);
       	printf("Enter percentage: ");
        scanf("%f",&(pstd+i)->perc);
    }
     
    printf("\nEntered details are:\n");
    for(i=0; i<n; i++)
    {
        printf("%30s \t %5d \t %.2f\n",(pstd+i)->name,(pstd+i)->roll,(pstd+i)->perc);
    }
      
    return 0;
}
