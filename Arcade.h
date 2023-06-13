#ifndef ARCADE_H
#define ARCADE_H
#include <iostream>
using namespace std;

class Arcade : public Complain{
	private:
		
	public:
		Arcade(string _desc="") : Complain(_desc){}
		
		void setArcadeDesc(string _desc){
			setDescription(_desc);
		}
		
		void displayOutput(){
			cout<<description<<endl;
		}
		//setinfo
		//getinfo
};

#endif

