#include"HashHdr.h"

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

long Bank::getAccno()		//getter for acc_no
{
	return acc_no;
}


//HashTable class member functions
HashTable::HashTable()	//parameterised constructor
{
	capacity=10;
	arr=new Bank[capacity];
	size=0;
}

int HashTable::hash(long acc_no)	//hash function
{
	return acc_no%10;
}

int HashTable::insert(Bank ele)		//insert an element
{
	if(size==capacity)
		return -1;	//hash table is full
	int hval=hash(ele.getAccno());
	while(arr[hval].getAccno()!=0 && arr[hval].getAccno()!=ele.getAccno())		//hast table is not empty in the hash value
	{
		hval=hash(hval+1);
	}
	if(arr[hval].getAccno()==ele.getAccno())
		return -2;	//duplicates
	arr[hval]=ele;
	size++;
	return 1;	//inserted
}

int HashTable::remove(long ele)			//remove an element
{
	if(size==0)
		return -1;	//hash table is empty

	int hval=hash(ele);
	int flag=0;
	while(flag<=hval)
	{
		if(arr[hval].getAccno()!=ele)	//no element in the current hashvalue(may probe is considered) or element not in the hash value
		{
			hval=hash(hval+1);
			continue;
		}
		else	//elemnt is found
		{
			arr[hval].~Bank();
			return 1;	//removed
		}
		flag++;
	}
	return -2;		//element not found
}

int HashTable::search(long ele)					//search for an element
{
	if(size==0)
		return -1;	//hash table is empty

	int hval=hash(ele);
	int flag=0;
	while(flag<=hval)
	{
		if(arr[hval].getAccno()!=ele)	//no element in the current hashvalue(may probe is considered) or element not in the hash value
		{
			hval=hash(hval+1);
			flag++;
			continue;
		}
		else
			return 1;	//element is found
	}
	return -2;		//element not found	
}

Bank HashTable::findElement(long ele)						//find an element
{
	Bank ret;
	if(size==0)
		return ret;	//hash table is empty

	int hval=hash(ele);
	int flag=0;
	while(flag<=hval)
	{
		if(arr[hval].getAccno()!=ele)	//no element in the current hashvalue(may probe is considered) or element not in the hash value
		{
			hval=hash(hval+1);
			continue;
		}
		else
			return arr[hval];	//element is found
		flag++;
	}
	return ret;		//element not found		
}

void HashTable::display()					//display all elements
{
	if(size==0)
		cout<<"No Accounts in the list\n";
	else
	{
		int i;
		for(i=0;i<capacity;i++)
			arr[i].display();
	}
}