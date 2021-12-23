#include <iostream>
#include <vector>
using namespace std;

enum ETokenKind{
	eRESERVED,	// 記号
  eNUM, 			// 整数トークン
  eEOF, 			// 入力の終わりを表すトークン
	eSTART,			//開始
};

class Node
{
private:
	ETokenKind kind; // Node kind
  Node *left;     // Left-hand side
  Node *right; 
public:
	Node(/* args */);

	void add();

	~Node();
};



class Token
{
private:
	ETokenKind kind; // トークンの型
  Token *next;    // 次の入力トークン
  int val;        // kindがTK_NUMの場合、その数値
  char *str;      // トークン文字列
	
public:
	Token(ETokenKind kind, Token *token, char *str);
	void setval(int val);
	Token getnext();
	int getval();
	char *getstr();
	ETokenKind getkind();
	bool isThisChar(string c);
	void setnext(Token *t);
	~Token();
};

Token::Token(ETokenKind kind, Token *preToken, char *str)
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


Node::Node(/* args */)
{
}

Node::~Node()
{
}

int getnum(char *&p){
	int n=0;
	
	while(*p){
		char *p2=p;\
		if(*p2!=-17)break;
		p2++;
		if(*p2!=-68)break;
		p2++;
		if((*p2)+112<0||(*p2)+112>9)break;
		n*=10;
		n+=112+(*p2);
		p+=3;
	}
	return n;
}


class Analysis{
private:
	char *data;
	string s;
	Token *head;
	Node node;
	vector<Token> tokens;
public:
	Analysis(char *data);
	void doAnalysis();
	bool isFullSpace(char *p);
	bool isFullDigit(char *p);
	bool isFullAdd(char *p);
	bool isFullMul(char *p);
	vector<Token> getTokens();
	void outCppSource();
	~Analysis();
};

Analysis::Analysis(char *data)
{
	this->data=data;
	s="";
}
bool Analysis::isFullMul(char *p){
	char fadd[]="＊";
	char fsub[]="・";
	if(*p==fadd[0]){
		
		p++;
		if(*p!=fadd[1])return 0;
		p++;
		if(*p!=fadd[2])return 0;
		return 1;
	}
	if(*p==fsub[0]){
		
		p++;
		if(*p!=fsub[1])return 0;
		p++;
		if(*p!=fsub[2])return 0;
		return 1;

	}
	return 0;
};



void Analysis::doAnalysis(){
	char *p=data;
	Token *token=head;
	
	while(*p){
		//printf("%s\n",p);
		if(isFullSpace(p)){
			p+=3;
			continue;
		}
		if(isFullMul(p)){
			Token t(eRESERVED, token, p);
			tokens.push_back(t);
			p+=3;
			continue;
		}
		if(isFullAdd(p)){
			//printf("add\n");
			Token t(eRESERVED, token, p);
			tokens.push_back(t);
			p+=3;
			continue;
		}
		if(isFullDigit(p)){
			//printf("dig\n");
			Token t(eNUM, token, p);
			t.setval(getnum(p));
			tokens.push_back(t);
			continue;
		}
		printf("トークナイズできません\n");
		exit(1);
	}
	tokens.push_back(Token(eEOF,token,p));
	//token=new Token(eEOF,token,p);
	//*head=head->getnext();
};
bool Analysis::isFullSpace(char *p){
	char x[]="　";
	if(*p!=x[0])return 0;
	p++;
	if(*p!=x[1])return 0;
	p++;
	if(*p!=x[2])return 0;
	return 1;
};

vector<Token> Analysis::getTokens(){
	return tokens;
}

bool Analysis::isFullDigit(char *p){
	//全角数字は1bit目-17,2bit目-68,3bit目-112~-103(0~9)
	char x[]="　";
	if(*p!=-17)return 0;
	p++;
	if(*p!=-68)return 0;
	p++;
	//printf("%d\n",*p);
	if((*p)+112<0||(*p)+112>9)return 0;
	//printf("fa\n");
	return 1;
};

bool Analysis::isFullAdd(char *p){
	//全角＋ーは大きく異なる
	char fadd[]="＋";
	char fsub[]="ー";
	//printf("%d,%d\n",*p,fadd[0]);
	if(*p==fadd[0]){
		
		p++;
		if(*p!=fadd[1])return 0;
		p++;
		if(*p!=fadd[2])return 0;
		return 1;
	}
	if(*p==fsub[0]){
		
		p++;
		if(*p!=fsub[1])return 0;
		p++;
		if(*p!=fsub[2])return 0;
		return 1;

	}
	return 0;
};
void Analysis::outCppSource(){
	char *p=data;
	int i=0;
	while(tokens[i].getkind()!=eEOF){
		if(tokens[i].getkind()==eNUM){
			printf("%d",tokens[i].getval());
		}
		if(tokens[i].getkind()==eRESERVED){
			if(tokens[i].isThisChar("＊")){
				printf("%c",'*');
			}
			if(tokens[i].isThisChar("・")){
				printf("%c",'/');
			}
			
			if(tokens[i].isThisChar("＋")){
				printf("%c",'+');
			}
			if(tokens[i].isThisChar("ー")){
				printf("%c",'-');
			}
		}
		i++;
	}
}

Analysis::~Analysis()
{
}



int main(int argc,char **argv){
	
  if (argc != 2) {
    printf("引数が足りません\n");
    return 1;
  }
	char *p=argv[1];
	Analysis *analysis=new Analysis(p);
	analysis->doAnalysis();

  printf("#include <iostream>\n");
	printf("using namespace std;\n");
  printf("int main(){\n");
  printf("	cout<<");
	
	analysis->outCppSource();
	
	printf("<<endl;\n");
  printf("	return 0;\n");
  printf("}\n");
  return 0;
}