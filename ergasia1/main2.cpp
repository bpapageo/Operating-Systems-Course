#include "mymalloc.h"
 
int main()
{
    int n;
    char *text;
     
    printf("Enter limit of the text: ");
    scanf("%d",&n);
     
    /*allocate memory dynamically*/
    text=(char*)mymalloc(n*sizeof(char));
     
    printf("Enter text: ");
    scanf(" "); /*clear input buffer*/
    gets(text);
     
    printf("Inputted text is: %s\n",text);
     
    /*Free Memory*/
    myfree(text);
     
    return 0;
}
