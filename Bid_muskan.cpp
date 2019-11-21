#include<iostream>
#include<fstream>
#include<string>
#include<fstream>
#include "color.h"

using namespace std;

Color::Modifier red(Color::FG_RED);
Color::Modifier blue(Color::FG_BLUE);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier def(Color::FG_DEFAULT);

int count=0;
class bid
{
	private:
	string bid_title, bid_description, bid_amount;
	string deadline_date;
	char agree;
	string bid_no;
	public:
	void get_description(string s)
	{
		strcpyIbid_description,s);
	}
	void get_title(string s)
	{ 
		strcpy(bid_title,s);
	}
	int get_amount(string s)
	{
		if(s=='0')
			{cout<<red<<endl<<"Enter valid amount"<<endl;
			return 0;}
		else
			strcpy(bid_amount,s);
		return 1;
	}

	int deadline(string s)
	{
		if(s[0]>=4 || s[0]==3 && s[1]>=2 || s[2]>=2 || s[2]==1 && s[3]>=3)
		{
			cout<<red<<endl<<"Enter in valid format"<<endl;
			return 0;
		}
		else
			strcpy(deadline_date,s);
		return 1;
	}

	
	
};
		
int main()
{	string bid_title, bid_description, bid_amount;
	string deadline_date;
	char agree;
	string bid_no;
	char create_bid;
	cout<<blue<<"\n\nCreate Bid\n (Y/N)\n\n";
	cin>>create_bid;
	Bid b;
	int x;
	if(create_bid=='y' || create_bid=='Y')
	{
			cout<<blue<<"\nNow enter bid details\n";
			cout<<blue<<"\nEnter bid description\n";
			getline(cin,bid_description);
			b.get_description(&bid_description);
			cout<<blue<<"\nEnter bid title\n";
			getline(cin,bid_title);
			b.get_title(&bid_title);
			do
			{
				cout<<blue<<"\nEnter bid amount";
				cin>>bid_amount;
			}
			while(b.get_amount(&bid_amount)==0);
			
			do
			{
				cout<<blue<<"\nEnter deadline date in dd/mm/yy format\n";
				getline(cin,deadline_date);
			}
			while(b.deadline(&deadline_date)==0);

			cout<<blue<<"\n Confirm?\n (Y/N) \n";
			cin>>agree;
			if(agree=='Y' || agree=='y')
			{	count++;
				cout<<"\nYour bid is created and waiting for the final confirmation from the admin.\n";
				bid_no=count;
				ofstream fp;

			        fp.open("Bid_List.txt", ios::app);
			        fp.write((char*)&b, sizeof(b));
			}	
	
	return 0;
}

		 
