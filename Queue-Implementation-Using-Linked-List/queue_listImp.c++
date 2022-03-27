#include"queue_listHdr.h"

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

//node class member functions
Node::Node()	//default constructor
{
	data = new Bank();
	next=NULL;
}

Node::Node(long acc_no,string name,string ifsc,string type,double balance)	//parameterised constructor
{
	data = new Bank(acc_no,name,type,ifsc,balance);
	next=NULL;
}

//Queue class member functions
Queue::Queue()	//default constructor
{
	first=NULL;	
}

int Queue::isEmpty()	//to check if the queue is empty
{
	return first==NULL;
}

void Queue::enqueue(Node *ele)	//to enqueue an account details
{
	//ele-pointer of the node to enqueue
	if(isEmpty())
		first=ele;
	else
	{
		Node *temp=first;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=ele;
	}
}

Bank* Queue::dequeue()	//to dequeue an account from the queue
{
	if(!isEmpty())
	{
		Bank *ret=first->data;
		Node *temp=first;
		first=first->next;
		delete temp;
		temp=NULL;
		return ret;
	}
	else
	{
		Bank *ret=new Bank();
		return ret;
	}

}

Bank* Queue::peek()	//to peek the top element from the queue
{
	if(!isEmpty())
		return first->data;
	else
	{
		Bank *ret=new Bank();
		return ret;
	}
}

Bank* Queue::lastElement()	//to display the details of the last element from the queue
{
	if(isEmpty())
	{
		Bank *ret=new Bank();
		return ret;
	}
	else
	{
		Node *temp=first;
		while(temp->next!=NULL)
			temp=temp->next;
		return temp->data;
	}
}

void Queue::makeQueueEmpty()	//to make the entire queue empty
{
	while(!isEmpty())
		dequeue();
}
