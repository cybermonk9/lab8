#include<stdio.h>
#include<stdlib.h>
#define NULL 0
struct node
{
char ssn[10],name[20],dept[10],desg[10],phno[15];
int sal;
struct node *rlink;
struct node *llink;
};
typedef struct node *nodepointer;
nodepointer temp,first=NULL,end=NULL;
nodepointer getnode()
{
nodepointer x;
x=(nodepointer)malloc(sizeof(struct node));
return x;
}
void read()
{
temp=getnode();
temp->llink=NULL;
temp->rlink=NULL;
printf("enter the ssn\n");
fflush(stdin);
gets(temp->ssn);
printf("enter the name\n");
fflush(stdin);
gets(temp->name);
printf("enter the department\n");
fflush(stdin);
gets(temp->dept);
printf("enter the designation\n");
fflush(stdin);
gets(temp->desg);
printf("enter the phone number\n");
fflush(stdin);
gets(temp->phno);
printf("Enter the salary\n");
scanf("%d",&temp->sal);
}
void createdll()
{
int n,i;
printf("Enter the number of employees\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("enter the details of employee %d\n",i);
read();
if(first==NULL)
{
first=temp;
end=temp;
}
else
{
end->rlink=temp;
temp->llink=end;
end=temp;
}
}
}
void displaycount()
{
int count=0;
nodepointer temp1=first;
if(temp1==NULL)
printf("DLL is empty and count is %d\n",count);
else
{
printf("\n_____________________________________________________________________________\n");
printf("\nssn\tname\t\tdept\tdesg\tphno\t\tsal\n");
printf("\n_____________________________________________________________________________\n");
while(temp1!=NULL)
{
printf("%s\t%s\t%s\t%s\t%s\t%d\n",temp1->ssn,temp1->
name,temp1->dept,temp1->desg,temp1->phno,temp1->sal);
count++;
temp1=temp1->rlink;
}
printf("\n_____________________________________________________________________________\n");
printf("employee count is %d\n",count);
}
}
void insertend()
{
temp=getnode();
printf("Enter the details of new employee\n");
read();
if(first==NULL)
{
first=temp;
end=temp;
}
else
{
end->rlink=temp;
temp->llink=end;
end=temp;
}
}
void deleteend()
{
nodepointer temp1=end;
if(temp1==NULL)
{
printf("DLL is empty\n");
}
else if(first==end)
{
printf("The deleted element is with ssn %s\n",temp1->ssn);
first=NULL;
end=NULL;
free(temp1);
}
else
{
printf("The deleted element is with ssn %s\n",temp1->ssn);
end=end->llink;
end->rlink=NULL;
free(temp1);
}
}
void insertfront()
{
printf("Enter the details of employee\n");
read();
if(first==NULL)
{
first=temp;
end=temp;
}
else
{
temp->rlink=first;
first->llink=temp;
first=temp;
}
}
void deletefront()
{
nodepointer temp1=first;
if(first==NULL)
printf("DLL is empty\n");
else if(first==end)
{
printf("The deleted element is with ssn %s\n",temp1->ssn);
first=NULL;
end=NULL;
free(temp1);
}
else
{
printf("The deleted element is with the ssn %s\n",temp1->ssn);
first=first->rlink;
first->llink=NULL;
free(temp1);
}
}
void main()
{
int ch;
while(1)
{
printf("Double linked list\n");
printf("MENU\n1.create\t2.display and count\t3.insert end\t4.delete end\t5.insert front\t6.delete front\t7.exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: createdll();
break;
case 2: displaycount();
break;
case 3: insertend();
break;
case 4: deleteend();
break;
case 5: insertfront();
break;
case 6: deletefront();
break;
case 7: exit(0);
default:printf("Enter the valid choice\n");
}
}
}


