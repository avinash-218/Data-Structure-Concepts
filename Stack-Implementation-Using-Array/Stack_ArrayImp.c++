#include"Stack_ArrayHdr.h"

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

//Stack methods
Stack::Stack()	//default constructor
{
	top=-1;
	capacity=10;
	arr=new Bank[capacity];
	Bank temp;
	for(int i=0;i<capacity;i++)
		arr[i]=temp;
}

Stack::Stack(int size,int cap,Bank *array)	//parameterised constructor
{
	capacity=cap;
	arr=new Bank[cap];
	top=size-1;
	for(int i=0;i<size;i++)
		arr[i]=array[i];
	Bank temp;
	for(int i=size;i<capacity;i++)
		arr[i]=temp;
}

Stack::Stack(const Stack &cpy)		//copy constructor
{
	capacity=cpy.capacity;
	top=cpy.top;
	arr=new Bank[capacity];
	for(int i=0;i<=top;i++)
		arr[i]=cpy.arr[i];
	Bank temp;
	for(int i=top+1;i<capacity;i++)
		arr[i]=temp;
}

Stack::~Stack()		//destructor
{
	top=-1;
	capacity=0;
	delete []arr;
	arr=NULL;
}

int Stack::isFull()		//to check if the stack is full
{
	return top+1==capacity;
}

int Stack::isEmpty()		//to check if the stack is empty
{
	return top==-1;	
}


int Stack::push(Bank ele)		//to push an element to the stack
{
	//ele-bank account details to push to the stack
	if(isFull())
		return -1;		//can't push element because stack is full
	else
	{
		arr[++top]=ele;
		return 1;		//element pushed to the stack
	}
}

Bank Stack::pop()		//to pop an element from the stack
{
	if(isEmpty())
	{
		Bank temp;
		return temp ;	//stack is empty
	}
	else
	{
		Bank temp=arr[top];
		Bank temp1;
		arr[top--]=temp1;
		return temp;	//popped
	}
}

Bank Stack::peek()	//to peek an element from the stack
{
	Bank temp;
	if(isEmpty())
		return temp;
	else
		return arr[top];
}

void Stack::makeStackEmpty()		//to empty the stack
{
	while(!isEmpty())
		pop();
}
