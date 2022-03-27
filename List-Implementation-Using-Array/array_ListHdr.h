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
	friend class List_ADT;	//declaring as friend class
};

class List_ADT		//List_ADT class
{
	private:
			Bank *arr;	//array elements
			int size;	//size
			int cap;		//capacity
	public:
			List_ADT();		//default constructor
			List_ADT(Bank*,int,int);	//parameterised constructor
			List_ADT(const List_ADT&);	//copy constructor
			~List_ADT();	//destructor

			int isFull();	//to check if the list is full
			int isEmpty();	//to check if the list is empty
			int insertAtFirst(Bank);	//to insert an account at first
			int insertAtLast(Bank);	//to insert an account at last
			int insertAfterElement(Bank,long);	//to insert an account after an account
			int insertBeforeElement(Bank,long);	//to insert an account before an account in the list
			int insertByPos(int,Bank);	//insert an account in the given position by doing necessary shifting
			int posOfElement(long);	//to find the position of an account in the list
			int displayList();	//to display all accounts' details of list
			int deleteAtFirst();	//to delete the account at the beginning of the list
			int deleteAtLast();	//to delete the account at the last of the list
			int deleteByPos(int);	//to delete the account at the given position
			int deleteAfterElement(long);	//to delete the account after an account
			int deleteBeforeElement(long);	//to delete the account before an account
			void makeListEmpty();	//to empty the list
			Bank elementAtPosition(int);	//to retrieve the accound details at the position
};