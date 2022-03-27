#include<iostream>
using namespace std;
//class definitions
class Bank	//bank class
{
	public:
			Bank();	//default constructor
			Bank(long,string,string,string,double);	//parameterised constructor
			Bank(const Bank&);		//copy constructor
			~Bank();	//destructor
			void display();	//to display details
	private:
			long acc_no;	//account number
			string name;	//holder name
			string type;	//Savings or current account
			string ifsc;	//IFSC code
			double balance;	//account balance
	friend class AVL;	//declaring Node class and AVL class are friends
};

class Node 		//node class
{
	public:
			Node();	//default constructor
			Node(long,string,string,string,double);	//parameterised constructor
			void displayData();	//to display the data of the node
						
	private:
			Bank *data;	//pointer to Rational object
			Node *left;	//pointer of left node
			Node *right;	//pointer of right node
			int height;		//height of node 
	friend class AVL;	//declaring Node class and AVL class are friends
};

class AVL		//AVL tree class
{
	public:
			AVL();	//default constructor
			int height(Node*);	//getter for height of parameter node
			int BalanceFactor(Node *);	//to calculate BF of parameter node
			int inorder(Node*);		//display by inorder traversal
			int preorder(Node*);	//display by preorder traversal
			int postorder(Node*);	//display by postorder traversal
			Node* getRoot();		//getter to return root node
			void setRoot(Node*);	//setter to set root node	
			Node *LLRotate(Node*);	//LL Rotation
			Node *RRRotate(Node*);	//RR Rotation
			Node *LRRotate(Node*);	//LR Rotation
			Node *RLRotate(Node*);	//RL Rotation
			Node *insert(Node*,Node*);	//insert a node in the tree
			Node* search(Node*,long);	//to search a element

	private:
			Node *root;		//root node of tree
};