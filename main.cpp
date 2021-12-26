#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Analysis.cpp"

using namespace std;




int main(int argc,char **argv){
	
  if (argc != 2) {
    printf("引数が足りません\n");
    return 1;
  }
	ifstream ifs(argv[1]);
	if (!ifs)
  {
  	std::cout << "ファイルが開けませんでした。" << std::endl;
    std::cin.get();
    return 0;
  }
	const char *txt;
	
	string data="";
  while (!ifs.eof()){
		string buf;
    getline(ifs, buf);
    data += buf + "\n";
  }
	data+='\0';
	const char *p;
	p=data.c_str();
	Analysis *analysis=new Analysis(p);
	analysis->doAnalysis();

  printf("#include <iostream>\n");
	printf("using namespace std;\n");
  printf("int main(){\n");
	
	analysis->outCppSource();
	
	printf("<<endl;\n");
  printf("	return 0;\n");
  printf("}\n");
  return 0;
}