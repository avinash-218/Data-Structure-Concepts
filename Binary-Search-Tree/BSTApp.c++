#include"BSTHdr.h"

int main()
{
	BST tree;
	int ch=0;
	while(true)
	{
		cout<<"\nChoose an option\n";
		cout<<"1-to insert a Bank account\n";
		cout<<"2-to remove a Bank account\n";
		cout<<"3-to search an account\n";
		cout<<"4-to display the details of the first account \n";
		cout<<"5-to display the details of the last account \n";
		cout<<"6-to display the details of all the accounts in inorder traversal\n";
		cout<<"7-to display the details of all the accounts in preorder traversal\n";
		cout<<"8-to display the details of all the accounts in postorder traversal\n";
		cout<<"-1 - to exit\n\n";
		cin>>ch;
		cout<<"\n";
		if(ch==-1)
			break;
		switch(ch)
		{
			case 1:
			{
				long acc_no;
				string name,ifsc,type;
				double balance;
				Node *root=tree.getRoot();
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
				Node *ele=new Node(acc_no,name,type,ifsc,balance);
				if(tree.insert(root,ele)==true)
					cout<<"The account details is successfully inserted\n";
				break;
			}
			case 2:
			{
				long acc_no;
				cout<<"Enter account number\n";
				cin>>acc_no;
				Bank* removed=new Bank();
				removed=tree.deleteNode(acc_no);
				if(removed->getAccNum()==0)
					cout<<"No Account exists with the account number\n";
				else
					removed->display();
				break;
			}
			case 3:
			{
				long acc_no;
				cout<<"Enter the account number to search for\n";
				cin>>acc_no;
				Node *root=tree.getRoot();
				if(root!=NULL)
				{
					Node *ret=tree.search(root,acc_no);
					if(ret!=NULL)
						ret->displayData();
					else
						cout<<"Account details not present\n";
				}
				else
					cout<<"List is Empty\n";
				break;
			}
			case 4:
			{
				Node *root=tree.getRoot();
				Bank *ret=tree.findMin(root);
				if(ret->getAccNum()==0)
					cout<<"List is Empty\n";
				else
					ret->display();
				break;
			}
			case 5:
			{
				Node *root=tree.getRoot();
				Bank *ret=tree.findMax(root);
				if(ret->getAccNum()==0)
					cout<<"List is Empty\n";
				else
					ret->display();
				break;
			}
			case 6:
			{
				Node *root=tree.getRoot();
				if(tree.inorder(root)==-1)
					cout<<"List is empty\n";
				break;
			}
			case 7:
			{
				Node *root=tree.getRoot();
				if(tree.preorder(root)==-1)
					cout<<"List is empty\n";
				break;
			}
			case 8:
			{
				Node *root=tree.getRoot();
				if(tree.postorder(root)==-1)
					cout<<"List is empty\n";
				break;
			}
			default:
			{
				cout<<"Invalid Input\n";
			}
		}
	}
}