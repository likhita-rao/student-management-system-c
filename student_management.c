#include <stdio.h>
#include <string.h>
struct student
{
char name[50];
int roll;
int marks;
char grade[10];
};


void display(int n,struct student s[])
{
for(int i=0;i<n;i++)
{
printf("%s\t",s[i].name);
printf("%d\t",s[i].roll);
printf("%d\t",s[i].marks);
printf("%s\t",s[i].grade);
printf("\n");
}
}



void addstd(int*n,struct student s[])
{
printf("Enter the name of student to be added\n");
scanf("%s",s[*n].name);
printf("Enter the roll number of student to be added\n");
scanf("%d",&s[*n].roll);
printf("Enter the marks of student to be added\n");
scanf("%d",&s[*n].marks);
printf("Enter the grade of student to be added\n");
scanf("%s",s[*n].grade);
(*n)++;
display(*n,s);
}


void search(int n,struct student s[])
{
int a=0;
char name[50];
printf("Enter the name of the student to be searched");
scanf("%s",name);
for(int i=0;i<n;i++)
{
if(strcmp(name,s[i].name)==0)
{
a=1;
break;
}
else
a=0;
}
if(a==0)
printf("STUDENT NOT FOUND");
else
printf("STUDENT FOUND");
}


void update(int n,struct student s[])
{
char name[50];
printf("Enter the name of the student to be updated");
scanf("%s",name);
for(int i=0;i<n;i++)
{
if(strcmp(name,s[i].name)==0)
{
printf("MARKS\n");
scanf("%d",&s[i].marks);
printf("GRADE\n");
scanf("%s",s[i].grade);
break;
}
}
display(n,s);
}

void delete(int *n,struct student s[])
{
char name[50];
printf("Enter name of the student to be deleted:");
scanf("%s",name);
for(int i=0;i<*n;i++)
{
if(strcmp(name,s[i].name)==0)
{
for(int j=i;j<(*n-1);j++)
{
strcpy(s[j].name,s[j+1].name);
s[j].roll=s[j+1].roll;
s[j].marks=s[j+1].marks;
strcpy(s[j].grade,s[j+1].grade);
}
(*n)--;
break;
}
}

display(*n,s);
}
int main()
{
int n,choice;
printf("Enter number of students:\n");
scanf("%d",&n);
struct student s[100];
for(int i=0;i<n;i++)
{
printf("Enter the name of student no.%d\n",i+1);
scanf("%s",s[i].name);
printf("Enter the roll number of student no.%d\n",i+1);
scanf("%d",&s[i].roll);
printf("Enter the marks of student no.%d\n",i+1);
scanf("%d",&s[i].marks);
printf("Enter the grade of student no.%d\n",i+1);
scanf("%s",s[i].grade);
}
printf("------MENU------");
printf("CHOOSE ONE OPTION");
printf("1.ADD STUDENTS \n 2.DISPLAY STUDENTS \n 3.SEARCH STUDENT \n 4.UPDATE STUDENT \n 5.DELETE STUDENT \n 6.EXIT \n");
do{
printf("ENTER YOUR CHOICE:");
scanf("%d",&choice);
switch(choice)
{
case 1:
addstd(&n,s);
break;
case 2:
display(n,s);
break;
case 3:
search(n,s);
break;
case 4:
update(n,s);
break;
case 5:
delete(&n,s);
break;
}
}
while(choice!=6)
return 0;
}

