#include<iostream>
using namespace std;

class Variable
{
private:
	/* data */
	char txt;
	Variable *next;
	bool check=0;

public:
	Variable(char *p);
	string getVariableName(char *p);
	bool checkVariableName(char *p);
	~Variable();
};

Variable::Variable(char *p)
{
	txt=*p;
	p++;
	if(*p){
		next=new Variable(p);
	}else{
		check=1;
	}
}
string Variable::getVariableName(char *p){
	p++;
	if(*p)return txt+next->getVariableName(p);
	return (string)""+txt;
};

bool Variable::checkVariableName(char *p){
	if(!(*p))return check;
	p++;
	return next->checkVariableName(p);
}

Variable::~Variable()
{
}


