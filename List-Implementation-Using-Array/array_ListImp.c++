#include"array_ListHdr.h"

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
}


//List_ADT methods
List_ADT::List_ADT()	//default constructor
{
	size=0;
	cap=10;		//default capacity is set as 10
	arr=new Bank[cap];
}

List_ADT::List_ADT(Bank *a,int s,int c)	//parameterised constructor	
{
	size=s;
	cap=c;
	arr=new Bank[cap];
	for(int i=0;i<size;i++)	//copying given element
		arr[i]=a[i];
}

List_ADT::List_ADT(const List_ADT &cpy)	//copy constructor
{
	size=cpy.size;
	cap=cpy.cap;
	arr=new Bank[cap];
	for(int i=0;i<size;i++)		//copying given elements
		arr[i]=cpy.arr[i];
}

List_ADT::~List_ADT()	//destructor
{
	size=0;
	cap=10;
	delete []arr;
	arr=NULL;
}

int List_ADT::isFull()	//to check if the list is full
{
	return cap==size;
}

int List_ADT::isEmpty()	//to check if the list is empty
{
	return size==0;
}

int List_ADT::insertAtLast(Bank ele)	//to insert an account to the last of the list
{
	//ele-object of Bank class
	//return - success or failure
	if(!isFull())	//if the list is not full
	{
		arr[size++]=ele;
		return 1;	//success
	}
	else
		return -1;	//failure(list full)
}

int List_ADT::insertAtFirst(Bank ele)	//to insert an account to the first of the list
{
	//ele-object of Bank class
	//return - success or failure
	if(!isFull())	//if list is not full
	{
		for(int i=size;i>0;i--)
			arr[i]=arr[i-1];
		size++;
		arr[0]=ele;
		return 1;	//success
	}
	else
		return -1;	//list is full
}

int List_ADT::posOfElement(long ele)	//to find the position of an account in the list
{
	//ele-account number to find the position in the list
	//return - success or failure
	int i;
	for(i=0;i<size+1;i++)
		if(arr[i].acc_no==ele)
			return i;	
	return -1;	//account is not present
}

int List_ADT::insertByPos(int pos,Bank ele)	//to insert an account in the given position (by necessary shifting)
{
	//ele-object of Bank class
	//pos-position to insert ele
	//return - success or failure
	if (!isFull() && pos>0 && pos<=size+1)	//if the list is not full
	{
		if(pos==1)	//to insert at first
			insertAtFirst(ele);
		else if(pos==size+1)	//to insert at last
			insertAtLast(ele);
		else 	//to insert in-between
		{
			int flag=size;
			while(flag>pos-1)
			{
				arr[flag]=arr[flag-1];
				flag--;
			}
			arr[pos-1]=ele;
			size++;
			return 1;	//success
		}
	}
	else
		return -1;	//list is full or invalid position
}

int List_ADT::insertAfterElement(Bank ele,long sch)	//to insert an account after an account in the list
{
	//ele-object of Bank class
	//sch-bank account number after which to insert ele
	//return - success or failure
	if(!isEmpty())
	{
		int pos=posOfElement(sch);
		return insertByPos(pos+2,ele);
	}
	else
		return -1;	//list is empty
}

int List_ADT::insertBeforeElement(Bank ele,long sch)	//to insert an account before an account in the list
{
	//ele-object of Bank class
	//sch-bank account number before which to insert ele
	//return - success or failure
	if(!isEmpty())
	{
		int pos=posOfElement(sch);
		insertByPos(pos+1,ele);
	}
	else
		return -1;	//list is empty
}


int List_ADT::displayList()	//to display accounts' details of list
{
	if(isEmpty())	//if list is empty
		return -1;
	else
	{
		cout<<"Accounts in the list:\n\n";
		for(int i=0;i<size;i++)
		{
			arr[i].display();
			cout<<"\n\n\n";
		}
	}
	cout<<"\n";
	return 1;	//list is displayed
}

int List_ADT::deleteAtFirst()	//to delete the account at first
{
	if(!isEmpty())	//if list is empty
	{
		for(int i=0;i<size-1;i++)
			arr[i]=arr[i+1];
		arr[size--].~Bank();		//calling destructor to set default values
		return 1;	//success
	}
	else
		return 0;	//failure
}

int List_ADT::deleteAtLast()	//to delete the account at last
{
	if(!isEmpty())	//if list is empty
	{
		arr[size--].~Bank();		//calling destructor to set default values
		return 1;;	//success
	}
	else
		return 1;	//list is empty
}

int List_ADT::deleteByPos(int pos)	//to delete the account at a position
{
	//pos-position of the account to remove
	if(!isEmpty() && pos>0 && pos<=size)	//if list is not empty
	{
		if(pos==1)
			deleteAtFirst();
		else if (pos==size)
				deleteAtLast();
		else
		{
			for(int i=pos-1;i<size;i++)
				arr[i]=arr[i+1];
			arr[size--].~Bank();		//calling destructor to set default values
		}
		return 1;	//success
	}
	else
		return -1;	//list is empty or invalid position
}

int List_ADT::deleteAfterElement(long ele)	//to delete the account after an account
{
	//ele-bank account number after which to delete an account
	int pos=posOfElement(ele);
	return deleteByPos(pos+2);
}

int List_ADT::deleteBeforeElement(long ele)	//to delete the account before an account
{
	//ele-bank account number before which to delete an account
	int pos=posOfElement(ele);
	return deleteByPos(pos);
}

void List_ADT::makeListEmpty()	//to empty the list
{
	while(size!=0)
		deleteAtFirst();
}

Bank List_ADT::elementAtPosition(int pos)	//to find the account at the position
{
	//pos-position at which to find the account
	if(pos>0 && pos<=size)
		return arr[pos-1];
	else
	{
		Bank temp;
		return temp;
	}
	cout<<"\n";
}
