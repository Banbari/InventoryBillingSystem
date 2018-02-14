#ifndef H_M
#define H_M
#include<string>
#include<string.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<math.h>
#include<time.h>
using namespace std;
class customer 
{
public:
	int custm_id;
	int custm_age;
	int check_inyear;
	int check_inmonth;
	int check_indate;
	char roomtype[20];
	char custm_name[30];
	int room_charge;
	int compare(char[]);
	char custm_occupation[20];
	int getdata();
	void putdata();

	long total; //variable for Generate Bill
	int food;
	long room;
	float ser;
	int t;
	int oc;
	int r_day;

public:
	void welcomescreen();
	void login_screen();
	void add_customer();
	void delete_customer();
	void update_customer();
	int search_customer();
	void main_screen();
	void display_customer();
	void checkout_customer();
	void room_detail();
	void generate_bill();
	void room_bill();
	
};
#endif


void customer::welcomescreen()
{
	system("cls");
    cout<<  endl << endl << endl<< endl;
	cout<<"                           COMPUTERISED MANAGEMENT SYSTEM  "<<endl;
	cout<<"  	                       APIIT SD INDIA, PANIPAT       "<< endl;
	cout<<"                             INDIVIDUAL  ASSINGMENT         "<< endl;
	cout<<"                                       ON                   "<< endl;
	cout<<"                       Further Programming Concepts in C++  "<< endl;
	cout<<"                                  (CE00314-2)               "<<endl;
	cout<<"              ____________________________________________________  "<< endl;
	cout<<  endl << endl << endl<< endl;
	cout<<"                  SUBMITTED BY:		      SUBMITTED TO:     "<<endl;
	cout<<"                   Prince kumar          Ms. Deepti Dhingra   "<<endl;
	cout<<"                   (PT082219)               (LECTURER)      "<<endl;
	cout<<  endl << endl;
	cout<<"              Press Enter to continue...." << endl << endl << endl << endl;
    getch();
}


void customer::login_screen()
{
	time_t t;
	system("cls");
	t=time(NULL);
	cout<<"\n                                                        "<<ctime(&t);
	customer c;
	t -= 24L*60L*60L;
	char choice;
	cout<<  endl << endl << endl<< endl;
	cout<<"                            LOGIN SCREEN\n";
	cout<<"              ____________________________________________________  "<< endl;
	cout<<"                          1.Administrator Login\n";
	cout<<"                          2.customer Login\n";
	cout<<"                          3.Exit\n";
	cout<<"\n\n\n";
	cout<<"Enter Choice::   ";
	cin>>choice;
	switch(choice)
	{
	case'1':
		system("cls");
		main_screen();
		
		break;
	case '2':
		search_customer();
		break;
	case'3':
		exit(0);
		break;
	default:
		cout<<"wrong choice entered";
		_getch();
	}
	login_screen();
}

void customer :: main_screen()
{
	char choice;
	start:
	cout<<"Enter your Choice\n1-Add New Customer\n2-Search Customer\n3-Delete Customer\n4-Checkout Customer\n0-Exit\n";
	cin>>choice;
	switch(choice)
	{
		case '1':add_customer();
				break;
		case '2':search_customer();
				break;
		case '3':delete_customer();
				break;
		case '4':checkout_customer();
				break;
		case '0':return;
		defaule:
				cout<<"Wrong Choice\n";
				_getch();
				goto start;
	}
}
void customer::add_customer()
{
	customer c;
	ofstream outf;
    outf.open("customer",ios::out|ios::app|ios::binary);
    if(c.getdata()==1)
    outf.write((char*)&c,sizeof(c));
    outf.close();
    _getch();

}

int customer::getdata()
{
	cout<<"\nEnter customer CheckIn Date : ";
	START:
	cout<<"\n--------------------------------";
	cout<<"\nYear : ";
	cin>>check_inyear;
	cout<<"\nMonth : ";
	cin>>check_inmonth;
	cout<<"\nDate : ";
	cin>>check_indate;
	cout<<"\nEnter Room Type : ";
	cin>>roomtype;
cout<<"\nEnter Room Charge : ";
	cin>>room_charge;
if((check_inmonth==2) && (check_indate>29))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    goto START;
  }
  if((check_inmonth>12)||(check_indate>31))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    goto START;
  }
  if((check_inmonth==4||check_inmonth==6||check_inmonth==9||check_inmonth==11) && (check_indate>30))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    goto START;
  }
  if((check_inyear%4)!=0 && (check_inmonth==2) && (check_indate>28))
  {
    cout<<"wrong input!!!\n";
    cout<<"\nenter the date again....\n";
    goto START;
  }
  cout<<"Enter Customer Name : ";
  cin>>custm_name;
cout<<"\t\t\t\tUser Name = ";
char username[26];
	cin>>username;
	if(strcmp(username,"admin")==0)
	{
		string pass ="";
		char ch;
		cout <<"\n\t\t\t\tPassword  = ";
		ch = _getch();
		while(ch != 13)
		{
			pass.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		if(pass == "admin")
		{
			cout <<"\n\t\t"<< "Access granted";
			return 1;
		}
	}
	return 0;
}

int customer::search_customer()
{
	fstream file;
    customer c;
    int i=1;
    char nam[25];
    file.open("customer",ios::in);
	cout<<"\t\t\t\t    customer Detail \n";
    cout<<"\t\t\t_________________________________ \n\n";
    cout<<"\t\t\t\t\n Enter name to Search: ";
	cin>>nam;
    file.seekg(0,ios::beg);
    while(file.read((char *) &c, sizeof(customer)))
      {
         if(c.compare(nam))
     {
    cout<<"\t\t\t\t custm_id"<<"              "<<"custm_name \n"<<endl;
    cout<<"                      "<<c.custm_id<<"              "<<c.custm_name ;
    cout<<"\n\t\t\t_________________________________________ ";
	cout<<"\n\t\t\t     ...Thank you for using ^_^ ... ";
	return 1;
   i=0;
   break ;
  }
 }
 file.close() ;
 if(i)
 {
  cout<<"Sorry!!!! Record Not found";
 }
 return 0;
 //getch();
}

int customer::compare(char *temp_name)
{
	return strcmp(custm_name,temp_name);
}

void customer::delete_customer()
{
	fstream file;
    fstream temp;
	temp.open("tempdata.txt",ios::out);
	customer c;
    int i=1;
    char nam[25];
    file.open("customer",ios::in);
	cout<<"\t\t\t\t  All customer Detail \n";
    cout<<"\t\t\t_____________________________\n\n";
    cout<<"\t\t\t\t\n Enter name to Search: ";
	 cin>>nam;
     file.seekg(0,ios::beg);
     while(file.read((char *) &c, sizeof(customer)))
  {
         if(!c.compare(nam))
       {
		   cout<<"\t\t\t\t custm_id"<<"              "<<"custm_name\n"<<endl;
           cout<<"                               "<<c.custm_id<<"              "<<c.custm_name;

           i=0;
           temp.write((char *)&c,sizeof(customer));
  
      }
   }
	 file.close() ;
     temp.close();
     remove("customer");
     rename("tempfile.txt","customer");

 getch();
}


void customer::checkout_customer()
{
	system("cls");
	cout<<"\n\t\t\t_______________________________________"<<endl;
	cout<<"\n\t\t\t\t  HOTEL MANAGEMENT SYSTEM "<<endl;
	cout<<"\n\t\t\t_______________________________________\n\n"<<endl;
	cout<<"\t\t\t\t  All customer Detail \n";
	cout<<"Enter Customer Name : ";
	if(search_customer())
	{
		generate_bill();
		//delete_customer();
	}
}



class Generatebill:public customer
{
public :
	int r_charge;
	char custm_name[25];
	char b;

public:

	void calculate()
	{
		system("cls");

		  cout<<"\n Enter Room type:";
						  cout<<"\n Select 1 for Super Luxary \n Select 2 for Luxary \n Select 3 for Delux \n";
					      cin>>b;
					      if(b=1)
					      {
							  r_charge=4000;
						  }
						  else
						  if(b=2)
						  {
							  r_charge=3000;
						  }
						  else
							  if(b=3)
							  {
								  r_charge=2000;
							  }
							  else{
					      cout<<"\n Wrong choice ...";
						  cout<<"\n ERROR: Room is not allocated.";
						cout<<"\n Bill cannot be created ";
							  }
	   
	   cout<<"\n Enter the bill amount of restaurant:";
	   cin>>food;
	   cout<<"\n Enter other charges:";
	   cin>>oc;
	   cout<<"\n Enter customer name:";
	   cin>>custm_name;
		cout<<"\n Enter number of days:";
	   cin>>r_day;
		room= r_charge * r_day;
	   t=(int) room + food + oc;
	   ser=(int)(0.05*t);
	   total=t+ser;
	  }

	void display_bill()
	  {
	   system("CLS");
	   cout<<"\n________________________________________________________________________________";
	   cout<<"\n                              Marriott Luxury Hotel                       ";
	   cout<<"\n                        ____________________________________                  ";
	   cout<<"\n                               Chandigarh , Punjab-070.                        ";
	   cout<<"\n                                   Tel :- 12253636                               ";
	   cout<<"\n--------------------------------------------------------------------------------";
	   cout<<"\n      Customer name : "<<custm_name;
	   cout<<"\n                              ";
	   cout<<"\n      Stayed for "<<r_day<<" days";
	   cout<<"\n      Room charges    : "<<r_charge<<"(Per day)";
	   cout<<"\n      Room charges    : "<<room<<"(total)";
	   cout<<"\n      Restaurant bill : "<<food;
	   cout<<"\n      Other charges   : "<<oc;
	   cout<<"\n                          Ser.tax % = 5%";
	   cout<<"\n                          Ser.tax   ="<<ser;
	   cout<<"\n      Bill Amount >>>>>> Rs "<<total;
	   cout<<"\n                              ";
	   cout<<"\n      THANK YOU !!!!!";
	   cout<<"\n      Visit Again !";
	  }
	  
  };


void customer::generate_bill()
{
	Generatebill b;
	b.calculate();
	b.display_bill();

}




int main()
{
	customer view;
	view.welcomescreen();
	view.login_screen();
	return 1;
	
}



