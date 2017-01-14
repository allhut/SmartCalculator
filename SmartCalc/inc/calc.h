/*  Copyright 2016 @ Allhut    */

#include "header.h"

class calc {

  private:
    char *p_str;  
    
  public: 
  	calc();
  	void getString();
    void printOutput();
    int exitOp();
};

calc::calc(){

	p_str = NULL;
}

void calc::getString(){
	p_str = new char[256];
	cin.getline(p_str, 256);
	//getline(cin, p_str);
}
void calc::printOutput(){
	int result = 0;  
	result = evaluateString(p_str);
	delete p_str;
	cout<<"Result:"<<result<<endl; 


}

int calc::exitOp(){

	if(*p_str == '\n')
		return 0;
	else
		return 1;
}

