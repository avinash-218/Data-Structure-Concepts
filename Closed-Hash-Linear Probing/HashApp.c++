#include"HashHdr.h"

int main()
{
	HashTable h;
	int ch=0;
	while(true)
	{
		cout<<"\nChoose an option\n";
		cout<<"1-to insert an account\n";
		cout<<"2-to remove the account\n";
		cout<<"3-to search if an account details is present or not\n";
		cout<<"4-to find an account details\n";
		cout<<"5-to display all account details\n";
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
				int flag=h.insert(ele);
				if(flag==1)
					cout<<"Account details inserted\n";
				else if(flag==-1)
					cout<<"List is Full, can't insert\n";
				else
					cout<<"Duplicate Account Number is not allowed\n";
				break;
			}
			case 2:
			{
				long acc_no;
				double balance;
				cout<<"Enter account number\n";
				cin>>acc_no;
				int temp=h.remove(acc_no);
				if(temp==-1)
					cout<<"List is Empty\n";
				else if(temp==-2)
					cout<<"Bank Account not found\n";
				else
					cout<<"Account details deleted\n";
				break;
			}
			case 3:
			{
				long acc_no;
				double balance;
				cout<<"Enter account number\n";
				cin>>acc_no;
				int temp=h.search(acc_no);
				if(temp==-1)
					cout<<"List is Empty\n";
				else if(temp==-2)
					cout<<"Bank Account not found\n";
				else
					cout<<"Bank Account found\n";
				break;
			}
			case 4:
			{
				long acc_no;
				double balance;
				cout<<"Enter account number\n";
				cin>>acc_no;
				Bank temp=h.findElement(acc_no);
				if(temp.getAccno()==0)
					cout<<"Bank Account not found\n";
				else
					temp.display();
				break;
			}
			case 5:
			{
				h.display();
				break;
			}
			default:
			{
				cout<<"Invalid Input\n";
			}
		}
	}
}