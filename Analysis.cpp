
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
	vector<Token> getTokens();
	void outCppSource();
	~Analysis();
};


Analysis::Analysis(char *data)
{
	this->data=data;
	s="";
}




void Analysis::doAnalysis(){
	char *p=data;
	
	while(*p){
		printf("%s\n",p);
		if(isFullSpace(p)){
			p+=3;
			continue;
		}

		if(isRESERVED2(p)){
			//printf("add\n");
			Token t(eRESERVED, p);
			tokens.push_back(t);
			p+=6;
			continue;
		}
		
		if(isRESERVED1(p)){
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



vector<Token> Analysis::getTokens(){
	return tokens;
}


void Analysis::outCppSource(){
	char *p=data;
	int i=0;
	while(tokens[i].getkind()!=eEOF){
		if(tokens[i].getkind()==eNUM){
			printf("%d",tokens[i].getval());
		}
		if(tokens[i].getkind()==eRESERVED){
			//2文字
			if(tokens[i].isThisChar("＜＝")){
				printf("%s","<=");
			}
			else if(tokens[i].isThisChar("＞＝")){
				printf("%s",">=");
			}
			else if(tokens[i].isThisChar("！＝")){
				printf("%s","!=");
			}
			else if(tokens[i].isThisChar("＝＝")){
				printf("%s","==");
			}

			//1文字
			else if(tokens[i].isThisChar("＜")){
				printf("%c",'<');
			}
			else if(tokens[i].isThisChar("＞")){
				printf("%c",'>');
			}

			else if(tokens[i].isThisChar("（")){
				printf("%c",'(');
			}
			else if(tokens[i].isThisChar("）")){
				printf("%c",')');
			}
			else if(tokens[i].isThisChar("＊")){
				printf("%c",'*');
			}
			else if(tokens[i].isThisChar("・")){
				printf("%c",'/');
			}
			
			else if(tokens[i].isThisChar("＋")){
				printf("%c",'+');
			}
			else if(tokens[i].isThisChar("ー")){
				printf("%c",'-');
			}
		}
		i++;
	}
}

Analysis::~Analysis()
{
}