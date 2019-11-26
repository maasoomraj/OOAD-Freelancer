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
    main_header();
  cout<<blue<< bold_on<<"\n\n\tRegister/Login\n\t  1. Register ("<<green<<"press 1"<<blue<<")\n\t  2. Login ("<<green<<"press 2"<<blue<<")"<<"\n\t  3. Forgot Password ("<<green<<"press 3"<<blue<<")\n\n"<< bold_off<<def;
  choice();
  cin>>first_ch;
  }
  while(!((first_ch[0] - 0 >= 49 && first_ch[0] - 0 <= 51) && first_ch.size() == 1));


  //REGISTER CODE START -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-
  if(first_ch[0] - 0 == 49)
  {
    systemClear();
    main_header();
    user newUser;
    string type;
    do
    {

      cout<<blue<< bold_on<<"\n\n\tRegister as -\n\t  1. Employer ("<<green<<"press 1"<<blue<<")\n\t  2. Freelancer ("<<green<<"press 2"<<blue<<")\n\n"<< bold_off<<def;
      choice();
      cin>>type;
    }
    while(newUser.gettype(type));


    string f_name,l_name,email,city,state,password,c_password;
    string agree;
    string age;
    string contact;
    systemClear();
    main_header();
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
    string new_pass,new_cpass;
    do {
      cout<<blue<< bold_on<<"\tPassword - "<< bold_off<<def;
      SetStdinEcho(false);
      cin>>new_pass;
      SetStdinEcho(true);
      cout<<"\n";
      cout<<blue<< bold_on<<"\tConfirm Password - "<< bold_off<<def;
      SetStdinEcho(false);
      cin>>new_cpass;
      SetStdinEcho(true);
      cout<<"\n";
    }while((compareString(new_pass,new_cpass)));
    newUser.getpassword(new_pass,new_cpass);


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
    main_header();
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
  //LOGIN CODE END -



  //RESET PASSWORD CODE ENDED --
  if(first_ch[0] - 0 == 51)
  {
    systemClear();
    main_header();
    string email;
    cout<<"\n\n   Enter Your email id - ";
    space();
    cin>>email;



    ifstream f;
    f.open("sf/forgot_pass/forgot_no.txt");
    ofstream f1;
    f1.open("sf/forgot_pass/forgot_no1.txt");
    int n=0;
    if(f)
    {
      f>>n;
      f1<<n+1;
    }
    else
    {
      f1<<n;
    }
    f.close();
    f1.close();

    remove("sf/forgot_pass/forgot_no.txt");
    rename("sf/forgot_pass/forgot_no1.txt","sf/forgot_pass/forgot_no.txt");
    ifstream fp;
    fp.open("sf/forgot_pass/check.txt",ios::in);
    string s;
    int m = n%20;
    while(m--)
    {
      fp.read((char*)&s, sizeof(std::string));
    }
    fp.read((char*)&s, sizeof(std::string));


    string mail  = "Hello User,\n\nYour verification code is "+ s+" .";
    ofstream file;
    file.open ("sf/forgot_pass/mail_code.txt");
    file << mail;
    file.close();
    string mail_system = "neomutt -s \"Request for Password Reset\" "+email+" < sf/forgot_pass/mail_code.txt";

    const char *command = mail_system.c_str();
    system(command);

    systemClear();
    main_header();

    string verification_code;

    for(int i=3;i>0;i--)
    {
      if(i!=3)
      cout<<"   Only "<<i<<" chances Available.\n\n";
      cout<<"\n\n   Enter the code -";
      cin>>verification_code;
      if(!(compareString(s,verification_code)))
      {
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
          if(!(compareString(user_new.email,email)))
          {
            string new_cpass;
            string new_pass;

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

            user_new.password = new_pass;


            fp1.write((char*)&user_new, sizeof(user_new));
          }
          else
          {
            fp1.write((char*)&user_new, sizeof(user_new));
          }

        }
      }

      remove("sf/User/details.txt");
      rename("sf/User/newfile.txt", "sf/User/details.txt");


        string mail  = "Hello User,\n\nYour Password was reset Succesfully .";
        ofstream file;
        file.open ("sf/forgot_pass/mail_true_code.txt");
        file << mail;
        file.close();
        string mail_system = "neomutt -s \"Password Reset Succesfully\" "+email+" < sf/forgot_pass/mail_true_code.txt";

        const char *command = mail_system.c_str();
        system(command);
        goto start;
      }
      else
      {
        cout<<"Wrong Code";
      }
    }
    systemClear();
    goto start;



  }
  //RESET PASSWORD CODE ENDED --


}

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
        cout<<blue<<"\n   Delete a Job - "<<green<<"(Press 10)\n"<<def;

      }

      choice();
      cin>>details_choice;
      if(details_choice == 0)
      {
        remove("sf/User/currentUser.txt");
        systemClear();
        goto start;
      }

      else if(details_choice == -1)
      {
        systemClear();
        return 0;
      }


      //ACCOUNT DETAILS CODE START -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-
      if(details_choice == 1)
      {
        systemClear();
        page_header(checkDetails.f_name + " " +checkDetails.l_name);
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

        //PRESS ENTER TO CONTINUE ----
        std::cout <<red<< "\n   Press Enter to continue. "<<def;
        fgetc(stdin);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //PRESS ENTER TO CONTINUE ----

        goto first_page;
      }
      //ACCOUNT DETAILS CODE START -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-


      //EDIT DETAILS CODE START -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-
      else if(details_choice == 2)
      {
        systemClear();
        page_header(checkDetails.f_name + " " +checkDetails.l_name);
        int edit_no;
        cout<<blue<<"\n\n   Edit Name - "<<green<<"(Press 1)\n"<<def;
        choice();
        cin>>edit_no;

        if(edit_no == 1)
        {
          systemClear();
          page_header(checkDetails.f_name + " " +checkDetails.l_name);
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

        //PRESS ENTER TO CONTINUE ----
        std::cout <<red<< "\n   Press Enter to continue. "<<def;
        fgetc(stdin);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //PRESS ENTER TO CONTINUE ----

        goto first_page;
        }
      }
      //EDIT DETAILS CODE END -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-



      // REST PASSWORD CODE START -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-
      else if(details_choice == 3)
      {
        systemClear();
        page_header(checkDetails.f_name + " " +checkDetails.l_name);
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

        //PRESS ENTER TO CONTINUE ----
        std::cout <<red<< "\n   Press Enter to continue. "<<def;
        fgetc(stdin);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //PRESS ENTER TO CONTINUE ----

        goto start;
        }
        //RESET PASSWORD CODE END -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-

        // CREATE JOB (employer) CODE START -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-
        else if(details_choice == 4 && (checkDetails.type.size() == 8))
        {
          systemClear();
          page_header(checkDetails.f_name + " " +checkDetails.l_name);
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
              file_job_create.open("sf/Job/jobs_file/"+ jobid+".txt", ios::app);

              ofstream fp;

              fp.open("sf/Job/Job.txt", ios::app);
              fp.write((char*)&j, sizeof(j));



              cout<<"Job Id : "<<bold_on<<jobid<< bold_off<<" Created Succesfully."<<endl<<endl;

              string mail  = "Hello "+checkDetails.email+",\n\nYou just created a Job with Job ID : "+j.show_job()+" .\n For future refrences, the details of job are here - \n   Job ID : "+j.show_job()+"\n   Title : "+j.show_title()+"\n   Description : "+j.show_description()+"\n   Price : "+j.show_price()+"\n   Deadline : "+j.show_deadline()+"\n\nPlease login to check more.\n\n  Regards,\n  Freelancing Portal.";
              ofstream file;
              file.open ("sf/Mail/Rejectedmail.txt");
              file << mail;
              file.close();
              string mail_system = "neomutt -s \"Reg. Created a Job\" "+checkDetails.email+" < sf/Mail/Rejectedmail.txt";

              const char *command = mail_system.c_str();
              system(command);

              //PRESS ENTER TO CONTINUE ----
              std::cout <<red<< "\n   Press Enter to continue. "<<def;
              fgetc(stdin);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              //PRESS ENTER TO CONTINUE ----
              goto first_page;
              // goto first_page;
              }
              else
              {
                //PRESS ENTER TO CONTINUE ----
                std::cout <<red<< "\n   Press Enter to continue. "<<def;
                fgetc(stdin);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                //PRESS ENTER TO CONTINUE ----
                goto first_page;
              }
          }



        }
        // CREATE JOB (employer) CODE END -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-

      else if(details_choice == 4 && (checkDetails.type.size() == 10))
      {
        systemClear();
        page_header(checkDetails.f_name + " " +checkDetails.l_name);
        string s, currentJob;
        char ch;
        cout<<endl<<"Do you want to create a Bid? (Y/N)";
        space();
        cin>>ch;
        if(ch=='Y'||ch=='y')
        {
            Bid b;
            cout<<endl<<"Enter the Job ID of the Job you want to Bin on :";
            space();
            cin>>s;
            currentJob = s;
            // Put condition to check if such a job ID exits
            b.get_jobID(s);
            cout<<endl<<"Enter your email again : "<<endl;
            space();
            cin>>s;
            b.get_email(s);
            cout<<endl<<"Enter Bid decription : "<<endl;
            space();
            cin>>s;
            b.get_description(s);
            cout<<endl<<"Enter amount willing to take for this Job : "<<endl;
            space();
            do
            {
                cin>>s;
            }
            while(b.get_amount(s)==0);
            cout<<endl<<bold_on<<"Are you sure you want to continue : (Y/N)"<<bold_off<<endl;
            space();
            cin>>ch;
            if(ch=='y' || ch=='Y')
            {

                ifstream f_if;
                f_if.open("sf/Bid/bid_no.txt");
                ofstream f_of;
                f_of.open("sf/Bid/bid_no1.txt");
                int n=1;
                if(f_if)
                {
                  f_if>>n;
                  f_of<<n+1;
                }
                else
                {
                  f_of<<n;
                }
                f_if.close();
                f_of.close();

                remove("sf/Bid/bid_no.txt");
                rename("sf/Bid/bid_no1.txt","sf/Bid/bid_no.txt");

                stringstream sso;
                sso<<n;
                string number_bid;
                sso>>number_bid;
                string bidId = "Bid"+number_bid;

                b.get_BidNo(bidId);


                ofstream f;
                f.open("sf/Job/jobs_file/"+currentJob+".txt",ios::app); // Open file with the current jobNo...eg Job1.txt
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
                cout<<"\n   "<<b.show_BidNo()<<"  :  Bid Created Succesfully.\n";


                string mail  = "Hello "+b.show_email()+",\n\nYou just created a bid with Bid Id : "+b.show_BidNo()+" on Job with Job Id : "+b.show_job()+" .\nHere are your bid details for Future Reference :\n   Bid Id : "+b.show_BidNo()+"\n   Bid Amount : "+b.show_amount()+"\n   Job ID : "+b.show_job()+"\n   Bid Description : "+b.show_description()+"\n\nPlease login to check more.\n\nRegards,\nFreelancing Portal";
                ofstream file;
                file.open ("sf/Mail/Rejectedmail.txt");
                file << mail;
                file.close();
                string mail_system = "neomutt -s \"Reg. Created a Bid\" "+b.show_email()+" < sf/Mail/Rejectedmail.txt";

                const char *command = mail_system.c_str();
                system(command);


                //PRESS ENTER TO CONTINUE ----
                std::cout <<red<< "\n   Press Enter to continue. "<<def;
                fgetc(stdin);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                //PRESS ENTER TO CONTINUE ----
                goto first_page;

            }
            else
            {
              //PRESS ENTER TO CONTINUE ----
              std::cout <<red<< "\n   Press Enter to continue. "<<def;
              fgetc(stdin);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              //PRESS ENTER TO CONTINUE ----
              goto first_page;
            }
        }
      }

        // CHECK AVAILBALE JOB (freelancer) CODE START -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-
        else if(details_choice == 5)
        {
          systemClear();
          page_header(checkDetails.f_name + " " +checkDetails.l_name);
          ifstream filecheck;
          filecheck.open("sf/Job/Job.txt", ios::in);
          Job1 job_class;
          string repeat="0";
          if(filecheck != NULL)
          {
          while(!filecheck.eof())
          {
            filecheck.read((char*)&job_class, sizeof(job_class));

            if((compareString(repeat,job_class.JobId)))
            if(!(compareString("0",job_class.isApproved)))
            {
              if(!(compareString("0",job_class.isTaken)))
              {
              cout<<"\nJob  -  "<<bold_on<<job_class.JobId<<bold_off<<" : "<<job_class.title<<"\n\n";
              }
            }
            repeat = job_class.JobId;
            }
          }

          //PRESS ENTER TO CONTINUE ----
          std::cout <<red<< "\n   Press Enter to continue. "<<def;
          fgetc(stdin);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          //PRESS ENTER TO CONTINUE ----
          goto first_page;

        }
        // CHECK AVAILBALE JOB (freelancer) CODE END -#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-

        //SEARCH BY JOB_ID CODE STARTED ----
        else if(details_choice == 6)
        {
          systemClear();
          page_header(checkDetails.f_name + " " +checkDetails.l_name);

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

          //PRESS ENTER TO CONTINUE ----
          std::cout <<red<< "\n   Press Enter to continue. "<<def;
          fgetc(stdin);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          //PRESS ENTER TO CONTINUE ----
          goto first_page;
        }
        //SEARCH BY JOB_ID CODE ENDED ----

        //VIEW MY JOBS CODE STARTED -----
        else if(details_choice == 7 && (checkDetails.type.size() == 8))
        {
          systemClear();
          page_header(checkDetails.f_name + " " +checkDetails.l_name);

          ifstream filecheck;
          filecheck.open("sf/Job/Job.txt", ios::in);
          Job1 job_class;
          string repeat="0";
          if(filecheck != NULL)
          {
          while(!filecheck.eof())
          {
            filecheck.read((char*)&job_class, sizeof(job_class));
            if((compareString(repeat,job_class.JobId)))
            if(!(compareString("0",job_class.isApproved)))
              {
                if(!(compareString("0",job_class.isTaken)))
                {
                  if(!(compareString(checkDetails.email,job_class.email)))
                    cout<<"\nJob  -  "<<bold_on<<job_class.JobId<<bold_off<<" : "<<job_class.title<<"\n\n";
                }
              }
              repeat = job_class.JobId;
            }
          }

          //PRESS ENTER TO CONTINUE ----
          std::cout <<red<< "\n   Press Enter to continue. "<<def;
          fgetc(stdin);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          //PRESS ENTER TO CONTINUE ----
          goto first_page;
        }
        //VIEW MY JOBS CODE ENDED -----


        //VIEW MY BIDS CODE STARTED -----
        else if(details_choice == 7 && (checkDetails.type.size() == 10))
        {
          systemClear();
          page_header(checkDetails.f_name + " " +checkDetails.l_name);

          ifstream filecheck;
          filecheck.open("sf/Bid/Bid.txt", ios::in);
          Bid1 bid_class;
          string repeat ="0";
          if(filecheck != NULL)
          {
          while(!filecheck.eof())
          {
            filecheck.read((char*)&bid_class, sizeof(bid_class));
            if((compareString(repeat,bid_class.BidNo)))
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
              repeat = bid_class.BidNo;
            }
          }

          //PRESS ENTER TO CONTINUE ----
          std::cout <<red<< "\n   Press Enter to continue. "<<def;
          fgetc(stdin);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          //PRESS ENTER TO CONTINUE ----
          goto first_page;
        }
        //VIEW MY BIDS CODE ENDED -----



        //VIEW BIDS ON JOB CODE START -----
        else if(details_choice == 8 && (checkDetails.type.size() == 8))
        {
          systemClear();
          page_header(checkDetails.f_name + " " +checkDetails.l_name);

          string s_input;
          cout<<"\n\n\t Enter Job Id : ";
          cin>>s_input;

          ifstream filecheck;
          filecheck.open("sf/Job/jobs_file/"+s_input+".txt", ios::in);
          Bid1 bid_class;
          string repeat ="0";
          if(filecheck != NULL)
          {
          while(!filecheck.eof())
          {
            filecheck.read((char*)&bid_class, sizeof(bid_class));

            if((compareString(repeat,bid_class.BidNo)))
            cout<<"\nBid  -  "<<bold_on<<bid_class.BidNo<<bold_off<<" : "<<bid_class.amount<<"\n\n";
            repeat = bid_class.BidNo;

            }
          }

          //PRESS ENTER TO CONTINUE ----
          std::cout <<red<< "\n   Press Enter to continue. "<<def;
          fgetc(stdin);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          //PRESS ENTER TO CONTINUE ----
          goto first_page;
        }
        //VIEW BIDS ON JOB CODE START -----


        //VIEW MY ACCEPTED BIDS CODE STARTED -----
        else if(details_choice == 8 && (checkDetails.type.size() == 10))
        {
          systemClear();
          page_header(checkDetails.f_name + " " +checkDetails.l_name);

          ifstream filecheck;
          filecheck.open("sf/Bid/Bid.txt", ios::in);
          Bid1 bid_class;
          string repeat ="0";
          if(filecheck != NULL)
          {
          while(!filecheck.eof())
          {
            filecheck.read((char*)&bid_class, sizeof(bid_class));
            if((compareString(repeat,bid_class.BidNo)))
            if(!(compareString(checkDetails.email,bid_class.email)))
              {
                if(!(compareString(bid_class.isAccepted,"2")))
                {
                  cout<<"\n   Bid on JobID : "+bid_class.jobID<<"\t"<<bold_on<<"Status : "<<bold_off;
                  cout<<green<<bold_on<<"ACCEPTED\n\n"<<bold_off<<def;
                }
              }
              repeat = bid_class.BidNo;
            }
          }

          //PRESS ENTER TO CONTINUE ----
          std::cout <<red<< "\n   Press Enter to continue. "<<def;
          fgetc(stdin);
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          //PRESS ENTER TO CONTINUE ----
          goto first_page;
        }

        else if(details_choice==9 && (checkDetails.type.size() == 8))
        {
            systemClear();
            page_header(checkDetails.f_name + " " +checkDetails.l_name);


            // Job1 job;
            // Bid1 bid;
            string job_id,bid_id;
            cout<<blue<<"\n\n   Enter JobId : "<<def;
            space();
            cin>>job_id;
            cout<<blue<<"   Enter BidId you want to select for "<<job_id<<" : "<<def;
            space();
            cin>>bid_id;

            cout<<"\n\n   Please hold on while we are making required changes.\n";
            // job.JobId=job_id;


            ofstream fp11;
            fp11.open("sf/Job/jobs_file/newfile.txt", ios::app);
            ifstream fp12;
            fp12.open("sf/Job/jobs_file/"+job_id+".txt", ios::in);
            Bid1 user_new1;
            if(fp12 != NULL)
            {
            while(!fp12.eof())
            {
              fp12.read((char*)&user_new1, sizeof(user_new1));
                if(!(compareString(user_new1.BidNo ,bid_id)))
                {
                  user_new1.isAccepted ="2";
                  fp11.write((char*)&user_new1, sizeof(user_new1));
                }
            }
            }

                string change_file = "sf/Job/jobs_file/"+job_id+".txt";
                string change_file1 = "rm "+change_file;
                const char *command = change_file1.c_str();
                system(command);
                string change_file2 = "mv sf/Job/jobs_file/newfile.txt "+change_file;
                const char *command1 = change_file2.c_str();
                system(command1);



                ofstream fp1;
                fp1.open("sf/Bid/newfile.txt", ios::app);
                ifstream fp;
                fp.open("sf/Bid/Bid.txt", ios::in);
                Bid1 user_new;
                string repeat = "0";
                if(fp != NULL)
                {
                while(!fp.eof())
                {
                  fp.read((char*)&user_new, sizeof(user_new));
                  if((compareString(repeat,user_new.BidNo)))
                  {
                    if(!(compareString(user_new.jobID ,job_id)))
                    {

                      if(!(compareString(user_new.BidNo ,bid_id)))
                      {
                        user_new.isAccepted ="2";
                        string mail  = "Hello "+user_new.email+",\n\nCongratulations, Your bid with Bid Id : "+user_new.BidNo+" on Job with Job Id : "+user_new.jobID+" just got selected. The employer hired you as a Freelancer. Please login to details of Job.";
                        ofstream file;
                        file.open ("sf/Mail/Acceptedmail.txt");
                        file << mail;
                        file.close();
                        string mail_system = "neomutt -s \"Reg. Bid got Selected\" "+user_new.email+" < sf/Mail/Acceptedmail.txt";

                        const char *command = mail_system.c_str();
                        system(command);
                      }
                      else
                      {
                        user_new.isAccepted ="1";
                        string mail  = "Hello "+user_new.email+",\n\nWe are sorry as your bid with Bid Id : "+user_new.BidNo+" on Job with Job Id : "+user_new.jobID+" just got rejected by the employer. Please login to check more.";
                        ofstream file;
                        file.open ("sf/Mail/Rejectedmail.txt");
                        file << mail;
                        file.close();
                        string mail_system = "neomutt -s \"Reg. Bid got Rejected\" "+user_new.email+" < sf/Mail/Rejectedmail.txt";

                        const char *command = mail_system.c_str();
                        system(command);
                      }

                      fp1.write((char*)&user_new, sizeof(user_new));
                    }
                    else
                    {
                      fp1.write((char*)&user_new, sizeof(user_new));
                    }
                  }


                  repeat = user_new.BidNo;

                }
                }

              remove("sf/Bid/Bid.txt");
              rename("sf/Bid/newfile.txt", "sf/Bid/Bid.txt");


              ofstream delete_job;
              delete_job.open("sf/Job/new_job.txt",ios::app);
              ifstream delete_if;
              delete_if.open("sf/Job/Job.txt",ios::in);
              Job1 delete_class;
              if(delete_if)
              {
                  while(!delete_if.eof())
                  {
                      delete_if.read((char*)&delete_class, sizeof(delete_class));
                      if(!(compareString(delete_class.JobId,user_new.jobID)))
                      {
                        delete_class.isTaken = "1";
                        delete_job.write((char*)&delete_class, sizeof(delete_class));
                      }
                      else
                      {
                        delete_job.write((char*)&delete_class, sizeof(delete_class));
                      }

                  }
              }
              remove("sf/Job/Job.txt");
              rename("sf/Job/new_job.txt","sf/Job/Job.txt");


              //PRESS ENTER TO CONTINUE ----
              std::cout <<red<< "\n   Press Enter to continue. "<<def;
              fgetc(stdin);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              //PRESS ENTER TO CONTINUE ----
              goto first_page;
            }

            else if(details_choice==10 && (checkDetails.type.size() == 8) )
            {
              systemClear();
              page_header(checkDetails.f_name + " " +checkDetails.l_name);
                //systemclear()
                Job1 j;
                string job_id;
                cout<<blue<<"\n\n   Enter JobId to be deleted"<<def;
                space();
                cin>>job_id;
                j.JobId=job_id;

                ofstream del_job1;
                del_job1.open("sf/Job/new_job.txt",ios::app);
                ifstream del_job;
                del_job.open("sf/Job/Job.txt",ios::in);
                Job1 delJob;
                if(del_job)
                {
                    while(!del_job.eof())
                    {
                        del_job.read((char*)&delJob, sizeof(delJob));
                        if(!(compareString(delJob.JobId,j.JobId)));
                        else
                        {
                          del_job1.write((char*)&delJob, sizeof(delJob));
                        }

                    }
                }
                remove("sf/Job/Job.txt");
                rename("sf/Job/new_job.txt","sf/Job/Job.txt");
                string del_file = "sf/Job/jobs_file/"+job_id+".txt";
                string del_file1 = "rm "+del_file;
                const char *command = del_file1.c_str();
                system(command);

                //PRESS ENTER TO CONTINUE ----
                std::cout <<red<< "\n   Press Enter to continue. "<<def;
                fgetc(stdin);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                //PRESS ENTER TO CONTINUE ----
                goto first_page;
                // goto first_page;

            }

        }


return 0;
}
