#include<iostream>
using namespace std;

class Variable
{
private:
	/* data */
	char txt;
	Variable *next;
	bool check=0;
	string name;

public:
	Variable(char *p,string name);
	string getVariableName(char *p);
	bool checkVariableName(char *p);
	~Variable();
};

Variable::Variable(char *p,string name)
{
	txt=*p;
	p++;
	if(*p){
		next=new Variable(p,name);
	}else{
		check=1;
		this->name=name;
	}
}
string Variable::getVariableName(char *p){
	p++;
	if(*p)return next->getVariableName(p);
	return name;
};

bool Variable::checkVariableName(char *p){
	if(!(*p))return check;
	p++;
	return next->checkVariableName(p);
}

Variable::~Variable()
{
}


