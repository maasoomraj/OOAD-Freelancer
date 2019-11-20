#include<iostream>
#include<fstream>
#include<string>
#include "password.h"
using namespace std;

class user
{
private:
  string f_name,l_name,age,email,city,state,contact,password;
   // age, email, city, state, contact, password;
public:
  int getf_name(string c)
  {
    for(int i=0;i<c.size();i++)
    {
      if(!((c[i] -0 >= 65 && c[i]-0<=90) ||(c[i] -0 >= 97 && c[i]-0<=122)))
        {
          cout<<"\nError : First Name can contain only alphabets.\n\n";
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
          cout<<"\nError : Last Name can contain only alphabets.\n\n";
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
          cout<<"\nError : Age can contain only numbers.\n\n";
          return 1;
        }
    }

    if(c.size()>2)
    {
      cout<<"\nError : Age can be less than 99.\n\n";
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
      cout<<"\nError : Enter valid email address.\n\n";
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
          cout<<"\nError : City can contain only alphabets.\n\n";
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
          cout<<"\nError : State can contain only alphabets.\n\n";
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
          cout<<"\nError : Contact can contain only numbers.\n\n";
          return 1;
        }
    }

    if(c.size()!=10)
    {
      cout<<"\nError : Contact Number is invalid.\n\n";
      return 1;
    }
    contact =c;
    return 0;
  }
  int getpassword(string c1, string c2)
  {
    if(c1.size() != c2.size())
    {
      cout<<"\nPassword doesnot matches.\n\n";
      return 1;
    }
    for(int i=0;i<c1.size();i++)
    {
      if(c1[i] != c2[i])
      {
        cout<<"\nPassword doesnot matches.\n\n";
        return 1;
      }
    }
    password = c1;
    return 0;
  }
};

int main ()
{

  user newUser;
  cout<<"\n\n\t\tRegister/Login\n\nType 'r' for register and 'l' for login\n\n";
  char first_ch;
  cin>>first_ch;
  if(first_ch == 'r')
  {
    string f_name,l_name,email,city,state,password,c_password;
    string type,agree;
    string age;
    string contact;
    int error=0;
    cout<<"Enter your Details to Register - \n\n";
    do {
      cout<<"First Name - ";
      cin>>f_name;
    } while(newUser.getf_name(f_name));
    do {
      cout<<"Last Name - ";
      cin>>l_name;
    } while(newUser.getl_name(l_name));
    do {
      cout<<"Age - ";
      cin>>age;
    } while(newUser.getage(age));
    do {
      cout<<"Email id - ";
      cin>>email;
    } while(newUser.getemail(email));
    do {
      cout<<"City - ";
      cin>>city;
    } while(newUser.getcity(city));
    do {
      cout<<"State - ";
      cin>>state;
    } while(newUser.getstate(state));
    do {
      cout<<"Contact - ";
      cin>>contact;
    } while(newUser.getcontact(contact));
    do {
      cout<<"Password - ";
      SetStdinEcho(false);
      cin>>password;
      SetStdinEcho(true);
      cout<<"\n";
      cout<<"Confirm Password - ";
      SetStdinEcho(false);
      cin>>c_password;
      SetStdinEcho(true);
      cout<<"\n";
    } while(newUser.getpassword(password,c_password));
    // type :
    // cout<<"What are you - Employer/Freelancer\nPress 'e' for Employer and 'f' for Freelancer - ";
    // cin>>type;
    // if(!(type[0] - 0 == 69 || type[0] - 0 == 70 || type[0] - 0 == 101 || type[0] - 0 == 102))
    // {
    //   cout<<"\nError : You can enter only 'e' and 'f'.\n\n";
    //   goto type;
    // }
    // if(type.size() != 1)
    // {
    //   cout<<"\nError : You can enter only 'e' and 'f'.\n\n";
    //   goto type;
    // }
    // cout<<"Password - ";
    // cin>>password;
    // cout<<"Confirm Password - ";
    // cin>>c_password;
    // cout<<"\t\tTerms and Conditions -\n1. One email id can be used for one account.\n2. You can either be Employer or Freelancer.\n";
    // cout<<"Do you agree that all details you entered are Correct (Y/N) - \n";
    // cin>>agree;
    // if(agree[0] == 'y' || agree[0] == 'Y')
    // {
    //   for(int i=0;i<l_name.size();i++)
    //   {
    //     if(!((l_name[i] -0 >= 65 && l_name[i]-0<=90) ||(l_name[i] -0 >= 97 && l_name[i]-0<=122)))
    //       {
    //         cout<<"\nError : Last Name can contain only alphabets.\n";
    //         break;
    //         error =1;
    //       }
    //   }
    //   if(age >=85)
    //   {
    //     cout<<"\nError : Age can be less than 85.\n";
    //     error =1;
    //   }
    //   if(!(contact >=1000000000 && contact<=9999999999))
    //   {
    //     cout<<"\nError : Contact Number is invalid.\n";
    //     error =1;
    //   }
    //
    //   if( password != c_password)
    //   {
    //     cout<<"\nError : Password doesn't matches in entries.\n";
    //     error =1;
    //   }


      // if(error == 0)
      // {
      //   FILE *fp,*fp1;
      //
      //   if(type[0] - 0== 69 || type[0] - 0 == 101 )
      //   {
      //     fp = fopen ("Employer_List.txt","a");
      //   }
      //   else if (type[0] - 0== 70 || type[0] - 0 == 102 )
      //   {
      //     fp = fopen ("Freelancer_List.txt","a");
      //   }
      //     fwrite(&f_name,f_name.size()+1,1,fp );
      //     fprintf(fp," ");
      //     fwrite(&l_name,l_name.size()+1,1,fp );
      //     fprintf(fp," ");
      //     fprintf(fp,"%d ",age);
      //     fwrite(&email,email.size()+1,1,fp );
      //     fprintf(fp," ");
      //     fwrite(&city,city.size()+1,1,fp );
      //     fprintf(fp," ");
      //     fwrite(&state,state.size()+1,1,fp );
      //     fprintf(fp," ");
      //     // fwrite(&contact,sizeof(long long),1,fp );
      //     // fwrite(&password,sizeof(password),1,fp );
      //     // fprintf(fp,"\t");
      //
      //
      //   cout<<"\nUser Created Succesfully.\n\n";
      //   fclose(fp);
      //
      //   // fp1 = fopen ("Freelancer_List.txt","r");
      //   //
      //   // string name;
      //   // fscanf(fp1,"%s",&name);
      //   // cout<<name;
      //   // fclose(fp1);
      // }
  //   }
  //
    }
  // else
  // {
  //   cout<<"login\n";
  // }

// end:
return 0;
}
