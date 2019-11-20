#include<iostream>
#include<fstream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	string bid_title, bid_description, bid_amount;
	string deadline_date;
	char create_bid, agree;
	string bid_no;

	cout<<"\n\nCreate Bid\n If yes, then type y else type n\n\n";
	cin>>create_bid;
	int count=0;
	FILE *f;
	f= fopen("Bid_List.txt","a");
	if(create_bid=='y' || create_bid=='Y')
	{
		cout<<"\nNow enter bid details\n";
		cout<<"\nEnter bid description\n";
		getline(cin,bid_description);
		cout<<"\nEnter bid title\n";
		getline(cin,bid_title);
		cout<<"\nEnter bid amount";
		cin>>bid_amount;
		cout<<"\nEnter deadline date\n";
		getline(cin,deadline_date);
		cout<<"\n Confirm details or Cancel\n Enter Y to continue else enter N\n";
		cin>>agree;
		if(agree=='Y' || agree=='y')
		{	count++;
			cout<<"\nYour bid is created and waiting for the final confirmation from the admin.\n";
			bid_no=count;
		}

		fputs("Bid Number: ",f);
		fwrite(&bid_no,bid_no.size()+1,1,f);
		fputs("\n\n Bid Description: ",f);
		fwrite(&bid_description,bid_description.size()+1,1,f);
		fputs("\n\n Bid Title: ",f);
		fwrite(&bid_title,bid_title.size()+1,1,f);
		fputs("\n\nBid Amount: ",f);
		fwrite(&bid_amount,bid_amount.size()+1,1,f);
		fputs("\n\nDeadline: ",f);
		fwrite(&deadline_date,deadline_date.size()+1,1,f);
		fputs("\n\n",f);
	}
	fclose(f);
	return 0;
}
