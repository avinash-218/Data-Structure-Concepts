#include"singly_ListHdr.h"

int main()
{
	SLL_ADT list;
	int ch=0;
	while(ch!=-1)
	{
		cout<<"\nChoose an option:\n";
		cout<<"1-to insert an account at first\n";
		cout<<"2-to insert an account at last\n";
		cout<<"3-to insert an account at a position\n";
		cout<<"4-to insert an account after an account\n";
		cout<<"5-to insert an account before an account\n";
		cout<<"6-to remove the account at first\n";
		cout<<"7-to remove the account at last\n";
		cout<<"8-to remove an account at a position\n";
		cout<<"9-to remove the account after an account in the list\n";
		cout<<"10-to remove the account before an account in the list\n";
		cout<<"11-to display the details of all accounts\n";
		cout<<"12-to clear the entire list of accounts\n";
		cout<<"13-to search for an account details\n";
		cout<<"14-to retrieve the account details at a position in the list \n";
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
				Node *newNode=new Node(acc_no,name,type,ifsc,balance);
				list.insertAtFirst(newNode);
				cout<<"Account details inserted at first\n";
				break;
			}
			case 2:
			{
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
				Node *newNode=new Node(acc_no,name,type,ifsc,balance);
				list.insertAtLast(newNode);
				cout<<"Account details inserted at last\n";
				break;
			}
			case 3:
			{
				int pos;
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
				Node *newNode=new Node(acc_no,name,type,ifsc,balance);
				cout<<"Enter the position\n";
				cin>>pos;
				if(list.insertByPos(pos,newNode)==-1)
					cout<<"Account Details can't be inserted at the position\n";
				else
					cout<<"Account Details inserted at the position\n";
				break;
			}
			case 4:
			{
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
				Node *newNode=new Node(acc_no,name,type,ifsc,balance);
				long sch;
				cout<<"Enter the account number after which to insert the account details\n";
				cin>>sch;
				if(list.insertAfterElement(newNode,sch)==1)
					cout<<"Account Details is inserted after the given account\n";
				else
					cout<<"Account Details can't be inserted\n";
				break;
			}
			case 5:
			{
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
				Node *newNode=new Node(acc_no,name,type,ifsc,balance);
				long sch;
				cout<<"Enter the account number after which to insert the account details\n";
				cin>>sch;
				if(list.insertBeforeElement(newNode,sch)==-1)
					cout<<"Account Details can't be inserted\n";
				else
					cout<<"Account Details is inserted before the given account\n";
				break;
			}
			case 6:
			{
				if (list.deleteAtFirst()==1)
					cout<<"Account Details at first is deleted\n";
				else
					cout<<"Account Details can't be deleted\n";
				break;
			}
			case 7:
			{
				if(list.deleteAtLast()==-1)
					cout<<"List is empty, can't delete any Account Details\n";
				else
					cout<<"Account Details at last is deleted\n";
				break;
			}
			case 8:
			{
				int pos;
				cout<<"Enter the position\n";
				cin>>pos;
				if(list.deleteByPos(pos)==-1)
					cout<<"Account Details can't be deleted\n";
				else
					cout<<"Account Details at the given position is deleted\n";
				break;
			}
			case 9:
			{
				long sch;
				cout<<"Enter the account number after which to delete the account\n";
				cin>>sch;
				if(list.deleteAfterElement(sch)==-1)
					cout<<"Account Details can't be deleted\n";
				else
					cout<<"Account Details is deleted\n";
				break;
			}
			case 10:
			{
				long sch;
				cout<<"Enter the account number before to delete the account after it\n";
				cin>>sch;
				if(list.deleteBeforeElement(sch)==-1)
					cout<<"Account Details can't be deleted\n";
				else
					cout<<"Account Details is deleted\n";
				break;
			}
			case 11:
			{
				if(list.displayList()==-1)
					cout<<"List is empty\n";
				break;
			}
			case 12:
			{
				list.makeListEmpty();
				cout<<"Now the list is empty\n";
				break;
			}
			case 13:
			{
				long sch;
				cout<<"Enter the account number to search\n";
				cin>>sch;
				if(list.posOfElement(sch)==-1)
					cout<<"Details of the account is not present\n";
				else
					cout<<"Details of the account is present\n";
				break;
			}
			case 14:
			{
				int pos;
				cout<<"Enter the position\n";
				cin>>pos;
				Bank* ele=list.elementAtPosition(pos);
				if(ele->getAccNum()==0)
					cout<<"Invalid Position\n";
				else
					ele->display();
				break;
			}
			default:
			{
				cout<<"Invalid Input\n";
				break;
			}
		}
	}
}

