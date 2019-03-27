#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int *date;
	int Front, Rear;
	int MaxSize;
}QNode;

QNode *CreatQueue( int MaxSize );
int IsFull( QNode *Q );
int AddQ( QNode *Q, int X );
int IsEmpty( QNode *Q );
int DeleteQ( QNode *Q );
void Print( QNode *Q );
int main(int argc, char *argv[]) {
	QNode *Q;
	int MaxSize;
	char ch;
	int X;
	printf("Please input the MaxSize:\n");
	scanf("%d",&MaxSize);
	Q = CreatQueue(MaxSize);
	while(1){
		printf("Please input the date:");
		scanf("%d",&X);
		if(AddQ(Q,X)){
			printf("Add sucessfully!\n");
		}
		else{
			printf("Error!\n");
		}
		printf("Continue??  Y or N\n");
		scanf(" %c",&ch);
		if(ch!='Y'){
			break;
		}
	}
	printf("After adding:\n");
	Print(Q);
	while(1){
		
		if(DeleteQ(Q)){
			printf("Delete sucessfully!\n");
		}
		else{
			printf("Error!\n");
		}
		printf("Continue??  Y or N\n");
		scanf(" %c",&ch);
		if(ch!='Y'){
			break;
		}
	}
	printf("After deleting:\n");
	Print(Q);
	return 0;
}
QNode *CreatQueue( int MaxSize )
{
	QNode *Q = (QNode*)malloc(sizeof(QNode));
	Q->date = (int*)malloc(sizeof(int)*MaxSize);
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
}
int IsFull( QNode *Q )
{
	return ((Q->Rear+1)%Q->MaxSize == Q->Front);
}
int AddQ( QNode *Q, int X )
{
	if( IsFull(Q) ){
		printf("The queue is full!\n");
		return 0;
	}
	else{
		Q->Rear = (Q->Rear+1)%Q->MaxSize;
		Q->date[Q->Rear] = X;
		return 1;
	}
}
int IsEmpty( QNode *Q )
{
	return (Q->Front == Q->Rear);
}
int DeleteQ( QNode *Q )
{
	if( IsEmpty(Q) ){
		printf("The queue is empty!\n");
		return 0;
	}
	else{
		Q->Front = (Q->Front+1)%Q->MaxSize;
		return Q->date[Q->Front];
	}
	
}
void Print( QNode *Q )
{
	int i=1;
	printf("The queue is follwing!\n");
	int Front = Q->Front;
	while(Front!=Q->Rear){
		printf("The %d date is %d.\n",i,Q->date[(Front+1)%Q->MaxSize]);
		i++;
		Front = (Front+1)%Q->MaxSize;
	}
}
