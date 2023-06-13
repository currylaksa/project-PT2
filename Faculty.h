#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
using namespace std;


class Faculty : public Complain{
	private:
		
	public:
		Faculty(string _desc="") : Complain(_desc){}
		
		void setFacultyDesc(string _desc){
			setDescription(_desc);
		}
		
		void displayOutput(){
			cout<<description<<endl;
		}
		
		//setinfo
		//getinfo
};

#endif