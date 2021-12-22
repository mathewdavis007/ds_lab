#include <stdio.h>

typedef struct{
	int expo;
	float coeff;
}terms;

void display(terms termsArr[],int startA,int endA,int startB,int endB,int startAns,int endAns){
	//printf("%d \n",startA);
	
	for (int i = startA;i<=endA;i++){
	        
		printf("%fx^%d + ",termsArr[i].coeff,termsArr[i].expo);
	}
	printf("\n");
	for (int j = startB;j<=endB;j++){
		printf("%.2fx^%d + ",termsArr[j].coeff,termsArr[j].expo);
	}
	printf("\n");
	
	
	for (int k = startAns;k<=endAns;k++){
		printf("%.2fx^%d + ",termsArr[k].coeff,termsArr[k].expo);
	}
	printf("\n");
}

int compare(int a,int b){
	if (a>b){
		return 1;
	}
	
	else if (a<b){
		return -1;
	}
	
	else{
		return 0;
	}
}

void addPolynomial(terms termsArr[],int startA,int endA,int startB,int endB,int avail){
	int startAns = avail;
	int startATemp = startA;
	int startBTemp = startB;
	//printf("startB %d\n",termsArr[1].coeff);
	//printf("startB %d\n",termsArr[1].coeff);
	while (startA<=endA && startB<=endB){
		int res = compare(termsArr[startA].expo,termsArr[startB].expo);
		
		switch (res){
			case 0:
				termsArr[avail].expo = termsArr[startA].expo;
				termsArr[avail].coeff = termsArr[startA].coeff+termsArr[startB].coeff;
				//printf("%d %d\n",termsArr[startA].coeff,termsArr[startB].coeff);
				startA++;startB++;avail++;
				break;
				
			case 1:
				termsArr[avail].expo = termsArr[startA].expo;
				termsArr[avail].coeff = termsArr[startA].coeff;
				startA++;avail++;
				break;
				
			case -1:
				termsArr[avail].expo = termsArr[startB].expo;
				termsArr[avail].coeff = termsArr[startB].coeff;
				startB++;avail++;
				break;
				
				
				
		
		}
	}
	for (;startA<=endA;startA++){
		termsArr[avail++] = termsArr[startA];
	}
	
	for (;startB<=endB;startB++){
		termsArr[avail++] = termsArr[startB];
	}
	
	startA--;startB--;
	int endAns = avail - 1;
	
	//printf("startB %d\n",termsArr[1].coeff);
	//printf("startB %d\n",termsArr[1].coeff);
	
	display(termsArr,startATemp,endA,startBTemp,endB,startAns,endAns);
}

void main(){
	terms termsArr[100];
	
	//accepting input from user
	int n,startA=0,startB,endA,endB,avail;
	printf("Enter no of terms in first polynomial: ");
	scanf("%d",&n);
	
	for (int i=0;i<n;i++){
		printf("exponent : ");
		scanf("%d",&termsArr[i].expo);
		printf("coefficient : ");
		scanf("%f",&termsArr[i].coeff);
	}
	
	endA = n-1;
	startB = n;
	
	printf("Enter no of terms in second polynomial: ");
	scanf("%d",&n);
	
	for (int i=startB;i<startB+n;i++){
		printf("exponent : ");
		scanf("%d",&termsArr[i].expo);
		printf("coefficient : ");
		scanf("%f",&termsArr[i].coeff);
	}
	
	//printf("startB %d\n",termsArr[startB].coeff);
	
	endB = startB + n - 1;
	
	
	avail = endB + n;
	printf("%d \n",startA);
	
	addPolynomial(termsArr,startA,endA,startB,endB,avail);
	
	
	
}
