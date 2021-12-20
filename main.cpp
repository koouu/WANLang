#include <iostream>

int main(int argc,char **argv){
	
  if (argc != 2) {
    printf("因数が足りません\n");
    return 1;
  }

  printf("#include <iostream>");
  printf("int main(){\n");
  printf("	printf(\"hellowould\");\n");
  printf("	return 0;\n");
  printf("}\n");
  return 0;
}