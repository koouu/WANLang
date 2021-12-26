#pragma once
#include<iostream>
using namespace std;

//1文字のやつ
const string RESERVED_LIST_1="＋ー＊・（）＜＞";
//2もじのやつ
const string RESERVED_LIST_2="＜＝＞＝＝＝！＝；";



bool isRESERVED2(const char *p){
	int fsize=6;
	for(int i=0;i<RESERVED_LIST_2.size()/fsize;i++){
		const char *p2=p;
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



bool isRESERVED1(const char *p){
	int fsize=3;
	for(int i=0;i<RESERVED_LIST_1.size()/fsize;i++){
		const char *p2=p;
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

bool isFullJP(const char *p){
	if(*p==-29){
		p++;
		//あ~み&&む~ん
		if(*p!=-127&&*p!=-126)return 0;
		p++;
		if((*p<-127||*p>-65)&&(*p<-128||*p>-109))return 0;
		p++;
		return 1;
	}
		
	return 0;
}
int getFullJPNum(const char *p){
	int ret=0;
	if(isFullJP(p)){
		p++;
		ret+=127+(*p);
		p++;
		ret+=((128+(*p))<<1);
		//0~9は数字だから
		ret+=10;
	}else{
		p+=2;
		ret=(*p)+112;
	}
	
	
	return ret;

}

int getFullNum(const char *p){
	p+=2;
	return (*p)+112;
}

bool isIdentifier(const char *&p){
	bool f=0;
	while(1){
		const char *p2=p;
		
		p2=p;
		if(*p2==-29){
			p2++;
			//あ~み&&む~ん
			if(*p2!=-127&&*p2!=-126)break;
			p2++;
			if((*p2<-127||*p2>-65)&&(*p2<-128||*p2>-109))break;
			p2++;
			p+=3;
			f=1;
			continue;
		}
		
		//数字
		if(*p2==-17){
			if(f!=1)break;
			p2++;
			if(*p2!=-68)break;
			p2++;
			if((*p)+112<0||(*p)+112>9)break;
			p2++;
			p+=3;
			continue;
		}
		break;
		
	}
	
	return f;
	
};

int getnum(const char *&p){
	int n=0;
	
	while(*p){
		const char *p2=p;
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
bool isFullPar(const char *p){
	if(*p!=-17)return 0;
	p++;
	if(*p!=-68)return 0;
	p++;
	if(*p!=-120&&*p!=-119)return 0;
	return 1;
	
};

bool isFullMul(const char *p){
	const char fadd[]="＊";
	const char fsub[]="・";
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

bool isFullSpace(const char *p){
	const char x[]="　";
	if(*p!=x[0])return 0;
	p++;
	if(*p!=x[1])return 0;
	p++;
	if(*p!=x[2])return 0;
	return 1;
};

bool isFullDigit(const char *p){
	//全角数字は1bit目-17,2bit目-68,3bit目-112~-103(0~9)
	const char x[]="　";
	if(*p!=-17)return 0;
	p++;
	if(*p!=-68)return 0;
	p++;
	//printf("%d\n",*p);
	if((*p)+112<0||(*p)+112>9)return 0;
	//printf("fa\n");
	return 1;
};

bool isFullAdd(const char *p){
	//全角＋ーは大きく異なる
	const char fadd[]="＋";
	const char fsub[]="ー";
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


bool compareFullChar(const char *p,string s){
	
	for(int i=0;i<s.size();i++){
		if(!(*p))return 0;
		if(*p!=s[i])return 0;
		p++;
	}
	return 1;
}



bool isFullCom(const char *p){
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