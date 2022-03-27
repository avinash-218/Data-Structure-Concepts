#include"priorityQueueHdr.h"

int main()
{
	BinHeap heap;
	int ch=0;
	while(true)
	{
		cout<<"\nChoose an option\n";
		cout<<"1-to insert an account\n";
		cout<<"2-to remove the account\n";
		cout<<"3-to find the first bank account in ascending order\n";
		cout<<"4-to search for an account details\n";
		cout<<"5-to display the details of all accounts\n";
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
				if(heap.enqueue(ele)==1)
					cout<<"Account details inserted\n";
				else
					cout<<"List is Full, can't insert\n";
				break;
			}
			case 2:
			{
				Bank ele=heap.dequeue();
				if(ele.getAccno()==0)
					cout<<"List is empty, can't delete any Account Details\n";
				else
					ele.display();
				break;
			}
			case 3:
			{
				Bank temp=heap.findMin();
				if(temp.getAccno()==0)
					cout<<"List is empty";
				else
					temp.display();
				break;
			}
			case 4:
			{
				long sch;
				cout<<"Enter the account number to check if it is present in the list\n";
				cin>>sch;
				if(heap.search(sch)==-1)
					cout<<"Details of the account is not present\n";
				else
					cout<<"Details of the account is present\n";
				break;
			}
			case 5:
			{
				heap.displayHeap();
				break;
			}
			default:
				cout<<"Invalid Input\n";
		}
	}
}