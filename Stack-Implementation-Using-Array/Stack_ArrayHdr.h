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

class Stack 	//stack class
{
	public:
			Stack();	//default constructor
			Stack(int,int,Bank*);	//parameterised constructor
			Stack(const Stack&);	//copy constructor
			~Stack();	//destructor
			int isFull();		//to check if the stack is full
			int isEmpty();		//to check if the stack is empty
			int push(Bank);		//to push an element to the stack
			Bank pop();		//to pop an element from the stack
			Bank peek();	//to peek an element from the stack
			void makeStackEmpty();		//to empty the stack
	private:
		int top;	//to point to the topmost element of the stack
		int capacity;	//to contain capacity of the stack
		Bank *arr;	//array to contain the stack elements
};