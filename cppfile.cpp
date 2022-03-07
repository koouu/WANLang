#include <bits/stdc++.h>
using namespace std;

int var0;
int var1[10][10];
int var2[(1<<11)][10];

int var3(int var4,int var5){
	
	if(var2[var4][var5]!=-1)return var2[var4][var5];
	
	if(var4==(1<<var5)){
		return var2[var4][var5]=0;
	}

	int var6 = (1<<30);
	int var7=var4 & ~(1<<var5);

	for(int var8=0;var8<var0;var8++){
		if(!(var7&(1<<var8))){
			continue;
		}

		if(var6>var3(var7,var8)+var1[var5][var8]){
			var6=var3(var7,var8)+var1[var5][var8];
		}

	}
	return var2[var4][var5]=var6;


}



int main(){
	cin>>var0;
	for(int var5=0;var5<var0;var5++){
		for(int var8=0;var8<var0;var8++){
			cin>>var1[var5][var8];
		}
	
	}
	for(int var4=0;var4<(1<<var0);var4++){
		for(int var5=0;var5<var0;var5++){
			var2[var4][var5]=-1;
		}
	
	}

	int var6 = (1<<30);
	
	for(int var5=0;var5<var0;var5++){
		if(var6>var3((1<<var0)-1,var5)){
			var6=var3((1<<var0)-1,var5);
		}
		
	
	}
	cout<<var6<<endl;


}

