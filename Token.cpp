#include <iostream>
using namespace std;

enum ETokenKind{
	eRESERVED,	// 記号
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
  char *str;      // トークン文字列
	
public:
	Token(ETokenKind kind, char *str);
	void setval(int val);
	Token getnext();
	int getval();
	char *getstr();
	ETokenKind getkind();
	bool isThisChar(string c);
	void setnext(Token *t);
	~Token();
};

Token::Token(ETokenKind kind, char *str)
{	

		this->kind=kind;
		this->str=str;
}
char*Token::getstr(){
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

bool Token::isThisChar(string c){
	
	char *c2=str;
	if(c[0]!=*c2)return 0;
	c2++;
	if(c[1]!=*c2)return 0;
	c2++;
	if(c[2]!=*c2)return 0;
	return 1;
}

Token::~Token()
{
}


