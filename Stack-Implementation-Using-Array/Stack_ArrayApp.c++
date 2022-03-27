#include"Stack_ArrayHdr.h"

int main()
{
	Stack stack;
	int ch=0;
	while(true)
	{
		cout<<"\nChoose an option\n";
		cout<<"1-to insert a Bank account\n";
		cout<<"2-to remove a Bank account\n";
		cout<<"3-to peek the account at first\n";
		cout<<"4-to remove all the accounts\n";
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
				Bank ele(acc_no,name,type,ifsc,balance);
				if(stack.push(ele)==-1)
					cout<<"List is Full, Can't insert the account details\n";
				else
					cout<<"The account details is successfully inserted\n";
				break;
			}
			case 2:
			{
				Bank temp=stack.pop();
				if(temp.getAccNum()==0)
					cout<<"List is empty\n";
				else
				{
					cout<<"The  details of the removed account is :\n";
					temp.display();
					cout<<"\n";
				}
				break;
			}
			case 3:
			{
				Bank temp=stack.peek();
				if(temp.getAccNum()==0)
					cout<<"List is empty\n";
				else
				{
					cout<<"The details of the first account is :\n";
					temp.display();
				}
				break;
			}
			case 4:
			{
				stack.makeStackEmpty();
				cout<<"Now the list is empty\n";	
				break;
			}
			default:
			{
				cout<<"Invalid Input\n";
			}
		}
	}
}

