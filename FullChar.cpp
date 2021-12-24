#include<iostream>
using namespace std;

//1文字のやつ
const string RESERVED_LIST_1="＋ー＊・（）＜＞";
//2もじのやつ
const string RESERVED_LIST_2="＜＝＞＝＝＝！＝";

bool isRESERVED2(char *p){
	int fsize=6;
	for(int i=0;i<RESERVED_LIST_2.size()/fsize;i++){
		char *p2=p;
		bool f=1;
		for(int j=0;j<fsize;j++){
			if(RESERVED_LIST_2[i*fsize+j]!=*p2){
				f=0;
				break;
			}
			p2++;
		}
		if(f)return 1;
	}
	return 0;
}

bool isRESERVED1(char *p){
	int fsize=3;
	for(int i=0;i<RESERVED_LIST_1.size()/fsize;i++){
		char *p2=p;
		bool f=1;
		for(int j=0;j<fsize;j++){
			if(RESERVED_LIST_1[i*fsize+j]!=*p2){
				f=0;
				break;
			}
			p2++;
		}
		if(f)return 1;
	}
	return 0;
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
bool isFullPar(char *p){
	if(*p!=-17)return 0;
	p++;
	if(*p!=-68)return 0;
	p++;
	if(*p!=-120&&*p!=-119)return 0;
	return 1;
	
};

bool isFullMul(char *p){
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

bool isFullSpace(char *p){
	char x[]="　";
	if(*p!=x[0])return 0;
	p++;
	if(*p!=x[1])return 0;
	p++;
	if(*p!=x[2])return 0;
	return 1;
};

bool isFullDigit(char *p){
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

bool isFullAdd(char *p){
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


bool compareFullChar(char *p,string s){
	for(int i=0;i<s.size();i++){
		if(!(*p))return 0;
		if(*p!=s[i])return 0;
	}
	return 1;
}



bool isFullCom(char *p){
	//全角＋ーは大きく異なる
	if(*p!=-17)return 0;
	p++;
	if(*p!=-68)return 0;
	p++;
	//<or<=
	if(*p==-100)return 1;
	//>or>=
	if(*p==-98)return 1;
	//== or !=
	if(*p==-99||*p==-127){
		if(*p!=-17)return 0;
		p++;
		if(*p!=-68)return 0;
		p++;
		
		if(*p==-100)return 1;
		return 0;
	}
	
	return 1;
	return 0;
};