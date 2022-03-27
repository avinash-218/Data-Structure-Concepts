#include<iostream>
using namespace std;

//class definitions
class Bank	//bank class
{
	public:
			Bank();											//default constructor
			Bank(long,string,string,string,double);			//parameterised constructor
			Bank(const Bank&);								//copy constructor
			~Bank();										//destructor
			void display();									//to display details
	private:
			long acc_no;	//account number
			string name;	//holder name
			string type;	//Savings or current account
			string ifsc;	//IFSC code
			double balance;	//account balance
};

class Graph//graph class
{
	public:
			Graph(int);									//parameterised constructor
			~Graph();   								// destructor
			void performDFS();							//perform Depth first traversal
			void DFS(int);								// perform DFS on adjacent vertices
			void getData();								//get application data for each vertices
			void createGraph();							//create adjacency matrix (create vertices by getting edges)
			void printAdjacent();						//to print adjacency matrix
			void displayAll();   						//to Display Detail of all vertices
			int display();
			void performBFS();
			void BFS(int);
	private:
			Bank *vertices;								//verteices pointer
			int noOfVertices;							//number of vertuices in the graph
			bool* visited;								//to denote which vertices are visited
			int** adjMatrix;							//adjacency matrix
};