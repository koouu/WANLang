
#include "FullChar.cpp"


#include <iostream>
#include <vector>
#include"Token.cpp"
using namespace std;

class Analysis{
private:
	char *data;
	string s;
	//Token *head;
	//Node node;
	vector<Token> tokens;
public:
	Analysis(char *data);
	void doAnalysis();
	bool isFullSpace(char *p);
	bool isFullDigit(char *p);
	bool isFullAdd(char *p);
	bool isFullMul(char *p);
	bool isFullPar(char *p);
	vector<Token> getTokens();
	void outCppSource();
	~Analysis();
};


Analysis::Analysis(char *data)
{
	this->data=data;
	s="";
}
bool Analysis::isFullPar(char *p){
	if(*p!=-17)return 0;
	p++;
	if(*p!=-68)return 0;
	p++;
	if(*p!=-120&&*p!=-119)return 0;
	return 1;
	
};

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
	
	while(*p){
		printf("%s\n",p);
		if(isFullSpace(p)){
			p+=3;
			continue;
		}
		if(isFullPar(p)){
			Token t(eRESERVED, p);
			tokens.push_back(t);
			p+=3;
			continue;
		}
		if(isFullMul(p)){
			Token t(eRESERVED, p);
			tokens.push_back(t);
			p+=3;
			continue;
		}
		if(isFullAdd(p)){
			//printf("add\n");
			Token t(eRESERVED, p);
			tokens.push_back(t);
			p+=3;
			continue;
		}
		if(isFullDigit(p)){
			//printf("dig\n");
			Token t(eNUM, p);
			t.setval(getnum(p));
			tokens.push_back(t);
			continue;
		}
		printf("トークナイズできません\n");
		exit(1);
	}
	tokens.push_back(Token(eEOF,p));
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
			if(tokens[i].isThisChar("（")){
				printf("%c",'(');
			}
			if(tokens[i].isThisChar("）")){
				printf("%c",')');
			}
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