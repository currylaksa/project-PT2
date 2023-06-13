#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;
class Student : public User{
	private:
		string matricNum;
		Arcade* arcade;
		Faculty* faculty;
		Hostel* hostel;
		Other* other;
		int cntA, cntF, cntH, cntO;
		
	public:
		Student(string _username="", string _matricNum="") : User(_username){
			matricNum = _matricNum;
			arcade = new Arcade[5];
			faculty = new Faculty[5];
			hostel = new Hostel[5];
			other = new Other[5];
			cntA = cntF = cntH = cntO = 0;
		}
			
		
		void setMatricNum(string _matricNum){
			matricNum = _matricNum;
		}
		
		string getStudentName(){
			return getUsername();
		}
		
		string getMatricNum(){
			return matricNum;
		}
		
		void displayComplain(){
			system("cls");
			cout<<"Name: "<<getStudentName()<<endl
				<<"Matric No: "<<getMatricNum()<<endl<<endl
				<<"Complain: "<<endl;
				
			cout<<"Complain for Arcade:\n";
			for(int i=0 ; i<5 ;i++)
			{
				if(arcade[i].getDescription() != "")
				{
					cout<<i+1<<". ";
					arcade[i].displayOutput();
				}
					
			}
			
			cout<<"\nComplain for Faculty: \n";
			for(int i=0 ; i<5 ;i++)
			{
				if(faculty[i].getDescription() != "")
				{
					cout<<i+1<<". ";
					faculty[i].displayOutput();
				}
					
			}
			
			cout<<"\nComplain for Hostel:\n";
			for(int i=0 ; i<5 ;i++)
			{
				
				if(hostel[i].getDescription() != "")
				{
					cout<<i+1<<". ";
					hostel[i].displayOutput();
				}
					
			}
			
			cout<<"\nComplain for Other:\n";
			
			for(int i=0 ; i<5 ;i++)
			{
				
				if(other[i].getDescription() != "")
				{
					cout<<i+1<<". ";
					other[i].displayOutput();
				}
			}
			
		}
		
		void linkArcade(Arcade a)
		{
			if(cntA >= 6)
			{
				cout<<"Max number of complain for the arcade per person";
				return;
			}
			
			arcade[cntA] = a;
			cntA++;
		}
		
		void linkFaculty(Faculty f)
		{
			if(cntF >= 6)
			{
				cout<<"Max number of complain for the arcade per person";
				return;
			}
			
			faculty[cntF] = f;
			cntF++;
		}
		
		void linkHostel(Hostel h)
		{
			if(cntH >= 6)
			{
				cout<<"Max number of complain for the arcade per person";
				return;
			}
			
			hostel[cntH] = h;
			cntH++;
		}
		
		void linkOther(Other o)
		{
			if(cntO >= 6)
			{
				cout<<"Max number of complain for the arcade per person";
				return;
			}
			
			other[cntO] = o;
			cntO++;
		}
		
		
};

#endif