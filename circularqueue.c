#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front= NULL;
struct node *rear = NULL;
void enqueue()
{
	struct node* new_n;
	int d;
	new_n = (struct node*)malloc(sizeof(struct node));
	printf("enter an element :");
	scanf("%d",&d);
	new_n->data =d;
	new_n->next =NULL;
	if((front == NULL)&&(rear == NULL))
	{
		front =rear =new_n;
	}
	else
	{
		rear->next=new_n;
		rear=new_n;
	 } 
}
void dequeue()
{
	struct node* temp;
	temp=front;
	if((front==NULL)&&(rear==NULL))
	{
		printf("queue is empty");
	}
	else
	{
		printf("deleted node is %d",front->data);
		front=front->next;
		free(temp);
	}
}
void display()
{
	struct node *temp;
	temp=front;
	if((front==NULL)&&(rear==NULL))
	{
		printf("queue is empty");
	}
	else
	{
		temp=front;
		while(temp!=NULL)
		{
			printf("%d",temp->data);
			temp=temp->next;
		}
	}
}
void main()
{
	int ch;
	while (1)
	{
		printf("\nqueue operations are ");
		printf("\n 1.insert");
		printf("\n 2.delete");
		printf("\n 3.display");
		printf("\n 4.exit");
		printf("\n enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enqueue();
			break;
			case 2: dequeue();
			break;
			case 3: display();
			break;
			case 4: exit(0);
			break;
			default: printf("\n invalid choice,try again");
		}
	}
}
