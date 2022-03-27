#include"GraphHdr.h"

//Bank class member functions
Bank::Bank()	//default constructor
{
	acc_no=0;
	name="";
	type="";
	ifsc="";
	balance=0.0;
}

Bank::Bank(long acc,string n,string t,string i,double bal)	//parameterised constructor
{
	acc_no=acc;
	name=n;
	type=t;
	ifsc=i;
	balance=bal;
}

Bank::Bank(const Bank& temp)		//copy constructor
{
	acc_no=temp.acc_no;
	name=temp.name;
	type=temp.type;
	ifsc=temp.ifsc;
	balance=temp.balance;
}

Bank::~Bank()	//destructor
{
 	acc_no=0;
	name="";
	type="";
	ifsc="";
	balance=0.0;	
}


void Bank::display()	//to display the account details
{
	cout<<"Account Number : "<<acc_no;
	cout<<"\nHolder Name : "<<name;
	cout<<"\nIFSC Code : "<<ifsc;
	cout<<"\nType : "<<type;
	cout<<"\nBalance : "<<balance;
	cout<<"\n\n";
}

//Graph class member functions
Graph::Graph(int n)										//parameterised constructor
{
	noOfVertices=n;
	vertices=new Bank[n];
	adjMatrix = new int*[noOfVertices];

	for( int i=0; i<noOfVertices; i++ )
		adjMatrix[i] = new int[noOfVertices];
	
	visited = new bool[noOfVertices];
	for( int i=0;i<noOfVertices ; i++)
		for( int j=0; j<noOfVertices ; j++)
			adjMatrix[i][j] = 0;
}

void Graph::getData()	//input details for every vertices
{
	int i;
	for(i=0;i<noOfVertices;i++)
	{
		cout<<"\nVertex "<<i+1<<":\n";
		long acc_no;
		string name,ifsc,type;
		double balance;
		cout<<"Enter account number\n";
		cin>>acc_no;
		cout<<"Enter name of the account holder\n";
		cin>>name;
		cout<<"Enter Savings or Current Account\n";
		cin>>type;
		cout<<"Enter the IFSC Code\n";
		cin>>ifsc;
		cout<<"Enter the balance amount in your account\n";
		cin>>balance;
		Bank ele(acc_no,name,type,ifsc,balance);
		vertices[i] = ele;
	}
}

void Graph::createGraph()	//to create a graph
{
	int i,num_edge,v,w,weight;
	cout<<"\nEnter No of Edges in graph: ";
	cin>>num_edge;
	for(i=0;i<num_edge;i++)
	{
		cout<<"\nEnter the Vertices numbers one after one that form an edge:\n";
		cin>>v>>w;
		adjMatrix[v-1][w-1] = 1;
		adjMatrix[w-1][v-1] = 1;		
	}
}

void Graph::performDFS()
{
 visited = new bool[noOfVertices];
 for( int i=0; i<noOfVertices; i++)
	visited[i] = false;
 for( int i=0; i<noOfVertices; i++)
  if(!visited[i])
   DFS(i);
}

void Graph::DFS(int i)
{
 vertices[i].display();
 visited[i] = true;
 for( int j=0; j<noOfVertices; j++)
  if( adjMatrix[i][j] == 1)
   if(!visited[j])
	DFS(j);
}

void Graph::performBFS()
{
 visited = new bool[noOfVertices];
 for( int i=0; i<noOfVertices; i++)
	visited[i] = false;
 vertices[0].display();
 for( int i=0; i<noOfVertices; i++)
	BFS(i);
}

void Graph::BFS(int i)
{
 visited[i] = true;
 for( int j=0; j<noOfVertices; j++)
  if( adjMatrix[i][j] == 1)
   if(!visited[j])
   {
	visited[j]=true;
   	vertices[j].display();
   }
}

void Graph::displayAll()		//to display all the vertices details
{
	int i;
	for(i=0;i<noOfVertices;i++)
	{
		vertices[i].display();
		cout<<"\n";
	}
}

void Graph::printAdjacent()		//to display the adjacent matrix
{
	int i,j;
	cout<<"\n Adjacent Matrix :\n";
	for(i=0;i<noOfVertices;i++)
		cout<<"\t"<<i+1;
	cout<<"\n";
	for(i=0;i<noOfVertices;i++)
		cout<<"--------";
	cout<<"\n";
	for(i=0;i<noOfVertices;i++)
	{
		cout<<i+1<<" |\t";
		for(j=0;j<noOfVertices;j++)
			cout<<adjMatrix[i][j]<<"\t";
		cout<<"\n";
	}
}

Graph::~Graph()			//destructor
{
	int i;
	for(i=0;i<noOfVertices;i++)
		adjMatrix[i]=NULL;
	noOfVertices = 0;
	vertices=NULL;
	visited=NULL;
}