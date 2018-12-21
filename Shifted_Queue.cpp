#include<iostream>
#define MAXQUEUE 5
using namespace std;

/* queue implementation */
struct queue
{
	int items[MAXQUEUE];
	int front, rear;
};


/* this function to find if the queue is empty  */
bool empty(queue *ptr)
{
	if (ptr->rear == -1)
		return (true);

	else
		return (false);

}


/* this function to find if the queue is full */
bool full(queue *ptr)
{
	if (ptr->rear == MAXQUEUE - 1)
		return (true);

	else
		return (false);

}


/* this function to insert a value in queue */
void insert(queue *ptr, int x)
{
	(ptr->rear)++;
	ptr->items[ptr->rear] = x;
}


/* this function to remove a value in queue */
void remove(queue *ptr)
{
	int s;
	s = ptr->items[0];

	for (int i = 0; i < ptr->rear; i++)
		ptr->items[i] = ptr->items[i + 1];

	(ptr->rear)--;

}


/* For the size whish full */
int size(queue *ptr)
{
	return (ptr->rear + 1);
}


/* this function to display the queue */
void display(queue *ptr)
{
	cout << "\n";

	for (int i = 0; i <= ptr->rear; i++)
	{
		cout << " [ " << ptr->front << " ]:- " << ptr->items[ptr->front] << endl;
		(ptr->front)++;
	}

	ptr->front = 0;
	cout << "\n";
}


int main()
{
	int x;
	int c;
	queue q;
	q.front = 0;
	q.rear = -1;

	/* This for loop to repeat your functions as you need , And  you can change ite parameter values*/
	for (int i = 0; i < 20; i++)
	{
		/* The function you have */
		cout << "\n [1]:- Insert\n";
		cout << " [2]:- Remove\n";
		cout << " [3]:- Display\n";
		cout << " [4]:- Size\n\n";

		cout << " Choose your function ";
		cin >> c;

		/* insert in queue */
		if (c == 1)
		{
			if (full(&q))
				cout << " The queue is overfull" << endl;

			else
			{
				cout << " Enter the value ";
				cin >> x;
				insert(&q, x);
				display(&q);
			}

		}

		/* remove from the queue */
		else if (c == 2)
		{
			if (empty(&q))
				cout << " The queue is empty" << endl;

			else
			{
				remove(&q);
				display(&q);
			}
		}

		/* Knowing the number of values */
		else if (c == 3)
			display(&q);

		/* Display the queue */
		else if (c == 4)
			cout << " " << size(&q) << endl;

		else
		{
			cout << "\n You should enter only [ 1 , 2  , 3 , 4]";
			break;
		}

	}

	cout << "\n\n";
	system("pause");
	return 0;

}
