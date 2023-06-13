#ifndef STAFF_H
#define STAFF_H
#include <iostream>
using namespace std;
class Staff : public User{
	private:
		string staffID;
		string password;
		Complain complain;
		
	public:
		Staff(string _username="", string _password="") : User(_username){
			//...
		}

		void setStaffID(string _id){
			staffID = _id;
		}

		void setPassword(string _password){
			password = _password;
		}
		
		string getStaffName(){
			return getUsername(); 
		}
		
		string getStaffID(){
			return staffID;
		}
		
		string getPassword(){
			return password;
		}
		
		void displayComplain(){
			complain.displayOutput();
		}
		
		
};

#endif