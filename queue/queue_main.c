#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX];
}QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	
}

void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}



int is_full(QueueType* q)
{
	return((q->rear +1)%MAX==q->front);
}
int is_empty(QueueType* q)
{
	return(q->front == q->rear);

}
void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do {
			i = (i + 1) % (MAX);
			printf("%d ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
	/*for (int i = 0; i < MAX; i++)
	{
		if (i <= q->front || q->data[i])
			printf("|");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
	*/
}
void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		error("큐가 포화상태");
	}
	q->rear = (q->rear + 1) % MAX;
	q->data[(q->rear)] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
	{
		error("큐 공백상태");
	}
	q->front = (q->front + 1) % MAX;
	return q->data[q->front];

}
int main(void)
{
	QueueType q;
	int element;
	init_queue(&q);
	int s = 0;
	while(1)
	{
		printf("\n= = = = Menu = = = =\n");
		printf("1. Input data and Enqueue\n2. Dequeue and Print data\n3. Print Queue\n4. Exit\n");
		printf("Slect number = ");
		scanf_s("%d", &s);
		if (s == 1 && !is_full(&q))
		{
			printf("\nEnqueue: ");
			scanf_s("%d", &element);
			enqueue(&q, element);
			printf("\n");
		}
		else if (s == 2 && !is_empty(&q))
		{
			element = dequeue(&q);
			printf("Dequeue: %d\n", element);
		}
		else if (s == 3)
		{
			queue_print(&q);
		}
		else if (s==1 && is_full(&q))
		{
			printf("Queue is full\n");
		}
		else if (s==2 && is_empty(&q))
		{
			printf("Queue is empty\n");
		}
		else if(s==4){
			printf("Exit the program");
			break;
		}
		else {
			printf("잘못된 입력\n");
			
		}
	}
}