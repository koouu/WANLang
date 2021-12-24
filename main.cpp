#include <iostream>
#include <vector>

#include "Analysis.cpp"

using namespace std;




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