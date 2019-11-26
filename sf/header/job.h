using namespace std;
class Job
{
    private:
    string email, description, title, price, deadline, isTaken,isApproved,JobId;

    public:
    void get_description(string s)
    {
        description=s.substr(0,s.length());
    }
    void get_title(string s)
    {
        title=s.substr(0,s.length());
    }

    void get_email(string s)
    {
        email=s.substr(0,s.length());
    }

    void get_JobId(string s)
    {
        JobId=s.substr(0,s.length());
    }

    int get_price(string s)
    {
        for(int i=0;i<s.length();i++)
        {
            if(!(s[i]-0>=48 && s[i]-0<=57))
            {
                cout<<endl<<"Enter valid amount"<<endl;
                return 0;
            }
        }
        price=s.substr(0,s.length());
        return 1;
    }

    int get_deadline(string s)
    {

      if(s.length() != 6)
      {
        cout<<endl<<"Enter in valid format (ddmmyy)\n";
        return 0;
      }
        for(int i=0;i<s.length();i++)
        {
            if(!(s[i]-0>=48 && s[i]-0<=57))
            {
                cout<<endl<<"Enter in valid format\n";
                return 0;
            }
        }
        if((s[0]-0>=51 && s[0]-0<=57) || (s[2]-0==49 && s[2]-0>=51) || (s[2]-0>=50))
        {
            cout<<endl<<"Enter in valid format\n";
            return 0;
        }
        else
        {
            deadline=s.substr(0,s.length());
            return 1;
        }

    }

    void IsTaken()
    {
      isTaken = "0";
      isApproved = "0";
      JobId = "0";
    }
};

class JobNo
{
public:
  int JobNo;
};
