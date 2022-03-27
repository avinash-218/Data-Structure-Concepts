#include"array_QueueHdr.h"

//Bank class member functions
Bank::Bank()	//default constructor
{
	acc_no=0;
	name="";
	type="";
	ifsc="";
	balance=0.0;
}

Bank::Bank(long acc,string n,string t,string i,double bal)	//parameterised constructor
{
	acc_no=acc;
	name=n;
	type=t;
	ifsc=i;
	balance=bal;
}

Bank::Bank(const Bank& temp)		//copy constructor
{
	acc_no=temp.acc_no;
	name=temp.name;
	type=temp.type;
	ifsc=temp.ifsc;
	balance=temp.balance;
}

Bank::~Bank()	//destructor
{
 	acc_no=0;
	name="";
	type="";
	ifsc="";
	balance=0.0;	
}

long Bank::getAccNum()	//getter to get account number
{
	return acc_no;
}

void Bank::display()	//to display the account details
{
	cout<<"Account Number : "<<acc_no;
	cout<<"\nHolder Name : "<<name;
	cout<<"\nIFSC Code : "<<ifsc;
	cout<<"\nType : "<<type;
	cout<<"\nBalance : "<<balance;
	cout<<"\n";
}

//Queue methods
Queue::Queue()	//default constructor
{
	front=-1;
	rear=-1;
	capacity=10;
	Bank temp;
	arr=new Bank[capacity];
	for(int i=0;i<capacity;i++)
		arr[i]=temp;
}

Queue::Queue(int f,int r,int cap,Bank *cpy)		//parameterised constructor
{
	front=f;
	rear=r;
	capacity=cap;
	arr=new Bank[capacity];
	for(int i=0;i<=r;i++)
		arr[i]=cpy[i];
	Bank temp;
	for(int i=r+1;i<capacity;i++)
		arr[i]=temp;
}

Queue::Queue(const Queue &cpy)		//copy constructor
{
	front=cpy.front;
	rear=cpy.rear;
	capacity=cpy.capacity;
	for(int i=front;i<rear;i++)
		arr[i]=cpy.arr[i];
	Bank temp;
	for(int i=rear;i<capacity;i++)
		arr[i]=temp;
}

Queue::~Queue()		//destructor
{
	rear=-1;
	front=-1;
	capacity=10;
	delete []arr;
	arr=NULL;
}

int Queue::isEmpty()	//to check if the queue is empty
{
	if( (front==-1 && rear==-1) || (front>rear) )
		return 1;	//queue is empty
	else
		return 0;	//queue is not empty
}

int Queue::isFull()		//to check if the queue is full
{
	return (rear+1==capacity);
}

int Queue::enqueue(Bank ele)	//to enqueue an account details
{
	//ele-bank account details to enqueue
	if(!isFull())
	{
		if(rear==-1 && front ==-1)
		{
			arr[0]=ele;
			front=0;
			rear=0;
		}
		else
			arr[++rear]=ele;
		return 1;		//queue is empty
	}
	else
		return -1;		//queue is full
}

Bank Queue::dequeue()		//to dequeue an account details
{
	Bank temp,temp1;
	if(!isEmpty())
	{
		if(front==0 && rear==0)
		{
			rear=-1;
			front=-1;
		}
		else
		{
			temp=arr[front++];
		}
		return temp;	//successfully dequeued
	}
	else
		return temp1;	//queue is empty
}

Bank Queue::lastElement()	//to return the last element in the queue
{
	if(!isEmpty())
		return arr[rear];
	else
	{
		Bank temp;
		return temp;	
	}
}

void Queue::makeQueueEmpty()	//to empty the queue
{
	while(!isEmpty())
		dequeue();
}

Bank Queue::peek()		//to peek the first element of the queue
{
	if(!isEmpty())
		return arr[front];
	else
	{
		Bank temp;
		return temp;
	}
}