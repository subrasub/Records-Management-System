#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct date
{
	int dd, mm, yy;
};

class customer
{
	char name[25], address[30];
   int tel, mob;
   date checkin, checkout;
   int stay, type, rno;
   double charges, stax, total, rent;
   double stotal, wash, drink, med, beaut, food, telcal;

  	int checkdate(date dt)
	{
  		int maxdays[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      if (dt.yy%100!=0 && dt.yy%4==0 || dt.yy%400==0)
   		maxdays[1]=29;
      if (dt.mm>=1 && dt.mm<=12)
  		{
    		if (dt.dd>=1 && dt.dd<=maxdays[dt.mm-1])
      		return 1;
    		else
      		return 0;
  		}
  		else
    		return 0;
	}

   date nextdate(date dt, int days)
	{
   	int maxdays[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      if (dt.yy%100!=0 && dt.yy%4==0 || dt.yy%400==0)
   		maxdays[1]=29;
   	dt.dd+=days;
   	while (dt.dd>maxdays[dt.mm-1])
   	{
      	dt.dd-=maxdays[dt.mm-1];
      	dt.mm++;
      	if (dt.mm==13)
      	{
         	dt.mm=1;
         	dt.yy++;
      	}
   	}
   	return dt;
	}

   public:

   void inputdate(date& dt)
	{
   	int valid;
   	do
   	{
      	cout<<"Enter Day [1-31]  ? "; cin>>dt.dd;
      	cout<<"Enter Month [1-12]? "; cin>>dt.mm;
      	cout<<"Enter Year [YYYY] ? "; cin>>dt.yy;
      	valid=checkdate(dt);
      	if (valid==0)
      		cout<<"Invalid date. Input again.\n";
   	}
   	while(valid==0);
	}

   int roomtype()
   {
  	   cout<<"\t 1. Single DX"<<endl;
      cout<<"\t 2. Double DX"<<endl;
      cout<<"\t 3. Single AC"<<endl;
      cout<<"\t 4. Double AC"<<endl;
      cout<<"\t 5. Single NAC"<<endl;
      cout<<"\t 6. Double NAC"<<endl<<endl;
      cout<<"Input Choice    ? "; cin>>type;

      switch(type)
      {
      	case 1: cout<<"Single DX"<<endl; break;
      	case 2: cout<<"Double DX"<<endl; break;
      	case 3: cout<<"Single AC"<<endl; break;
      	case 4: cout<<"Double AC"<<endl; break;
      	case 5: cout<<"Single NAC"<<endl; break;
      	case 6: cout<<"Double NAC"<<endl; break;
      }
		return type;
   }

   int roomrent()
   {
   	if(type==1)
      	charges=1200;
      else
      if(type==2)
      	charges=1700;
      else
      if(type==3)
      	charges=1000;
      else
      if(type==4)
      	charges=1300;
      else
      if(type==5)
      	charges=600;
      else
      if(type==6)
      	charges=850;
   }


   int cwash()
	{
		int s, t, b;
		cout<<"No. of shirts? "; cin>>s;
   	cout<<"No. of trousers? "; cin>>t;
   	cout<<"No. of Blazers? "; cin>>b;
   	wash=(s*30)+(t*20)+(b*50);
	}

	int cdrink()
	{
		int t, c;
   	cout<<"No. of coffee? "; cin>>c;
   	cout<<"No. of Tea? "; cin>>t;
   	drink=(c*20)+(t*15);
	}

	int cmed()
	{
		char ch;
		cout<<"Medical Aid taken? "; cin>>ch;
   	if(ch=='Y' || ch=='y')
   		med=100;
   	else
   		med=0;
	}

   int cbeaut()
   {
		char ch;
		cout<<"Beautician servies? ";cin>>ch;
   	if(ch=='Y' || ch=='y')
   		beaut=150;
   	else
   		beaut=0;
	}

	int cfood()
	{
		int l, d;
   	cout<<"Complementary Breakfast!"<<endl;
   	cout<<"No. of days Lunch? "; cin>>l;
   	cout<<"No. of days Dinner? "; cin>>d;
   	food=(l*80)+(d*100);
	}

	int ctel()
	{
		int icall, lcall;
   	cout<<"No. of Local Calls: ";cin>>lcall;
   	cout<<"No. of Intl. Calls: ";cin>>icall;
   	tel=(lcall*3)+(icall*5);
	}

   void services()
	{
   	char ch;
   	cout<<"Any Services taken?[Y/N]"; cin>>ch;
      if(ch=='Y' || ch=='y')
   	{
      	cout<<"______________________________"<<endl;
      	cout<<"\t \t SERVICES"<<endl;
			cout<<"-------"<<endl;
   		cout<<"1. Washing \n"; cwash();
      	cout<<"-------"<<endl;
      	cout<<"2. Tea/Coffee \n"; cdrink();
      	cout<<"-------"<<endl;
      	cout<<"3. Medical Aid [Y/N]\n"; cmed();
      	cout<<"-------"<<endl;
      	cout<<"4. Beautician [Y/N]\n"; cbeaut();
      	cout<<"-------"<<endl;
      	cout<<"5. Food served \n"; cfood();
      	cout<<"-------"<<endl;
      	cout<<"6. Telephone Calls \n"; ctel();
      	cout<<"-------"<<endl;
      	cout<<"Press any key to Proceed..";
   		stotal= wash+ drink+ med+ beaut+ food+ telcal;
   	}
      if(ch=='N' || ch=='n')
      {
        	stotal=0; wash=0; drink=0; med=0; beaut=0; food=0; telcal=0;
        	cout<<"Click to proceed"; getch();
      }
      else
      	cout<<"Invalid input\n";
}

	void input()
   {
   	cout<<"__________________________________"<<endl;
		cout<<"Customer name   ? "; gets(name); strupr(name);
      cout<<"Address         ? "; gets(address); strupr(address);
      cout<<"Telephone number? "; cin>>tel;
      cout<<"Mobile number   ? "; cin>>mob;

      cout<<"__________________________________"<<endl;
      cout<<"Check-in Date:    "<<endl; inputdate(checkin);
      cout<<"__________________________________"<<endl<<endl;

      cout<<"No. of days     ? "; cin>>stay; cout<<endl<<endl;

      cout<<"__________________________________"<<endl;
      checkout=nextdate(checkin, stay);
      cout<<"__________________________________"<<endl;

      cout<<"Type of room:     "<<endl; roomtype();
      cout<<"Room number: ";cin>>rno; cout<<endl;
      cout<<"__________________________________"<<endl;
      cout<<"Check-out Date: "<<checkout.dd<<'/'<<checkout.mm<<'/'<<checkout.yy<<endl;
      roomrent();
   }


   void displaybill()
   {
   	services();
      clrscr();
     	cout<<"__________________________________"<<endl;
      printf("Name: %-15s \t Room No: %-3i \t Bill No:35 \n", name, rno);
      printf("Check-in date: %02i-%02i-%04i \t Check-out date: %02i-%02i-%04i \n", checkin.dd, checkin.mm, checkin.yy, checkout.dd, checkout.mm, checkout.yy);
      cout<<"__________________________________"<<endl;
      rent= (charges*stay);
      cout<<"Room Rent      : "<<rent<<endl;
      cout<<"Service charges: "<<stotal<<endl;
      stax=0.15*(charges+stotal);
      cout<<"Sales Tax      : "<<stax<<endl;
      cout<<"__________________________________"<<endl;
      total= rent + stotal + stax;
      cout<<"TOTAL: "<<total;
   }

   void servdetail()
   {
   	cout<<"Laundry   : "<<wash<<endl;
      cout<<"Drinks    : "<<drink<<endl;
      cout<<"Medical aid: "<<med<<endl;
      cout<<"Beautician services: "<<beaut<<endl;
      cout<<"Food: "<<food<<endl;
      cout<<"Phone Calls: "<<telcal<<endl;
   }

   void searchdisplay()
   {
   	cout<<"______________________________________"<<endl;
      printf("NAME: %-15s \t ADDRESS: %-20s \n", name, address);
      printf("Telephone: %10i \t Mobile: %10i \n", tel, mob);
      printf("Type of room: %i \t Room Number: %3i \n", type, rno);
      printf("Check-in date: %02i-%02i-%04i \t Check-out date: %02i-%02i-%04i \n", checkin.dd, checkin.mm, checkin.yy, checkout.dd, checkout.mm, checkout.yy);
		printf("No. of days stay: %3i \n", stay);
   	cout<<"______________________________________"<<endl;
   }

   void cdetail()
   {
   	cout<<"______________________________________"<<endl;
      cout<<"Name: \t"<<name<<endl;
      cout<<"Room Number: \t"<<rno<<endl;
      cout<<"Contact ID: \t"<<mob<<endl;
   }
	void dispdetail()
   {
   	printf("%5i %25c %02i-%02i-%04i \n", rno, name, checkin.dd, checkin.mm, checkin.yy);
   }

   char *retname(){return name;}
   char *retad(){return address;}
   int rettel(){return tel;}
   int retmob(){return mob;}
   int retstay(){return stay;}
   int retrno(){return rno;}
   double retcharges(){return charges;}
   void updatead(char* ad){strcpy(address,ad);}
   void updatetype(int r){type=r; roomrent();}
   void updateph(double p){tel=p;}
   void updatemob(double m){mob=m;}

};

void addrec()
{
	ofstream fout("Customer.dat", ios::binary|ios::app);
	customer a;
	int n;
	clrscr();
	cout<<"Number of records? "; cin>>n;
	for (int k=0; k<n; k++)
	{
		cout<<"Record #"<<(k+1)<<endl;
      a.input();
		fout.write((char*)&a, sizeof(a));
		cout<<endl<<endl;
	}
	fout.close();
	cout<<"Press any key.";
getch();
}

void readdetails()
{
	ifstream fin("Customer.dat", ios::binary);
	customer a;
   while(fin.read((char*)&a, sizeof(a)))
   {
   	a.searchdisplay();
      cout<<"_________________________________________ \n";
   }
   fin.close();
   cout<<"Press any key.";
getch();
}

void readserv()
{
  	ifstream fin("Customer.dat", ios::binary);
	customer a;
   int found=0, rno;
	clrscr();
	cout<<"Services for room no. ? "; cin>>rno;
   while(fin.read((char*)&a, sizeof(a)))
   {
   	if(a.retrno()==rno)
      {
        	a.servdetail(); found=1;
      	cout<<"_________________________________________ \n";
   	}
   }
   if(found==0)
   	cout<<"Room not found!\n";
   fin.close();
getch();
}

void readbill()
{
	fstream fio("Customer.dat", ios::binary|ios::in|ios::out);
	customer a;
	int found=0, rno;
	clrscr();
	cout<<"Bill for room no. ? "; cin>>rno;
   while (fio.read((char*)&a, sizeof(a)))
  	{
  		if (rno==a.retrno())
		{
			a.displaybill();
         fio.seekg(-sizeof(a), ios::cur);
         fio.write((char*)&a, sizeof(a));
      	found=1;
   	}
  	}
  	if(found==0)
  		cout<<"Room no. not found!\n";
	fio.close();
   cout<<endl<<endl;
	cout<<"Press any key.";
getch();
}

void readsearch()
{
	ifstream fin("Customer.dat", ios::binary);
	customer a;
	int found=0, rno;
	clrscr();
	cout<<"Search for room no. ? "; cin>>rno;
	while (fin.read((char*)&a, sizeof(a)))
	{
   	if (rno==a.retrno())
		{
			a.cdetail();
      	found=1;
   	}

   }
   if(found==0)
   	cout<<"Room no. not found!\n";
	fin.close();
   cout<<endl<<endl;
	cout<<"Press any key.";
getch();
}

void editad()
{
	fstream f("Customer.dat", ios::binary|ios::in|ios::out);
	customer a;
   int found=0, rno;
   clrscr();
   cout<<"Customer's room no. ?";cin>>rno;
   while(f.read((char*)&a, sizeof(a)))
   	if(a.retrno()==rno)
      {
   		char ad[80];
         cout<<"Input new address?"; gets(ad);
         a.updatead(ad);
         f.seekg(-sizeof(a), ios::cur);
         f.write((char*)&a, sizeof(a));
         found=1; break;
      }
   if(found==0)
   	cout<<"Record not found!\n";
   f.close();
   cout<<endl<<endl;
   cout<<"Press any key.\n";
getch();
}

void edittype()
{
	fstream f("Customer.dat", ios::binary|ios::in|ios::out);
	customer a;
   int found=0, rno;
   clrscr();
   cout<<"Customer's room no. ?";cin>>rno;
   while(f.read((char*)&a, sizeof(a)))
   	if(a.retrno()==rno)
      {
   		int r;
         cout<<"\t 1. Single DX"<<endl;
      	cout<<"\t 2. Double DX"<<endl;
      	cout<<"\t 3. Single AC"<<endl;
      	cout<<"\t 4. Double AC"<<endl;
      	cout<<"\t 5. Single NAC"<<endl;
      	cout<<"\t 6. Double NAC"<<endl<<endl;
         cout<<endl;
         cout<<"Input type of room?"; cin>>r;
         a.updatetype(r);
         f.seekg(-sizeof(a), ios::cur);
         f.write((char*)&a, sizeof(a));
         found=1; break;
      }
   if(found==0)
   	cout<<"Record not found!\n";
   f.close();
   cout<<endl<<endl;
   cout<<"Press any key.\n";
getch();
}

void editphone()
{
	fstream f("Customer.dat", ios::binary|ios::in|ios::out);
	customer a;
   int found=0, rno;
   clrscr();
   cout<<"Customer's room no. ?";cin>>rno;
   while(f.read((char*)&a, sizeof(a)))
   	if(a.retrno()==rno)
      {
   		double phone;
         cout<<"Input new Phone no.?"; cin>>phone;
         a.updateph(phone);
         f.seekg(-sizeof(a), ios::cur);
         f.write((char*)&a, sizeof(a));
         found=1; break;
      }
   if(found==0)
   	cout<<"Record not found!\n";
   f.close();
   cout<<endl<<endl;
   cout<<"Press any key.\n";
getch();
}

void editmob()
{
	fstream f("Customer.dat", ios::binary|ios::in|ios::out);
	customer a;
   int found=0, rno;
   clrscr();
   cout<<"Customer's room no. ?";cin>>rno;
   while(f.read((char*)&a, sizeof(a)))
   	if(a.retrno()==rno)
      {
   		double mob;
         cout<<"Input new mobile no.?"; cin>>mob;
         a.updatemob(mob);
         f.seekg(-sizeof(a), ios::cur);
         f.write((char*)&a, sizeof(a));
         found=1; break;
      }
   if(found==0)
   	cout<<"Record not found!\n";
   f.close();
   cout<<endl<<endl;
   cout<<"Press any key.\n";
getch();
}

void delroom()
{
	ifstream fin("Customer.dat", ios::binary);
	ofstream fout("TEMP.DAT", ios::binary);
	customer a;
	int found=0, rno;
	clrscr();
	cout<<"Room no. to be cancelled? "; cin>>rno;
	while (fin.read((char*)&a, sizeof(a)))
	if (rno==a.retrno())
	{
		cout<<"Room Cancelled.";
		found=1;
	}
	else
	fout.write((char*)&a, sizeof(a));
	if (found==0)
		cout<<rno<<": not found in the list! \n";
	fin.close();
	fout.close();
	remove("Customer.dat");
	rename("TEMP.DAT", "Customer.dat");
   cout<<"Press any key to return.";
getch();
}

void delname()
{
	ifstream fin("Customer.dat", ios::binary);
	ofstream fout("TEMP.DAT", ios::binary);
	customer a;
	int found=0;
   char name[25];
  	clrscr();
	cout<<"Name to search? "; gets(name);
	while (fin.read((char*)&a, sizeof(a)))
	if (strcmpi(name, a.retname())==0)
	{
		cout<<"Room Cancelled.";
		found=1;
	}
	else
	fout.write((char*)&a, sizeof(a));
	if (found==0)
		cout<<name<<": not found in the list! \n";
	fin.close();
	fout.close();
	remove("Customer.dat");
	rename("TEMP.DAT", "Customer.dat");
   cout<<"Press any key to return.";
getch();
}

void delphone()
{
	ifstream fin("Customer.dat", ios::binary);
	ofstream fout("TEMP.DAT", ios::binary);
	customer a;
	int found=0, phone;
	clrscr();
	cout<<"Room no. to be cancelled? "; cin>>phone;
	while (fin.read((char*)&a, sizeof(a)))
	if (phone==a.rettel())
	{
		cout<<"Room Cancelled.";
		found=1;
	}
	else
	fout.write((char*)&a, sizeof(a));
	if (found==0)
		cout<<phone<<": not found in the list! \n";
	fin.close();
	fout.close();
	remove("Customer.dat");
	rename("TEMP.DAT", "Customer.dat");
   cout<<"Press any key to return.";
getch();
}

void delmobile()
{
	ifstream fin("Customer.dat", ios::binary);
	ofstream fout("TEMP.DAT", ios::binary);
	customer a;
	int found=0, mob;
	clrscr();
	cout<<"Room no. to be cancelled? "; cin>>mob;
	while (fin.read((char*)&a, sizeof(a)))
	if (mob==a.retmob())
	{
		cout<<"Room Cancelled.";
		found=1;
	}
	else
	fout.write((char*)&a, sizeof(a));
	if (found==0)
		cout<<mob<<": not found in the list! \n";
	fin.close();
	fout.close();
	remove("Customer.dat");
	rename("TEMP.DAT", "Customer.dat");
   cout<<"Press any key to return.";
getch();
}

void searchroom()
{
	ifstream fin("Customer.dat", ios::binary);
	customer a;
	int found=0, rno;
	clrscr();
	cout<<"Room Number? "; cin>>rno;
	while (fin.read((char*)&a, sizeof(a)))
	if (rno==a.retrno())
	{
		a.searchdisplay();
		found=1; break;
	}
	if (found==0)
		cout<<rno<<": not found in the list! \n";
	fin.close();
   cout<<"Press any key to return.";
getch();
}

void searchphone()
{
	ifstream fin("Customer.dat", ios::binary);
	customer a;
	int found=0, tel;
	clrscr();
	cout<<"Telephone to search? "; cin>>tel;
	while (fin.read((char*)&a, sizeof(a)))
	if (tel==a.rettel())
	{
		a.searchdisplay();
      found=1; break;
	}
	if (found==0)
		cout<<tel<<" not found in the file\n";
	fin.close();
   cout<<"Press any key to return.";
getch();
}

void searchmobile()
{
	ifstream fin("Customer.dat", ios::binary);
	customer a;
	int found=0, mobile;
	clrscr();
	cout<<"Mobile to search? "; cin>>mobile;
	while (fin.read((char*)&a, sizeof(a)))
	if (mobile==a.retmob())
	{
		a.searchdisplay();
		found=1; break;
	}
	if (found==0)
	cout<<mobile<<" not found in the file\n";
	fin.close();
	cout<<"Press any key to return.";
getch();
}

void searchname()
{
	ifstream fin("Customer.dat", ios::binary);
	customer a;
	int found=0;
   char name[25];
  	clrscr();
	cout<<"Name to search? "; gets(name);
	while (fin.read((char*)&a, sizeof(a)))
	if (strcmpi(name, a.retname())==0)
	{
		a.searchdisplay();
		found=1; break;
	}
	if (found==0)
	cout<<name<<": not found in the file\n";
	fin.close();
	cout<<"Press any key to return.";
getch();
}

void displaymenu()
{
	int ch;
   do
   {
   	clrscr();
   	cout<<"1. Display bill"<<endl;
      cout<<"2. Diplay detail of a customer"<<endl;
      cout<<"3. Display all customers"<<endl;
      cout<<"4. Display service cost"<<endl;
      cout<<"0. Return back"<<endl;
      cout<<endl<<"Input choice? ";cin>>ch;
      switch(ch)
      {
      	case 1: readbill(); break;
         case 2: readsearch(); break;
         case 3: readdetails(); break;
      	case 4: readserv(); break;
      }
   }
   while(ch);
}

void searchmenu()
{
	int ch;
   do
   {
   	clrscr();
   	cout<<"Search for: "<<endl;
      cout<<"1. Customer Name"<<endl;
      cout<<"2. Room Number"<<endl;
      cout<<"3. Mobile Number"<<endl;
      cout<<"4. Phone Number"<<endl;
      cout<<"0. Return Back"<<endl;
      cout<<endl<<"Input choice? ";cin>>ch;
      switch(ch)
      {
      	case 1: searchname(); break;
         case 2: searchroom(); break;
         case 3: searchmobile(); break;
         case 4: searchphone(); break;
      }
   }
   while(ch);
}

void deletemenu()
{
	int ch;
   do
   {
   	clrscr();
   	cout<<"Delete on basis of: "<<endl;
   	cout<<"1.Room"<<endl;
      cout<<"2.Name"<<endl;
      cout<<"3.Phone"<<endl;
      cout<<"4.Mobile"<<endl;
      cout<<"0. Return Back"<<endl;
      cout<<endl<<"Input choice? ";cin>>ch;\
      switch(ch)
      {
      	case 1: delroom(); break;
         case 2: delname(); break;
         case 3: delphone(); break;
         case 4: delmobile(); break;
      }
   }
   while(ch);
}

void editmenu()
{
	int ch;
   do
   {
   	clrscr();
   	cout<<"1. Edit Address of Customer"<<endl;
      cout<<"2. Edit room type of Customer"<<endl;
      cout<<"0. Return back"<<endl;
      cout<<endl<<"Input choice? ";cin>>ch;
      switch(ch)
      {
      	case 1: editad(); break;
         case 2: edittype(); break;
      }
   }
   while(ch);
}

void main()
{
	int ch;
   do
   {
   	clrscr();
   	cout<<"1. Add Records"<<endl;
      cout<<"2. Display Records"<<endl;
      cout<<"3. Search Records"<<endl;
      cout<<"4. Delete Records"<<endl;
      cout<<"5. Edit Records"<<endl;
      cout<<"0. Exit Program"<<endl;
      cout<<endl<<"Input choice? ";cin>>ch;

      switch(ch)
      {
      	case 1: addrec(); break;
         case 2: displaymenu(); break;
         case 3: searchmenu(); break;
         case 4: deletemenu(); break;
         case 5: editmenu(); break;
      }
   }
   while(ch);
}





















































































































































































