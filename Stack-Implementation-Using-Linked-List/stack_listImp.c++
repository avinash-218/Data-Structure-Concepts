#include"stack_listHdr.h"
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

Node::Node(long acc_no,string name,string type,string ifsc,double balance)	//parameterised constructor
{
	data = new Bank(acc_no,name,type,ifsc,balance);
	next=NULL;
}

//Stack class member functions
Stack::Stack()		//default constructor
{
	top=NULL;		
}

int Stack::isEmpty()	//to find if the Stack is empty
{
	return top==NULL;
}

void Stack::push(Node *ele)		//to push an element to the stack
{
	if(isEmpty())
		top=ele;
	else
	{
		ele->next=top;
		top=ele;
	}
}

Bank* Stack::pop()	//to pop the top element in the stack
{
	if(isEmpty())
	{
		Bank *temp=new Bank();
		return temp;
	}
	else
	{
		Bank *ret=top->data;
		Node *temp=top;
		top=top->next;
		delete temp;
		temp=NULL;
		return ret;
	}
}

Bank* Stack::peek()	//to peek the top element in the stack
{
	if(isEmpty())
	{
		Bank *temp=new Bank();
		return temp;
	}
	else
	{
		Bank *ret=top->data;
		return ret;
	}
}

void Stack::makeStackEmpty()	//to empty the stack
{
	while(!isEmpty())
		pop();
}
