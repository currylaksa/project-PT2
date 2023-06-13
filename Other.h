#ifndef OTHER_H
#define OTHER_H
#include <iostream>
using namespace std;
class Other : public Complain{
	private:
		
	public:
		Other(string _desc="") : Complain(_desc){}
		
		void setOtherDesc(string _desc){
			setDescription(_desc);
		}
		
		void displayOutput(){
			cout<<description<<endl;
		}
		
		//setinfo
		//getinfo
};

#endif