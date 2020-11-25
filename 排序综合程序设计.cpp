#include"iostream"
#include"cstdio"
#include"stdlib.h"
#include"cstring"
#include"cstdlib"
#include"vector"
#include"map"
#include"algorithm"
#include <iomanip>
#include <time.h>
#include <fstream>
#include <sstream>
using namespace std;
typedef pair<string, double> PAIR;
struct CmpByValue
{
    bool operator()(const PAIR& lhs, const PAIR& rhs)
    {
        return lhs.second < rhs.second;
    }
};
//��������������map��value��������
const int M = 40000 ;//����
map<string,double>Map;//���������㷨�Ŀ���
int mp[M];      //����װ����������飻

void Random_number()//����������ĺ���
{
    int RandomNumber;
    srand((unsigned)time(NULL));//time()��ϵͳʱ���ʼ���֡�Ϊrand()���ɲ�ͬ��������ӡ�
    for(int i=0; i<M; i++)
    {
        RandomNumber = rand();//ÿ������һ�������
        mp[i]=RandomNumber;//��ֵ������
    }
}
void quicksort(int left, int right, vector<int>& num) // �������򣬴�С���󣬵ݹ�
{
    if(left >= right)
        return;
    int i, j, base;
    i = left, j = right;
    base = num[left];  //ȡ����ߵ���Ϊ��׼��
    while (i < j)
    {
        while (num[j] >= base && i < j)
            j--;
        while (num[i] <= base && i < j)
            i++;
        if(i < j)
        {
           swap(num[i],num[j]);
        }
    }
    //��׼����λ
    num[left] = num[i];
    num[i] = base;
    quicksort(left, i - 1, num);//�ݹ����
    quicksort(i + 1, right, num);//�ݹ��ұ�
}
void Quick_sort() //��������
{
    clock_t start,finish;   //��ʼʱ��ͽ���ʱ��
    double duration;        //�㷨����ʱ��
    vector<int>num;         //�������
    FILE *fw;
    if((fw=fopen("����������.txt","w+"))==NULL)//���ļ�
    {
        cout<<"Wrong read."<<endl;
        exit(0);
    }
    for(int i=0; i<M; i++)
        num.push_back(mp[i]);

    start=clock();
    quicksort(0,M-1,num); //��������
    finish=clock();

    duration=(double)(finish - start)/CLOCKS_PER_SEC;//��������ʱ��
    Map["��������"]=duration;
    cout<<"������������ʱ��:\t"<<duration<<endl;

    for(int i=0; i<M; i++)//�����ļ�
    {
        fprintf(fw,"%d ",num[i]);
    }
    fclose(fw);
}
void Selection_sort()//ѡ������
{
    clock_t start,finish;   //��ʼʱ��ͽ���ʱ��
    double duration;        //�㷨����ʱ��
    int num[M];         //�������
    FILE *fw;
    if((fw=fopen("ѡ��������.txt","w+"))==NULL)
    {
        cout<<"Wrong read."<<endl;
        exit(0);
    }

    for(int i=0; i<M; i++)
        num[i]=mp[i];

    start=clock(); //��ʼʱ��
    for(int i=0; i<M; i++)      //ѡ������
        for(int j=i+1; j<M; j++)
        {
            if(num[i]>num[j])
            {
                swap(num[i],num[j]);
            }
        }
    finish=clock(); //����ʱ��
    duration=(double)(finish - start)/CLOCKS_PER_SEC;//��������ʱ��
    Map["ѡ������"]=duration;
    cout<<"ѡ�������㷨����ʱ��:\t"<<duration<<endl;

    for(int i=0; i<M; i++)//�����ļ�
    {
        fprintf(fw,"%d ",num[i]);
    }
    fclose(fw);
}
void Bubble_sort() //��������
{
    bool flag;
    clock_t start,finish;   //��ʼʱ��ͽ���ʱ��
    double duration;        //�㷨����ʱ��
    int num[M];         //�������


    FILE *fw;
    if((fw=fopen("����������.txt","w+"))==NULL)
    {
        cout<<"Wrong read."<<endl;
        exit(0);
    }

    for(int i=0; i<M; i++)
        num[i]=mp[i];

    start=clock();
    flag = true;
    for(int i=1; i<M&&flag==true; i++) //��������
    {
        flag=false;
        for(int j=0; j<M-i; j++)
        {
            if(num[j]>num[j+1])
            {
                swap(num[j],num[j+1]);
                flag =true;
            }
        }
    }
    finish=clock();
    duration=(double)(finish - start)/CLOCKS_PER_SEC;//��������ʱ��
    Map["��������"]=duration;
    cout<<"���������㷨����ʱ��:\t"<<duration<<endl;

    for(int i=0; i<M; i++)//�����ļ�
    {
        fprintf(fw,"%d ",num[i]);
    }
    fclose(fw);
}
void Insertion_sort() //��������
{
    clock_t start,finish;   //��ʼʱ��ͽ���ʱ��
    double duration;        //�㷨����ʱ��
    int num[M];         //�������
    FILE *fw;
    if((fw=fopen("����������.txt","w+"))==NULL) //���ļ�
    {
        cout<<"Wrong read."<<endl;
        exit(0);
    }
    for(int i=0; i<M; i++)
        num[i]=mp[i];

    start=clock();
    for(int i=1; i<M; i++)      //��������
    {
        for(int j=i; j>0; j--)
        {
            if(num[j-1]>num[j])
                swap(num[j],num[j-1]);
        }
    }

    finish=clock();

    duration=(double)(finish - start)/CLOCKS_PER_SEC;//��������ʱ��
    Map["��������"]=duration;
    cout<<"������������ʱ��:\t"<<duration<<endl;

    for(int i=0; i<M; i++)
    {
        fprintf(fw,"%d ",num[i]);
    }
    fclose(fw);
}
void Shell_sotr() // ϣ������
{
    clock_t start,finish;   //��ʼʱ��ͽ���ʱ��
    double duration;        //�㷨����ʱ��
    int num[M];         //�������
    FILE *fw;
    if((fw=fopen("ϣ��������.txt","w+"))==NULL) //���ļ�
    {
        cout<<"Wrong read."<<endl;
        exit(0);
    }
    for(int i=0; i<M; i++)
        num[i]=mp[i];
    start=clock();
    /*ϣ������*/
    int h=1;
    while(h < M/3) h=3*h+1;  // 1,4,13,40...
    while(h>=1)
    {
        for(int i=h; i<M; i++)
        {
            for(int j=i; j>=h ; j-=h)
            {
                if(num[j-h]>num[j])
                {
                    swap(num[j-h],num[j]);
                }
            }
        }
        h=h/3;
    }

    finish=clock();

    duration=(double)(finish - start)/CLOCKS_PER_SEC;//��������ʱ��
    Map["ϣ������"]=duration;
    cout<<"ϣ����������ʱ��:\t"<<duration<<endl;

    for(int i=0; i<M; i++)  //�����ļ�
    {
        fprintf(fw,"%d ",num[i]);
    }
    fclose(fw);
}
void Print()  //���
{
    cout<<"�ȽϿ�����ַ�����:"<<endl;

    /*��map��Ԫ��ת�浽vector��*/
    vector<PAIR> SORT(Map.begin(),Map.end());
    sort(SORT.begin(), SORT.end(), CmpByValue());///����

    for(int i=0; i<2; i++) //����㷨�ٶȽϿ��ǰ����
    {
        cout<<"\t"<<SORT[i].first<<endl;
    }
}
int main()
{
    cout<<"�����Ѿ����У����Ե�Ƭ��"<<endl;
    Random_number();
    cout<<"��������������"<<endl;
    Selection_sort();//ѡ������
    Bubble_sort();//��������
    Insertion_sort();//��������
    Shell_sotr();//ϣ������
    Quick_sort();//��������
    Print();
    return 0;
}

