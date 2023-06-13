#ifndef COMPLAIN_H
#define COMPLAIN_H
#include <iostream>
using namespace std;

class Complain
{
	protected:
		string description;
	
	public:
		Complain(string _desc=""){
			description = _desc;
		}
		
		void setDescription(string _desc){
			description = _desc;
		}
		
		string getDescription(){
			return description;
		}
		
		
		virtual void displayOutput(){
			cout<<"Desc from Complain..."<<endl;
		}
};

#endif