#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Analysis.cpp"

using namespace std;




int main(int argc,char **argv){
	
  if (argc != 2) {
    printf("引数にファイルを書いてほしいワン\n");
    return 1;
  }
	ifstream ifs(argv[1]);
	if (!ifs)
  {
  	cout << "ファイルが開けないワン" << std::endl;
    return 1;
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
	
	analysis->outCppSource();
	
  return 0;
}