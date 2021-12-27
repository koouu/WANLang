
#include "FullChar.cpp"


#include <iostream>
#include <vector>
#include"Token.cpp"
using namespace std;

class Analysis{
private:
	const char *data;
	string s;
	//Token *head;
	//Node node;
	vector<Token> tokens;
public:
	Analysis(const char *data);
	void doAnalysis();
	vector<Token> getTokens();
	void outCppSource();
	~Analysis();
};


Analysis::Analysis(const char *data)
{
	this->data=data;
	s="";
}




void Analysis::doAnalysis(){
	const char *p=data;
	int ncnt=0;
	while(*p){
		//printf("%s\n",p);
		// if(isFullSpace(p)){
		// 	p+=3;
		// 	continue;
		// }
		//tab
		if(*p==9||*p==10){
			if(*p==10)ncnt++;
			Token t(eRESERVED, p);
			tokens.push_back(t);
			p++;
			
			continue;
		}

		if(compareFullChar(p,"※")){
			Token t(eRESERVED, p);
			tokens.push_back(t);
			commentOut(p);
			continue;
		}
		if(isRESERVED3(p)){
			//printf("add\n");
			Token t(eRESERVED, p);
			tokens.push_back(t);
			p+=9;
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
		const char *p2=p;
		if(isIdentifier(p2)){
			Token t(eIDENT, p);
			p=p2;
			tokens.push_back(t);
			continue;
		}
		p2=p;
		if(isFullString(p2)){
			Token t(eRESERVED, p);
			p=p2;
			tokens.push_back(t);
			continue;
		}



		if(isFullDigit(p)){
			//printf("dig\n");
			Token t(eNUM, p);
			t.setval(getnum(p));
			tokens.push_back(t);
			continue;
		}
		printf("%d行目がわからないワン\n",ncnt+1);
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
	const char *p=data;
	int i=0;
	ofstream ofs("cppfile.cpp");
	ofs<<"#include <bits/stdc++.h>\n";
	ofs<<"using namespace std;\n";	

	
	while(tokens[i].getkind()!=eEOF){
		if(tokens[i].getkind()==eIDENT){
			ofs<<tokens[i].getIdentifier();
		}
		if(tokens[i].getkind()==eNUM){
			ofs<<tokens[i].getval();
		}
		if(tokens[i].getkind()==eRESERVED){

			if(*(tokens[i].getstr())==9){
				ofs<<"	";
			}

			if(*(tokens[i].getstr())==10){
				ofs<<"\n";
			}

			//2文字
			if(tokens[i].isThisChar("＜＝")){
				ofs<<"<=";
			}
			else if(tokens[i].isThisChar("＞＝")){
				ofs<<">=";
			}
			else if(tokens[i].isThisChar("！＝")){
				ofs<<"!=";
			}
			else if(tokens[i].isThisChar("＝＝")){
				ofs<<"==";
			}
			else if(tokens[i].isThisChar("＋＋")){
				ofs<<"++";
			}
			else if(tokens[i].isThisChar("＋＝")){
				ofs<<"+=";
			}
			else if(tokens[i].isThisChar("ーー")){
				ofs<<"--";
			}

			else if(tokens[i].isThisChar("ー＝")){
				ofs<<"-=";
			}
			else if(tokens[i].isThisChar("＊＝")){
				ofs<<"*=";
			}
			else if(tokens[i].isThisChar("／＝")){
				ofs<<"/=";
			}

			//1文字
			else if(tokens[i].isThisChar("．")){
				ofs<<'.';
			}
			else if(tokens[i].isThisChar("　")){
				ofs<<' ';
			}
			else if(tokens[i].isThisChar("＜")){
				ofs<<'<';
			}
			else if(tokens[i].isThisChar("＞")){
				ofs<<'>';
			}

			else if(tokens[i].isThisChar("（")){
				ofs<<'(';
			}
			else if(tokens[i].isThisChar("）")){
				ofs<<')';
			}
			else if(tokens[i].isThisChar("％")){
				ofs<<'%';
			}
			else if(tokens[i].isThisChar("＊")){
				ofs<<'*';
			}
			else if(tokens[i].isThisChar("／")){
				ofs<<'/';
			}
			
			else if(tokens[i].isThisChar("＋")){
				ofs<<'+';
			}
			else if(tokens[i].isThisChar("ー")){
				ofs<<'-';
			}
			else if(tokens[i].isThisChar("。")){
				ofs<<';';
			}
			else if(tokens[i].isThisChar("、")){
				ofs<<',';
			}
			else if(tokens[i].isThisChar("＝")){
				ofs<<'=';
			}
			else if(tokens[i].isThisChar("｛")){
				ofs<<'{';
			}
			else if(tokens[i].isThisChar("｝")){
				ofs<<'}';
			}
			else if(tokens[i].isThisChar("「")){
				ofs<<'[';
			}
			else if(tokens[i].isThisChar("」")){
				ofs<<']';
			}
			else if(tokens[i].isThisChar("※")){
				ofs<<getCommentOut(tokens[i].getstr()).c_str();
			}
			else if(tokens[i].isThisChar("＆")){
				ofs<<'&';
			}
			else if(tokens[i].isThisChar("｜")){
				ofs<<'|';
			}
			else if(tokens[i].isThisChar("～")){
				ofs<<'~';
			}
			else if(tokens[i].isThisChar("！")){
				ofs<<'!';
			}
			
			else if(tokens[i].isThisChar("”")){
				ofs<<getFullString(tokens[i].getstr()).c_str();
			}
		}
		i++;
	}
}

Analysis::~Analysis()
{
}