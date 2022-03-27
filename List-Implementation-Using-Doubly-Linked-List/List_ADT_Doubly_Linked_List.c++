#include<iostream>
using namespace std;

//classes
class Node	//node class
{
	public:
			Node();	//default constructor
			Node(const Node&);	//copy constructor
			void getData();

	private:
			int data;
			Node *prev,*next;
	friend class DLL;
};

class DLL	//Doubly Linked List class
{
	public:
			DLL();	//default constructor
			int isEmpty();	//to check if the list is empty
			void insertAtFirst(Node*);	//insert a node in the first of the list
			void insertAtLast(Node *);	//insert a node in the last of the list
			void insertByPos(int,Node *);	//to insert node in a position
			int findPosition(int);			//to find the position of an element
			void displayList();	//to display the elements of the list
			void deleteAtFirst();	//to delete element at first
			void deleteAtLast();	//to delete element at last
			void deleteByPos(int);	//to delete element at position
			void makeListEmpty();	//to empty the list
	private:
			Node *first;
};

// methods of class Node
Node::Node()	//default constructor
{
	data=0;
	next=NULL;
	prev=NULL;
}

Node::Node(const Node &temp)	//copy constructor
{
	data=temp.data;
	prev=temp.prev;
	next=temp.next;
}

void Node::getData()	//to get the data part of a node
{
	cout<<"Enter a number\n";
	cin>>data;
}

//methods of class Doubly Linked List (DLL)
DLL::DLL()	//default constructor
{
	first=NULL;
}

int DLL::isEmpty()	//to check if the list is empty
{
	return (first==NULL);
}

void DLL::insertAtFirst(Node *newNode)	//to insert a node at the beginning of the list
{
	if(isEmpty())
		first=newNode;
	else
	{
		newNode->next=first;
		first->prev=newNode;
		first=newNode;
	}
	cout<<"Element is inserted\n";
}

void DLL::insertAtLast(Node *newNode)	//to insert a node at last of the list
{
	if(isEmpty())
		first=newNode;
	else
	{
		Node *temp=first;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newNode;
		newNode->prev=temp;
	}
	cout<<"Element is inserted\n";
}

void DLL::insertByPos(int pos,Node *newNode)	//to insert a node at a position
{
	if(!isEmpty())
	{
		if(pos==1)
			insertAtFirst(newNode);
		else if(!isEmpty() && pos>1)
		{
			Node *temp=first;
			int flag=1;
			while(temp->next!=NULL && flag<pos-1)
			{
				temp=temp->next;
				flag++;
			}
			if(temp->next==NULL && flag==pos-1)
				insertAtLast(newNode);
			else if(flag==pos-1)
			{
				newNode->prev=temp;
				newNode->next=temp->next;
				temp->next=newNode;
				newNode->next->prev=newNode;
				cout<<"Element inserted\n";
			}
			else
				cout<<"Element can't be inserted\n";
		}
		else
			cout<<"Element can't be inserted\n";
	}
	else
		cout<<"Element can't be inserted\n";
}

int DLL::findPosition(int ele)	//to find position of an element
{
	Node *temp=first;
	int flag=1;
	while(temp!=NULL)
	{
		if(temp->data==ele)
			return flag;
		else
			temp=temp->next;
			flag++;
	}
	return -1;	//no element found
}

void DLL::deleteAtFirst()	//to delete the element at first
{
	if(!isEmpty())
	{
		Node *temp=first;
		first=first->next;
		delete temp;
		temp=NULL;
	}
	else
		cout<<"List is empty\n";
}

void DLL::deleteAtLast()	//to delete element at last
{
	if(!isEmpty())
	{
		Node *temp=first;
		while(temp->next!=NULL)
			temp=temp->next;
		if(temp->prev==NULL)
			deleteAtFirst();
		else
			temp->prev->next=NULL;
			delete temp;
			temp=NULL;
	}
	else
		cout<<"List is Empty\n";
}

void DLL::deleteByPos(int pos)	//to delete element at position
{
	if(!isEmpty())
	{
		if(pos==1)
		{
			deleteAtFirst();
			cout<<"Deletion Successful\n";
		}
		else
		{
			Node *temp=first;
			int flag=1;
			while(temp->next!=NULL && flag<pos)
			{
				temp=temp->next;
				flag++;
			}
			if(temp->next==NULL && pos==flag)
			{
				deleteAtLast();
				cout<<"Deletion Successful\n";
			}
			else if(pos==flag)
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				delete temp;
				temp=NULL;
				cout<<"Deletion Successful\n";
			}
			else
				cout<<"Invalid Position\n";
		}
	}
	else
		cout<<"List is Empty\n";
}


void DLL::displayList()		//to display the data part of every nodes of the list
{
	if(isEmpty())
		cout<<"List is Empty\n";
	else
	{
		cout<<"Elements Of the list are:\n";
		Node *temp=first;
		while(temp!=NULL)		
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
	}
}

void DLL::makeListEmpty()	//to empty the list
{
	Node *temp=first;
	while(temp!=NULL)
	{
		deleteAtFirst();
		temp=temp->next;
	}
	cout<<"List is Empty\n";
}


//application

int main()
{
	DLL list;
	int ch=0;
	while(ch!=-1)
	{
		cout<<"\nChoose an option:\n";
		cout<<"1-to check if list is empty\n";
		cout<<"2-to insert element at first\n";
		cout<<"3-to insert element at last\n";
		cout<<"4-to insert element at a position\n";
		cout<<"5-to insert an element after an element in the list\n";
		cout<<"6-to insert an element before an element in the list\n";
		cout<<"7-to delete element at first\n";
		cout<<"8-to delete element at last\n";
		cout<<"9-to delete element at a position\n";
		cout<<"10-to delete the element after an element in the list\n";
		cout<<"11-to delete the element before an element in the list\n";
		cout<<"12-to find position of an element\n";
		cout<<"13-to display the list\n";
		cout<<"14-to delete all elements of the list\n";
		cout<<"-1 - to exit\n\n";
		cin>>ch;

		if(ch==1)
		{
			if(list.isEmpty())
				cout<<"List is Empty\n";
			else
				cout<<"not empty\n";
		}
		else if(ch==2)
		{
			Node *newNode=new Node();
			newNode->getData();
			list.insertAtFirst(newNode);
		}
		else if(ch==3)
		{
			Node *newNode=new Node();
			newNode->getData();
			list.insertAtLast(newNode);
		}
		else if(ch==4)
		{
			Node *newNode=new Node();
			newNode->getData();
			int pos;
			cout<<"enter the position\n";
			cin>>pos;
			list.insertByPos(pos,newNode);
		}
		else if(ch==5)
		{
			Node *newNode=new Node();
			newNode->getData();
			int ele;
			cout<<"enter the element after which to enter the given number\n";
			cin>>ele;
			list.insertByPos(list.findPosition(ele)+1,newNode);
		}
		else if(ch==6)
		{
			Node *newNode=new Node();
			newNode->getData();
			int ele;
			cout<<"enter the element before which to enter the given number\n";
			cin>>ele;
			list.insertByPos(list.findPosition(ele),newNode);
		}
		else if(ch==7)
			list.deleteAtFirst();
		else if(ch==8)
			list.deleteAtLast();
		else if(ch==9)
		{
			int pos;
			cout<<"enter the position\n";
			cin>>pos;
			list.deleteByPos(pos);
		}
		else if(ch==10)
		{
			int ele;
			cout<<"enter the element\n";
			cin>>ele;
			list.deleteByPos(list.findPosition(ele)+1);
		}
		else if(ch==11)
		{
			int ele;
			cout<<"enter the element\n";
			cin>>ele;
			list.deleteByPos(list.findPosition(ele)-1);
		}
		else if(ch==12)
		{
			int ele,pos;
			cout<<"enter the element\n";
			cin>>ele;
			pos=list.findPosition(ele);
			if(pos==-1)
				cout<<"Element does not exist in the list\n";
			else
				cout<<"Position of "<<ele<<" is at "<<pos;
		}
		else if(ch==13)
			list.displayList();
		else if(ch==14)
			list.makeListEmpty();
	}
}
