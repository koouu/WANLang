#include "Variable.cpp"

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
	Variable *v[2];
	int cnt=0;
	~Data();
public:
	void setVariable(char *c){

	}
};

Data::Data(/* args */)
{
	char *c;
	*c=-127;
	v[0]=new Variable(c);
	*c=-126;
	v[1]=new Variable(c);
}

Data::~Data()
{
}
