#include"singly_ListHdr.h"

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

Node::Node(long acc,string name,string type,string ifsc,double balance)	//parameterised constructor
{
	data = new Bank(acc,name,type,ifsc,balance);
	next=NULL;
}

//SLL_ADT class member functions
SLL_ADT::SLL_ADT()	//default constructor
{
	first=NULL;
}

int SLL_ADT::isEmpty()		//to check if the list is empty
{
	if(first==NULL)
		return 1;
	else
		return 0;
}

void SLL_ADT::insertAtFirst(Node *newNode)	//insert an account at first
{
	//newNode - node to insert
	if(isEmpty())
		first=newNode;
	else
	{
		newNode->next=first;
		first=newNode;
	}
}

void SLL_ADT::insertAtLast(Node *newNode)	//insert an account at last
{
	//newNode - node to insert
	if(!isEmpty())
	{
		Node *temp=first;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newNode;
	}
	else
		insertAtFirst(newNode);
}

int SLL_ADT::insertByPos(int pos,Node *newNode)	//insert an account at a position
{
	//newNode - node to insert
	//pos-position where to insert newNode
	if(!isEmpty())
	{
		int i=1;
		Node *temp=first;
		while(temp->next!=NULL && i!=pos-1)
		{
			temp=temp->next;
			i++;
		}
		if(i==pos-1)
		{
			newNode->next=temp->next;
			temp->next=newNode;
			return 1; //success
		}
		else if(pos==1)
		{
			insertAtFirst(newNode);
			return 1;	//success
		}
		else
			return -1;	//failure
	}
	else
	{
		if(pos==1)
		{
			first=newNode;
			return 1;	//success
		}
		else
			return -1;	//failure
	}
}

int SLL_ADT::posOfElement(long ele)	//to find the position of an account in the list
{
	//ele-element whose position in the list to be found
	Node *temp=first;
	int i=1;
	while(temp->next!=NULL && temp->data->acc_no!=ele)
	{
		temp=temp->next;
		i++;
	}
	if(temp->data->acc_no==ele)
		return i;	//position of element in the list
	else
		return -1;	//element is not present
}

int SLL_ADT::insertAfterElement(Node *newNode,long sch)	//to insert an account after an account in the list
{
	//newNode-node to insert
	//sch-bank account number to search
	int pos=posOfElement(sch);
	if(!isEmpty() && pos!=-1)
	{
		return insertByPos(pos+1,newNode);
	}
	else
		return -1;	//list is empty
}

int SLL_ADT::insertBeforeElement(Node *newNode,long sch)	//to insert an account before an account in the list
{
	//newNode-node to insert
	//sch-bank account number to search
	int pos=posOfElement(sch);
	if(!isEmpty() && pos!=-1)
	{
		return insertByPos(pos,newNode);
	}
	else
		return -1;	//list is empty
}

int SLL_ADT::deleteAtFirst()	//to delete account in the beginning of the list
{
	if(!isEmpty())
	{
		Node *temp=first;
		first=temp->next;
		delete temp;
		temp=NULL;
		return 1;	//Success
	}
	else
		return -1;	//empty list

}

int SLL_ADT::deleteAtLast()		//to delete account in the end of the list
{
	if(!isEmpty())
	{
		Node *temp=first;
		int flag=1;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			flag++;
		}
		return deleteByPos(flag);
	}
	else
		return -1;	//empty list
}

int SLL_ADT::deleteByPos(int pos)	//delete the account at a position
{
	//pos-position of an account
	if(!isEmpty())
	{
		if(pos==1)
			return deleteAtFirst();
		else
		{
			int i=1;
			Node *temp=first;
			Node *prev=first;
			while(temp->next!=NULL && i<=pos-1)
			{
				prev=temp;
				temp=temp->next;
				i++;
			}
			if(i==pos)
			{
				prev->next=temp->next;
				delete temp;
				temp=NULL;
				return 1;	//deleted
			}
			else
				return -1;	//invalid position
		}
	}
	else
		return -1;	//failure
}

int SLL_ADT::deleteAfterElement(long ele)	//to delete the element after an element
{
	//ele-bank account number
	int pos=posOfElement(ele);
	return deleteByPos(pos+1);
}

int SLL_ADT::deleteBeforeElement(long ele) //to delete the element after an element
{
	//ele-bank account number
	int pos=posOfElement(ele);
	return deleteByPos(pos-1);
}

void SLL_ADT::makeListEmpty()	//to empty the list
{
	while(!isEmpty())
		deleteAtFirst();
}

int SLL_ADT::displayList()	//to display all the elements of the lsit
{
	if(!isEmpty())
	{
		cout<<"Elements in the list are:\n";
		Node *temp=first;
		while(temp!=NULL)
		{
			temp->data->display();
			cout<<"\n";
			temp=temp->next;
		}
	}
	else
		return -1;	//list is empty
	return 1;	//list is displayed
}

Bank* SLL_ADT::elementAtPosition(int pos)	//to find element at the position
{
	//pos-position
	Node *temp=first;
	int i=1;
	while(temp!=NULL && i<pos)
	{
		temp=temp->next;
		i++;
	}
	if(temp==NULL)
		{
			Bank* ret=new Bank();
			return ret;
		}
	else if(i==pos)
		return temp->data;
}
