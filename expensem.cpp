/* Welcome to the Expense Manager designed by the A-Team.
	We strive to bring you excellence and quality.
	This program manages your current expenses, reminds you about payments,
	provides guidance in the world of finance, and even helps you convert currency!
	Try it out for yourself!
	Brought to you by Deepak.S, Deepak.R, V.K.Arvind and Girishankar */





//HEADER FILES

#include <fstream.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


// GLOBAL VARIABLES

long int EM_ID;
int n_bno;
int count69=0;


// CLASSES (TOTAL =8)
// MAIN CLASS

class manager
{
 char o_first_name[50];
 char o_last_name[50];
 char o_username[50];
 char o_password[50];

 public:
 void login();
 void congrats(long int EM_ID);
 void start_1();
 void start_2();
 void border();
 void time_delay(long);
 void loading(long);
 void regis();
 void converter();
 void tips();
 void tax();
 void expense();
 void expensespage();
 void change_pass();
 void pass_change();
 void EMaccount();
 void logout();
 void pay();
 void schedpay();
}m;



// OTHER CLASSES

class transactions
{
 public:
 long double amount;

 int date;
 int month;
 int year;
 long int t_EM_ID;
 char type[50];
};


class spay
{
 public:
 int date;
 int month;
 int year;
 float amount;
 char reason[50];
 long S_EM_ID;
}sp;



class time_check
{
 public:
 int t_day;
 int t_month;
 int t_year;
 void timecheck();
}t;


class account_info
{
 char b[40];
 char acc_number[50];
 unsigned long int bal;
 int acc_n_bno;

 public:
 long int acc_EM_ID;
 void account1();
 void account2();
 void account3();
 void acc_info();
 char* select_acc();
 void mainmenu();
 void bank_trans(char n[50]);
 void atrans(char n[50]);
 void acc_delete();
 void selectpage(char bnnn[50]);
}a;


class expenses
{
 float amount_expense;
 int date;
 int month;
 int year;
 char cat[50];

 public:
 long int e_EM_ID;
 void expenseenter();
 void expensedisplay();
 void receipt();
 void expensetotal();
}e2;


class registration
{
 public:
 char first_name[50];
 char last_name[50];
 char username[40];
 char password[40];
 char email_ID[50];
 char mphone[15];
 char security_question[80];
 char sec_answer[50];
 int month;
 int date;
 int year;
};


class budget
{
 public:
 char username[50];
 float income;
 long int budget;
 budget()
  {
	clrscr();
	m.border();
	cout<<"\n*\t\t\t      BUDGET CALCULATION";
	cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
	cout<<"\n*\n* Please enter your annual income: ";
	cin>>income;
	cout<<"\n* Based on financial calculatuions an ideal budget for your will be :";
	cout<<0.625*income;                                            // 62.5% original income
	cout<<"\n*\n* Enter your desired budget: ";
	cin>>budget;
	ofstream bgt;                                               //opening to write to the file
	bgt.open("budget.txt",ios::binary|ios::app);               //append mode to append to the end of the file
	bgt.write((char*)&bgt,sizeof(bgt));                       //syntax for writing
	bgt.close();
	cout<<"\n*\n* Your Budget details have been saved";
	cout<<"\n* Press any key to return to the mainmenu: ";
	getche();
	return;
  }
};



// 35 FUNCTIONS IN TOTAL. 34 DEFINED BELOW
//FUNCTION DEFINITIONS





void manager::schedpay()
{
 clrscr();                //for clearing the entire screen
 m.border();             // function for the border
 cout<<"\n*\t\t\t        SCHEDULED PAYMENTS";
 cout<<"\n**_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 cout<<"\n*\t\t\t Here, you can schedule your payments!";
 cout<<"\n* \n* \n*";
 cout<<"\n* What is the payment for? : ";
 gets(sp.reason);

 clrscr();
 m.border();
 dateofpay:                  //label for goto
 cout<<"\n* Enter the day (number) on which you need to make the payment: ";
 cin>>sp.date;
 cout<<"\n* On which month must you make the payment? (enter the month number): ";
 cin>>sp.month;
 cout<<"\n* In which year must you make the payment?: ";
 cin>>sp.year;
 if(sp.date>31||sp.month>12||sp.year<2016||sp.date==0)         //comparison to check for valid date details
  {
	cout<<"\n* Invalid Date of Payment. Please re-enter";
	m.time_delay(1000);
	goto dateofpay;
  }
 else if((sp.month==4||sp.month==6||sp.month==9||sp.month==11)&&sp.date>30)
  {
	cout<<"\n* Invalid Date of Payment. Please re-enter";
	m.time_delay(1000);
	goto dateofpay;
  }
 else if(sp.month==2&&(sp.year%4==0)&&sp.date>29)
  {
	cout<<"\n* Invalid Date of Payment. Please re-enter";
	m.time_delay(1000);
	goto dateofpay;
  }
 else if(sp.month==2&&(sp.year%4!=0)&&sp.date>28)
  {
	cout<<"\n* Invalid Date of Payment. Please re-enter";
	m.time_delay(1000);
	goto dateofpay;
  }
 cout<<"\n* Enter the amount: ";
 cin>>sp.amount;
 sp.S_EM_ID=EM_ID;           //variable to know the position of the record
 ofstream f;
 f.open("sched.dat",ios::binary|ios::app);
 f.write((char*)&sp,sizeof(sp));
 f.close();
 return;
}







void manager::pay()           //Scheduling your payments
{
 clrscr();
 m.border();
 int flag87=0;
 cout<<"\n*\t\t\t      SCHEDULED PAYMENTS";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 ifstream f;
 f.open("sched.dat",ios::binary);
 f.seekg(0,ios::beg);
 while(f.read((char*)&sp,sizeof(sp)))
  {
	if(sp.S_EM_ID==EM_ID)  // to check if the current file record matches with the account
	 {
	  if((t.t_day==sp.date)&&(t.t_month==sp.month)&&(t.t_year==sp.year))
		{
		 cout<<"\n*\n* Payment Description"<<" - "<<sp.reason;
		 cout<<"\n* You have scheduled this payment for today for an amount of "<<sp.amount;
		 cout<<"\n*\n*";
		 flag87=1;
		}
	 }
  }
 if(!flag87)      //if flag87 returns false
  {
	cout<<"\n\n\n\n\n*\t\t You have not scheduled any payments for today";

  }
 f.close();
 cout<<"\n*\n\n\n\n\n\n\t\t Press any key to return to the mainmenu: ";
 getche();
 return;
}







void manager::regis()
{
 registration r,check; // class variables
 clrscr();
 m.border();
 ifstream f;
 f.open("userinfo.dat",ios::binary);
 cout<<"\n* \t \t \tWELCOME TO THE REGISTRATION PAGE";
 cout<<"\n*    You are one step away from creating your own Expense Manager account";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";

 firstname:
 cout<<" \n* \n* \n* Enter your first name : ";
 gets(r.first_name);
 int flag69=0;
 for(int k=0;r.first_name[k]!='\0';k++)
  {
	if(!isalpha(r.first_name[k]))
	 {
	  cout<<"\n* Does your name have numbers in it? Please enter again";
	  flag69=1;
	  break;
	 }
  }
 if(flag69)
 goto firstname;
 if(strlen(r.first_name)<1)
  {
	clrscr();
	m.border();
	cout<<"\n* Is your first name less than one letter? \n* Please enter your name again";
	goto firstname;
  }

 charenter:             // label for goto
 cout<<"\n* Do you have a last name? (y/n)";
 char ch6;
 cin>>ch6;
 if(ch6=='y'||ch6=='Y')
  {
	cout<<" \n* Enter your last name";
	gets(r.last_name);
	int flag55=0;
	for(int m=0;r.last_name[m]!='\0';m++)
	 {
	  if(!isalpha(r.last_name[m]))
		{
		 cout<<"\n* Does your name have numbers in it? Please enter again";
		 flag55=1;
		 break;
		}
	 }
	if(flag55)
	 {
	  goto charenter;
	 }
	else if(strlen(r.last_name)<1)
	 {
	  clrscr();
	  border();
	  cout<<"\n* Is your last name less than one letter? \n* Please enter your name again";
	  goto charenter;
	 }
	strcpy(o_last_name,r.last_name);
  }
 else if(ch6=='n'||ch6=='N')
 goto username;
 else
  {
	cout<<"\n* Invalid choice. Please enter again";
	goto charenter;
  }

 username:            // label for goto
 cout<<"\n* Enter a username :" ;
 gets(r.username);
 if(strlen(r.username)==0)
  {
	cout<<"\n* Please Enter some Username";
	m.time_delay(1000);
	goto username;
  }
 f.seekg(0);
 while(f.read((char*)&check,sizeof(check)))
  {
	if(strcmp(check.username,r.username)==0)
	 {
	  cout<<"\n* Username already exists. Redirecting to previous page";
	  m.time_delay(1000);
	  m.start_2();
	 }
  }
 f.close();

 re_password:            // label for goto
 clrscr();
 m.border();
 cout<<"\n*\t\t\t\t REGISTRATION";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 cout<<"\n*\n* Enter a Password: \n* ";
 int j_p,i,d,digits=0,upper_case=0;
 for(j_p=0;;j_p++)
  {
	r.password[j_p]=getch();
	char a;
	a=r.password[j_p];
	if(a==13)
	 {
	  r.password[j_p]='\0';
	  j_p--;
	  break;
	 }
	else if(a==8)
	 {
	  if(j_p>0)
		{
		 cout<<"\b"<<" "<<"\b";
		 j_p=j_p-2;
		}
	 }
	putch('*');
  }
 int len=strlen(r.password);
 if(len<=7)                                                              //Password strength verification
  {
	cout<<"\n* Your password is weak. Account prone to hacking";
	cout<<"\n* Do you wish to re-enter your password? (y/n) : ";
	char pw_reenter_ans;
	cin>>pw_reenter_ans;
	if(pw_reenter_ans=='Y'||pw_reenter_ans=='y')
	goto re_password;
	else goto next;
  }
 if(len==0)
  {
	cout<<"\n* Please enter a password \n";
	goto re_password;
  }
 for(i=0;i<len;i++)
  {
	if(isdigit(r.password[i])!=0)
	 {
	  digits++;
	 }
  }
 for(d=0;d<len;d++)
  {
	if(isupper(r.password[d])!=0)
	 {
	  upper_case++;
	 }
  }
 if(upper_case>0&&digits>0&&len>10)
 cout<<"\n* strong password";
 else if(upper_case>0||digits>0)
 cout<<"\n* moderate password";
 else
 cout<<"\n* weak password";

 next:            // label for goto
 dateofbirth:            // label for goto
 clrscr();
 m.border();
 cout<<"\n*\t\t\t\t REGISTRATION";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 cout<<"\n*\n* Enter your Date of Birth";
 cout<<"\n* Date : ";
 cin>>r.date;
 cout<<"\n* Month: ";
 cin>>r.month;
 cout<<"\n* Year : ";
 cin>>r.year;
 if(r.date>31||r.month>12||r.year>2015||r.year<1900||r.date==0)
  {

	cout<<"\n* Invalid Date of Birth. Please re-enter";
	m.time_delay(1000);
	goto dateofbirth;
  }
 else if((r.month==4||r.month==6||r.month==9||r.month==11)&&r.date>30)
  {
	cout<<"\n* Invalid Date of Birth. Please re-enter";
	m.time_delay(1000);
	goto dateofbirth;
  }
  else if(r.month==2&&(r.year%4==0)&&r.date>29)
  {
  cout<<"\n* Invalid Date of Birth. Please re-enter";
  m.time_delay(1000);
  goto dateofbirth;
  }
  else if(r.month==2&&(r.year%4!=0)&&r.date>28)
  {
  cout<<"\n* Invalid Date of Birth. Please re-enter";
  m.time_delay(1000);
  goto dateofbirth;
  }

 phone:            // label for goto
 clrscr();
 m.border();
 cout<<"\n*\t\t\t\t REGISTRATION";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 cout<<"\n*\n* Enter your contact number in this format - +(Country code)-(10 digit number)";
 cout<<"\n* Example +91-9922993399\n  ";
 gets(r.mphone);
 int lenphone=strlen(r.mphone);
 if(lenphone!=14)
  {
	cout<<"\n* Please enter a valid phone number in the given format";
	goto phone;
  }
 for(int m=0;m<lenphone;m++)
  {
	if(isalpha(r.mphone[m]))
	 {
	  cout<<"\n* Invalid input. Please enter again";
	  goto phone;
	 }
  }

 email:            // label for goto
 cout<<"\n* Enter your email ID\n  ";
 gets(r.email_ID);
 int flag97=0;
 for(int q=0;r.email_ID[q]!='\0';q++)
  {
	if(r.email_ID[q]=='@')                 // Verification for the email-id entry
	 {
	  flag97=1;
	  break;
	 }
  }
 if(!flag97)
  {
	cout<<"\n* Invalid email id. Please enter again";
	goto email;
  }
 fstream f2;
 f2.open("userinfo.dat",ios::binary|ios::app);
 f2.write((char*)&r,sizeof(r));
 long int endpos=f2.tellg();                                  // current byte location in file
 EM_ID=endpos/sizeof(r);                               // assigning value of EM_ID
 f2.close();
 ofstream regis_storage;
 regis_storage.open("regis_storage.dat",ios::binary|ios::app);
 regis_storage.write((char*)&r,sizeof(r));
 regis_storage.close();
 strcpy(o_username,r.username);
 strcpy(o_password,r.username);
 clrscr();
 congrats(EM_ID);                   // TRANSFERRING EM-ID TO THE CONGRATS PAGE
}







void manager::congrats(long int EM_ID)
{
 account_info acc;
 m.border();
 cout<<"\n* \t\t\t        CONGRATULATIONS!!!";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
  cout<<"\n*\n* \t\t YOU HAVE CREATED YOUR EXPENSE MANAGER ACCOUNT!";
 cout<<"\n*\n* \t\t \t\t YOUR EM-ID IS "<<EM_ID;
 m.time_delay(5000);
 cout<<"\n* Redirecting to the account information page";
 acc.acc_info();          //Transferring control to account details input page
}








void manager::border()
{
 for(int i=0;i<40;++i)
 cout<<"*"<<" ";
 for(int k=0;k<22;k++)
  {
	cout<<"*";
	for(int j=0;j<77;j++)
	cout<<" ";
	cout<<"* ";
  }
 cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * Ex.Manag. (c) 2016*";
 gotoxy(3,2);         //Transfers the screen pointer to the given position in the screen
}








void account_info::acc_info()
{
 clrscr();
 m.border();
 cout<<"\n*\t\t\t\tACCOUNT INFORMATION";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 account_info acc;                 //class variable
 cout<<"\n*\t     How many bank accounts do you wish to enter? (MAX 3)\n* \n*\n*\t\t\t\t     ";
 cin>>acc.acc_n_bno;
 if(acc.acc_n_bno>3)
  {
	cout<<"\n* You have either entered an invalid input or have exceeded the maximum number. Please enter again";
	cout<<"\n* Redirecting";
	m.time_delay(2000);
	acc.acc_info();
  }
 if(acc.acc_n_bno==0)
 a.mainmenu();
 n_bno=acc.acc_n_bno;
 acc.account1();
}









void account_info::account1()                //function to enter the first bank account details
{
 clrscr();
 m.border();
 account_info acc,acc1;      //class variables
 cout<<"\n\t\t\t\t ACCOUNT DETAILS";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 cout<<"\n*\n* Enter details of your first bank account";
 cout<<"\n* Bank name : ";
 gets(acc.b);
 for(int w=0;acc.b[w]!='\0';w++)
  {
	if(!isalpha(acc.b[w]))
	 {
	  cout<<"\n* Invalid input. Please enter again";
	  a.account1();                           // calls the function again due to invalid details
	 }
  }
 cout<<"\n*";
 cout<<"\n* please enter the opening account balance: ";
 cin>>acc.bal;
 cout<<"\n* Bank account number: ";
 cin>>acc.acc_number;
 for(int o=0;acc.acc_number[o]!='\0';o++)
  {
	if(!isalnum(acc.acc_number[o]))
	 {
	  cout<<"\n* Invalid entry. Please re-enter your bank account details";
	  a.account1();                           // calls the function again due to invalid details
	 }
  }
 ifstream f;
 f.open("accinfo.dat",ios::binary);
 while(f.read((char*)&acc1,sizeof(acc1)))
  {
	if(!strcmp(acc1.acc_number,acc.acc_number))             //compares if the account number entered by the user is already existing or not
	 {
	  cout<<"\n* Account number already exists in our database. Please check your account number";
	  m.time_delay(1000);
	  acc.account1();
	 }
  }
 f.close();
 acc.acc_EM_ID=EM_ID;          //variable to know the position of the record
 ofstream f1;
 f1.open("accinfo.dat",ios::binary|ios::app);
 f1.write((char*)&acc,sizeof(acc));
 f1.close();
 if(n_bno>=2)          //if the number of bank account the user entered is greater than or equal to zero it will transfer the control to the next function or it will go to the login page
 acc.account2();
 else
  {
	cout<<"\n* Redirecting to the login page";
	m.time_delay(1000);
	m.login();
  }
}










void account_info::account2()                //function to enter the first bank account details
{
 clrscr();
 m.border();
 cout<<"\n\t\t\t\t ACCOUNT DETAILS";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 account_info acc2,acc1;
 cout<<"\n*\n* Enter details of your second bank account";
 cout<<"\n* Bank name : ";
 gets(acc2.b);
 for(int w=0;acc2.b[w]!='\0';w++)
  {
	if(!isalpha(acc2.b[w]))
	 {
	  cout<<"\n* Invalid entry. Please re-enter your bank details";
	  a.account2();
	 }
  }
 cout<<"\n*";
 cout<<"\n* please enter the opening account balance: ";
 cin>>acc2.bal;
 cout<<"\n* Bank account number: ";
 cin>>acc2.acc_number;
 for(int o=0;acc2.acc_number[o]!='\0';o++)
  {
	if(!isalnum(acc2.acc_number[o]))
	 {
	  cout<<"\n* Invalid input. Please re-enter you bank details";
	  a.account2();
	 }
  }
 ifstream f;
 f.open("accinfo.dat",ios::binary);
 while(f.read((char*)&acc1,sizeof(acc1)))                   //reads from the file
  {
	if(!strcmp(acc1.acc_number,acc2.acc_number))             //compares if the account number entered by the user is already existing or not
	 {
	  cout<<"\n* Account number already exists in our database. Please check your account number";
	  m.time_delay(1000);
	  acc2.account2();
	 }
  }
 f.close();
 acc2.acc_EM_ID=EM_ID;          //variable to know the position of the record
 ofstream f1;
 f1.open("accinfo.dat",ios::binary|ios::app);
 f1.write((char*)&acc2,sizeof(acc2));
 f1.close();
 if(n_bno>=3)
 acc2.account3();
 else
  {
	cout<<"\n* Redirecting to the login page";
	m.time_delay(1000);
	m.login();
  }
}








void account_info::account3()             //function to enter the first bank account details
{
 clrscr();
 m.border();
 cout<<"\n\t\t\t\t ACCOUNT DETAILS";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 account_info acc3,acc1;
 cout<<"\n*\n* Enter details of your third bank account";
 cout<<"\n* Bank name : ";
 gets(acc3.b);
 for(int w=0;acc3.b[w]!='\0';w++)
  {
	if(!isalpha(acc3.b[w]))
	 {
	  cout<<"\n* Invalid entry. Please re-enter your bank details";
	  a.account3();
	 }
  }
 cout<<"\n*";
 cout<<"\n* please enter the opening account balance: ";
 cin>>acc3.bal;
 cout<<"\n* Bank account number: ";
 cin>>acc3.acc_number;
 for(int o=0;acc3.acc_number[o]!='\0';o++)
  {
	if(!isalnum(acc3.acc_number[o]))
	 {
	  cout<<"\n* Invalid entry. Please re-eneter your bank account details";
	  a.account3();
	 }
  }
 ifstream f;
 f.open("accinfo.dat",ios::binary);
 while(f.read((char*)&acc1,sizeof(acc1)))
  {
	if(!strcmp(acc1.acc_number,acc3.acc_number))          //compares if the account number entered by the user is already existing or not
	 {
	  cout<<"\n* Account number already exists in our database. Please check your account number";
	  m.time_delay(1000);
	  acc3.account3();
	 }
  }
 f.close();
 acc3.acc_EM_ID=EM_ID;
 ofstream f1;
 f1.open("accinfo.dat",ios::binary|ios::app);
 f1.write((char*)&acc3,sizeof(acc3));
 f1.close();
 cout<<"\n* Redirecting to the login page";
 m.time_delay(1000);
 m.login();             //transfers the control to the login page
}









void manager::start_1()
{
 clrscr();
 m.border();
 cout<<"\n* ____ _  _ ____ ____ __ _  ____ ____   _  _   __   __ _  __   ___ ____ ____ ";             //Displays welcome to expense manager
 cout<<"\n*( __ | \\/ |   _(  __|  ( \\/ ___|  __) ( \\/ ) / _\\ (  ( \\/ _\\ / __|  __|  _ \\";
 m.time_delay(200);
 cout<<"\n* ) _) )  ( ) __/) _)/    /\\___ \\) _)  / \\/ \\/    \\/    /    ( (_ \\) _)  )  /";
 m.time_delay(200);
 cout<<"\n*(____|_  _|__) ( ___)_)__)(____(____) \\_)(_/\\_/\\_/\\_)_) _/\\_/\\___( ___|__\\_";
 cout<<"\n* \n* \n* \n* \n* \n* \n* \n* \t\t\t  WELCOME TO EXPENSE MANAGER";
 cout<<"\n* \t \t \t  PRESS ANY KEY TO CONTINUE:";
 getche();
 m.start_2();
}








void manager::start_2()
{
 lb:
 char ch;
 clrscr();
 m.border();
 cout<<"\n*\n*\n*\n*\n*\n*\n*\n* \t\t\t ARE YOU AN EXISTING USER (y/n)?";        //asks if the user has an expense manager account or not
 cin>>ch;
 if(ch=='y'||ch=='Y')
 m.login();
 else if(ch=='N'||ch=='n')
 m.regis();
 else
  {
	cout<<"\n* Invalid option";
	goto lb;
  }
}









void manager::login()                         //function to proceed with the login
{
 clrscr();
 m.border();
 registration reg;          //class variable
 cout<<"\t\t\t\t  LOGIN PAGE                            ";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_";
 ifstream f;
 f.open("userinfo.dat",ios::binary);
 if(!f)
  {
	cerr<<"\n* File Does not exist";
	exit(1);
  }
 f.close();
 int i;
 char username[40],pass[40];
 start:
 int found=0;
 long int pos_pass;
 f.open("userinfo.dat",ios::binary);
 cout<<"\n*\n*\n*\n*\t\t\tUserName     : ";
 gets(username);
 while(f.read((char*)&reg,sizeof(reg)))
  {
	if (strcmp(reg.username,username)==0) //checks if the username exists in our database
	 {
	  found=1;    //if the username exists the value of found will be zero
	  pos_pass=f.tellg()/sizeof(reg);
	  break;
	 }
  }
 if(!found)
  {
	cout<<"\n* Inavalid Username";
	cout<<"\n* restarting login procdeure";
	m.time_delay(5000);
	m.login();
  }
 strcpy(o_username,username);
 int f_p=0;

 startp:
 if(f_p<3)       //to check whether the maximum login attempts have been reached
  {
	cout<<"\n*\n*\t\t\tPassword     : ";
	for(i=0; ;i++)
	 {
	  pass[i]=getch();
	  char a;
	  a=pass[i];
	  if(a==13)
		{
		 pass[i]='\0';
		 break;
		}
	  else if(a==8)
		{
		 if(i>0)
		  {
			cout<<"\b"<<" "<<"\b";
			i-=2;
		  }
		}
	  else
	  putch('*');
	 }

  }
 else
  {
	cout<<"\n* Maximum login attempts reached ";
	m.time_delay(500);
	m.start_2();
  }
 f.seekg(pos_pass-1);
 while(f.read((char*)&reg,sizeof(reg)))
  {
	if((strcmp(reg.password,pass))!=0)         //compares whether the password matches
	 {
	  f_p++;
	  cout<<"\n* wrong password.";
	  goto startp;
	 }
	else break;
  }
 strcpy(o_password,pass);
 ofstream f3;
 f3.open("login_storage.dat",ios::binary|ios::app);
 f3.write((char*)&reg,sizeof(reg));
 f3.close();
 clrscr();
 a.mainmenu();
}









void manager::time_delay(long nano)       //function for time delay
{
 clock_t start=clock();
 while(clock()-start<nano);
}









void manager::loading(long time)        //function to display loading...
{
 clrscr();
 m.border();
 cout<<"\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\t\t\t\t Processing";
 cout<<".";
 m.time_delay(time);
 cout<<".";
 m.time_delay(time);
 cout<<".";
 m.time_delay(time);
}









void manager::converter()          //currency convertor
{
 start1: //CONVRSION OF INDIAN MONEY//
 clrscr();
 m.border();
 cout<<"\n*\t\t\t              CURRENCY CONVERTER";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 float amount;
 int n;
 char ans;
 cout<<"\n* \t\t Enter the amount you want to convert in rupees";
 cin>>amount;
 cout<<"\n*\t\t(1). U.S dollars";
 cout<<"\n*\t\t(2). Singapore dollars";
 cout<<"\n*\t\t(3). Australian dollars";
 cout<<"\n*\t\t(4). Euros";
 cout<<"\n*\t\t(5). Dirhams";
 cout<<"\n*\t\t(6). Ringgit";
 cout<<"\n*\t\t(7). Peso";
 cout<<"\n*\t\t(8). Yen";
 cout<<"\n*\t\t(9). Yuan";
 cout<<"\n*\t\t(10). Rubel";
 cout<<"\n*\t\t(11). Franc";
 cout<<"\n*\t\t Enter the choice of currency you want to convert:";
 cin>>n;

 switch(n)         //switch to process the choice entered by the user
  {
	case 1:
	amount*=0.016;
	cout<<"\n*\t\t The amount in U.S.D is"<<" "<<amount;
	break;

	case 2:
	amount*=0.022;
	cout<<"\n*\t\t The amount in Singapore dollars is"<<" "<<amount;
	break;

	case 3:
	amount*=0.021;
	cout<<"\n*\t\t The amount in Australian dollars is"<<" "<<amount;
	break;

	case 4:
	amount*=0.015;
	cout<<"\n*\t\t The amount in Euros is"<<" "<<amount;
	break;

	case 5:
	amount*=0.059;
	cout<<"\n*\t\t The amount in Dirhams is"<<" "<<amount;
	break;

	case 6:
	amount*=0.059;
	cout<<"\n*\t\t The amount in Ringgits is"<<" "<<amount;
	break;

	case 7:
	amount*=0.24;
	cout<<"\n*\t\t The amount in Peso is"<<" "<<amount;
	break;

	case 8:
	amount*=1.93;
	cout<<"\n*\t\t The amount in Yen is"<<" "<<amount;
	break;

	case 9:
	amount*=0.099;
	cout<<"\n*\t\t The amount in Yuan is"<<" "<<amount;
	break;

	case 10:
	amount*=0.96;
	cout<<"\n*\t\t The amount in Rubel"<<" "<<amount;
	break;

	case 11:
	amount*=0.016;
	cout<<"\n*\t\t The amount in Francs is"<<" "<<amount;
	break;

	default:
	cout<<"\n* INVALID CHOICE";
  }
 cout<<"\n*\t\t Do you want to enter again? (y/n)";
 cin>>ans;
 if(ans=='y'||ans=='Y')
 goto start1;
 else
 return;
}








void manager::tips()
{
 clrscr();
 m.border();
 cout<<"\n*\t\t\t\t     TIPS";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 cout<<"\n*\n*\t\t\tHERE ARE SOME GOOD TIPS FOR YOU";
 cout<<"\n*\n*\t(1). Write a list before you go shopping and STICK TO IT!";
 cout<<"\n*\n*\t(2). One big way to save money is to reduce electricity consumption";
 cout<<"\n*\n*\t(3). Give up needless habits like cigarettes,alcohol and drugs";
 cout<<"\n*\n*\t(4). Use the telephone only when required";
 cout<<"\n*\n*\t(5). Dont spend too much cash on valentines day";
 cout<<"\n*\n*\t(6). Use your talent to earn extra cash";
 cout<<"\n*\n* Press any key to return to the mainmenu: ";
 getche();
 return;          //returns to the calling function
}









void account_info::acc_delete()        //function to perform deletion of bank account
{
 m.border();
 cout<<"\n*\t\t\t\t  ACCOUNT DELETION";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 ifstream f1;
 int flag=0;
 ofstream f2;
 f1.open("accinfo.dat",ios::binary);
 f2.open("temp.dat",ios::out|ios::binary);
 f2.close();
 char delete_accno[20];         //variable to get the account numer to be deleted
 cout<<"\n* Enter the account number of the account you want to delete";
 cin>>delete_accno;
 f2.open("temp.dat",ios::binary|ios::out);//temporary file to hold the non deleted values
 while(f1.read((char*)&a,sizeof(a)))
  {
	if(strcmp(delete_accno,a.acc_number)!=0)     //compares the account number entered by the user and the existing accoutn number and deletes it if the account number exists
	f2.write((char*)&a,sizeof(a));
	else
	flag=1; //assigns the value of flag to 1 if the account number has not been deleted
  }
 f1.close();
 f2.close();
 if(flag==1)
 cout<<"\n* ACCOUNT DETAILS HAVE BEEN DELETED";
 else
 cout<<"\n* ACCOUNT NOT FOUND. INVALID ACCOUNT NUMBER";
 remove("accinfo.dat");  //removing the original file
 rename("temp.dat","accinfo.dat");  //renaming the temporary file as the original file
 m.time_delay(1500);
 return;
}









void manager::change_pass()         //function to change the password
{
 clrscr();
 m.border();
 cout<<"\n*\t\t\t        PASSWORD CHANGE";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 char cur_pass[40];
 char cur_username[40];
 cout<<"\n* Username    : ";
 gets(cur_username);
 ifstream f2;
 f2.open("userinfo.dat",ios::binary);
 if(strcmp(m.o_username,cur_username)==0)
  {
	label:
	cout<<"\n* Password    : ";
	for(int i=0; ;i++)      //input the password charecter by charecter to make it easy to compare
	 {
	  cur_pass[i]=getch();
	  int a=0;
	  a=cur_pass[i];
	  if(a==13)
		{
		 cur_pass[i]='\0';
		 break;
		}
	  else if(a==8)
		{
		 if(i>0)
		  {
			cout<<"\b"<<" "<<"\b";
			i-=2;
		  }
		 else if(i==0)
		  {
			cout<<"\b";
			i--;
		  }
		}
	  else
	  cout<<"*";
	 }
  }
 else
  {
	cout<<"\n* Username not found";
	m.change_pass();
  }
 if(strcmp(cur_pass,m.o_password)!=0)         //compares the password entered and the existing password
  {
	goto label;
  }
 else
  {
	 m.pass_change();    //  calling function pass_change
  }
}









void manager::pass_change()         // function to replace the cureent password with a new password
{
 clrscr();
 m.border();
 cout<<"\n*\t\t\tPASSWORD CHANGE";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 registration reg; //class variable
 ifstream f;
 ofstream tempfile;
 f.open("userinfo.dat",ios::binary,ios::in);
 tempfile.open("tempfile.dat",ios::binary|ios::out);  //temporary file to perform file modification
 f.seekg(0);  //moves the file poiinter the the start of the file
 while(f.read((char*)&reg,sizeof(reg)))
  {
	if(strcmp(reg.username,m.o_username)==0)
	 {
	  char new_pass[40];
	  char new_passcheck[40];

	  re_password:
	  cout<<"\n* New Password : ";
	  int j_p,i,d,digits=0,upper_case=0;
	  for(j_p=0;;j_p++)
		{
		 new_pass[j_p]=getch();
		 int a=0;
		 a=new_pass[j_p];
		 if(a==13)
		  {
			new_pass[j_p]='\0';
			break;
		  }
		 else if(a==8)
		  {
			if(j_p>0)
			 {
			  cout<<"\b"<<" "<<"\b";
			  j_p=j_p-2;
			 }
			else if(j_p==0)
			 {
			  cout<<"\b";
			  j_p--;
			 }
		  }
		 else cout<<"*";
		}
	  int len=strlen(new_pass);
	  if(len<=7)
		{
		 cout<<"\n* Your password is weak. Account prone to hacking";
		 cout<<"\n* Do you wish to re-enter your password? (y/n) : ";
		 char pw_reenter_ans;
		 cin>>pw_reenter_ans;
		 if(pw_reenter_ans=='Y'||pw_reenter_ans=='y')
		 goto re_password;
		}
	  for(i=0;i<len;i++)
		{
		 if(isdigit(new_pass[i])!=0)
		  {
			digits++;
		  }
		}
	  for(d=0;d<len;d++)
		{
		 if(isupper(new_pass[d])!=0)
		  {
			upper_case++;
		  }
		}
	  if(upper_case>0&&digits>0&&len>10)
	  cout<<"\n* strong password";
	  else if(upper_case>0||digits>0)
	  cout<<"\n* moderate password";
	  else
	  cout<<"\n* weak password";
	  cout<<"\n* Re-Enter Password : "   ;
	  for(j_p=0;;j_p++)
		{
		 new_passcheck[j_p]=getch();
		 int a=0;
		 a=new_passcheck[j_p];
		 if(a==13)
		  {
			new_passcheck[j_p]='\0';
			break;
		  }
		 else if(a==8)
		  {
			if(j_p>0)
			 {
			  cout<<"\b"<<" "<<"\b";
			  j_p=j_p-2;
			 }
			else if(j_p==0)
			 {
			  cout<<"\b";
			  j_p--;
			 }
		  }
		 else cout<<"*";
		}
	  if(strcmp(new_pass,new_passcheck)==0)
		{
		 strcpy(reg.password,new_pass);   //copies the new passowrd to the existing password and writes it to the temporary file
		 tempfile.write((char*)&reg,sizeof(reg));
		}
	  else
	  cout<<"\n* The passwords do not match";
	 }
	else
	tempfile.write((char*)&reg,sizeof(reg));  //writes all the records other than the one to be modified
  }
 f.close();
 tempfile.close();
 remove("userinfo.dat");
 rename("tempfile.dat","userinfo.dat"); //renames the temporary file as the original file
 a.mainmenu();    //transfers control to the main menu
}








void manager::logout()     //function to log out
{
 clrscr();
 m.border();
 cout<<"\n*\n*\n*\n*\n*\n*\t\t\t\t  LOGGING OUT";
 cout<<".";
 m.time_delay(200);
 cout<<".";
 m.time_delay(200);
 cout<<".";
 m.time_delay(800);
 m.start_1();
}









void manager::tax()        //function to perform tax calculation
{
 clrscr();
 m.border();
 int age;
 double income;
 cout<<"\n*\t\t\t\t TAX CALCULATION";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 float tax;
 cout<<"\n*\n*\t\t1. Enter your age: ";
 cin>>age;
 cout<<"\n*\n*\t  2. Enter your Annual Income(exclude taxes) : ";
 cin>>income;
 if(age<=60)
  {
	if(income<20000.00)
	tax=income*0.1;
	else if(income>=20000.00 && income<70000.00)
	tax=income*0.15;
	else if(income>=70000.00 && income<= 150000.00)
	tax=income*0.25;
	else if(income>150000.00)
	tax=income*0.3;
  }
 else if(age>60)
  {
	if(income<20000)
	tax=income*0.05;
	else if(income>=20000.00 && income<70000.00)
	tax=income*0.1;
	else if(income>=70000.00 && income<= 150000.00)
	tax=income*0.2;
	else if(income>150000.00)
	tax=income*0.25;
  }
 cout<<"\n* Tax : "<<tax;

 cout<<"\n* Press any key to return to the mainmenu: ";
 getche();
 return;

}










void time_check::timecheck()     //funtion to know the current time
{
 time_t t=time(0);
 struct tm* localTime=localtime(&t);
 int Day=localTime->tm_mday;
 int Month=localTime->tm_mon+1;
 int Year=localTime->tm_year+1900;
 t_day=Day;
 t_month=Month;
 t_year=Year;
}








void manager::expensespage()           //funtion to add expenses
{
 clrscr();
 m.border();
 cout<<"\n*\t\t\t\t    EXPENSES";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 expenses ee;
 do
  {
	cout<<"\n* (1)Add an expense";
	cout<<"\n* (2)Check recent expenses";
	cout<<"\n* (3)Generate a receipt";
	cout<<"\n* (4)Return to the mainmenu";
	cout<<"\n* \n* Enter the option number of the operation you wish to carry out: ";
	int n;
	cin>>n;

	switch(n)         //switch to go to the current option
	 {
	  case 1: m.expense();
				 break;

	  case 2: ee.expensedisplay();
				 break;

	  case 3: ee.receipt();
				 break;

	  case 4: a.mainmenu();
				 break;

	  default:
				 cout<<"\n* Invalid choice";

	 }

  }while(1);
}











void manager::expense()
{
 reenter_expenses:
 clrscr();
 m.border();
 cout<<"\n*\t\t\t\t   EXPENSES";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 int n;
 cout<<"\n*(1). Automobile";
 cout<<"\n*(2). Entertainment";
 cout<<"\n*(3). Utilities";
 cout<<"\n*(4). Education";
 cout<<"\n*(5). Family";
 cout<<"\n*(6). Food";
 cout<<"\n*(7). Insurance";
 cout<<"\n*(8). Travel";
 cout<<"\n*(9). Others";
 cout<<"\n*(10). Go to Mainmenu";
 cout<<"\n*\n* Please enter the option number of the expense type you would like to add: ";
 cin>>n;

 switch(n)
  {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
			 e2.expenseenter();
			 clrscr();
			 m.border();
			 cout<<"\n*\t\t\t\t   EXPENSES";
			 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
			 char ch9;
			 cout<<"\n* Do you want to add another expense(y/n)?: ";
			 cin>>ch9;
			 if(ch9=='y'||ch9=='Y')
			 goto reenter_expenses;
			 else
			 return;

  case 10:
			  a.mainmenu();
			  break;

  default:
			  cout<<"\n* INVALID CHOICE";
			  char ch10;
			  cout<<"\n* DO YOU WISH TO REENTER YOUR CHOICE? (y/n)";
			  cin>>ch10;
			  if(ch10=='y'||ch10=='Y')
			  goto reenter_expenses;
			  else
			  return;
  }
}









void expenses::expenseenter()     //function to enter the expense details
{
 clrscr();
 m.border();
 cout<<"\n*\t\t\t\t  EXPENSES";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 expenses e;
 cout<<"\n* Enter the amount: ";
 cin>>e.amount_expense;

 dateofp:
 cout<<"\n* Enter the day (number): ";
 cin>>e.date;
 cout<<"\n* Enter the month: ";
 cin>>e.month;
 cout<<"\n* Enter the year: ";
 cin>>e.year;
 if(e.date>31||e.month>12||e.year<2016)
  {
	clrscr();
	m.border() ;
	cout<<"\n* Invalid Date of Purchase. Please re-enter";
	goto dateofp;
  }
 else if((e.month==4||e.month==6||e.month==9||e.month==11)&&e.date>30)
  {
	clrscr();
	m.border();
	cout<<"\n* Invalid Date of Purchase. Please re-enter";
	goto dateofp;
  }
 else if(e.month==2&&(e.year%4==0)&&e.date>29)
  {
	clrscr();
	m.border();
	cout<<"\n*! Invalid Date of Purchase. Please re-enter";
	goto dateofp;
  }
 else if(e.month==2&&(e.year%4!=0)&&e.date>28)
  {
	clrscr() ;
	m.border();
	cout<<"\n* Invalid Date of Purchase. Please re-enter";
	goto dateofp;
  }

 cout<<"\n* What is the category of the expense (such as automobile,education,etc.)?: ";
 cin>>e.cat;
 e.e_EM_ID=EM_ID;             //variable to know the position of the record
 ofstream f;
 f.open("expenses.dat",ios::binary|ios::app);
 f.close();
 f.open("expenses.dat",ios::binary|ios::app);
 if(!f)
  {
	cout<<"\n* Cannot open file";
	exit(0);
  }
 f.write((char*)&e,sizeof(e));
 f.close();
 return;
}











void expenses::expensedisplay()          //funtion to display the expenses
{
 clrscr();
 ifstream f;
 f.open("expenses.dat",ios::binary);
 m.border();
 expenses ex;
 cout<<"\n* \t \t \t \t LATEST EXPENSES";

 cout<<"\n* \n* \n* \t   CATEGORY         \t     AMOUNT          \t       DATE";
 cout<<"\n* ______________________________________________________________________________";
 f.seekg(0,ios::beg);
 while(f.read((char*)&ex,sizeof(ex)))
  {
	if(ex.e_EM_ID==EM_ID)
	 {
	  cout<<"\n* \n* \n* \t   "<<ex.cat<<"                 \t"<<ex.amount_expense<<"        \t"<<ex.date<<"/"<<ex.month<<"/"<<ex.year;
	  cout<<"\n*";
	 }
  }
 f.close();
 cout<<"\n* Press any key to proceed to expense calculation: ";
 getche();
 ex.expensetotal();
 m.expensespage();
}










void expenses::expensetotal()
{
 clrscr();
 m.border();
 float sum1=0,sum2=0,sum3=0;
 expenses ex;
 cout<<"\n*\t\t\t\tTOTAL EXPENSES";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 ifstream f;
 f.open("expenses.dat",ios::binary);
 while(f.read((char*)&ex,sizeof(ex)))
  {
	if(ex.e_EM_ID==EM_ID)
	{
	 if(((t.t_day-ex.date)<7)&&(t.t_month==ex.month)&&(t.t_year==ex.year))
	  {
		sum1+=ex.amount_expense;
	  }
	 if(((t.t_month==ex.month)&&(t.t_year==ex.year)))
	  {
		sum2+=ex.amount_expense;
	  }
	 if((t.t_year==ex.year))
	  {
		sum3+=ex.amount_expense;
	  }
	}
  }
 cout<<"\n* Total expenses so far in this week is "<<sum1;
 cout<<"\n* Total expenses so far this month is "<<sum2;
 cout<<"\n* Total expenses so far in this year is "<<sum3;
 f.close();

 cout<<"\n* Press any key to return to the expenses page: ";
 getche();
 return;
}










void expenses::receipt()       //function to generate the receipt
{
 clrscr();
 int f=0;
 m.border();
 cout<<"\n* \t\t\t\t     RECEIPT  ";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 cout<<"\n*   Enter the shop name : ";
 char shop[20], proname[50][50],paytype[50];
 float amount[50];
 gets(shop);
 cout<<"\n*   Enter the number of products : ";
 int n;
 cin>>n;
 int date,month,year;

 dateofpur:
 cout<<"\n* Enter the Date of Purchase";
 cout<<"\n* Day (number) :        ";
 cin>>date;
 cout<<"\n* Month (number):        ";
 cin>>month;
 cout<<"\n* Year :        ";
 cin>>year;
 if(date>31||month>12||year<2016)
  {
	clrscr();
	m.border() ;
	cout<<"\n* Invalid Date of Purchase. Please re-enter";
	goto dateofpur;
  }
 else if((month==4||month==6||month==9||month==11)&&date>30)
  {
	clrscr();
	m.border();
	cout<<"\n* Invalid Date of Purchase. Please re-enter";
	goto dateofpur;
  }
 else if(month==2&&(year%4==0)&&date>29)
  {
	clrscr();
	m.border();
	cout<<"\n*! Invalid Date of Purchase. Please re-enter";
	goto dateofpur;
  }
 else if(month==2&&(year%4!=0)&&date>28)
  {
	clrscr() ;
	m.border();
	cout<<"\n* Invalid Date of Purchase. Please re-enter";
	goto dateofpur;
  }
 for(int i=0;i<n;i++)
  {
	if(f>=2)
	 {
	  f=0;
	  clrscr();
	  m.border();
	  cout<<"\n* Enter the product name"<<"("<<(i+1)<<")"<<": ";
	  gets(proname[i]);
	  cout<<"\n* Enter the amount";
	  cin>>amount[i];
	  f++;
	 }
	else
	 {
	  cout<<"\n*! Enter the product name"<<"("<<(i+1)<<")"<<": ";
	  gets(proname[i]);
	  cout<<"\n* Enter the amount";
	  cin>>amount[i];
	  f++;
	 }
  }
 cout<<"\n* Enter the payment type: ";
 gets(paytype);
 clrscr();
 m.border();
 cout<<"\n* \t \t \t            RECEIPT";
 cout<<"\n* \t \t \t \t  ";
 cout<<date<<"/"<<month<<"/"<<year;
 cout<<"\n* \n* \t PRODUCT NAME \t \t \t \t          AMOUNT";
 cout<<"\n* ____________________________________________________________________________"<<"\n*";
 for(int k=0;k<n;k++)
  {
	cout<<"\n* \n*      ";
	cout<<proname[k];
	cout<<" \t \t \t \t                ";
	cout<<amount[k];
  }
 cout<<"\n* _____________________________________________________________________________"<<"\n*";
 cout<<"\n* Payment type : ";
 puts(paytype);
 float sum=0;
 for(int l=0;l<n;l++)
  {
	sum+=amount[l];
  }
 cout<<"\n*"<<"The Total Amount Is  "<<sum;
 m.time_delay(5000);
}










void account_info::selectpage(char bnnn[50])         //function to display the account selection page
{
 account_info acc;     //class variable
 ifstream f;
 f.open("accinfo.dat",ios::binary);
 f.seekg(0,ios::beg);    //to position the pointer at the begining of the file
 while(f.read((char*)&acc,sizeof(acc)))
  {
	if(strcmp(bnnn,acc.acc_number)==0)
	 {
	  cout<<"\n*\t\t\tYour account balance is "<<acc.bal;
	 }
  }
 f.close();
 m.time_delay(5000);
 return;
}









void account_info::mainmenu()
{
 if(count69<1)
  {
	m.pay();   	count69++;
  }
 int n;
 account_info acc;
 do
  {
	clrscr();
	m.border();
	cout<<"\n*\t\t\t\t   MAINMENU";
	cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
	cout<<"\n*\n*\t\t(1). Check Bank Account Balance";
	cout<<"\n*\t\t(2). Check expenses";
	cout<<"\n*\t\t(3). Bank Account related Transactions";
	cout<<"\n*\t\t(4). Currency converter";
	cout<<"\n*\t\t(5). Budget";
	cout<<"\n*\t\t(6). Tax Calculation";
	cout<<"\n*\t\t(7). Change password";
	cout<<"\n*\t\t(8). Delete account";
	cout<<"\n*\t\t(9). Tips";
	cout<<"\n*\t\t(10). Schedule a payment";
	cout<<"\n*\t\t(11). Logout";
	cout<<"\n*\n*\t\t Enter your choice:";
	cin>>n;
	char number[50];
	char bnnn[50];

	switch(n)
	 {
	  case 1: strcpy(bnnn,a.select_acc());
				 a.selectpage(bnnn);
				 break;

	  case 2: m.expensespage();
				 break;

	  case 3: strcpy(number,acc.select_acc());
				 acc.bank_trans(number);
				 break;

	  case 4: m.converter();
				 break;

	  case 5: budget();
				 break;

	  case 6: m.tax();
				 break;

	  case 7: m.change_pass();
				 break;

	  case 8: a.acc_delete();
				 break;

	  case 9: m.tips();
				 break;

	  case 10: m.schedpay();
				 break;

	  case 11: m.logout();
				  break;

	  default: cout<<"\n*\n* INVALID CHOICE";

	 }
  }while(1);    // to make it an infinte loop
}










char* account_info::select_acc()       //funtion to select an account
{

 clrscr();
 m.border();
 cout<<"\n*\t\t\t\tACCOUNT SELECTION";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 ifstream f;
 f.open("accinfo.dat",ios::binary);
 int flag45=0;
 account_info acc;
 char accno[50];
 cout<<"\n*\n* Enter your bank account number: ";
 gets(accno);
 char bn[50];
 f.seekg(0,ios::beg);
 while(f.read((char*)&acc,sizeof(acc)))
  {
	if(strcmp(accno,acc.acc_number)==0)
	 {
	  strcpy(bn,accno);
	  flag45=1;
	 }
  }
 if(!flag45)
  {
	cout<<"\n* Invalid account number";
	cout<<"\n* Redirecting to the mainmenu";
	m.time_delay(1500);
	a.mainmenu();
  }
 f.close();
 return(bn);
}











void account_info::bank_trans(char number[50])               //transactions page
{
 clrscr();
 m.border();
 cout<<"\n*\t\t\t    TRANSACTIONS PAGE";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 char num[50];
 strcpy(num,number);
 int n;
 cout<<"\n*\n* \t\t\t SELECT THE OPTION YOU WISH TO PERFORM: ";       //transaction page
 cout<<"\n* 1. Add Transaction ";
 cout<<"\n* 2. Check Latest Transactions ";
 cout<<"\n* 3. Go To Main Menu";
 cout<<"\n*  ";
 cin>>n;
 ifstream f;
 int flag56=0;
 switch(n)
  {
	case 1:
			  a.atrans(num);
			  break;

	case 2:
			  clrscr();
			  m.border();
			  cout<<"\n*\t\t              YOUR LATEST TRANSACTIONS";
			  transactions trans;
			  f.open("t.dat",ios::binary|ios::in);
			  while(f.read((char*)&trans,sizeof(trans)))
				{
				 if(trans.t_EM_ID==EM_ID)
				  {
					if(((t.t_day-trans.date)<=7)&&(t.t_month==trans.month)&&(t.t_year==trans.year))
					 {
					  cout<<"\n*\n* Displaying all transactions made in the past week (in this month)";
					  cout<<"\n* Type of transaction: "<<trans.type;
					  cout<<"\n* Date of transaction: "<<trans.date<<"/"<<trans.month<<"/"<<trans.year;
					  cout<<"\n* Amount: "<<trans.amount;

					  cout<<"\n*\n*\n*";
					  flag56=1;
					 }
				  }
				}
			  if(!flag56)
			  cout<<"\n* no transaction made in the past one week";
			  f.close();
			  m.time_delay(5000);
			  break;

	case 3: return;

  }
}










void account_info::atrans(char number[50])    //function to add a transaction
{
 clrscr();
 m.border();
 cout<<"\n*\n* \t\t\t        TRANSACTIONS PAGE";
 cout<<"\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
 ofstream f3;
 f3.open("t.dat",ios::binary|ios::app);
 f3.close();
 cout<<"\n* Enter the type of transaction";
 cout<<"\n* 1. Withdrawal";
 cout<<"\n* 2. Deposit";
 cout<<"\n* 3. Transfers"<<"\n*";
 int t;
 cin>>t;
 ifstream f,f5,f9,f4,f6,f7;
 ofstream f1,f2,temptrans,temptrans2,temptrans3,temptrans4;

 switch(t)
  {
	case 1:
			  account_info acc;
			  transactions trans;
			  cout<<"\n* Enter the amount withdrawn from your bank account: ";
			  cin>>trans.amount;
			  cout<<"\n* Enter the day of the transaction (number): ";
			  cin>>trans.date;
			  cout<<"\n* Enter the month of the transaction (number): ";
			  cin>>trans.month;
			  cout<<"\n* Enter the year of the transaction: ";
			  cin>>trans.year;
			  strcpy(trans.type,"Withdrawal");
			  trans.t_EM_ID=EM_ID;          //variable to know the position of the record

			  temptrans.open("tempfile2.dat",ios::binary|ios::out);
			  f9.open("accinfo.dat",ios::binary);
			  while(f9.read((char*)&acc,sizeof(acc)))
				{
				 if(strcmp(number,acc.acc_number)==0)
				  {
					acc.bal-=trans.amount;
					cout<<"\n* Balance remaining is  : "<<acc.bal;
					temptrans.write((char*)&acc,sizeof(acc));
				  }
				 else
				  {
					temptrans.write((char*)&acc,sizeof(acc));
				  }
				}
			  f9.close();
			  temptrans.close();
			  remove("accinfo.dat");
			  rename("tempfile2.dat","accinfo.dat");
			  f1.open("t.dat",ios::binary|ios::app);
			  f1.write((char*)&trans,sizeof(trans));
			  f1.close();
			  break;

	case 2:
			  cout<<"\n* Enter the amount Deposited in your account: ";
			  cin>>trans.amount;
			  cout<<"\n* Enter the date of the transaction (number): ";
			  cin>>trans.date;
			  cout<<"\n* Enter the month of the transaction (number): ";
			  cin>>trans.month;
			  cout<<"\n* Enter the year of the transaction: ";
			  cin>>trans.year;
			  strcpy(trans.type,"Deposit");
			  trans.t_EM_ID=EM_ID;     //variable to know the position of the record

			  temptrans2.open("tempfile2.dat",ios::binary|ios::out);
			  temptrans2.close();
			  temptrans2.open("tempfile2.dat",ios::binary|ios::out);
			  f7.open("accinfo.dat",ios::binary);
			  while(f7.read((char*)&acc,sizeof(acc)))
				{
				 if(strcmp(number,acc.acc_number)==0)
				  {
					acc.bal+=trans.amount;
					cout<<"\n* Balance remaining is  : "<<acc.bal;
					temptrans2.write((char*)&acc,sizeof(acc));
				  }
				 else
				  {
					temptrans2.write((char*)&acc,sizeof(acc));
				  }
				}
			  f7.close();
			  temptrans2.close();
			  remove("accinfo.dat");
			  rename("tempfile2.dat","accinfo.dat");
			  f2.open("t.dat",ios::binary|ios::app);
			  f2.write((char*)&trans,sizeof(trans));
			  f2.close();
			  break;

	case 3:
			  int ch;
			  cout<<"\n* 1. From Your Account";
			  cout<<"\n* 2. To Your Account";
			  cin>>ch;
			  if(ch==1)
				{
				 cout<<"\n* Enter the Amount Transffered from your acount";
				 cin>>trans.amount;
				 cout<<"\n* Enter the date of the transaction (number)";
				 cin>>trans.date;
				 cout<<"\n* Enter the month of the transaction (number)";
				 cin>>trans.month;
				 cout<<"\n* Enter the year of the transaction";
				 cin>>trans.year;
				 trans.t_EM_ID=EM_ID;    //variable to know the position of the record

				 strcpy(trans.type,"Transfer");
				 temptrans3.open("tempfile2.dat",ios::binary|ios::out);
				 f4.open("accinfo.dat",ios::binary);
				 while(f4.read((char*)&acc,sizeof(acc)))
				  {
					if(strcmp(number,acc.acc_number)==0)
					 {
					  acc.bal-=trans.amount;
					  cout<<"\n* Balance remaining is  : "<<acc.bal;
					  temptrans3.write((char*)&acc,sizeof(acc));
					 }
					else
					 {
					  temptrans3.write((char*)&acc,sizeof(acc));
					 }
				  }
				f4.close();
				temptrans3.close();
				remove("accinfo.dat");
				rename("tempfile2.dat","accinfo.dat");
				f1.open("t.dat",ios::binary|ios::app);
			  f1.write((char*)&trans,sizeof(trans));
			  f1.close();
			 }
			else if (ch==2)
			 {
			  cout<<"\n* Enter the amount Transffered to your account: ";
			  cin>>trans.amount;
			  cout<<"\n* Enter the date of the transaction (number): ";
			  cin>>trans.date;
			  cout<<"\n* Enter the month of the transaction (number): ";
			  cin>>trans.month;
			  cout<<"\n* Enter the year of the transaction: ";
			  cin>>trans.year;
			  trans.t_EM_ID=EM_ID;            //variable to know the position of the record

			  temptrans4.open("tempfile2.dat",ios::binary|ios::out);
			  f6.open("accinfo.dat",ios::binary);
			  while(f6.read((char*)&acc,sizeof(acc)))
				{
				 if(strcmp(number,acc.acc_number)==0)
				  {
					acc.bal+=trans.amount;
					cout<<"\n* Balance remaining is  : "<<acc.bal;
					temptrans4.write((char*)&acc,sizeof(acc));
				  }
				 else
				  {
					temptrans4.write((char*)&acc,sizeof(acc));
				  }
				}
			  f6.close();
			  temptrans4.close();
			  remove("accinfo.dat");
			  rename("tempfile2.dat","accinfo.dat");
			  f1.open("t.dat",ios::binary|ios::app);
			  f1.write((char*)&trans,sizeof(trans));
			  f1.close();
			 }
			break;

	default: cout<<"\n* Invalid choice";
				m.time_delay(500);
				a.atrans(number);
  }

  rechar1:
  cout<<"\n* Do you wish to enter another transaction? (y/n): ";
  char ch;
  cin>>ch;
  if(ch=='y'||ch=='Y')
  a.atrans(number);
  else if(ch=='n'||ch=='N')
  a.mainmenu();
  else
  {
	cout<<"\n* invalid choice";
	m.time_delay(500);
	goto rechar1;
  }
}







void main()
{
 t.timecheck();         //calling function to know the current time
 m.start_1();        //calling the starting function
}
