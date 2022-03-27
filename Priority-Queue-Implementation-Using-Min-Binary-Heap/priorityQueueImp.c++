#include"priorityQueueHdr.h"

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


void Bank::display()	//to display the account details
{
	cout<<"Account Number : "<<acc_no;
	cout<<"\nHolder Name : "<<name;
	cout<<"\nIFSC Code : "<<ifsc;
	cout<<"\nType : "<<type;
	cout<<"\nBalance : "<<balance;
	cout<<"\n\n";
}

long Bank::getAccno()		//getter for acc_no
{
	return acc_no;
}

//Min BinHeap class member functions
BinHeap::BinHeap()		//default constructor
{
	hsize=0;
	capacity=11;
	arr=new Bank[capacity+1];	//since operations use only from first index and zeroth index cause loss of track of parent childs
}

int BinHeap::isEmpty()	//to check if the heap is empty
{
	return (hsize==0);
}

int BinHeap::isFull()			//to check if heap is full
{
	return capacity==hsize;
}

int BinHeap::enqueue(Bank ins)	//insert an element
{
	//ins - element to insert
	if(isFull())
		return -1;	//heap is full
	else
	{
		int ctnode=++hsize;
		while(ctnode!=1 && arr[ctnode/2].acc_no > ins.acc_no)	//if parent acc_num is greater than acc_num of element to insert
		{
			arr[ctnode]=arr[ctnode/2];
			ctnode/=2;
		}
		arr[ctnode]=ins;
		return 1;	//success
	}
}

Bank BinHeap::dequeue()			//remove an element (delete min)
{
	if(isEmpty())
	{
		Bank temp;
		return temp;
	}
	else
	{
		Bank temp=arr[1];	//first element (starts from 1) to return
		Bank last=arr[hsize--];
		int low_child=2;	//assuming left child as low_child 
		int ctnode=1;
		while(low_child<hsize)
		{
			if(low_child<hsize && arr[low_child].acc_no>arr[low_child+1].acc_no)	//R-Child is min
				low_child++;	//changing low_child to right child since it is min than Left child

			if(last.acc_no<=arr[low_child].acc_no)	//last element replaced is the min element
				break;

			arr[ctnode]=arr[low_child];	//swapping parent with low_child
			ctnode=low_child;	//considering the low_child
			low_child*=2;	//assuming left child as low_child 
		}
		arr[ctnode]=last;
		return temp;
	}
}

Bank BinHeap::findMin()		//find minimum element
{
	if(!isEmpty())
		return arr[1];
	else
	{
		Bank temp;
		return temp;
	}
}

int BinHeap::search(long sch)		//search an element
{
	int i;
	for(i=1;i<=hsize;i++)
		if(arr[i].acc_no==sch)
			return 1;	//account found
	return -1;	//account not found
}

void BinHeap::displayHeap()	//display the heap
{
	if(isEmpty())
		cout<<"List is Empty\n";
	else
	{
		cout<<"Account Details:\n\n";
		int i;
		for(i=1;i<=hsize;i++)
			arr[i].display();		
	}
}
