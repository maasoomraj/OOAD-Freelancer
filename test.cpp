#include<iostream>
#include<fstream>
#include<string>
#include "password.h"
#include "stdc.h"
#include "color.h"
using namespace std;

Color::Modifier red(Color::FG_RED);
Color::Modifier blue(Color::FG_BLUE);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier def(Color::FG_DEFAULT);

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

class readUser
{
public:
  string email,password;
  string type;
  string f_name,l_name,age,city,state,contact;
};


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
    if(!((c[0] - 0 == 49 || c[0] - 50 == 2) && c.size() == 1))
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

class Employer : public user
{

};

class Freelancer : public user
{

};

int agreecheck(string agree)
{
   if(!(agree[0] == 'y' || agree[0] == 'Y' ||agree[0] == 'n' || agree[0] == 'N' ))
   return 1;
   else
   return 0;
}

std::ostream& bold_on(std::ostream& os)
{
    return os << "\e[1m";
}

std::ostream& bold_off(std::ostream& os)
{
    return os << "\e[0m";
}

int main ()
{
  string first_ch;
  do
  {
  cout<<blue<< bold_on<<"\n\n\tRegister/Login\n\t  1. Register ("<<green<<"press 1"<<blue<<")\n\t  1. Login ("<<green<<"press 2"<<blue<<")\n\n"<< bold_off<<def;
  cin>>first_ch;
  }
  while(!((first_ch[0] - 0 == 49 || first_ch[0] - 0 == 50) && first_ch.size() == 1));

  if(first_ch[0] - 0 == 49)
  {
    user newUser;
    string type;
    do
    {
      cout<<blue<< bold_on<<"\tRegister as -\n\t  1. Employer ("<<green<<"press 1"<<blue<<")\n\t  1. Freelancer ("<<green<<"press 1"<<blue<<")\n\n"<< bold_off<<def;
      cin>>type;
    }
    while(newUser.gettype(type));


    string f_name,l_name,email,city,state,password,c_password;
    string agree;
    string age;
    string contact;
    cout<<blue<< bold_on<<"\nEnter your Details to Register - \n\n"<< bold_off<<def;
    do {
      cout<<blue<< bold_on<<"\tFirst Name - "<< bold_off<<def;
      cin>>f_name;
    } while(newUser.getf_name(f_name));
    do {
      cout<<blue<< bold_on<< bold_on<<"\tLast Name - "<< bold_off<<def;
      cin>>l_name;
    } while(newUser.getl_name(l_name));
    do {
      cout<<blue<< bold_on<<"\tAge - "<< bold_off<<def;
      cin>>age;
    } while(newUser.getage(age));
    do {
      cout<<blue<< bold_on<<"\tEmail id - "<< bold_off<<def;
      cin>>email;
    } while(newUser.getemail(email));
    do {
      cout<<blue<< bold_on<<"\tCity - "<< bold_off<<def;
      cin>>city;
    } while(newUser.getcity(city));
    do {
      cout<<blue<< bold_on<<"\tState - "<< bold_off<<def;
      cin>>state;
    } while(newUser.getstate(state));
    do {
      cout<<blue<< bold_on<<"\tContact - "<< bold_off<<def;
      cin>>contact;
    } while(newUser.getcontact(contact));
    do {
      cout<<blue<< bold_on<<"\tPassword - "<< bold_off<<def;
      SetStdinEcho(false);
      cin>>password;
      SetStdinEcho(true);
      cout<<"\n";
      cout<<blue<< bold_on<<"\tConfirm Password - "<< bold_off<<def;
      SetStdinEcho(false);
      cin>>c_password;
      SetStdinEcho(true);
      cout<<"\n";
    } while(newUser.getpassword(password,c_password));


    cout<<red<<"\n\tTerms and Conditions -\n   1. One email id can be used for one account.\n   2. You can either be Employer or Freelancer.\n"<<def;
    do {
      cout<<green<<"\n Do you agree that all details you entered are Correct (Y/N) - \n"<<def;
      cin>>agree;
    } while(agreecheck(agree));

    if(agree[0] == 'y' || agree[0] == 'Y')
    {

      int error =0;
      ifstream filecheck;
      filecheck.open("details.txt", ios::in);
      readUser checkDetails;
      if(filecheck != NULL)
      {
      while(!filecheck.eof())
      {
        filecheck.read((char*)&checkDetails, sizeof(checkDetails));
        if(!(compareString(newUser.showemail(),checkDetails.email)))
        {
          cout<<"\n   Error : Email id is already taken.\n\n";
          error = 1;
          break;
        }
        if(!(compareString(newUser.showcontact(),checkDetails.contact)))
        {
          cout<<"\n   Error : Phone Number is already taken.\n\n";
          error = 1;
          break;
        }

      }
    }

      if(error==0)
      {
        ofstream fp;

        fp.open("details.txt", ios::app);
        fp.write((char*)&newUser, sizeof(newUser));

        cout<<"\n   User Created Succesfully.\n\n";
      }

    }
  }

  else if(first_ch[0] - 0 == 50)
  {
    string email,password;
    cout<<blue<< bold_on<<"\tEmail id - "<< bold_off<<def;
    cin>>email;
    cout<<blue<< bold_on<<"\tPassword- "<< bold_off<<def;
    SetStdinEcho(false);
    cin>>password;
    SetStdinEcho(true);

    int status=0;

    ifstream filecheck;
    filecheck.open("details.txt", ios::in);
    readUser checkDetails;

    while(!filecheck.eof())
    {
      filecheck.read((char*)&checkDetails, sizeof(checkDetails));
      if(!(compareString(email,checkDetails.email)))
      {

        if(!(compareString(password,checkDetails.password)))
        {
          status =1;
          break;
        }
        else
        {
          status =2;
          cout<<"\n   Error : Password is wrong.\n\n";
          break;
        }

      }

    }
    if(status == 0)
    {
      cout<<"\n   Error : Email is wrong.\n\n";
    }
    if (status ==1)
    {
      int details_choice;
      cout<<"\n\n   Logged in Succesfully.\n";
      cout<<"\n\n   Hello "<<bold_on<<checkDetails.f_name<<bold_off<<",\n";
      cout<<blue<<"\n   Account details - "<<green<<"(Press 1)\n"<<def;
      cout<<blue<<"\n   Edit details - "<<green<<"(Press 2)\n"<<def;
      cout<<blue<<"\n   Reset Password - "<<green<<"(Press 3)\n"<<def;
      cin>>details_choice;



      if(details_choice == 1)
      {
        cout<<bold_on<<"\n\n   Name - "<<bold_off<<checkDetails.f_name<<" "<<checkDetails.l_name<<endl;
        cout<<bold_on<<"\n   Type - "<<bold_off;
        if(checkDetails.type.size() == 8)
        cout<<"Employer\n";
        else
        cout<<"Freelancer\n";
        cout<<bold_on<<"\n   Age - "<<bold_off<<checkDetails.age<<endl;
        cout<<bold_on<<"\n   City - "<<bold_off<<checkDetails.city<<endl;
        cout<<bold_on<<"\n   State - "<<bold_off<<checkDetails.state<<endl<<endl;
      }

      else if(details_choice == 2)
      {
        int edit_no;
        cout<<blue<<"\n   Edit Name - "<<green<<"(Press 1)\n"<<def;
        cin>>edit_no;

        if(edit_no == 1)
        {
          string new_fname,new_lname;
          cout<<blue<<"\n   Enter New First Name - "<<"\n"<<def;
          cin>>new_fname;
          checkDetails.f_name = new_fname;
          cout<<blue<<"\n   Enter New Last Name - "<<"\n"<<def;
          cin>>new_lname;
          checkDetails.l_name = new_lname;

          ofstream fp1;
          fp1.open("newfile.txt", ios::app);
          ifstream fp;
          fp.open("details.txt", ios::in);
          readUser user_new;
          if(fp != NULL)
          {
          while(!fp.eof())
          {
            fp.read((char*)&user_new, sizeof(user_new));
            if(!(compareString(user_new.email,checkDetails.email)))
            {
              fp1.write((char*)&checkDetails, sizeof(checkDetails));
            }
            else
            {
              fp1.write((char*)&user_new, sizeof(user_new));
            }

          }
        }

        remove("details.txt");
        rename("newfile.txt", "details.txt");
        }
      }

      else if(details_choice == 3)
      {
        string new_pass,new_cpass;
        do{
          cout<<blue<<"\n   Enter New password - "<<"\n"<<def;
          SetStdinEcho(false);
          cin>>new_pass;
          SetStdinEcho(true);
          cout<<blue<<"\n   Confirm new password - "<<"\n"<<def;
          SetStdinEcho(false);
          cin>>new_cpass;
          SetStdinEcho(true);
        }while((compareString(new_pass,new_cpass)));

          checkDetails.password = new_pass;

          ofstream fp1;
          fp1.open("newfile.txt", ios::app);
          ifstream fp;
          fp.open("details.txt", ios::in);
          readUser user_new;
          if(fp != NULL)
          {
          while(!fp.eof())
          {
            fp.read((char*)&user_new, sizeof(user_new));
            if(!(compareString(user_new.email,checkDetails.email)))
            {
              fp1.write((char*)&checkDetails, sizeof(checkDetails));
            }
            else
            {
              fp1.write((char*)&user_new, sizeof(user_new));
            }

          }
        }

        remove("details.txt");
        rename("newfile.txt", "details.txt");
        }
      }




  }


return 0;
}
