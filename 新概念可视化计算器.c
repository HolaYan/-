#include<stdio.h>
#include<string.h>
#define MAX 10000 
void printline(int n);
void getresult();
void read();

double number_stack[MAX];
char symbol_stack[MAX];
int i_num = 0,i_sym = 0;

int main(){
	int sign;
	double number1,number2;
	char symbol;
	printf("-----------------------��ӭʹ�ü򵥼�����-----------------------\n\n"); 
    printf("-------����1 ��ʼ����-------\n\n"); 
   	printf("-------����0 �˳�-----------\n");
	scanf("%d",&sign);
	if(sign == 1){
		printline(1);
		read();
		getresult();
		printline(2);
	}
	else if(sign == 0){
		printline(2);
	}
	return 0;
}

void printline(int n){
	if(n == 1){
    	printf("------��������Ҫ���ʽ��-----------------------\n"); 
    	printf("------ÿ������֮���ÿո����������1 + 2 + 3----\n"); 
    	printf("------����س����������������������---------\n");
	}
	else if(n == 2){
		printf("------------------------ллʹ��--------------------------------\n");
	}
}

void getresult(){
	double result,temp;
	char symbol,signal;
	int i = 0,j = 0;
	result = 0;
	for(i;i <= i_num;i++){
		if(symbol_stack[j] == '+' && j <= i_sym){
			result += (number_stack[i] + number_stack[++i]);
			j++;
		}
		else if(symbol_stack[j] == '-' && j <= i_sym){
			result += (number_stack[i] - number_stack[++i]);
			j++;
		}
		else if(symbol_stack[j] == '*' && j <= i_sym){
			result += (number_stack[i] * number_stack[++i]);
			j++;
		}
		else if(symbol_stack[j] == '/' && j <= i_sym){
			result += (number_stack[i] / number_stack[++i]);
			j++;
		}
	}
	printf("The result is %lf\n",result);
}

void read(){
	double temp;
	char blank_place;
	while((scanf("%lf",&temp)) != EOF){
		number_stack[i_num++] = temp;
		blank_place = getchar();
		if(blank_place == '\n'){
		//	printf("------------------------ллʹ��--------------------------------\n");
            break;
		}
		scanf("%c",&symbol_stack[i_sym++]);
	}
}
