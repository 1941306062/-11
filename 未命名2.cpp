
#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

#define MAXSIZE 100
typedef  struct
{
	char elem[MAXSIZE];
	int  top;
} SqStack2; //顺序栈2的类型定义,存放运算符，故定义成char型的栈

/**********函数声明**********/
//运算符栈的基本操作
void InitStack2(SqStack2 &s);
int StackEmpty2(SqStack2 s);
void Push2(SqStack2 &s, char x);
void Pop2(SqStack2 &s, char &x);
void GetTop2(SqStack2 s, char &x);

char Precede(char theta1, char theta2);//比较两个运算符θ1和θ2的优先关系
void Conversion(char exp[80],char suffix[80]);//中缀式转换成后缀式



/**********子函数**********/
/**********运算符栈的基本操作**********/
void InitStack2(SqStack2 &s)   //栈的初始化
{
	s.top=-1;
}
int StackEmpty2(SqStack2 s)   //判栈空
{
	if(s.top==-1) return 1;
	else return 0;
}
void Push2(SqStack2 &s, char x)   //将元素x入栈
{
	if(s.top==MAXSIZE-1)   //判栈满
	{
		printf("Stack is full\n");
		return;
	}
	s.top++;
	s.elem[s.top]=x;
}
void Pop2(SqStack2 &s, char &x)   //将栈顶元素出栈
{
	if(s.top==-1)   //判栈空
	{
		printf("Stack is empty\n");
		return;
	}
	x=s.elem[s.top];
	s.top--;
}
void GetTop2(SqStack2 s, char &x)   //取栈顶
{
	if(s.top==-1)
	{
		printf("Stack is empty\n");
		return;
	}
	x=s.elem[s.top];
}
/**********其它子函数**********/
void Conversion(char exp[80],char suffix[80])   //中缀式转换成后缀式
{
	SqStack2 optr;
	char x,top;
	int i,j=0;
	InitStack2(optr);//构造栈optr存放运算符
	Push2(optr,'#');
	GetTop2(optr, top);//取出栈顶运算符，用top保存
	i=0;
	while(exp[i]!='#'||top!='#')
	{
		// 请在这里补充代码，完成本关任务
		/********** Begin *********/
		if(exp[i]>='0'&&exp[i]<='9'||exp[i]=='.')
		{
			while(exp[i]>='0'&&exp[i]<='9'||exp[i]=='.')
			{
				suffix[j++]=exp[i++];
			}
			suffix[j++]=',';
		}

		else  switch(Precede(top,exp[i]))
			{
				case '<':
					if(i==0||exp[i-1]=='(')
					{
						suffix[j++]='0';
						suffix[j++]=',';
					}
					Push2(optr,exp[i]);
					i++;
					break;
				case '=':
					Pop2(optr,x);
					i++;
					break;
				case '>':
					Pop2(optr,x);
					suffix[j++]=x;
					break;

			}
		GetTop2(optr, top);
		/********** End **********/
	}
	suffix[j]='\0';
}

char Precede(char theta1, char theta2)   //比较两个运算符θ1和θ2的优先关系，返回'>'、'<'或'='。
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if(theta1=='+'||theta1=='-')
	{
		if(theta2=='-'||theta2=='+'||theta2=='#'||theta2==')')
			return '>';

		else if(theta2=='*'||theta2=='/'||theta2=='(')
			return '<';
	}

	else if(theta1=='*'||theta1=='/')
	{
		if(theta2=='-'||theta2=='+'||theta2=='#'||theta2=='*'||theta2=='/'||theta2==')')
			return '>';

		else if(theta2=='(')
			return '<';
	}

	else if(theta1=='(')
	{
		if(theta2=='-'||theta2=='+'||theta2=='*'||theta2=='/'||theta2=='(')
			return '<';

		else if(theta2==')')
			return '=';
	}

	else if(theta1==')')
	{
		if(theta2=='-'||theta2=='+'||theta2=='#'||theta2=='*'||theta2=='/'||theta2==')')
			return '>';
	}

	else if(theta1=='#')
	{
		if(theta2=='-'||theta2=='+'||theta2=='*'||theta2=='('||theta2=='/')
			return '<';

		else if(theta2=='#')
			return '=';
	}
	/********** End **********/
}
/**********其它子函数**********/
double Operate(double a, char theta, double b)   //求两数a和b作θ运算的结果
{
	switch(theta)
	{
		case '+':
			return(a+b);
		case '-':
			return(a-b);
		case '*':
			return(a*b);
		case '/':
			return(a/b);
	}
}

int main()
{
	char exp[80],suffix[80];
	scanf("%s",exp);//输入一个中缀式，以'#'结束
	Conversion(exp,suffix);//借助栈将中缀式转换为后缀式
	printf("Suffix: %s\n",suffix);
}

//9+(3-1)*3+1/2#
//9,3,1,-3,*+1,2,/+
//123.678+5*(5.6+78)-78.24/2+100#
//123.678,5,5.6,78,+*+78.24,2,/-100,+
//-123.678+0*(-5.6-78)-78.24/2+100#
//0,123.678,-5,0,5.6,-78,+*+78.24,2,/-100,+


/*double Evaluation(char exp[80]) { //中缀式求值
SqStack1 opnd;
SqStack2 optr;
char s[80],x,top;
double sum,a,b,result;
int i,j=0,n;
InitStack1(opnd);//构造栈opnd存放操作数
InitStack2(optr);//构造栈optr存放运算符
Push2(optr,'#');
GetTop2(optr, top);//取出栈顶运算符，用top保存
i=0;
while(exp[i]!='#'||top!='#') {
	// 请在这里补充代码，完成本关任务

	if(exp[i]>='0'&&exp[i]<='9') {  // 若有小数点,则小数点前
		sum=0;
		while(exp[i]>='0'&&exp[i]<='9') {
			sum=sum*10+exp[i++]-'0';
		}

		if(exp[i]=='.') { //小数点后
			i++;
			double m=0.1;
			while(exp[i]>='0'&&exp[i]<='9') {
				sum=sum+(exp[i++]-'0')*m;
				m=m*0.1;
			}
		}
		opnd.top++;
		opnd.elem[opnd.top]=sum;
	}

	else 	switch(Precede(top,exp[i])) {
			case '<':
				if(i==0||exp[i-1]=='(')
				Push1(opnd,0);
				Push2(optr,exp[i]);
				i++;
				break;//
			case '=':
				Pop2(optr,x);
				i++;;
				break;
			case '>':
				Pop2(optr,x);
				Pop1(opnd,a);
				Pop1(opnd,b);
				Push1(opnd,Operate(b,x,a));
				break;
		}
	GetTop2(optr, top);
}
Pop1(opnd,result);
return(result);
}
  */
