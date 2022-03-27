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
	friend class Stack;	//declaring Node class and SLL_ADT class are friends		
};

class Node 		//node class
{
	public:
			Node();	//default constructor
			Node(long,string,string,string,double);	//parameterised constructor
	private:
			Bank *data;	//pointer to Rational object
			Node *next;	//pointer of next node
	friend class Stack;	//declaring Node class and SLL_ADT class are friends
};

class Stack 	//stack class
{
	public:
			Stack();	//default constructor
			int isEmpty();		//to check if the stack is empty
			void push(Node*);		//to push an element to the stack
			Bank* pop();		//to pop an element from the stack
			Bank* peek();	//to peek an element from the stack
			void makeStackEmpty();		//to empty the stack
	private:
		Node *top;	//point to the top node
};