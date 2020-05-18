
#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

#define MAXSIZE 100
typedef  struct
{
	char elem[MAXSIZE];
	int  top;
} SqStack2; //˳��ջ2�����Ͷ���,�����������ʶ����char�͵�ջ

/**********��������**********/
//�����ջ�Ļ�������
void InitStack2(SqStack2 &s);
int StackEmpty2(SqStack2 s);
void Push2(SqStack2 &s, char x);
void Pop2(SqStack2 &s, char &x);
void GetTop2(SqStack2 s, char &x);

char Precede(char theta1, char theta2);//�Ƚ������������1�ͦ�2�����ȹ�ϵ
void Conversion(char exp[80],char suffix[80]);//��׺ʽת���ɺ�׺ʽ



/**********�Ӻ���**********/
/**********�����ջ�Ļ�������**********/
void InitStack2(SqStack2 &s)   //ջ�ĳ�ʼ��
{
	s.top=-1;
}
int StackEmpty2(SqStack2 s)   //��ջ��
{
	if(s.top==-1) return 1;
	else return 0;
}
void Push2(SqStack2 &s, char x)   //��Ԫ��x��ջ
{
	if(s.top==MAXSIZE-1)   //��ջ��
	{
		printf("Stack is full\n");
		return;
	}
	s.top++;
	s.elem[s.top]=x;
}
void Pop2(SqStack2 &s, char &x)   //��ջ��Ԫ�س�ջ
{
	if(s.top==-1)   //��ջ��
	{
		printf("Stack is empty\n");
		return;
	}
	x=s.elem[s.top];
	s.top--;
}
void GetTop2(SqStack2 s, char &x)   //ȡջ��
{
	if(s.top==-1)
	{
		printf("Stack is empty\n");
		return;
	}
	x=s.elem[s.top];
}
/**********�����Ӻ���**********/
void Conversion(char exp[80],char suffix[80])   //��׺ʽת���ɺ�׺ʽ
{
	SqStack2 optr;
	char x,top;
	int i,j=0;
	InitStack2(optr);//����ջoptr��������
	Push2(optr,'#');
	GetTop2(optr, top);//ȡ��ջ�����������top����
	i=0;
	while(exp[i]!='#'||top!='#')
	{
		// �������ﲹ����룬��ɱ�������
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

char Precede(char theta1, char theta2)   //�Ƚ������������1�ͦ�2�����ȹ�ϵ������'>'��'<'��'='��
{
	// �������ﲹ����룬��ɱ�������
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
/**********�����Ӻ���**********/
double Operate(double a, char theta, double b)   //������a��b��������Ľ��
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
	scanf("%s",exp);//����һ����׺ʽ����'#'����
	Conversion(exp,suffix);//����ջ����׺ʽת��Ϊ��׺ʽ
	printf("Suffix: %s\n",suffix);
}

//9+(3-1)*3+1/2#
//9,3,1,-3,*+1,2,/+
//123.678+5*(5.6+78)-78.24/2+100#
//123.678,5,5.6,78,+*+78.24,2,/-100,+
//-123.678+0*(-5.6-78)-78.24/2+100#
//0,123.678,-5,0,5.6,-78,+*+78.24,2,/-100,+


/*double Evaluation(char exp[80]) { //��׺ʽ��ֵ
SqStack1 opnd;
SqStack2 optr;
char s[80],x,top;
double sum,a,b,result;
int i,j=0,n;
InitStack1(opnd);//����ջopnd��Ų�����
InitStack2(optr);//����ջoptr��������
Push2(optr,'#');
GetTop2(optr, top);//ȡ��ջ�����������top����
i=0;
while(exp[i]!='#'||top!='#') {
	// �������ﲹ����룬��ɱ�������

	if(exp[i]>='0'&&exp[i]<='9') {  // ����С����,��С����ǰ
		sum=0;
		while(exp[i]>='0'&&exp[i]<='9') {
			sum=sum*10+exp[i++]-'0';
		}

		if(exp[i]=='.') { //С�����
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
