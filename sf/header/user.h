#include "color.h"
using namespace std;
int compareString(string a, string b)
{
  if (a.size() != b.size())
  return 1;

  for(int i=0;i<a.size();i++)
  {
    if(a[i] != b[i])
    return 1;
  }

  return 0;
}

Color::Modifier red(Color::FG_RED);
Color::Modifier blue(Color::FG_BLUE);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier def(Color::FG_DEFAULT);

class user
{
// public:
private:
  string email,password;
  string type;
  string f_name,l_name,age,city,state,contact;

   // age, email, city, state, contact, password;
public:
  int getf_name(string c)
  {
    for(int i=0;i<c.size();i++)
    {
      if(!((c[i] -0 >= 65 && c[i]-0<=90) ||(c[i] -0 >= 97 && c[i]-0<=122)))
        {
          cout<<red<<"\nError : First Name can contain only alphabets.\n\n"<<def;
          return 1;
        }
    }
    f_name =c;
    return 0;
  }
  int getl_name(string c)
  {
    for(int i=0;i<c.size();i++)
    {
      if(!((c[i] -0 >= 65 && c[i]-0<=90) ||(c[i] -0 >= 97 && c[i]-0<=122)))
        {
          cout<<red<<"\nError : Last Name can contain only alphabets.\n\n"<<def;
          return 1;
        }
    }
    l_name =c;
    return 0;
  }
  int getage(string c)
  {
    for(int i=0;i<c.size();i++)
    {
      if(!((c[i] -0 >= 48 && c[i]-0<=57) ))
        {
          cout<<red<<"\nError : Age can contain only numbers.\n\n"<<def;
          return 1;
        }
    }

    if(c.size()>2)
    {
      cout<<red<<"\nError : Age can be less than 99.\n\n"<<def;
      return 1;
    }
    age =c;
    return 0;
  }
  int getemail(string c)
  {
    int coi =0;
    for(int i=0;i<c.size();i++)
    {
      if(c[i] - 0 == 64)
        {
          coi =1;
          break;
        }
    }
    if (coi ==0)
    {
      cout<<red<<"\nError : Enter valid email address.\n\n"<<def;
      return 1;
    }

    email = c;
    return 0;
  }
  int getcity(string c)
  {
    for(int i=0;i<c.size();i++)
    {
      if(!((c[i] -0 >= 65 && c[i]-0<=90) ||(c[i] -0 >= 97 && c[i]-0<=122)))
        {
          cout<<red<<"\nError : City can contain only alphabets.\n\n"<<def;
          return 1;
        }
    }
    city =c;
    return 0;
  }
  int getstate(string c)
  {
    for(int i=0;i<c.size();i++)
    {
      if(!((c[i] -0 >= 65 && c[i]-0<=90) ||(c[i] -0 >= 97 && c[i]-0<=122)))
        {
          cout<<red<<"\nError : State can contain only alphabets.\n\n"<<def;
          return 1;
        }
    }
    state =c;
    return 0;
  }
  int getcontact(string c)
  {
    for(int i=0;i<c.size();i++)
    {
      if(!((c[i] -0 >= 48 && c[i]-0<=57) ))
        {
          cout<<red<<"\nError : Contact can contain only numbers.\n\n"<<def;
          return 1;
        }
    }

    if(c.size()!=10)
    {
      cout<<red<<"\nError : Contact Number is invalid.\n\n"<<def;
      return 1;
    }
    contact =c;
    return 0;
  }
  int getpassword(string c1, string c2)
  {
    if(compareString(c1,c2))
    {
      cout<<red<<"\nError : Password doesnot matches.\n\n"<<def;
    }
    password = c1;
    return 0;
  }
  int gettype(string c)
  {
    if(!((c[0] - 0 == 49 || c[0] - 0 == 50) && c.size() == 1))
    {
      cout<<red<<"\nError : You can enter only '1' or '2'.\n\n"<<def;
      return 1;
    }


    if(c[0] - 0 == 49)
    {
      type ="Employer";
    }
    else
    {
      type ="Freelancer";
    }
    return 0;
  }


  string showf_name()
  {
    return f_name;
  }
  string showl_name()
  {
    return l_name;
  }
  string showage()
  {
    return age;
  }
  string showemail()
  {
    return email;
  }
  string showcity()
  {
    return city;
  }
  string showstate()
  {
    return state;
  }
  string showcontact()
  {
    return contact;
  }

};
