#include"GraphHdr.h"

int main()
{
	int n,ch;
	cout<<"Enter no of Vertices: ";
	cin>>n;
	Graph g(n);
	g.getData();
	g.createGraph();
	while(true)
	{
		cout<<"\nChoose an option\n";
		cout<<"1 - Perform DFS Traversal\n";
		cout<<"2 - Perform BFS Traversal\n";
		cout<<"3 - Display all accounts details\n";
		cout<<"4 - To Display Adjacent Matrix\n";
		cout<<"-1 - to exit\n\n";
		cin>>ch;
		cout<<"\n";
		if(ch==-1)
			break;
		switch(ch)
		{
			case 1:
			{
				g.performDFS();
				break;
			}
			case 2:
			{
				g.performBFS();
				break;
			}
			case 3:
			{
				g.displayAll();
				break;
			}
			case 4:
			{
				g.printAdjacent();
				break;
			}
			default:
			{
				cout<<"Invalid Input\n";
			}
		}
	}
}