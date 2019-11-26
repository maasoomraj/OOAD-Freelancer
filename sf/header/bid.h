using namespace std;

class Bid
{
    private:
    string jobID, email, amount, description, comment, isAccepted, isCompleted;

    public:
    Bid(){
        jobID = email = amount = description = comment = "\0";
        isAccepted ="0";
        isCompleted = "0";
    }

    void get_description(string s)
    {
        description=s.substr(0,s.length());
    }
    void get_comment(string s)
    {
        comment=s.substr(0,s.length());
    }

    void get_email(string s)
    {
        email=s.substr(0,s.length());
    }

    int get_amount(string s)
    {
        for(int i=0;i<s.length();i++)
        {
            if(!(s[i]-0>=48 && s[i]-0<=57))
            {
                cout<<endl<<"Enter valid amount"<<endl;
                return 0;
            }
        }
        amount=s.substr(0,s.length());
        return 1;
    }

    void get_jobID(string s)
    {
        jobID=s.substr(0,s.length());
    }
};
