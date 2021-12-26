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
}

void Data::setVariable(const char *c){
	string var="var"+to_string(cnt);
	v->setVariable(c,var);
	cnt++;
}

string Data::getVariable(const char *c){
	return v->getVariableName(c);
}
Data::~Data()
{
}
