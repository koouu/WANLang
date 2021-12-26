#include "Variable.cpp"
#include <string>

template<class T>
class Singleton {
	T& operator=(const Singleton<T>&);
	Singleton(const Singleton<T>&);
protected:
	Singleton() {};
	virtual ~Singleton() {};
public:
	static T& GetInstance() {
		static T ins;
		return ins;
	}
};

class Data: public Singleton<Data>
{
private:
	friend Singleton<Data>;
	Data();
	Variable *v;
	int cnt=0;
	~Data();
public:
	void setVariable(const char *c);
	string getVariable(const char *c);
};

Data::Data(/* args */)
{
	cnt=0;
	v=new Variable();
	v->setVariable("わん","cout");
	v->setVariable("ぷーどる","string");
	v->setVariable("ちわわ","int");
	v->setVariable("ぶる","bool");
	v->setVariable("ぽめらにあん","long long");
	v->setVariable("わんこ","main");
	v->setVariable("むれ","vector");
	v->setVariable("ついか","push_back");
	
}

void Data::setVariable(const char *c){
	string var="var"+to_string(cnt);
	cnt+=v->setVariable(c,var);
}

string Data::getVariable(const char *c){
	setVariable(c);
	return v->getVariableName(c);
}
Data::~Data()
{
}
