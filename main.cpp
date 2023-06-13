#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <conio.h>
#include "Complain.h"
#include "Arcade.h"
#include "Faculty.h"
#include "Hostel.h"
#include "Other.h"
#include "User.h"
#include "Student.h"
#include "Staff.h"

using namespace std;

int displayMenu();
void studentInfo(string&,string&);
void staffInfo(string&,string&,string&);
int readStudent(Student []);
int readStaff(Staff []); 
int complainMenu();
int viewMenu(); 

int displayMenu(){
	//system("cls");
	int option;
	cout<<"\n";
    cout<<"\t\t ================================================\n";
	cout<<"\t\t|           Complaint Management System          |\n";
	cout<<"\t\t ================================================\n\n\n";
	cout<<"\t\t-------------------------------------------------\n";
	cout<<"\t\t|\t1. Student \t\t\t\t|\n";
	cout<<"\t\t-------------------------------------------------\n";
	cout<<"\t\t-------------------------------------------------\n";
	cout<<"\t\t|\t2. Staff \t\t\t\t|\n";
	cout<<"\t\t-------------------------------------------------\n";
	cout<<"\t\t-------------------------------------------------\n";
	cout<<"\t\t|\t3. EXIT \t\t\t\t|\n";
	cout<<"\t\t-------------------------------------------------\n\n";

    cout<<"\t\tInput an option: ";
	cin>>option;
	cin.ignore();
	
	return option;
}

void studentInfo(string& name, string& matricNum){
	
	cout<<"Login Page for Student"<<endl;
	cout<<"Enter your name: ";
	getline(cin,name);
	cout<<"Matric No: ";
	getline(cin,matricNum);
	
	return;
}
//
void staffInfo(string &name, string &staffID, string &password){
	cout<<"Login Page for Staff"<<endl;
	cout<<"Enter your name: ";
	getline(cin,name);
	cout<<"Enter your staff id: ";
	getline(cin,staffID);
	cout<<"Enter password: ";
	password.clear();
	char p;
	int i=0;
	do {
		p = getch();
		if (p == '\n' || p == 13) {  // Terminate loop if Enter key is pressed
			cout << endl;
			break;
		} else if (p == '\b') {  // Handle Backspace key
			if (!password.empty()) {
				cout << "\b \b";
				password.pop_back();
			}
		} else {
			cout.put('*');
			password.push_back(p);
		}
	} while (true);
	
//	cout<<password<<endl;
	return;
}

int readStudent(Student std[]){
	ifstream fStd;
	int count = 0;
	string name,matricNum;
	
	fStd.open("StudentList.txt");
	
	if(!fStd)
	{
		cout<<"File not found!!!"<<endl;
		exit(0);
	}
//	else
//		cout<<"Student file have been found"<<endl;
	
	while(getline(fStd,name,','))
	{
		getline(fStd,matricNum,'\n');
		std[count].setUsername(name);
		std[count].setMatricNum(matricNum);
//		cout<<std[count].getStudentName()<<"\t"<<std[count].getMatricNum()<<endl;
		count++;
	}
	
	return count;
}

int readStaff(Staff sta[])
{
	ifstream fSta;
	fSta.open("StaffList.txt");
	int count = 0;
	string name,id,password;

	if(!fSta)
	{
		cout<<"File not found!!!"<<endl;
		exit(0);
	}
//	else
//		cout<<"Staff file have been found"<<endl;

	while(getline(fSta,name,','))
	{
		getline(fSta,id,',');
		getline(fSta,password,'\n');
		sta[count].setUsername(name);
		sta[count].setStaffID(id);
		sta[count].setPassword(password);
//		cout<<sta[count].getStaffName()<<"\t"
//			<<sta[count].getStaffID()<<"\t"
//			<<sta[count].getPassword()<<endl;
		count++;
	}
	
	return count;

}

int complainMenu(){
	int option;
	
	//system("cls");
	cout<<"Which category you want to complain?"<<endl
		<<"1. Arcade\n"
		<<"2. Faculty\n"
		<<"3. Hostel\n"
		<<"4. Other\n"
		<<"\nEnter your option: ";
	cin >> option;
	return option;
}

int viewMenu(){
	int option;
	//system("cls");
	cout<<"Which type of complain do you want view?\n"
		<<"1. Arcade\n"
		<<"2. Faculty\n"
		<<"3. Hostel\n"
		<<"4. Other\n"
		<<"5. All of above\n"
		<<"\nEnter your option: ";
	//cin>>option;
	cin>>option;
	return option;
}

int verifyStudent(Student s[], int cnt, string _name, string _matricNum){
	for(int i=0 ; i<cnt ; i++)
	{
		if(_name == s[i].getStudentName())
		{
			if(_matricNum == s[i].getMatricNum())
				return i;
		}
	}
	
	return -1;
}

int verifyStaff(Staff s[], int cnt, string _name, string _staffID, string _pw){
	for(int i=0 ; i<cnt ; i++)
	{
		if(_name == s[i].getStaffName())
		{
//			cout<<_name<<'\t'<<_staffID<<'\t'<<_pw<<endl;
			if(_staffID == s[i].getStaffID())
				if(_pw == s[i].getPassword())
					return i;
		}
	}
	
	return -1;
}

string descComplain(){
	string com;
	cin.ignore();
	cout<<"Please describe your complaint: ";
	getline(cin,com);
	return com;
}




int main(){
	
	int opt,opt2;
	string name, id, pw;
	int stdbetul, staffbetul;
	Student student[10];
	Staff staff[5];
	Complain *comp;
	Arcade a;
	Faculty f;
	Hostel h;
	Other o;
	string desc;
	int stdCount = readStudent(student);
	int staCount = readStaff(staff);
	int i=0;
	char yesNo;
	
	do{
		do
		{
			opt = displayMenu();
		}while(opt!=1 && opt!=2 && opt!=3);
		
			switch(opt)
			{
				case 1 :system("cls");
						studentInfo(name,id);
						do
						{
							stdbetul = verifyStudent(student,stdCount,name,id);
							if(stdbetul==-1)
								{
									system("cls");
									cout<<"Log in failed, Please try again"<<endl;
									studentInfo(name,id);
								}
							
						
						}while(stdbetul== -1);
				
						if(stdbetul>=0 && stdbetul<=9)
						{
							system("cls");
							cout<<"Log in Successfully!"<<endl; 
						}
							
						do
						{
							do
							{
								opt2 = complainMenu();
								if(opt2<1 || opt2>4)
								{
									system("cls");
									cout<<"Please enter invalid option(1-4)."<<endl;
								}
							}while(opt2<0 || opt2>4);
							
							system("cls");
							if(opt2 == 1)
							{
								desc = descComplain();
								a.setArcadeDesc(desc);
								student[stdbetul].linkArcade(a);
							}
							else if(opt2 == 2)
							{
								desc = descComplain();
								f.setDescription(desc);
								student[stdbetul].linkFaculty(f);
							}
							else if(opt2 == 3)
							{
								desc = descComplain();
								h.setDescription(desc);
								student[stdbetul].linkHostel(h);	
							}
							else if(opt2 == 4)
							{
								desc = descComplain();
								o.setDescription(desc);
								student[stdbetul].linkOther(o);
							}
					
							cout<<"Do you want to make more complain?(Y/N) -> ";
							cin>>yesNo;
							if(yesNo == 'Y' || yesNo == 'y')
								system("cls");
								
						}while(yesNo == 'Y' || yesNo == 'y');
				
						student[stdbetul].displayComplain();
						cout<<"\nPress any key to return to main page...";
						_getch();
						system("cls");
				
						break;
		
				case 2 :system("cls");
						staffInfo(name,id,pw);
						do
						{
							staffbetul = verifyStaff(staff,staCount,name,id,pw);
							if(staffbetul==-1)
							{
								system("cls");
								cout<<"Log in failed, Please try again"<<endl;
								staffInfo(name,id,pw);
							}
						}while(staffbetul == -1);
				 
						if(stdbetul>=0 && stdbetul<=4)
						{
							system("cls");
							cout<<"Log in Successfully!"<<endl;
						}
				 			
				 		do
						{
				 			do
							{
								opt2 = viewMenu();
								if(opt2<1 || opt2>5)
								{
									system("cls");
									cout<<"Please enter invalid option(1-5)."<<endl;
								}
							}while(opt2<1 || opt2>5);	
						
						
							if(opt2 == 1)
							{
								comp = new Arcade[10];
								for(int i=0 ; i<10 ; i++)
								{
									comp[i].displayOutput();
								}
					
							}
							else if(opt2 == 2)
							{
								comp = new Faculty[10];
								for(int i=0 ; i<10 ; i++)
								{
									comp[i].displayOutput();
								}
							}
							else if(opt2 == 3)
							{
								comp = new Hostel[10];
								for(int i=0 ; i<10 ; i++)
								{
									comp[i].displayOutput();
								}
							}
							else if(opt2 == 4)
							{
								comp = new Other[10];
								for(int i=0 ; i<10 ; i++)
								{
									comp[i].displayOutput();
								}
							}
							else
							{
								comp = new Complain[10];
								for(int i=0 ; i<10 ; i++)
								{
									comp[i].displayOutput();
								}
							}	
							
							cout<<"Do you want to view other complains?(Y/N) ->";
							cin>>yesNo;
							
							system("cls");
								
						}while(yesNo == 'Y' || yesNo == 'y');
						
						break;
		
				case 3 :system("cls");
						return 0;
			}
	}while(opt==1||opt==2);
	
	return 0;
	}
 