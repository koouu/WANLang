#include<iostream>
#include "FullChar.cpp"
using namespace std;

class Variable
{
private:
	/* data */
	char txt;
	Variable *next[150]={};
	bool check=0;
	string name;

public:
	Variable();
	void setVariable(char *p,string name);
	string getVariableName(char *p);
	bool checkVariableName(char *p);
	~Variable();
};

Variable::Variable()
{
	check=0;
}

void Variable::setVariable(char *p,string name){
	txt=*p;
	int nextnum=getFullJPNum(p);
	if(next[nextnum]==NULL)next[nextnum]=new Variable();
	
	
	p+=3;
	if(*p){
		next[nextnum]->setVariable(p,name);
	}else{
		check=1;
		this->name=name;
	}
}


string Variable::getVariableName(char *p){
	int nextnum=getFullJPNum(p);
	p+=3;
	if(*p)return next[nextnum]->getVariableName(p);
	return name;
};

bool Variable::checkVariableName(char *p){
	int nextnum=getFullJPNum(p);
	p+=3;
	if(!(*p))return check;
	return next[nextnum]->checkVariableName(p);
}

Variable::~Variable()
{
}


