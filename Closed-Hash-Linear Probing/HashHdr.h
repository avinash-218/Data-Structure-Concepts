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

class HashTable	//hashtable class (linear probing)
{
	private:
			int capacity;	//bucket size
			int size;		//filled size
			Bank *arr;		//bank accounts
	public:
			HashTable();						//default constructor
			int hash(long);						//hash function
			int insert(Bank);					//insert an element
			int remove(long);					//remove an element
			int search(long);					//search for an element
			Bank findElement(long);				//find an element
			void display();						//display all elements
};