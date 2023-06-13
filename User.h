#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;
class User{
	private:
		string username;
		
	public:
		User(string _username){
			username = _username;
		}
		
		void setUsername(string _username){
			username = _username;
		}
		
		string getUsername(){
			return username;
		}
};

#endif