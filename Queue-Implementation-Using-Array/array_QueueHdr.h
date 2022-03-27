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
};

class Queue		//Queue class
{
	public:
			Queue();	//default constructor
			Queue(int,int,int,Bank*);	//parameterised constructor
			Queue(const Queue&);	//copy construcotr
			~Queue();	//destructor
			int isEmpty();	//to check if the queue is empty or not
			int isFull();	//to check if the queue is full or not
			int enqueue(Bank);	//to add an element to the last of the queue
			Bank dequeue();	//to remove the element at the first of the queue
			Bank peek();	//to peek the element at the first of the queue
			Bank lastElement();		//to display the last element in the queue
			void makeQueueEmpty();	//to empty the queue
	private:
			int front,rear,capacity;
			Bank *arr;
};