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
	public:
	string bid_title, bid_description, bid_amount;
	string deadline_date;
	char agree;
	int bid_no;

	void create_bid()
	{
		FILE *f;
		f= fopen("Bid_List.txt","a");


			cout<<blue<<"\n\t  Bid details -\n\n";
			cout<<blue<<"\n   Enter bid description\n\n";
			getline(cin,bid_description);
			cout<<blue<<"\n   Enter bid title\n\n";
			getline(cin,bid_title);
			cout<<blue<<"\n   Enter bid amount\n\n";
			cin>>bid_amount;
			cout<<blue<<"\n   Enter deadline date\n\n";
			getline(cin,deadline_date);
			cout<<blue<<"\n   Confirm details or Cancel\n\n Enter Y to continue else enter N\n";
			cin>>agree;
			if(agree=='Y' || agree=='y')
			{	count++;
				cout<<"\nYour bid is created and waiting for the final confirmation from the admin.\n";
				bid_no=count;
			}

			fwrite(&bid_no,sizeof(int),1,f);
			fputs("\t\t",f);
			fwrite(&bid_description,bid_description.size()+1,1,f);
			fputs("\t\t",f);
			fwrite(&bid_title,bid_title.size()+1,1,f);
			fputs("\t\t",f);
			fwrite(&bid_amount,bid_amount.size()+1,1,f);
			fputs("\t\t",f);
			fwrite(&deadline_date,deadline_date.size()+1,1,f);
			fputs("\n\n",f);
		}
	fclose(f);

};

int main()
{
	char create_bid;
	cout<<blue<<"\n\nCreate Bid\n (Y/N)\n\n";
	cin>>create_bid;
	if(create_bid=='y' || create_bid=='Y')
	{
		bid obj;
		obj.create_bid();

	}

	return 0;
}
