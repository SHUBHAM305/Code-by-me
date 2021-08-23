#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 5
struct train
{
int data;
int seat;
int age;
char name[40];
int gender;
struct train *link;
int IDTYPE;
int status;
int PRN;
};
struct train *start=NULL;
int k=0,a,c=1000;
//*****************************************************************
				struct train *createnode()
{
 struct train *n;
 n=(struct train*)malloc(sizeof(struct train));
 printf("\n\nName of the  passager = ");
 getchar();
 gets(n->name);
 printf("ENTER THE AGE OF PASSANGER =");
 scanf("%d",&n->age);
 printf("\nEnter Passanger Gender\n1: MALE 2: FEMALE 3: TRANSGENDER 4: OTHERs\n Enter The Value = ");
 scanf("%d",&n->gender);
  printf("\nENTER THE IDTYPE 1: AADHAR 2: DRIVING LICENCE 3: VOTER ID CARD 4: OTHER GOVERNMENT DOCUMENTS(O.G.T).\nEnter Which is  = ");
 scanf("%d",&n->IDTYPE);
 n->link=NULL;
 return (n);
}
//*****************************************************************
						void sorting()
{
struct train *temp,*pre;
int m;
	temp=start;
	pre=start;
	while(temp!=NULL)
	{
	pre=temp->link;
		    while(pre!=NULL)
		    {
			 if(temp->data>pre->data)
			 {
			 m=temp->data;
			 temp->data=pre->data;
			 pre->data=m;
			 }
		    pre=pre->link;
		    }
	temp=temp->link;
	}
}
//**********************************************************************
									void nochoice(struct train *n)

{
struct train *temp;
int d=0;
sorting();	
			temp=start;
			while(temp!=NULL)
			{
			++d;
			printf("di=%d",d);
				if(d!=temp->data)
				{
				printf("data%d d%d",temp->data,d);
				break;
				}
				else if(d==temp->data && temp->link==NULL)
				{
					d++;
					break;
				}			
			temp=temp->link;
			}
printf(" d%d",d);
n->seat=d;
n->data=d;
n->PRN=c;
	temp=start;
	while(temp->link!=NULL)
	{
	temp=temp->link;
	}
temp->link=n;
}
//***********************************************************************
									void choice(struct train *n)
{
	struct train *temp,*pre;
	int r[max];
	int m=0,h=0,d=0;
	sorting();
		temp=start;
		while(d<max)
		{
		++d;
				//printf("\n**k=%d",k);
				if(d!=temp->data)
				{
				//printf("\n***k=%d",k);
				r[m]=d;
				m++;
				}
		if(temp->link!=NULL)
		{		
		temp=temp->link;
		}
		}
		printf("\nVACANT SEATS NUMBER = ");
		for(h=0;h<m;h++)
		{
		printf(" %d",r[h]);
		}
		printf("\nEnter the seat number which are vacant =  ");
		scanf("%d",&n->seat);
		while(r[h]!=n->seat) 
		{
		h=0;	
			   while(h<=m)
			   {
					if(r[h]==n->seat)
					{
					break;
					}
				h++;
			   }
				if(r[h]!=n->seat)
				{
				 printf("\n\n INVALId SEAT NUMBER OR THIS BOOKED PREVIOUSLY\nRE-ENTER THE SEAT NUMBER = ");
				 scanf("%d",&n->seat);
				}
		}
		temp=start;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=n;
		n->data=n->seat;
		n->PRN=c;
		printf("seat of n%d",n->data);
}
//*********************************************************************************
									void DelCNF()
{
struct train *temp,*g,*pre,*j;
int d,u,i,f;
char s[40];
printf("\n**********************************************\nENTER THE SEAT NUMBER TO CANCEL TICKET = ");
scanf("%d",&d);
printf("\nENTER THE PRN NUMBER TO CANCEL TICKET = ");
scanf("%d",&f);
printf("\nENTER THE NAME OF THE PASSANGER = ");
getchar();
gets(s);   
if(d<=max)
    {
    temp=start;
	while(temp!=NULL)
	{
		u=strcmp(s,temp->name);
		if(d==temp->seat && temp==start && u==0 && f==temp->PRN)
		{
		g=temp;
		start=start->link;
		free(temp);
		--k;

		printf("\n*************************************\nTHANKS FOR COMING BY INDIAN RAILWAY\n********************************");
		break;
		}
		else if(d==temp->seat && temp!=start && u==0 && f==temp->PRN)
		{
			//printf("\n*temp = %d",temp->seat);
		g=temp;
		//printf("\ng = %d",g->seat);
		pre->link=temp->link;
		--k;
		//printf("\n*g = %d",g->seat);
		//printf("\n**g = %d",g->seat);
			if(temp!=NULL)
			{
			//printf("\nk = %d",k);
			if(k<max)
			{
			printf("\n*************************************\nTHANKS FOR COMING BY INDIAN RAILWAY\n********************************");
			}
			if (k>=max)
			{
			temp=start;
			while(temp->seat!=0 && temp!=NULL)
			{
	 		temp=temp->link;
			}
			//printf("\n***g = %d",g->seat);
			
			temp->seat=g->seat;
					//printf("\nnew = %d, pre = %d",temp->seat,g->seat);

			temp->data=g->data;
			//printf("\nnew = %d, pre = %d",ft->data,tt->data);
			temp->status=g->status;
			free(g);
			j=pre->link;
			i=max;
			while(j!=NULL)
			{
			++i;
			j->data=i;
			j=j->link;
			}
			}
			}

			printf("\n*************************************\nTHANKS FOR COMING BY INDIAN RAILWAY\n********************************");
		break;
		}
	pre=temp;
	temp=temp->link;
			if(temp==NULL)
			{
			printf("\n***********************THIS PRN NUMBER AND SEAT OR NAME DOES NOT MATCH\n****************");	
			}
		}
	}
	else if (d>max)
	{
		printf("\n***********************SEAT NUMBER THOES NOT EXIST\n****************");
	}
}
//*********************************************************************************
									void AcceptBooking()
{
struct train *n,*temp;
//inserting the first nodein list.
if(start==NULL)
{
n=createnode();
++k;
++c;
printf("\nChoices of seat on Demnad 1:NO Choice 2:Choice Of Passanger\n Enter Choice = ");
scanf("%d",&a);
	if(a==1)
	{
	n->data=k;
	n->seat=k;
	n->PRN=c;
	start=n;
	}
	else if(a==2)
	{
	    printf("\nMAX SEAT NUMBER IS %d\nEnter the seat number = ",max);
		scanf("%d",&n->seat);
		while(n->seat>max)
		{
		printf("\n\nINVALID INPUT SEAT NUMBER OT GREATER THAN %d.2\nRE-ENTER THE SEAT NUMBER = ",max);
		scanf("%d",&n->seat);
		}
		n->data=n->seat;
		n->PRN=c;
		start=n;
	}
}
else
{

	if(k<max)
	{
	n=createnode();
	
   	printf("\nChoices of seat on Demnad 1:NO Choice 2:Choice Of Passanger\n Enter Choice = ");
	scanf("%d",&a);
		if(a==1)
		{
		++k;
		++c;
		nochoice(n);
		}
		else if(a==2)
		{

		++k;
		++c;	
		choice(n);
		}
	}
	else if(k>=max)
	{
	printf("\n**************\nALL SEATS OF TRAIN ARE BOOKED\n**************\n");
	printf("\nIF YOU WANT TO TAKE WAITING TICKET PRESS 1: TAKE TICKET 2: NO TAKE TICKET\n");
	a=0;
	scanf("%d",&a);
		if(a==2)//for No taking waiting ticket
		{
		printf("\nSORRY FOR INCONVINENCE\nTHANKS FOR COMING\n");
		}
		else if(a==1)//for waiting.
		{
		n=createnode();
		++k;
		++c;
		n->data=k;
		n->seat=0;
		n->PRN=c;
		temp=start;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=n;
		}
    }
}

printf("\n*************************************\nTHANKS FOR COMING BY INDIAN RAILWAY\n********************************");
}
//*****************************************************************************************************

									void DisCnfRev()
{
struct train *n;
if(start==NULL)
{
	printf("\n****************************************************NO BOOKING TAKE PALCE ALL SEATS OF TRAIN IS EMPTY\n*******************************************************");
}
n=start;
while(n!=NULL && n->seat!=0)
{
printf("\n******************************************************************************\nPRN NUMBER OF THIS PASSANGER = %d",n->PRN);
printf("\nNAME OF THE PASSANGER = %s",n->name);
printf("\nAGE OF THE PASSANGER =%d",n->age);
if(n->gender==1)
printf("\nGENDER OF THE PASSANGER = MALE");
if(n->gender==2)
printf("\nGENDER OF THE PASSANGER = FEMALE");
if(n->gender==3)
printf("\nGENDER OF THE PASSANGER = TRANSGENDER");
if(n->gender==4)
printf("\nGENDER OF THE PASSANGER = OTHER");
printf("\nSEAT NUMBER OF THIS PASSANGER = %d",n->seat);
if(n->IDTYPE==1)
printf("\nID GIVEN BY THE PASSANGER = AADHAR");

if(n->IDTYPE==2)
printf("\nID GIVEN BY THE PASSANGER =DRIVING LICENSE");

if(n->IDTYPE==3)
printf("\nID GIVEN BY THE PASSANGER = VOTER ID CARD");

if(n->IDTYPE==4)
printf("\nID GIVEN BY THE PASSANGER = OTHER GOVERNMENT DOCUMENTS.");
printf("\n*******************************************************************************");
n=n->link;
}
}
//*******************************************************************************************************
									void DisWtRev()
{
struct train *n;
if(start==NULL)
{
printf("\n******************************************************\nMAY BE A SEAT IS VACANT OR WHOLE SEATS ARE BOOKED\n***********************************************************************\n");
}
else
{
n=start;
while(n!=NULL)
{
if(n->seat==0)
{
printf("\n*******************************************************************************\nPRN NUMBER OF THIS PASSANGER = %d",n->PRN);
printf("\nNAME OF THE PASSANGER = %s",n->name);
printf("\nAGE OF THE PASSANGER =%d",n->age);
if(n->gender==1)
printf("\nGENDER OF THE PASSANGER = MALE");
if(n->gender==2)
printf("\nGENDER OF THE PASSANGER = FEMALE");
if(n->gender==3)
printf("\nGENDER OF THE PASSANGER = TRANSGENDER");
if(n->gender==4)
printf("\nGENDER OF THE PASSANGER = OTHER");
if(n->IDTYPE==1)
printf("\nID GIVEN BY THE PASSANGER = AADHAR");

if(n->IDTYPE==2)
printf("\nID GIVEN BY THE PASSANGER =DRIVING LICENSE");

if(n->IDTYPE==3)
printf("\nID GIVEN BY THE PASSANGER = VOTER ID CARD");

if(n->IDTYPE==4)
printf("\nID GIVEN BY THE PASSANGER = OTHER GOVERNMENT DOCUMENTS");
printf("\n*******************************************************************************");
}
n=n->link;
}
}
}

//*******************************************************************************************************
									void CancelRev()
{
struct train *temp,*pre;
int d;
int u,f;
char s[40];
printf("IF YOU WANT TO CANCEL TICKET PRESS 1:CANCEL OF WAITING TICKET\n2: CANCEL OF CNF TICKET\n");
scanf("%d",&a);
	if(a==1)
	{
		if(k<=max)
		{
			printf("\nTHER IS NO WAITING TICKET\nMAY BE A SEAT IS EMPTY\n");
		}
		else
		{	
		 printf("\nENTER THE TICKET PRN NUMBER = ");
		 scanf("%d",&f);
		 printf("\nENTER THE NAME OF PASSANGER = ");
		 getchar();
		 gets(s);
		
			temp=start;
			while(temp!=NULL)
			{
			u=strcmp(s,temp->name);
				if(0==temp->seat && u==0 && f==temp->PRN)
				 {
				   pre->link=temp->link;
				   --k;
				   d=temp->data;
					 while(pre!=NULL)
					 {
					 pre=pre->link;
					 pre->data=d;
					 ++d;
					 }
				   free(temp);
				   break;
				 }
			pre=temp;
			temp=temp->link;
				if (temp==NULL)				
				{
				printf("\nEITHER PRN NUMBER IS WRONG OR THE NAME YOU ENTER IS WRONG");
				}
			}
		}
	}
	else if(a==2)
	{
		if(k!=0)
		{
		DelCNF();
		}
		else
		{
		printf("\nTHERE IS NO ANY BOOKING TAKE PALCE")	;
		}
	}
}
//*******************************************************************************************************
									void main()
		{
		int ch;
		clrscr();
		while(1)
		{
		printf("\nENTER THE NUMBER ACCORDING TO FUNCTION PERFORM\n");
		printf("\n1: FOR BOOKING SEATS\n2: FOR CANCEL RESERATION\n3: FOR DISPLAYING CONFIRM SEATS\n4: SHOWING THE WATING LIST\n5: FOR END OPERATION\n ENTER THE VALUE = ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			AcceptBooking();
			break;
		case 2:
			CancelRev();
			break;
		case 3:
			DisCnfRev();
			break;
	     case 4:
			 DisWtRev();
			 break; 
		case 5:
			exit(1);
		default:
			printf("\n*********************\n\nINVALIDINPUT\n\n***********");
		}
		}
		}