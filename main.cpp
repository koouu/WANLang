#include <iostream>


enum TokenKind{
	TK_RESERVED,	// 記号
  TK_NUM, 			// 整数トークン
  TK_EOF, 			// 入力の終わりを表すトークン
};



int main(int argc,char **argv){
	
  if (argc != 2) {
    printf("引数が足りません\n");
    return 1;
  }

  printf("#include <iostream>\n");
	printf("using namespace std;\n");
  printf("int main(){\n");
  printf("	cout<<");
	char *p=argv[1];
	while(*p){
		
		if(p[0]==-17&&p[1]==-68&&p[2]<=-103&&p[2]>=-112){
				printf("%d",(int)p[2]+112);
		}

		if(p[0]==-17&&p[1]==-68&&p[2]==-117){
			printf("+");
		}
		if(p[0]==-29&&p[1]==-125&&p[2]==-68){
			printf("-");
		}

		p++;
		p++;
		p++;
	}

	printf("<<endl;\n");
  printf("	return 0;\n");
  printf("}\n");
  return 0;
}