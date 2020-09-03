#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include<unistd.h>
#include<conio.h>
using namespace std;
class parkingg
{
	private:
		string number;
		string token;
		string type;
		 int price,p;
		 
		public:
			parkingg()
			{
				price=0;
			}
			int insert_car()
			{ 
			fstream parking,bank;
		
				cout<<"\n\n\t\t\t\t\t_____________---INSEERT DATA---____________";
				cout<<"\n\n\n\t\tCar Price :50\t\tRiksha Price :30\t\tBike Price :20\t\tOthers :100";
				cout<<"\n\n\tEnter  type : ";
				cin>>type;
				cout<<"\n\tEnter "<<type<<" number : ";
				cin>>number;
				cout<<"\n\tEnter "<<type<<" token : ";
				cin>>token;
					parking.open("parking stand.txt",ios::app|ios::out);
				parking<<"   "<<type<<"     "<<number<<"      "<<token<<endl;
				cout<<"\n\tEnter price : ";
				cin>>p;
				price=price+p;
				bank.open("bankk.txt",ios::out);
				bank<<price<<endl;
				bank.close();
				parking.close();
			}
			int view_car()
			{
				fstream parking;
					parking.open("parking stand.txt",ios::in);
					if(!parking)
					{
						cout<<"\n\tFile opening error...!"<<endl;
					}
						
					else
					{
						cout<<"\n\n\t----------------------------------------------------------";
							cout<<"\n\t| TYPE \t\t\tNumber"<<"\t\t\t  Token "<<" |";
								cout<<"\n\t----------------------------------------------------------";
						parking>>type>>number>>token;
						while(!parking.eof())
						{
							
								cout<<"\n\t "<<type<<"\t\t\t"<<number<<"\t\t\t "<<token<<endl;
														parking>>type>>number>>token;
						}
					}
					parking.close();
			}
			int search_car()
			{int c;
			string t;
			fstream parking;
			
					parking.open("parking stand.txt",ios::in);
					if(!parking)
					{
							cout<<"\n\tFile opening error...!"<<endl;
					}
					else 
					{	cout<<"\n\n\tEnter token number : ";
				cin>>t;
					parking>>type>>number>>token;
					while(!parking.eof())
					{
					
						if(t==token)
						{
						system("cls");
						cout<<"\n\n\t-------------------------------------------------------------------------";
							cout<<"\n\t| TYPE \t\t\tNumber of "<<type<<"\t\t\tToken of "<<type<<"    |";
								cout<<"\n\t-------------------------------------------------------------------------";
								cout<<"\n\t "<<type<<"\t\t\t"<<number<<"\t\t\t\t"<<token<<endl;
				
							c++;
							}
								parking>>type>>number>>token;			
					}}
						parking.close();
					if(c==0)
					{
						cout<<"\n\n\tRecord not found....!";
						
					}
				
			}
			int del_car()
			{ 
				string t;
				int c=0;
				fstream parking,parking1;
				//parking1.open("parking1 stand.txt",ios::out|ios::app);
				parking.open("parking stand.txt",ios::in);
				if(!parking)
				{
					cout<<"\n\tfile opening error";
				}
				cout<<"\n\n\t\tEnter token number for delete record : ";
				cin>>t;
				parking1.open("parking1 stand.txt",ios::out|ios::app);
					parking>>type>>number>>token;
					while(!parking.eof())
					{
					
						if(t==token)
						{
						system("cls");
					     	cout<<"\n\n\t\t\tRecord delete sucessfully...!";
							c++;
							}
							else
							{
								parking1<<"  "<<type<<"    "<<number<<"    "<<token<<endl;
							}
								parking>>type>>number>>token;			
					}
					if(c==0)
					{
							cout<<"\n\n\tRecord nor found....!";
					}
						parking1.close();
						parking.close();
					remove("parking stand.txt");
					rename("parking1 stand.txt","parking stand.txt");
					}
					int bank_a()
					{   
					    fstream bank;
						
						if(!bank)
						{
							cout<<"\n\n\t\tFile opening error...!";
						}	
						bank.open("bankk.txt",ios::in);
						bank>>price;
							cout<<"\n\n\tTotal amount in bank : "<<price<<endl;
			               getch();
			              // system("cls");
						bank.close();
					}
					int park_menu()
					{int a;
							
					     b:	cout<<"\n\t\t---------------------------------";
	                        cout<<"\n\t\t|\t1:insert data\t\t|";
	                        cout<<"\n\t\t|\t2:view data\t\t|";
                          	cout<<"\n\t\t|\t3:search car\t\t|";
                         	cout<<"\n\t\t|\t4:delete data\t\t|";
                         	cout<<"\n\t\t|\t5:Bank\t\t\t|";
                         	cout<<"\n\t\t---------------------------------";
	cout<<"\nchoice : ";
	cin>>a;
	system("cls");
	switch(a)
	{
	case 1:
	         insert_car();
	         getch();
	         system("cls");
	         goto b;
	break;
    case 2:
    	     view_car();
    	       getch();
	         system("cls");
	         goto b;
    break;
	case 3:
		     search_car();
		       getch();
	         system("cls");
		     goto b;
	break;
	case 4:
			 del_car();
			   getch();
	         system("cls");
			 goto b;
	case 5:
			 bank_a();
			   getch();
	         system("cls");
			 goto b;
	break;
	default:
			 cout<<"\n\n\tINvalid choice";
			 goto b;
}
					}
};
int main()
{int a;
	parkingg p;
    p.park_menu();
}
