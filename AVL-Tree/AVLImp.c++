#include"AVLHdr.h"

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

//node class member functions
Node::Node()	//default constructor
{
	data = new Bank();
	right=NULL;
	left=NULL;
	height=0;
}

Node::Node(long acc_no,string name,string ifsc,string type,double balance)	//parameterised constructor
{
	data = new Bank(acc_no,name,type,ifsc,balance);
	right=NULL;
	left=NULL;
	height=0;
}

void Node::displayData()	//to display the account details in the node
{
	data->display();
}

//AVL class member functions

AVL::AVL()	//default constructor
{
	root=NULL;
}

int AVL:: height(Node* temp)		//to calc height of node
{
	if(temp==NULL)
		return -1;
	return temp->height;
}

int AVL:: BalanceFactor(Node* temp)		//to calc BalanceFactor of node
{
	//temp-node whose height to find
	if(temp==NULL)
		return -1;
	return (height(temp->left) - height(temp->right));

}

int AVL::preorder(Node* temp)	//to perform preorder traversal
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

int AVL::inorder(Node* temp)	//to perform inorder traversal
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

int AVL::postorder(Node* temp)	//to perform postorder traversal
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

Node* AVL::getRoot()	//getter to root address
{
	return root;
}

void AVL::setRoot(Node *set)	//setter to set root node
{
	root =set;
}

Node* AVL::search(Node *temp,long sch)	//to search for an account
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

Node * AVL::LLRotate(Node* k3)	//LL Rotation
{
	//k3 - root node
	Node *k2=k3->left;
	Node *temp=k2->right;
	k2->right=k3;
	k3->left=temp;

	//height update
	k3->height=max(height(k3->left),height(k3->right))+1;
	k2->height=max(height(k2->left),height(k2->right))+1;

	return k2;
}

Node * AVL::RRRotate(Node* k1)	//RR Rotation
{
	//k1- root node
	Node *k2=k1->right;
	Node *temp=k2->left;
	k2->left=k1;
	k1->right=temp;

	k1->height=max(height(k1->left),height(k1->right))+1;
	k2->height=max(height(k2->left),height(k2->right))+1;

	return k2;
}

Node * AVL::LRRotate(Node *k3)	//LR rotation
{
	//k3- root node
	k3->left=RRRotate(k3->left);	//RR rotate
	return  LLRotate(k3);			//LL rotate
}

Node * AVL::RLRotate(Node *k1)	//LR rotation
{
	//k3- root node
	k1->right=LLRotate(k1->right);	//RR rotate
	return  RRRotate(k1);			//LL rotate
}

Node * AVL::insert(Node* temp,Node* newNode)	//insert a node in the tree
{
	//temp-root
	//newNode-node to insert
	if(temp==NULL)
	{
		root=newNode;
		cout<<"Account details inserted\n";
		return root;
	}
	else if(temp->data->acc_no > newNode->data->acc_no)
	{
		if(temp->left==NULL)
			temp->left=newNode;
		else
			temp->left=insert(temp->left,newNode);
	}
	else if(temp->data->acc_no < newNode->data->acc_no)
	{
		if(temp->right==NULL)
			temp->right=newNode;
		else
			temp->right=insert(temp->right,newNode);
	}
	else
		cout<<"Duplicate Account can't be inserted\n";

	temp->height = max(height(temp->left),height(temp->right)) + 1;
	int bal=BalanceFactor(temp);

	if(bal>1)
	{
		if(newNode->data->acc_no < temp->left->data->acc_no)
			return LLRotate(temp);
		else
			return LRRotate(temp);
		cout<<"Account details inserted\n";
	}
	if(bal<-1)
	{
		if(newNode->data->acc_no > temp->right->data->acc_no)
			return RRRotate(temp);
		else
			return RLRotate(temp);
		cout<<"Account details inserted\n";
	}
	return temp;
}