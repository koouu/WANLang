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
	bool setVariable(const char *p,string name);
	string getVariableName(const char *p);
	bool checkVariableName(const char *p);
	~Variable();
};

Variable::Variable()
{
	check=0;
}

bool Variable::setVariable(const char *p,string name){
	int nextnum=getFullJPNum(p);
	if(next[nextnum]==NULL)next[nextnum]=new Variable();
	
	
	p+=3;
	//printf("s:\n%s\n",p);
	if(*p){
		return next[nextnum]->setVariable(p,name);
	}else{
		if(check)return 0;
		check=1;
		this->name=name;
		return 1;
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


