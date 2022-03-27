#include"BSTHdr.h"

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
	cout<<"\n\n";
}

//node class member functions
Node::Node()	//default constructor
{
	data = new Bank();
	right=NULL;
	left=NULL;
}

Node::Node(long acc_no,string name,string ifsc,string type,double balance)	//parameterised constructor
{
	data = new Bank(acc_no,name,type,ifsc,balance);
	right=NULL;
	left=NULL;
}

void Node::displayData()	//to display the account details in the node
{
	data->display();
}

//BST class member functions

BST::BST()	//default constructor
{
	root=NULL;
}

bool BST::isEmpty()	//to find if BST is empty
{
	return root==NULL;
}

Node* BST::getRoot()	//getter to root address
{
	return root;
}

bool BST::insert(Node* temp,Node* new_node)	//to insert a node into the BST
{
	//temp-root of BST (initially root is passed as argument)
	//new_node-node to insert
	if(isEmpty())
	{
		root=new_node;
		return true;
	}
	else
	{
		if(new_node->data->acc_no > temp->data->acc_no)
		{
			if(temp->right==NULL)
				temp->right=new_node;
			else
				insert(temp->right,new_node);
			return true;
		}
		else if(new_node->data->acc_no < temp->data->acc_no)
		{
			if(temp->left==NULL)
					temp->left=new_node;
				else
					insert(temp->left,new_node);
			return true;
		}
		else
			return false;
	}
}

Node* BST::search(Node *temp,long sch)	//to search for an account
{
	//sch-account number to search
	//temp-temp is root node
	if(temp==NULL || temp->data->acc_no==sch)
		return temp;
	else if(temp->data->acc_no<sch)
		search(temp->right,sch);
	else if(temp->data->acc_no>sch)
		search(temp->left,sch);
}

Bank* BST::findMin(Node* temp)	//to find the minimum node in the tree
{
	//temp-root node
		if(temp->left!=NULL)
			findMin(temp->left);
		else
			return temp->data;
}

Bank* BST::findMax(Node* temp)	//to find the maximum node in the tree
{
	//temp-root node
		if(temp->right!=NULL)
			findMax(temp->right);
		else
			return temp->data;
}

int BST::preorder(Node* temp)	//to perform preorder traversal
{
	//temp-root
	if(temp!=NULL)
	{
		temp->data->display();
		preorder(temp->left);
		preorder(temp->right);
		return 1;
	}
	return -1;
}

int BST::inorder(Node* temp)	//to perform inorder traversal
{
	//temp-root
	if(temp!=NULL)
	{
		inorder(temp->left);
		temp->data->display();
		inorder(temp->right);
		return 1;
	}
	return -1;
}

int BST::postorder(Node* temp)	//to perform postorder traversal
{
	//temp-root
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		temp->data->display();
		return 1;
	}
	return -1;
}

Bank* BST::deleteNode(long sch)	//to 	delete a node
{
	//sch-account number of the bank account to delete
	Node *temp=root;
	Node*parent=root;
	while(temp!=NULL)
	{	
		if(temp->data->acc_no==sch)	//element is found
		{	
			Bank *removed=temp->data;
			if(temp->left==NULL && temp->right==NULL)	//no child
			{
				if(temp==root)	//node to delete is root
				{
					delete temp;
					temp=NULL;
					root=NULL;
					return removed;
				}
				else			//node to delete is leaf
				{
					if(parent->left==temp)	//node to delete is left child
						parent->left=NULL;
					else					//node to delete is right child
						parent->right=NULL;
					delete temp;
					temp=NULL;
					return removed;
				}
			}
			else if(temp->left!=NULL && temp->right==NULL)	//only left child
			{
				if(temp==root)	//node to delete is root
				{
					root=temp->left;
					delete temp;
					temp=NULL;
					return removed;
				}
				else	//node to delete is not root (and non-leaf)
				{
					if(parent->right==temp)		//node to delete is right child
						parent->right=temp->left;
					else						//node to delete is left child
						parent->left=temp->left;
					delete temp;
					temp=NULL;
					return removed;
				}
			}
			else if(temp->left==NULL && temp->right!=NULL)	//only right child
			{
				if(temp==root)	//node to delete is root
				{
					root=temp->right;
					delete temp;
					temp=NULL;
					return removed;
				}
				else	//node to delete is non-root (and non-leaf)
				{
					if(parent->right==temp)		//node to delete is right child
						parent->right=temp->right;
					else						//node to delete is left child
						parent->left=temp->right;
					delete temp;
					temp=NULL;	
					return removed;
				}
			}
			else if(temp->left!=NULL && temp->right!=NULL)	//both child
			{
				Node *temp1=temp->right;
				if(temp1->left==NULL)
				{
					temp->data=temp1->data;
					temp->right=temp1->right;
					delete temp1;
					temp1=NULL;
				}
				else
				{
					while(temp1->left!=NULL)
					{
						parent=temp1;
						temp1=temp1->left;
					}
					temp->data=temp1->data;
					if(temp1->right!=NULL)	//successor node has a right child
						parent->left=temp1->right;
					else
						parent->left=NULL;	
					delete temp1;
					temp1=NULL;
				}
				return removed;

			}
		}
		else if(temp->data->acc_no>sch)	//element is in left sub-tree
		{
			parent=temp;
			temp=temp->left;
		}
		else	//element is in right sub-tree
		{
			parent=temp;
			temp=temp->right;
		}
	}
	Bank *not_found=new Bank();
	return not_found;	//no account exists
}