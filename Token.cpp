#include <iostream>
#include "FullChar.cpp"
#include "Data.cpp"
using namespace std;

enum ETokenKind{
	eArticle,		//文
	eRESERVED,	// 記号
	eIDENT,			// 識別子
  eNUM, 			// 整数トークン
  eEOF, 			// 入力の終わりを表すトークン
	eSTART,			//開始
};

class Token
{
private:
	ETokenKind kind; // トークンの型
  Token *next;    // 次の入力トークン
  int val;        // kindがTK_NUMの場合、その数値
  const char *str;      // トークン文字列
	Data& data =Data::GetInstance();
	
public:
	Token(ETokenKind kind, const char *str);
	void setval(int val);
	Token getnext();
	int getval();
	const char *getstr();
	ETokenKind getkind();
	bool isThisChar(string c);
	void setnext(Token *t);
	string getIdentifier();
	~Token();
};

Token::Token(ETokenKind kind, const char *str)
{	

		this->kind=kind;
		this->str=str;
}
const char*Token::getstr(){
	return str;
};
void Token::setnext(Token *t){
	this->next=t;
};

void Token::setval(int val)
{	
		this->val=val;
}
Token Token::getnext()
{	
		return *next;
}

int Token::getval()
{	
		return val;
}

ETokenKind Token::getkind(){
	return kind;
}

string Token::getIdentifier(){
	string s="";
	while(isFullJP(str)||isFullDigit(str)){
		for(int i=0;i<3;i++){
			s+=*str;
			str++;
		}
	}
	return data.getVariable(s.c_str());
}

bool Token::isThisChar(string c){
	
	const char *c2=str;
	for(int i=0;i<c.size();i++){
		if(c[i]!=*c2)return 0;
		c2++;
	}
	return 1;
	
}

Token::~Token()
{
}


