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
	printf("-----------------------欢迎使用简单计算器-----------------------\n\n"); 
    printf("-------输入1 开始计算-------\n\n"); 
   	printf("-------输入0 退出-----------\n");
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
    	printf("------请输入所要求的式子-----------------------\n"); 
    	printf("------每个数据之间用空格隔开，例如1 + 2 + 3----\n"); 
    	printf("------点击回车代表输入结束，并输出结果---------\n");
	}
	else if(n == 2){
		printf("------------------------谢谢使用--------------------------------\n");
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
		//	printf("------------------------谢谢使用--------------------------------\n");
            break;
		}
		scanf("%c",&symbol_stack[i_sym++]);
	}
}
