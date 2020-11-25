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
//上述代码用于让map按value进行排序
const int M = 40000 ;//数据
map<string,double>Map;//用于排序算法的快慢
int mp[M];      //用于装随机数的数组；

void Random_number()//生成随机数的函数
{
    int RandomNumber;
    srand((unsigned)time(NULL));//time()用系统时间初始化种。为rand()生成不同的随机种子。
    for(int i=0; i<M; i++)
    {
        RandomNumber = rand();//每次生成一个随机数
        mp[i]=RandomNumber;//赋值给数组
    }
}
void quicksort(int left, int right, vector<int>& num) // 快速排序，从小到大，递归
{
    if(left >= right)
        return;
    int i, j, base;
    i = left, j = right;
    base = num[left];  //取最左边的数为基准数
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
    //基准数归位
    num[left] = num[i];
    num[i] = base;
    quicksort(left, i - 1, num);//递归左边
    quicksort(i + 1, right, num);//递归右边
}
void Quick_sort() //快速排序
{
    clock_t start,finish;   //开始时间和结束时间
    double duration;        //算法所需时间
    vector<int>num;         //存随机数
    FILE *fw;
    if((fw=fopen("快速排序结果.txt","w+"))==NULL)//打开文件
    {
        cout<<"Wrong read."<<endl;
        exit(0);
    }
    for(int i=0; i<M; i++)
        num.push_back(mp[i]);

    start=clock();
    quicksort(0,M-1,num); //快速排序
    finish=clock();

    duration=(double)(finish - start)/CLOCKS_PER_SEC;//计算所需时间
    Map["快速排序"]=duration;
    cout<<"快速排序所需时间:\t"<<duration<<endl;

    for(int i=0; i<M; i++)//输入文件
    {
        fprintf(fw,"%d ",num[i]);
    }
    fclose(fw);
}
void Selection_sort()//选择排序
{
    clock_t start,finish;   //开始时间和结束时间
    double duration;        //算法所需时间
    int num[M];         //存随机数
    FILE *fw;
    if((fw=fopen("选择排序结果.txt","w+"))==NULL)
    {
        cout<<"Wrong read."<<endl;
        exit(0);
    }

    for(int i=0; i<M; i++)
        num[i]=mp[i];

    start=clock(); //开始时间
    for(int i=0; i<M; i++)      //选择排序
        for(int j=i+1; j<M; j++)
        {
            if(num[i]>num[j])
            {
                swap(num[i],num[j]);
            }
        }
    finish=clock(); //结束时间
    duration=(double)(finish - start)/CLOCKS_PER_SEC;//计算所需时间
    Map["选择排序"]=duration;
    cout<<"选择排序算法所需时间:\t"<<duration<<endl;

    for(int i=0; i<M; i++)//输入文件
    {
        fprintf(fw,"%d ",num[i]);
    }
    fclose(fw);
}
void Bubble_sort() //起泡排序
{
    bool flag;
    clock_t start,finish;   //开始时间和结束时间
    double duration;        //算法所需时间
    int num[M];         //存随机数


    FILE *fw;
    if((fw=fopen("起泡排序结果.txt","w+"))==NULL)
    {
        cout<<"Wrong read."<<endl;
        exit(0);
    }

    for(int i=0; i<M; i++)
        num[i]=mp[i];

    start=clock();
    flag = true;
    for(int i=1; i<M&&flag==true; i++) //起泡排序
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
    duration=(double)(finish - start)/CLOCKS_PER_SEC;//计算所需时间
    Map["起泡排序"]=duration;
    cout<<"起泡排序算法所需时间:\t"<<duration<<endl;

    for(int i=0; i<M; i++)//输入文件
    {
        fprintf(fw,"%d ",num[i]);
    }
    fclose(fw);
}
void Insertion_sort() //插入排序
{
    clock_t start,finish;   //开始时间和结束时间
    double duration;        //算法所需时间
    int num[M];         //存随机数
    FILE *fw;
    if((fw=fopen("插入排序结果.txt","w+"))==NULL) //打开文件
    {
        cout<<"Wrong read."<<endl;
        exit(0);
    }
    for(int i=0; i<M; i++)
        num[i]=mp[i];

    start=clock();
    for(int i=1; i<M; i++)      //插入排序
    {
        for(int j=i; j>0; j--)
        {
            if(num[j-1]>num[j])
                swap(num[j],num[j-1]);
        }
    }

    finish=clock();

    duration=(double)(finish - start)/CLOCKS_PER_SEC;//计算所需时间
    Map["插入排序"]=duration;
    cout<<"插入排序所需时间:\t"<<duration<<endl;

    for(int i=0; i<M; i++)
    {
        fprintf(fw,"%d ",num[i]);
    }
    fclose(fw);
}
void Shell_sotr() // 希尔排序
{
    clock_t start,finish;   //开始时间和结束时间
    double duration;        //算法所需时间
    int num[M];         //存随机数
    FILE *fw;
    if((fw=fopen("希尔排序结果.txt","w+"))==NULL) //打开文件
    {
        cout<<"Wrong read."<<endl;
        exit(0);
    }
    for(int i=0; i<M; i++)
        num[i]=mp[i];
    start=clock();
    /*希尔排序*/
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

    duration=(double)(finish - start)/CLOCKS_PER_SEC;//计算所需时间
    Map["希尔排序"]=duration;
    cout<<"希尔排序所需时间:\t"<<duration<<endl;

    for(int i=0; i<M; i++)  //输入文件
    {
        fprintf(fw,"%d ",num[i]);
    }
    fclose(fw);
}
void Print()  //输出
{
    cout<<"比较快的两种方法是:"<<endl;

    /*把map中元素转存到vector中*/
    vector<PAIR> SORT(Map.begin(),Map.end());
    sort(SORT.begin(), SORT.end(), CmpByValue());///排序

    for(int i=0; i<2; i++) //输出算法速度较快的前两名
    {
        cout<<"\t"<<SORT[i].first<<endl;
    }
}
int main()
{
    cout<<"程序已经运行，请稍等片刻"<<endl;
    Random_number();
    cout<<"随机数已生成完成"<<endl;
    Selection_sort();//选择排序
    Bubble_sort();//起泡排序
    Insertion_sort();//插入排序
    Shell_sotr();//希尔排序
    Quick_sort();//快速排序
    Print();
    return 0;
}

