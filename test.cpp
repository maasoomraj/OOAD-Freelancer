#include "sf/header/password.h"
#include "sf/header/stdc.h"
#include "sf/header/user.h"
#include "sf/header/class_call.h"
#include "sf/header/job.h"
#include "sf/header/function.h"
#include "sf/header/color.h"
#include "sf/header/bid.h"
using namespace std;



int main ()
{
  systemClear();
  int status=0;
  readUser checkDetails;
  ifstream f_curr;
  int run =0;
  f_curr.open("sf/User/currentUser.txt", ios::in);
  if(f_curr !=NULL)
  {
    run =1;
  }

  if(run ==0)
  {
    start:
    systemClear();
  string first_ch;
  do
  {
  cout<<blue<< bold_on<<"\n\n\tRegister/Login\n\t  1. Register ("<<green<<"press 1"<<blue<<")\n\t  2. Login ("<<green<<"press 2"<<blue<<")\n\n"<< bold_off<<def;
  cin>>first_ch;
  }
  while(!((first_ch[0] - 0 == 49 || first_ch[0] - 0 == 50) && first_ch.size() == 1));


  //REGISTER CODE START -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-
  if(first_ch[0] - 0 == 49)
  {
    systemClear();
    user newUser;
    string type;
    do
    {
      cout<<blue<< bold_on<<"\n\n\tRegister as -\n\t  1. Employer ("<<green<<"press 1"<<blue<<")\n\t  2. Freelancer ("<<green<<"press 2"<<blue<<")\n\n"<< bold_off<<def;
      cin>>type;
    }
    while(newUser.gettype(type));


    string f_name,l_name,email,city,state,password,c_password;
    string agree;
    string age;
    string contact;
    systemClear();
    cout<<blue<< bold_on<<"\n\n\tEnter your Details to Register - \n\n"<< bold_off<<def;
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

        fp.open("sf/User/details.txt", ios::app);
        fp.write((char*)&newUser, sizeof(newUser));

        cout<<"\n   User Created Succesfully.\n\nPlease wait, you will be redirected to login page.\n\n";

        string mail_system = "neomutt -s \"Succesfully Registered from Freelancing Portal\" "+newUser.showemail()+" < sf/Mail/register_mail.txt";
        const char *command = mail_system.c_str();
        system(command);

        // remove("sf/Mail/register_mail.txt");


        goto start;
      }

    }
  }
  //REGISTER CODE START -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-


  //LOGIN CODE START -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-
  else if(first_ch[0] - 0 == 50)
  {
    systemClear();
    string email,password;
    cout<<blue<< bold_on<<"\n\n\tEmail id - "<< bold_off<<def;
    cin>>email;
    cout<<blue<< bold_on<<"\tPassword- "<< bold_off<<def;
    SetStdinEcho(false);
    cin>>password;
    SetStdinEcho(true);

    ifstream filecheck;
    filecheck.open("sf/User/details.txt", ios::in);

    while(!filecheck.eof())
    {
      filecheck.read((char*)&checkDetails, sizeof(checkDetails));
      if(!(compareString(email,checkDetails.email)))
      {

        if(!(compareString(password,checkDetails.password)))
        {
          status =1;
          ofstream fp1;
          fp1.open("sf/User/currentUser.txt", ios::out);
          fp1.write((char*)&checkDetails, sizeof(checkDetails));
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
  }
}//LOGIN CODE END -
else
{
  status = 1;
  f_curr.read((char*)&checkDetails, sizeof(checkDetails));
}

    // goto next;
    // curr_usr :
    // f_curr.read((char*)&checkDetails, sizeof(checkDetails));
    // next :


    //LOGGED IN SUCCESSFULLY -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-
    first_page:
    if (status ==1)
    {
      systemClear();
      int details_choice;
      cout<<endl;
      header(checkDetails.f_name + " " +checkDetails.l_name);
      cout<<blue<<"\n   Account details - "<<green<<"(Press 1)\n"<<def;
      cout<<blue<<"\n   Edit details - "<<green<<"(Press 2)\n"<<def;
      cout<<blue<<"\n   Reset Password - "<<green<<"(Press 3)\n"<<def;
      if(checkDetails.type.size() == 8)
      {
        cout<<blue<<"\n   Create a Job - "<<green<<"(Press 4)\n"<<def;
      }
      else
      {
        cout<<blue<<"\n   Create a bid - "<<green<<"(Press 4)\n"<<def;
      }
      cout<<blue<<"\n   Check Available Jobs - "<<green<<"(Press 5)\n"<<def;
      cout<<blue<<"\n   Search Job by JobId - "<<green<<"(Press 6)\n"<<def;
      if(checkDetails.type.size() == 8)
      {
        cout<<blue<<"\n   View my Created Jobs - "<<green<<"(Press 7)\n"<<def;
      }
      else
      {
        cout<<blue<<"\n   View my Bids - "<<green<<"(Press 7)\n"<<def;
      }
      if(checkDetails.type.size() == 8)
      {
        cout<<blue<<"\n   View Bids on my Jobs - "<<green<<"(Press 8)\n"<<def;
      }
      else
      {
        cout<<blue<<"\n   View my Accepted Bids - "<<green<<"(Press 8)\n"<<def;
      }
      if(checkDetails.type.size() == 8)
      {
        cout<<blue<<"\n   Select a bid - "<<green<<"(Press 9)\n"<<def;
      }
      else
      {
        cout<<blue<<"\n   View my Accepted Bids - "<<green<<"(Press 9)\n"<<def;
      }
      choice();
      cin>>details_choice;
      if(details_choice == 0)
      {
        remove("sf/User/currentUser.txt");
        systemClear();
        return 0;
      }


      //ACCOUNT DETAILS CODE START -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-
      if(details_choice == 1)
      {
        systemClear();
        cout<<bold_on<<"\n\n   Name - "<<bold_off<<checkDetails.f_name<<" "<<checkDetails.l_name<<endl;
        cout<<bold_on<<"\n   Type - "<<bold_off;
        if(checkDetails.type.size() == 8)
        cout<<"Employer\n";
        else
        cout<<"Freelancer\n";
        cout<<bold_on<<"\n   Age - "<<bold_off<<checkDetails.age<<endl;
        cout<<bold_on<<"\n   City - "<<bold_off<<checkDetails.city<<endl;
        cout<<bold_on<<"\n   State - "<<bold_off<<checkDetails.state<<endl<<endl;
        string randomstr;
        cout<<red<<"\n\nPress any key to go to menu."<<def;
        cin>>randomstr;
        if(randomstr[0] -0>=1)
        goto first_page;
      }
      //ACCOUNT DETAILS CODE START -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-


      //EDIT DETAILS CODE START -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-
      else if(details_choice == 2)
      {
        systemClear();
        int edit_no;
        cout<<blue<<"\n\n   Edit Name - "<<green<<"(Press 1)\n"<<def;
        choice();
        cin>>edit_no;

        if(edit_no == 1)
        {
          systemClear();
          string new_fname,new_lname;
          cout<<blue<<"\n\n   Enter New First Name - "<<"\n"<<def;
          space();
          cin>>new_fname;
          checkDetails.f_name = new_fname;
          cout<<blue<<"\n   Enter New Last Name - "<<"\n"<<def;
          space();
          cin>>new_lname;
          checkDetails.l_name = new_lname;

          ofstream fp1;
          fp1.open("sf/User/newfile.txt", ios::app);
          ifstream fp;
          fp.open("sf/User/details.txt", ios::in);
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

        remove("sf/User/details.txt");
        rename("sf/User/newfile.txt", "sf/User/details.txt");
        goto first_page;
        }
      }
      //EDIT DETAILS CODE END -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-



      // REST PASSWORD CODE START -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-
      else if(details_choice == 3)
      {
        systemClear();
        string new_pass,new_cpass;
        do{
          cout<<blue<<"\n   Enter New password - "<<"\n"<<def;
          space();
          SetStdinEcho(false);
          cin>>new_pass;
          SetStdinEcho(true);
          cout<<blue<<"\n   Confirm new password - "<<"\n"<<def;
          space();
          SetStdinEcho(false);
          cin>>new_cpass;
          SetStdinEcho(true);
        }while((compareString(new_pass,new_cpass)));

          checkDetails.password = new_pass;

          ofstream fp1;
          fp1.open("sf/User/newfile.txt", ios::app);
          ifstream fp;
          fp.open("sf/User/details.txt", ios::in);
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

        remove("sf/User/details.txt");
        rename("sf/User/newfile.txt", "sf/User/details.txt");
        goto start;
        }
        //RESET PASSWORD CODE END -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-

        // CREATE JOB (employer) CODE START -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-
        else if(details_choice == 4 && (checkDetails.type.size() == 8))
        {


          string s;
          char ch;
          cout<<endl<<"Do you want to create a job?   (Y/N)";
          choice();
          cin>>ch;
          if(ch=='Y'||ch=='y')
          {
              Job j;
              j.get_email(checkDetails.email);
              cout<<endl<<"Enterjob title"<<endl;
              space();
              cin>>s;
              j.get_title(s);
              cout<<endl<<"Enter job decription"<<endl;
              space();
              cin>>s;
              j.get_description(s);
              cout<<endl<<"Enter amount to be paid for this job"<<endl;
              do
              {
                space();
                  cin>>s;
              }
              while(j.get_price(s)==0);
              cout<<endl<<"Enter deadline in ddmmyy format"<<endl;
              do
              {
                space();
                 cin>>s;
              }
              while(j.get_deadline(s)==0);
              cout<<endl<<"Are you sure you want to continue : (y/n)"<<endl;
              choice();
              cin>>ch;
              if(ch=='y' || ch=='Y')
              {
                j.IsTaken();
              //Need to make a file and increment job no everytime.

              ofstream f1;
              ifstream f;
              f.open("sf/Job/Job_No.txt", ios::in);
              char ch;
              int x;
              JobNo jobno;
              if(f != NULL)
              {
                f.read((char*)&jobno, sizeof(jobno));
                jobno.JobNo +=1;
                f1.open("sf/Job/Job_No.txt", ios::out);
                f1.write((char*)&jobno, sizeof(jobno));
              }
              else
              {
                jobno.JobNo =1;
                f1.open("sf/Job/Job_No.txt", ios::out);
                f1.write((char*)&jobno, sizeof(jobno));
              }
              //Need to make individual files with seperate job no.
              stringstream sso;
              sso<<jobno.JobNo;
              string number_job;
              sso>>number_job;
              string jobid = "Job"+number_job;

              j.get_JobId(jobid);

              ifstream file_job_create;
              file_job_create.open("sf/Job/jobs_file/"+ jobid, ios::app);

              ofstream fp;

              fp.open("sf/Job/Job.txt", ios::app);
              fp.write((char*)&j, sizeof(j));



              cout<<"Job Id : "<<bold_on<<jobid<< bold_off<<" Created Succesfully."<<endl<<endl;
              // goto first_page;
              }
              else
              {
                  return 0;
              }


          }



        }
        // CREATE JOB (employer) CODE END -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-

      else if(details_choice == 4 && (checkDetails.type.size() == 10))
      {
        string s, currentJob;
        char ch;
        cout<<endl<<"Do you want to create a Bid?   (Y/N)";
        cin>>ch;
        if(ch=='Y'||ch=='y')
        {
            Bid b;
            cout<<endl<<"Enter the jobID of the Job you want to Bin on";
            cin>>s;
            currentJob = s;
            // Put condition to check if such a job ID exits
            b.get_jobID(s);
            cout<<endl<<"Enter your email again"<<endl;
            cin>>s;
            b.get_email(s);
            cout<<endl<<"Enter Bid decription"<<endl;
            cin>>s;
            b.get_description(s);
            cout<<endl<<"Enter amount willing to take for this Job"<<endl;
            do
            {
                cin>>s;
            }
            while(b.get_amount(s)==0);
            cout<<endl<<"Are you sure you want to continue"<<endl;
            cin>>ch;
            if(ch=='y' || ch=='Y')
            {
                ofstream f;
                f.open("sf/Job/jobs_file/"+currentJob,ios::app); // Open file with the current jobNo...eg Job1.txt
                if(f)
                {
                    f.write((char*)&b, sizeof(b));
                }
                ofstream p;
                p.open("sf/Bid/Bid.txt",ios::app);
                if(p)
                {
                    p.write((char*)&b, sizeof(b));
                }
                cout<<"\n Bid Created Succesfully.\n";
            }
            else
            {
                return 0;
            }
        }
      }

        // CHECK AVAILBALE JOB (freelancer) CODE START -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-
        else if(details_choice == 5)
        {
          systemClear();
          ifstream filecheck;
          filecheck.open("sf/Job/Job.txt", ios::in);
          Job1 job_class;
          if(filecheck != NULL)
          {
          while(!filecheck.eof())
          {
            filecheck.read((char*)&job_class, sizeof(job_class));
            if(!(compareString("0",job_class.isApproved)))
            {
              if(!(compareString("0",job_class.isTaken)))
              {
              cout<<"\nJob  -  "<<bold_on<<job_class.JobId<<bold_off<<" : "<<job_class.title<<"\n\n";
              }
            }
            }
          }
        }
        // CHECK AVAILBALE JOB (freelancer) CODE END -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-

        //SEARCH BY JOB_ID CODE STARTED ----
        else if(details_choice == 6)
        {
          systemClear();
          string s_input;
          cout<<"\n\n\t Enter Job Id : ";
          cin>>s_input;

          ifstream fp_1;
          fp_1.open("sf/Job/Job.txt", ios::in);
          Job1 job_search;

          while(!fp_1.eof())
          {
            fp_1.read((char*)&job_search, sizeof(job_search));
            if(!(compareString(s_input,job_search.JobId)))
            {
              cout<<"\n\n   Title : "<<job_search.title;
              cout<<"\n\n   Description : "<<job_search.description;
              cout<<"\n\n   Created by : "<<job_search.email;
              cout<<"\n\n   Price : "<<job_search.price;
              cout<<"\n\n   Deadline : "<<job_search.deadline<<endl<<endl;
              break;
            }
          }
        }
        //SEARCH BY JOB_ID CODE ENDED ----

        //VIEW MY JOBS CODE STARTED -----
        else if(details_choice == 7 && (checkDetails.type.size() == 8))
        {
          systemClear();
          ifstream filecheck;
          filecheck.open("sf/Job/Job.txt", ios::in);
          Job1 job_class;
          if(filecheck != NULL)
          {
          while(!filecheck.eof())
          {
            filecheck.read((char*)&job_class, sizeof(job_class));
            if(!(compareString("0",job_class.isApproved)))
              {
                if(!(compareString("0",job_class.isTaken)))
                {
                  if(!(compareString(checkDetails.email,job_class.email)))
                    cout<<"\nJob  -  "<<bold_on<<job_class.JobId<<bold_off<<" : "<<job_class.title<<"\n\n";
                }
              }
            }
          }
        }
        //VIEW MY JOBS CODE ENDED -----


        //VIEW MY BIDS CODE STARTED -----
        else if(details_choice == 7 && (checkDetails.type.size() == 10))
        {
          systemClear();
          ifstream filecheck;
          filecheck.open("sf/Bid/Bid.txt", ios::in);
          Bid1 bid_class;
          if(filecheck != NULL)
          {
          while(!filecheck.eof())
          {
            filecheck.read((char*)&bid_class, sizeof(bid_class));
            if(!(compareString(checkDetails.email,bid_class.email)))
              {
                cout<<"\n   Bid on JobID : "+bid_class.jobID<<"\t"<<bold_on<<"Status : "<<bold_off;
                // if(bid_class.accepted == true)
                if(!(compareString(bid_class.isAccepted,"2")))
                {
                  cout<<green<<bold_on<<"ACCEPTED\n\n"<<bold_off<<def;
                }
                else if(!(compareString(bid_class.isAccepted,"1")))
                {
                  cout<<red<<bold_on<<"REJECTED\n\n"<<bold_off<<def;
                }
                else
                {
                  cout<<bold_on<<"PENDING\n\n"<<bold_off;
                }
              }
            }
          }
        }
        //VIEW MY BIDS CODE ENDED -----



        //VIEW BIDS ON JOB CODE START -----
        else if(details_choice == 8 && (checkDetails.type.size() == 8))
        {
          systemClear();
          string s_input;
          cout<<"\n\n\t Enter Job Id : ";
          cin>>s_input;

          ifstream filecheck;
          filecheck.open("sf/Job/jobs_file/"+s_input, ios::in);
          Bid1 bid_class;
          if(filecheck != NULL)
          {
          while(!filecheck.eof())
          {
            filecheck.read((char*)&bid_class, sizeof(bid_class));

            cout<<"\nBid  -  "<<bold_on<<bid_class.email<<bold_off<<" : "<<bid_class.amount<<"\n\n";

            }
          }
        }
        //VIEW BIDS ON JOB CODE START -----


        //VIEW MY ACCEPTED BIDS CODE STARTED -----
        else if(details_choice == 8 && (checkDetails.type.size() == 10))
        {
          systemClear();
          ifstream filecheck;
          filecheck.open("sf/Bid/Bid.txt", ios::in);
          Bid1 bid_class;
          if(filecheck != NULL)
          {
          while(!filecheck.eof())
          {
            filecheck.read((char*)&bid_class, sizeof(bid_class));
            if(!(compareString(checkDetails.email,bid_class.email)))
              {
                if(!(compareString(bid_class.isAccepted,"2")))
                {
                  cout<<"\n   Bid on JobID : "+bid_class.jobID<<"\t"<<bold_on<<"Status : "<<bold_off;
                  cout<<green<<bold_on<<"ACCEPTED\n\n"<<bold_off<<def;
                }
              }
            }
          }
        }
        //VIEW MY ACCEPTED BIDS CODE ENDED -----


      }



return 0;
}
