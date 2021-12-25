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
	void setVariable(char *c);
};

Data::Data(/* args */)
{
	cnt=0;
	v=new Variable();
}

void Data::setVariable(char *c){
	string var="var"+to_string(cnt);
	v->setVariable(c,var);
	
}
Data::~Data()
{
}
