#include<stdio.h>
#define Max 5000
int main(){
	int sugar,min=Max,temp,r,r1;
	scanf("%d",&sugar);
	if(sugar<3||sugar>Max)
		return 1;
	else{
		temp=sugar/5;
		if(temp==0){
			if(sugar%5==3)
				min =1;
		}
		else{
			while(temp>=0){
					r=sugar-5*temp;
					r1=r/3;
					if(r%3==0){
						if(min>temp+r1){
							min=temp+r1;
						}
					}
					temp=temp-1;
				}
			}
	}
	if(min==Max)
		min=-1;
	printf("%d",min);
	return 0; 
}