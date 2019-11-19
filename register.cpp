#include<iostream>
#include<fstream>
using namespace std;

int main ()
{
  cout<<"\n\n\t\tRegister/Login\n\nType 'r' for register and 'l' for login\n\n";
  char first_ch;
  cin>>first_ch;
  if(first_ch == 'r')
  {
    string f_name,l_name,email,city,state,password,c_password;
    string type,agree;
    int age;
    long long contact;
    int error=0;
    cout<<"Enter your Details to Register - \n\n";
    cout<<"First Name - ";
    cin>>f_name;
    cout<<"Last Name - ";
    cin>>l_name;
    cout<<"Age - ";
    cin>>age;
    cout<<"Email id - ";
    cin>>email;
    cout<<"City - ";
    cin>>city;
    cout<<"State - ";
    cin>>state;
    cout<<"Contact No. - ";
    cin>>contact;
    cout<<"What are you - Employer/Freelancer\nPress 'e' for Employer and 'f' for Freelancer - ";
    cin>>type;
    cout<<"Password - ";
    cin>>password;
    cout<<"Confirm Password - ";
    cin>>c_password;
    cout<<"\t\tTerms and Conditions -\n1. One email id can be used for one account.\n2. You can either be Employer or Freelancer.\n";
    cout<<"Do you agree that all details you entered are Correct (Y/N) - \n";
    cin>>agree;
    if(agree[0] == 'y' || agree[0] == 'Y')
    {
      for(int i=0;i<f_name.size();i++)
      {
        if(!((f_name[i] -0 >= 65 && f_name[i]-0<=90) ||(f_name[i] -0 >= 97 && f_name[i]-0<=122)))
          {
            cout<<"\nError : First Name can contain only alphabets.\n";
            break;
            error =1;
          }
      }
      for(int i=0;i<l_name.size();i++)
      {
        if(!((l_name[i] -0 >= 65 && l_name[i]-0<=90) ||(l_name[i] -0 >= 97 && l_name[i]-0<=122)))
          {
            cout<<"\nError : Last Name can contain only alphabets.\n";
            break;
            error =1;
          }
      }
      if(age >=85)
      {
        cout<<"\nError : Age can be less than 85.\n";
        error =1;
      }
      if(!(contact >=1000000000 && contact<=9999999999))
      {
        cout<<"\nError : Contact Number is invalid.\n";
        error =1;
      }

      if( password != c_password)
      {
        cout<<"\nError : Password doesn't matches in entries.\n";
        error =1;
      }


      if(error == 0)
      {
        FILE *fp;

        if(type[0] - 0== 69 || type[0] - 0 == 101 )
        {
          fp = fopen ("Employer_List.txt","a");
          fwrite(&f_name,f_name.size()+1,1,fp );
          fprintf(fp," ");
          fwrite(&l_name,l_name.size()+1,1,fp );
          fprintf(fp," ");
          fprintf(fp,"%d ",age);
          fwrite(&email,email.size()+1,1,fp );
          fprintf(fp," ");
          fwrite(&city,city.size()+1,1,fp );
          fprintf(fp," ");
          fwrite(&state,state.size()+1,1,fp );
          fprintf(fp," ");
          // fwrite(&contact,sizeof(long long),1,fp );
          // fwrite(&password,sizeof(password),1,fp );
          // fprintf(fp,"\t");
        }


        cout<<"\nUser Created Succesfully.\n\n";
        fclose(fp);
      }
    }

    }
  else
  {
    cout<<"login\n";
  }
}
