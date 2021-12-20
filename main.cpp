#include <iostream>


enum TokenKind{
	TK_RESERVED,	// 記号
  TK_NUM, 			// 整数トークン
  TK_EOF, 			// 入力の終わりを表すトークン
};



int main(int argc,char **argv){
	
  if (argc != 2) {
    printf("因数が足りません\n");
    return 1;
  }

  printf("#include <iostream>\n");
	printf("using namespace std;\n");
  printf("int main(){\n");
  printf("	cout<<");
	printf("%s",argv[1]);

	printf("<<endl;\n");
  printf("	return 0;\n");
  printf("}\n");
  return 0;
}