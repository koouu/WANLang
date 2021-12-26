#include<iostream>
#include "FullChar.cpp"
using namespace std;

class Variable
{
private:
	/* data */
	Variable *next[150]={};
	bool check=0;
	string name;

public:
	Variable();
	void setVariable(const char *p,string name);
	string getVariableName(const char *p);
	bool checkVariableName(const char *p);
	~Variable();
};

Variable::Variable()
{
	check=0;
}

void Variable::setVariable(const char *p,string name){
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


string Variable::getVariableName(const char *p){
	int nextnum=getFullJPNum(p);
	p+=3;
	if(*p)return next[nextnum]->getVariableName(p);
	return name;
};

bool Variable::checkVariableName(const char *p){
	int nextnum=getFullJPNum(p);
	p+=3;
	if(!(*p))return check;
	return next[nextnum]->checkVariableName(p);
}

Variable::~Variable()
{
}


