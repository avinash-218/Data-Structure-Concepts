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
	friend class SLL_ADT;	//declaring as friend class
};

class Node 		//node class
{
	public:
			Node();	//default constructor
			Node(long,string,string,string,double);	//parameterised constructor
	private:
			Bank *data;	//pointer to Bank object
			Node *next;	//pointer of next node
	friend class SLL_ADT;	//declaring Node class and SLL_ADT class are friends
};

class SLL_ADT
{
	public:
			SLL_ADT();	//default constructor
			int isEmpty();	//to check if the list is empty
			void insertAtFirst(Node*);	//to insert a node at first
			void insertAtLast(Node*);	//to insert a node at last
			int insertByPos(int,Node*);	//to insert a node at the position
			int posOfElement(long);	//to find position of an element in the list
			int insertAfterElement(Node*,long);	//to insert an element after an element in the list
			int insertBeforeElement(Node*,long);	//to insert an element before an element in the list			
			int deleteAtFirst();	//to delete first node
			int deleteAtLast();	//to delete last node
			int deleteByPos(int);	//to delete node at a position
			int deleteAfterElement(long);	//to delete the element after an element in the list
			int deleteBeforeElement(long);	//to delete the element before an element in the list
			int displayList();	//to display the data in every node of the list
			void makeListEmpty();	//to make the lsit empty
			Bank* elementAtPosition(int);	//to find element at the position
	private:
			Node *first;	//address of first node
};

