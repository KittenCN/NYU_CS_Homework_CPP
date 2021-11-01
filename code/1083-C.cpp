#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 200001
typedef  struct Node{
    int grade;
    int num;
}Node;
Node a[maxn];
Node A[100001];
Node B[100001];
int w[maxn];
bool cmp(Node a,Node b)
{
    if(a.grade == b.grade)
        return a.num<b.num;
    return a.grade>b.grade;
}
int n,r,q;
void MergeSort()///把AB归并到a中
{
    int i=1,j=1,k=1;///分别用来在AB以及a中移动的指针
    while(i<=n && j<=n)
    {
        if(A[i].grade > B[j].grade || (A[i].grade == B[j].grade && A[i].num < B[j].num))
        {
            a[k].grade = A[i].grade;
            a[k++].num = A[i++].num;
        }
        else{
            a[k].grade = B[j].grade;
            a[k++].num = B[j++].num;
        }
    }
    while(i<=n)
    {
        a[k].grade = A[i].grade;
        a[k++].num = A[i++].num;
    }
    while(j<=n)
    {
         a[k].grade = B[j].grade;
        a[k++].num = B[j++].num;
    }
}
int main()
{
    cin>>n>>r>>q;///2*n名选手 r轮比赛 关心的名次q
    for(int i=1;i<=2*n;i++)
    {
        cin>>a[i].grade;
        a[i].num=i;
    }
    for(int i=1;i<=2*n;i++)
        cin>>w[i];
    sort(a+1,a+1+2*n,cmp);
    for(int k=1;k<=r;k++)
    {
        int tt=1;
        for(int i=1;i<2*n;i+=2)
        {
            //cout<<w[a[i].num]<<" "<<w[a[i+1].num]<<endl;
            if(w[a[i].num]>w[a[i+1].num])
            {
                A[tt].grade = a[i].grade+1;
                A[tt].num = a[i].num;
                B[tt].grade  =  a[i+1].grade;
                B[tt].num = a[i+1].num;
                tt++;
            }    //a[i].grade++;
            else
            {
                A[tt].grade = a[i+1].grade+1;
                A[tt].num = a[i+1].num;
                B[tt].grade  =  a[i].grade;
                B[tt].num = a[i].num;
                tt++;
            }
        }
        MergeSort();
    }
    cout<<a[q].num<<endl;///排名第q的选手的编号
    system("pause");
    return 0;
}