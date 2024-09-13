#include <stdio.h>
int main(){
	int n,c[100]={0};
	int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char tet[]={'1','0','x','9','8','7','6','5','4','3','2'};
	scanf("%d",&n);
	char id[100][19];
	int error=0;
	for(int i=0;i<n;i++){
		scanf("%s",id[i]);
		int sum=0;
		for(int j=0;j<17;j++){
			sum+=(id[i][j]-'0')*weight[j];
		}
		int z=sum%11;
		if(tet[z]!=id[i][17]){
			error+=1;
			c[i]=1;
		}
		
	}
	if(error==0){
		printf("All passed");
	}
	else {
		for(int i=0;i<n;i++){
			if(c[i]==1){
				printf("%s\n", id[i]);
			}
		}
	}
}


#include<stdio.h>
int main(){
	int n,sum[100]={0},z[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char sfz[100][19],M[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",&sfz[i]);
		for(int j=0;j<17;j++){
			sum[i]+=z[j]*(sfz[i][j]-'0');
		}
		sum[i]=sum[i]%11;
	}
	int x=0;
	for(int i=0;i<n;i++){
		if(M[sum[i]]!=sfz[i][17]){
			x+=1;
			printf("%s\n",sfz[i]);
		}
	}
	if(x==0){
		printf("All passed");
	}
}