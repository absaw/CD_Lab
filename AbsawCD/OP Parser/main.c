#include<stdio.h>
#include<conio.h>
void main(){

/*OPERATOR PRECEDENCE PARSER*/
char stack[20],ip[20],opt[10][10][1],ter[10];
/*ip- input
opt - operator precedence
ter - terminal*/

int i,j,k,n,top=0,col,row;
//clrscr();
for(i=0;i<10;i++)
    {
     stack[i]=NULL;
     ip[i]=NULL;
     for(j=0;j<10;j++)
     {
            opt[i][j][1]=NULL;
     }
    }
printf("Enter the no.of terminals :\n");
scanf("%d",&n);
printf("\nEnter the terminals :\n");
scanf("%s",&ter);
printf("\nEnter the table values :\n");
for(i=0;i<n;i++)
{
     for(j=0;j<n;j++)
     {
         printf("Enter the value for %c %c:",ter[i],ter[j]);
         scanf("%s",opt[i][j]);
     }
}
printf("\n**** OPERATOR PRECEDENCE TABLE ****\n");
for(i=0;i<n;i++)
{
    printf("\t%c",ter[i]);//printing columns
}
printf("\n");
for(i=0;i<n;i++)
    {printf("\n%c",ter[i]);//printing rows

for(j=0;j<n;j++)
    {printf("\t%c",opt[i][j][0]);}}//printing operator precedence table

int t=1;
while(1)
{

printf("\nEnter 1 - Input \n2 -Exit\n");
scanf("%d",&t);
if(t==2)
{
    printf("Thank You");
    break;
}
stack[top]='$';

printf("\nEnter the input string:");
scanf("%s",ip);
i=0;
printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
printf("\n%s\t\t\t%s\t\t\t",stack,ip);

    while(i<=strlen(ip))
    {
        for(k=0;k<n;k++)
        {
            if(stack[top]==ter[k])
            col=k;
            if(ip[i]==ter[k])
            row=k;
        }
        if((stack[top]=='$')&&(ip[i]=='$'))
        {
            printf("String is accepted\n");
            break;
        }
        else if((opt[col][row][0]=='<') ||(opt[col][row][0]=='='))
        {
            stack[++top]=opt[col][row][0];
            stack[++top]=ip[i];
            printf("Shift %c",ip[i]);
            i++;
        }
        else
        {
             if(opt[col][row][0]=='>')
            {
                while(stack[top]!='<')
                {
                    --top;
                }
                top=top-1;
                printf("Reduce");
            }
            else
            {
                printf("\nString is not accepted");
                break;
            }
        }
        printf("\n");
        for(k=0;k<=top;k++)
        {
            printf("%c",stack[k]);
        }
        printf("\t\t\t");
        for(k=i;k<strlen(ip);k++)
        {
            printf("%c",ip[k]);
        }
        printf("\t\t\t");
    }
    }
getch();
}
