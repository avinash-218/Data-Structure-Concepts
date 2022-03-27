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
	friend class Queue;	//declaring Node class and SLL_ADT class are friends		
};

class Node 		//node class
{
	public:
			Node();	//default constructor
			Node(long,string,string,string,double);	//parameterised constructor
	private:
			Bank *data;	//pointer to Rational object
			Node *next;	//pointer of next node
	friend class Queue;	//declaring Node class and SLL_ADT class are friends
};

class Queue		//Queue class
{
	public:
			Queue();	//default constructor
			int isEmpty();	//to check if the queue is empty or not
			void enqueue(Node*);	//to add an element to the last of the queue
			Bank* dequeue();	//to remove the element at the first of the queue
			Bank* peek();	//to peek the element at the first of the queue
			Bank* lastElement();	//to display the details of the last account
			void makeQueueEmpty();	//to empty the queue
	private:
			Node *first;
};