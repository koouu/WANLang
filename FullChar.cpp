
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
