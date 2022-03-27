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
			long getAccNum();	//getter to get the account number
			void display();	//to display details
	private:
			long acc_no;	//account number
			string name;	//holder name
			string type;	//Savings or current account
			string ifsc;	//IFSC code
			double balance;	//account balance
	friend class BST;	//declaring Node class and SLL_ADT class are friends		
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
	friend class BST;	//declaring Node class and SLL_ADT class are friends
};

class BST	//class of Binary Search Tree
{
	public:
			BST();	//default constructor
			bool isEmpty();	//to check if the tree is empty
			bool insert(Node*,Node*);	//to insert a node
			Node* search(Node*,long);	//to search an account(wrt account number)
			Bank* findMin(Node*);	//to find the minimum node in the tree
			Bank* findMax(Node*);	//to find the maximum node in the tree
			int inorder(Node*);	//inorder traversal
			int preorder(Node*);	//preorder traversal
			int postorder(Node*);	//postorder traversal
			Bank* deleteNode(long);	//to delete a node
			Node* getRoot();	//getter to root address
	private:
			Node *root;
};

