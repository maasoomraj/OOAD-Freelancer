#include<iostream>
#include<fstream>
#include<cstring>
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
	int bid_no;
	public:
	void get_description(string s)
	{
		int i=0;

	for(i=0;i<s.size();i++)
		bid_description[i]=s[i];

	}
	void get_bid_no(int s)
	{
		bid_no=s;
	}
	void get_title(string s)
	{
		int i=0;

	for(i=0;i<s.size();i++)
		bid_title[i]=s[i];
		}
	int get_amount(string s)
	{

		for(int i=0;i<s.size();i++)
    {
      if((s[i]-0 >= 65 && s[i]-0<=90) ||(s[i] -0 >= 97 && s[i]-0<=122))
        {
          cout<<red<<"\nEnter valid amount\n"<<def;
          return 0;
        }
    }
	if(s[0]=='0')
			{cout<<red<<endl<<"Enter valid amount\n"<<def;
			return 0;}
	else
	{		int i=0;

	for(i=0;i<s.size();i++)
		bid_amount[i]=s[i];

		return 1;
	}}

	int deadline(string s)
	{	for(int i=0;i<s.size();i++)
    {
      if(!(s[i] -0 >= 48 && s[i]-0<= 57))
        {
          cout<<red<<"\nEnter in valid format\n"<<def;
          return 0;
        }
    }
		if(s[0]-0>=51 || s[2]-0>=49 || (s[2]-0==49 && s[3]-0>=50) || (s[0]-0==51 && s[1]-0>=49) )
		{
			cout<<red<<endl<<"Enter in valid format"<<endl;
			return 0;
		}
		else
	{
			int i=0;

	for(i=0;i<s.size();i++)
			deadline_date[i]=s[i];
	return 1;

		}

	}



};

int main()
{
	string bid_title, bid_description, bid_amount;
	string deadline_date;
	int bid_no;
	char agree;
	char create_bid;
	cout<<blue<<"\n\nCreate Bid\n (Y/N)\n\n"<<def;
	cin>>create_bid;
	bid b;
	int x;
	if(create_bid=='y' || create_bid=='Y')
	{
			cout<<blue<<"\nNow enter bid details\n"<<def;
			cout<<blue<<"\nEnter bid description"<<def;
			cin>>bid_description;
			//scanf("%[^\n]s",bid_description);
			b.get_description(bid_description);
			cout<<blue<<"\nEnter bid title\n"<<def;
			cin>>bid_title;			//scanf("%[^\n]s",bid_title);
			b.get_title(bid_title);
			do
			{
				cout<<blue<<"\nEnter bid amount"<<def;
				cin>>bid_amount;
				//scanf("%[^\n]s",bid_amount);
			}
			while(b.get_amount(bid_amount)==0);

			do
			{
				cout<<blue<<"\nEnter deadline date in dd/mm/yy format\n"<<def;
				//scanf("%[^\n]s",deadline_date);
				cin>>deadline_date;
			}
			while(b.deadline(deadline_date)==0);

			cout<<blue<<"\n Confirm?\n (Y/N) \n"<<def;
			cin>>agree;
			if(agree=='Y' || agree=='y')
			{
        // count++;
				cout<<green<<"\nYour bid is created and waiting for the final confirmation from the admin.\n"<<def;
				bid_no=0;
				b.get_bid_no(bid_no);
				ofstream fp;

			        fp.open("Bid_List.txt", ios::app);
			        fp.write((char*)&b, sizeof(b));
			}
	}

	return 0;
}