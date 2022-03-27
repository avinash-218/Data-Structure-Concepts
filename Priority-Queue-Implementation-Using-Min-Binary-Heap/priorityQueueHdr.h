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
			long getAccno();		//getter for acc_no
	private:
			long acc_no;	//account number
			string name;	//holder name
			string type;	//Savings or current account
			string ifsc;	//IFSC code
			double balance;	//account balance

	friend class BinHeap;	//declaring Bank class and BinHeap class are friends
};

class BinHeap	//bin heap tree
{
	private:
			Bank *arr;		//bank accounts
			int capacity;	//capcity of binary heap
			int hsize;		//heap size
	public:
			BinHeap();				//default constructor
			int isEmpty();			//check if heap is empty
			int isFull();			//to check if heap is full
			int enqueue(Bank);		//insert an element
			Bank dequeue();			//remove an element (delete min)			
			Bank findMin();			//find minimum element
			int search(long);		//search an element
			void displayHeap();		//display the heap
};
