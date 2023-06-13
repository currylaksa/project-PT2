#ifndef HOSTEL_H
#define HOSTEL_H
#include <iostream>
using namespace std;

class Hostel : public Complain{
	private:
		
	public:
		Hostel(string _desc="") : Complain(_desc){}
		
		void setHostelDesc(string _desc){
			setDescription(_desc);
		}
		
		void displayOutput(){
			cout<<description<<endl;
		}
		
		//setinfo
		//getinfo
};

#endif