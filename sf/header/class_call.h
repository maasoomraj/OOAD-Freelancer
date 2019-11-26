using namespace std;
class readUser
{
public:
  string email,password;
  string type;
  string f_name,l_name,age,city,state,contact;
};

// class Employer : public user
// {
//
// };
//
// class Freelancer : public user
// {
//
// };

class Job1
{
public:
      string email, description, title, price, deadline, isTaken,isApproved,JobId;
};

class Bid1
{
public:
    string jobID, email, amount, description, comment, isAccepted, isCompleted;
};

class Mail
{
public:
    string name;
};
